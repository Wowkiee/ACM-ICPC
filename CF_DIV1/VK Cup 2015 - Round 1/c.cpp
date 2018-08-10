#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 101010;

int n, m, k, q;
bool ans[N<<1];
pii rook[N<<1];
pair<pii, pii> rect[N<<1];
vector<pii> v[N];

struct Seg {
#define ls rt<<1
#define rs ls|1
	static const int N = ::N << 2;
	int mi[N];
	void build(int l, int r, int rt) {
		mi[rt] = 0;
		if(l == r) return ;
		int mid = l + r >> 1;
		build(l, mid, ls);
		build(mid+1, r, rs);
	}
	void upd(int p, int c, int l, int r, int rt) {
		if(l == r) {
			mi[rt] = c;
			return ;
		}
		int mid = l + r >> 1;
		if(p <= mid) upd(p, c, l, mid, ls);
		else upd(p, c, mid+1, r, rs);
		mi[rt] = min(mi[ls], mi[rs]);
	}
	int qry(int L, int R, int l, int r, int rt) {
		if(L <= l && r <= R) return mi[rt];
		int mid = l + r >> 1, res = m+1;
		if(L <= mid) res = min(res, qry(L, R, l, mid, ls));
		if(R >= mid+1) res = min(res, qry(L, R, mid+1, r, rs));
		return res;
	}
}seg;

void solve() {
	rep(i, 0, N) v[i].clear();
	rep(i, 1, k+1) v[rook[i].se].pb(mp(0, i));
	rep(i, 1, q+1) v[rect[i].se.se].pb(mp(1, i));
	seg.build(1, n, 1);
	rep(_, 1, m+1) {
		for(auto u : v[_]) {
			int i = u.se;
			if(u.fi) {
				int mi = seg.qry(rect[i].fi.fi, rect[i].se.fi, 1, n, 1);
				if(mi >= rect[i].fi.se) ans[i] = 1;
			} else {
				seg.upd(rook[i].fi, _, 1, n, 1);
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> m >> k >> q;
	rep(i, 1, k+1) {
		int x, y;
		cin >> x >> y;
		rook[i] = mp(x, y);
	}
	rep(i, 1, q+1) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		rect[i] = mp(mp(a, b), mp(c, d));
	}
	solve();
	swap(n, m);
	rep(i, 1, k+1) swap(rook[i].fi, rook[i].se);
	rep(i, 1, q+1) {
		swap(rect[i].fi.fi, rect[i].fi.se);
		swap(rect[i].se.fi, rect[i].se.se);
	}
	solve();
	rep(i, 1, q+1) cout << (ans[i] ? "YES" : "NO") << endl;
	return 0;
}
