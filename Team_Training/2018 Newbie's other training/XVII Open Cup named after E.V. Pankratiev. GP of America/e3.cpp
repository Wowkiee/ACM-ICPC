#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double db;

const int N = 202020, inf = N;

int n, m, k, w[N];
int pre[N];
bool spe[N];
vi ve;
vector<pair<pii, pii> > e[2];

int find(int x) {
	return x == pre[x] ? x : pre[x] = find(pre[x]);
}
void join(int x, int y) {
	x = find(x), y = find(y);
	pre[x] = y;
}

int solve(db x, bool o) {
	int cnt = k, t = 0;
	rep(i, 1, n + 1) pre[i] = i;
	for(int i = 0, j = 0; (i < sz(e[0]) || j < sz(e[1])) && t < n - 1; ) {
		int u, v;
		if((i == sz(e[0]) || (j < sz(e[1]) && e[0][i].fi.fi >= e[1][j].fi.fi + x)) && (o == 0 || cnt > 0)) {
			u = e[1][j].se.fi, v = e[1][j].se.se;
			++j;
		} else {
			u = e[0][i].se.fi, v = e[0][i].se.se;
			++i;
		}
		int fu = find(u), fv = find(v);
		if(fu == fv) continue;
		if(u == 1) --cnt;
		if(o) {
			if(u == 1) ve.pb(e[1][j - 1].fi.se);
			else ve.pb(e[0][i - 1].fi.se);
		}
		pre[fu] = fv;
		++t;
	}
	if(t != n - 1) {
		cout << -1 << endl;
		exit(0);
	}
	return cnt;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int tt;
	cin >> n >> m >> tt >> k;
	rep(i, 0, tt) {
		int x;
		cin >> x;
		spe[x] = 1;
	}
	rep(i, 0, m) {
		int u, v;
		cin >> u >> v >> w[i + 1];
		if(spe[v]) swap(u, v);
		e[spe[u] && !spe[v]].pb(mp(mp(w[i + 1], i + 1), mp(u, v)));
	}
	sort(all(e[0]));
	sort(all(e[1]));
	if(sz(e[1]) < k) {
		cout << -1 << endl;
		return 0;
	}
	db l = -inf, r = inf;
	rep(t, 0, 100) {
		db mid = (l + r) / 2;
		if(solve(mid, 0) <= 0) {
			l = mid;
		} else {
			r = mid;
		}
	}
	solve(l, 1);
	ll ans = 0;
	rep(i, 0, sz(ve)) ans += w[ve[i]];
	cout << ans << endl;
	return 0;
}
