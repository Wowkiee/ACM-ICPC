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
#define endl "\n"
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef vector<int> vi;
typedef double db;

const int N = 101010;
const ll inf = 1e18;

int n, m;
int val[N];
pair<pll, int> a[N];

struct Seg {
#define ls rt << 1
#define rs ls | 1
	static const int N = ::N << 2;
	pli ma[2][N];
	void up(int rt, int a, int b) {
		pli t[] = {ma[0][a], ma[1][a], ma[0][b], ma[1][b]};
		sort(t, t + 4);
		reverse(t, t + 4);
		ma[0][rt] = t[0];
		rep(i, 1, 4) if(t[i].se != t[0].se) {
			ma[1][rt] = t[i];
			break;
		}
	}
	void build(int l, int r, int rt) {
		if(l == r) {
			ma[0][rt] = mp(val[l], a[l].se);
			ma[1][rt] = mp(-inf, 0);
			return ;
		}
		int mid = l + r >> 1;
		build(l, mid, ls);
		build(mid + 1, r, rs);
		up(rt, ls, rs);
	}
	void upd(int p, pli c, int l, int r, int rt) {
		if(l == r) {
			ma[0][rt] = c;
			return ;
		}
		int mid = l + r >> 1;
		if(p <= mid) upd(p, c, l, mid, ls);
		else upd(p, c, mid + 1, r, rs);
		up(rt, ls, rs);
	}
	void qry(int L, int R, int l, int r, int rt) {
		if(L <= l && r <= R) {
			up(0, 0, rt);
			return ;
		}
		int mid = l + r >> 1;
		if(L <= mid) qry(L, R, l, mid, ls);
		if(R > mid) qry(L, R, mid + 1, r, rs);
	}
}seg[4];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T;
	cin >> T;
	int ca = 0;
	while(T--) {
		cout << "Case #" << ++ca << ":" << endl;
		cin >> n >> m;
		rep(i, 1, n + 1) cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
		rep(i, 1, n + 1) val[i] = a[i].fi.fi + a[i].fi.se;
		seg[0].build(1, n, 1);
		rep(i, 1, n + 1) val[i] = a[i].fi.fi - a[i].fi.se;
		seg[1].build(1, n, 1);
		rep(i, 1, n + 1) val[i] = -a[i].fi.fi + a[i].fi.se;
		seg[2].build(1, n, 1);
		rep(i, 1, n + 1) val[i] = -a[i].fi.fi - a[i].fi.se;
		seg[3].build(1, n, 1);
		while(m--) {
			int o;
			cin >> o;
			if(o == 1) {
				int k, x, y;
				cin >> k >> x >> y;
				a[k] = mp(mp(a[k].fi.fi + x, a[k].fi.se + y), a[k].se);
				seg[0].upd(k, mp(a[k].fi.fi + a[k].fi.se, a[k].se), 1, n, 1);
				seg[1].upd(k, mp(a[k].fi.fi - a[k].fi.se, a[k].se), 1, n, 1);
				seg[2].upd(k, mp(-a[k].fi.fi + a[k].fi.se, a[k].se), 1, n, 1);
				seg[3].upd(k, mp(-a[k].fi.fi - a[k].fi.se, a[k].se), 1, n, 1);
			} else if(o == 2) {
				int k, c;
				cin >> k >> c;
				a[k] = mp(a[k].fi, c);
				seg[0].upd(k, mp(a[k].fi.fi + a[k].fi.se, a[k].se), 1, n, 1);
				seg[1].upd(k, mp(a[k].fi.fi - a[k].fi.se, a[k].se), 1, n, 1);
				seg[2].upd(k, mp(-a[k].fi.fi + a[k].fi.se, a[k].se), 1, n, 1);
				seg[3].upd(k, mp(-a[k].fi.fi - a[k].fi.se, a[k].se), 1, n, 1);
			} else {
				int l, r;
				cin >> l >> r;
				rep(t, 0, 4) seg[t].ma[0][0] = seg[t].ma[1][0] = mp(-inf, 0), seg[t].qry(l, r, 1, n, 1);
				ll ans = 0;
				rep(t, 0, 2) {
					rep(a, 0, 2) rep(b, 0, 2) if(seg[t].ma[a][0].se != seg[3 - t].ma[b][0].se) {
						ans = max(ans, seg[t].ma[a][0].fi + seg[3 - t].ma[b][0].fi);
					}
				}
				cout << ans << endl;
			}
		}
	}
	return 0;
}
