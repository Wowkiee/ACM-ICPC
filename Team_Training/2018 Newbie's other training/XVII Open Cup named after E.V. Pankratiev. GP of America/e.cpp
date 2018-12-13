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
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 202020;
const db eps = 1e-8;

int n, m, k, w;
int pre[N];
bool spe[N];
vector<pair<int, pii> > e, g;

int init() {
	rep(i, 1, n + 1) pre[i] = i;
}
int find(int x) {
	return x == pre[x] ? x : pre[x] = find(pre[x]);
}
void join(int x, int y) {
	x = find(x);
	y = find(y);
	pre[x] = y;
}

void gao(db x, int &t, ll &tot) {
	init();
	t = tot = 0;
	int p = 0;
	rep(i, 0, sz(e)) {
		while(p < sz(g) && g[p].fi + x <= e[i].fi) {
			int u = g[p].se.fi, v = g[p].se.se;
			if(find(u) != find(v)) {
				join(u, v);
				++t;
				tot += g[p].fi;
			}
			++p;
		}
		int u = e[i].se.fi, v = e[i].se.se;
		if(find(u) != find(v)) {
			join(u, v);
			tot += e[i].fi;
		}
	}
	while(p < sz(g)) {
		int u = g[p].se.fi, v = g[p].se.se;
		if(find(u) != find(v)) {
			join(u, v);
			++t;
			tot += g[p].fi;
		}
		++p;
	}
}

ll solve() {
	if(sz(g) < w) return -1;
	rep(i, 1, n + 1) if(find(i) != find(1)) return -1;
	int st, ed;
	ll _;
	gao(-N, ed, _);
	gao(N, st, _);
	if(st > w || ed < w) return -1;
	db l = -N, r = N;
	rep(i, 0, 50) {
		db mid = (l + r) / 2;
		int t;
		ll tot;
		gao(mid, t, tot);
		if(t >= w) {
			l = mid;
		} else {
			r = mid;
		}
	}
	int t;
	ll tot;
	gao(l, t, tot);

	if(t < w) return -1;
	return tot;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m >> k >> w;
	rep(i, 1, k + 1) {
		int x;
		cin >> x;
		spe[x] = 1;
	}
	init();
	rep(i, 1, m + 1) {
		int u, v, w;
		cin >> u >> v >> w;
		join(u, v);
		if(spe[v]) swap(u, v);
		if(spe[u] && !spe[v]) {
			g.pb(mp(w, mp(u, v)));
		} else {
			e.pb(mp(w, mp(u, v)));
		}
	}
	sort(all(g));
	sort(all(e));
	cout << solve() << endl;
	return 0;
}
