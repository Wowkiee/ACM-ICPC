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

int q, n = 1000000, top;
pii a[N];
pair<int, pii> tmp[22];

#define ls rt << 1
#define rs ls | 1
int mi[N << 2], cnt[N << 2], la[N << 2];
void gao(int rt, int c) {
	mi[rt] += c;
	la[rt] += c;
}
void down(int rt) {
	if(!la[rt]) return ;
	gao(ls, la[rt]);
	gao(rs, la[rt]);
	la[rt] = 0;
}
void up(int rt) {
	mi[rt] = min(mi[ls], mi[rs]);
	cnt[rt] = 0;
	if(mi[ls] == mi[rt]) cnt[rt] += cnt[ls];
	if(mi[rs] == mi[rt]) cnt[rt] += cnt[rs];
}
void build(int l, int r, int rt) {
	cnt[rt] = r - l + 1;
	if(l == r) return ;
	int mid = l + r >> 1;
	build(l, mid, ls);
	build(mid + 1, r, rs);
}
void upd(int L, int R, int c, int l, int r, int rt) {
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
int qry(int L, int R, int l, int r, int rt) {
	if(L > R) return 0;
	if(L <= l && r <= R) {
		if(mi[rt] == 0) return r - l + 1 - cnt[rt];
		return r - l + 1;
	}
	int mid = l + r >> 1, ans = 0;
	down(rt);
	if(L <= mid) ans += qry(L, R, l, mid, ls);
	if(R > mid) ans += qry(L, R, mid + 1, r, rs);
	up(rt);
	return ans;
}
void _qry(int L, int R, int l, int r, int rt) {
	if(rt == 1) top = 0;
	if(L > R) return ;
	if(L <= l && r <= R) {
		tmp[++top] = mp(rt, mp(l, r));
		return ;
	}
	int mid = l + r >> 1;
	down(rt);
	if(L <= mid) _qry(L, R, l, mid, ls);
	if(R > mid) _qry(L, R, mid + 1, r, rs);
	up(rt);
}
int get(int rt, int c) {
	if(mi[rt] > c) return 0;
	if(mi[rt] < c) return n + 1;
	return cnt[rt];
}
int gao(int rt, int l, int r, int c, int k) {
	while(l < r) {
		int cl = get(ls, c), cr = get(rs, c);
		int mid = l + r >> 1;
		if(cl >= k) {
			rt = ls;
			r = mid;
		} else {
			k -= cl;
			rt = rs;
			l = mid + 1;
		}
	}
	return l;
}
int Gao(int c, int k) {
	rep(i, 1, top + 1) {
		int rt = tmp[i].fi;
		int count = get(rt, c);
		if(count >= k) return gao(rt, tmp[i].se.fi, tmp[i].se.se, c, k);
		k -= count;
	}
	return n;
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
			_qry(t, n, 1, n, 1);
			int r = Gao(0, d);
			upd(t, r, 1, 1, n, 1);
		} else if(s[0] == '-') {
			d = a[t].se;
			t = a[t].fi;
			Upd(t, -d);
			_qry(t, n, 1, n, 1);
			int r = Gao(1, d);
			upd(t, r, -1, 1, n, 1);
		} else {
//			cout << Qry(t) << " ";
//			cout << qry(1, t - 1, 1, n, 1) << " ";
			cout << Qry(t) - qry(1, t - 1, 1, n, 1) << endl;
		}
		a[i] = mp(t, d);
	}
	return 0;
}
