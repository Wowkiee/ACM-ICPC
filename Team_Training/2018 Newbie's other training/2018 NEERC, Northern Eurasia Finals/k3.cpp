
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define pw(x) (1ll << (x))
#define all(x) x.begin(), x.end()
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1010101;

int q, n = 1000000;
pii a[N];

#define ls rt << 1
#define rs ls | 1
ll ma[N << 2], la[N << 2];
void gao(int rt, ll c) {
	ma[rt] += c;
	la[rt] += c;
}
void down(int rt) {
	if(!la[rt]) return ;
	gao(ls, la[rt]);
	gao(rs, la[rt]);
	la[rt] = 0;
}
void up(int rt) {
	ma[rt] = max(ma[ls], ma[rs]);
}
void build(int l, int r, int rt) {
	ma[rt] = r;
	if(l == r) return ;
	int mid = l + r >> 1;
	build(l, mid, ls);
	build(mid + 1, r, rs);
}
void upd(int L, int R, ll c, int l, int r, int rt) {
	if(L > R) return ;
	if(L <= l && r <= R) {
		gao(rt, c);
		return ;
	}
	int mid = l + r >> 1;
	down(rt);
	if(L <= mid) upd(L, R, c, l, mid, ls);
	if(R > mid) upd(L, R, c, mid + 1, r, rs);
	up(rt);
}
ll qry(int L, int R, int l, int r, int rt) {
	if(L > R) return -1e18;
	if(L <= l && r <= R) return ma[rt];
	int mid = l + r >> 1;
	down(rt);
	ll ans = -1e18;
	if(L <= mid) ans = max(ans, qry(L, R, l, mid, ls));
	if(R > mid) ans = max(ans, qry(L, R, mid + 1, r, rs));
	up(rt);
	return ans;
}

#define lb(x) ((x) & -(x))
ll tot[N];
void Upd(int p, int c) {
	for( ; p <= n; p += lb(p)) tot[p] += c;
}
ll Qry(int p) {
	ll res = 0;
	for( ; p >= 1; p ^= lb(p)) res += tot[p];
	return res;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> q;
	build(1, n, 1);
	rep(i, 1, q + 1) {
		char s[11];
		int t, d;
		cin >> s >> t;
		if(s[0] == '+') {
			cin >> d;
			Upd(t, d);
			upd(t + 1, n, -d, 1, n, 1);
		} else if(s[0] == '-') {
			d = a[t].se;
			t = a[t].fi;
			Upd(t, -d);
			upd(t + 1, n, d, 1, n, 1);
		} else {
			ll ans = Qry(t) - t + qry(1, t, 1, n, 1);
			cout << ans << endl;
		}
		a[i] = mp(t, d);
	}
	return 0;
}
