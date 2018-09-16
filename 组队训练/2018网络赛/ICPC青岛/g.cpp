#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---

const int N = 101010;

int n, L;
int a[N], rt[N], cnt[N * 22], ls[N * 22], rs[N * 22];
multiset<ll> st;
set<pair<pii, ll> > s;

void init() {
	L = 0;
}

int newnode() {
	int u = ++L;
	cnt[u] = ls[u] = rs[u] = 0;
	return u;
}

void upd(int pre, int &now, int p, int l, int r) {
	now = newnode();
	cnt[now] = cnt[pre] + 1;
	ls[now] = ls[pre];
	rs[now] = rs[pre];
	if(l == r) return ;
	int mid = l + r >> 1;
	if(p <= mid) upd(ls[pre], ls[now], p, l, mid);
	else upd(rs[pre], rs[now], p, mid + 1, r);
}
int qry(int lt, int rt, int L, int R, int l, int r) {
	if(lt == rt || L > R) return 0;
	if(L <= l && r <= R) return cnt[rt] - cnt[lt];
	int mid = l + r >> 1, ans = 0;
	if(L <= mid) ans += qry(ls[lt], ls[rt], L, R, l, mid);
	if(R > mid) ans += qry(rs[lt], rs[rt], L, R, mid + 1, r);
	return ans;
}

ll calc(int l, int r) {
	if(l > r) return 0;
	ll res = 0;
	rep(i, l, r) {
		res += qry(rt[i], rt[r], 1, a[i] - 1, 1, n);
	}
	return res;
}

void gao(int p) {
	auto t = s.upper_bound(mp(mp(p, 1e9), 1e9));
	--t;
	int l = (*t).fi.fi, r = (*t).fi.se;
	ll A = (*t).se, B = 0, C = 0;
//	de(p);
//	dd(l), dd(r), de(A);
	int L = p - l, R = r - p;
	if(L <= R) {
		B = calc(l, p - 1);
		C = A - B;
		C -= qry(rt[l-1], rt[p-1], a[p] + 1, n, 1, n);
		rep(i, l, p) C -= qry(rt[p], rt[r], 1, a[i] - 1, 1, n);
		C -= qry(rt[p], rt[r], 1, a[p] - 1, 1, n);
	} else {
		C = calc(p + 1, r);
		B = A - C;
		B -= qry(rt[p], rt[r], 1, a[p] - 1, 1, n);
		rep(i, p + 1, r + 1) B -= qry(rt[l-1], rt[p-1], a[i] + 1, n, 1, n);
		B -= qry(rt[l-1], rt[p-1], a[p] + 1, n, 1, n);
	}
	if(A) st.erase(st.find(A));
	if(B) st.insert(B);
	if(C) st.insert(C);
	s.erase(t);
//	dd(l), dd(p - 1), de(B);
//	dd(p + 1), dd(r), de(C);
	if(l <= p - 1) s.insert(mp(mp(l, p - 1), B));
	if(p + 1 <= r) s.insert(mp(mp(p + 1, r), C));
}

void solve() {
	cin >> n;
	init();
	rep(i, 1, n+1) {
		cin >> a[i];
		upd(rt[i-1], rt[i], a[i], 1, n);
	}

	st.clear();s.clear();
	ll res = calc(1, n);
	if(res) st.insert(res);
	s.insert(mp(mp(1, n), res));

	rep(i, 1, n+1) {
		cout << res << " \n"[i == n];
		ll x;
		cin >> x;
		x ^= res;
		gao(x);

		auto t = st.end();
		if(t != st.begin()) {
			--t;
			res = *t;
		} else {
			res = 0;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
