#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(c) cout << #c << " = " << c << endl
#define dd(c) cout << #c << " = " << c << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 101010;

int n, m, m0;
int deg[N];
bool vis[N << 1];
vi res;
vector<vi> ans;
vector<pii> g[N];

void dfs(int u) {
	for(auto v : g[u]) if(!vis[abs(v.se)]) {
		vis[abs(v.se)] = 1;
		--deg[u], --deg[v.fi];
		dfs(v.fi);
		res.pb(-v.se);
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	while(cin >> n >> m) {
		///init
		fill_n(deg + 1, n, 0);
		fill_n(g + 1, n, vector<pii>());
		fill_n(vis + 1, m << 1, 0);
		res.clear(), ans.clear();
		///read
		rep(i, 1, m + 1) {
			int u, v;
			cin >> u >> v;
			g[u].pb(mp(v, i));
			g[v].pb(mp(u, -i));
			++deg[u], ++deg[v];
		}
		///solve
		m0 = m;
		int u = 0;
		rep(v, 1, n + 1) if(deg[v] & 1) {
			if(u == 0) {
				u = v;
			} else {
				++m0;
				g[u].pb(mp(v, -m0));
				g[v].pb(mp(u, -m0));
				++deg[u], ++deg[v];
				u = 0;
			}
		}
		rep(i, 1, n + 1) if(deg[i]) {
			dfs(i);
			int st = -1;
			rep(i, 0, sz(res)) if(res[i] > m) {
				st = i;
				break;
			}
			if(~st) {
				st = (st + 1) % sz(res);
				vi v;
				rep(i, 0, sz(res)) {
					int u = res[(i + st) % sz(res)];
					if(u > m) {
						ans.pb(v);
						v.clear();
					} else {
						v.pb(u);
					}
				}
			} else {
				ans.pb(res);
			}
			res.clear();
		}
		///print
		cout << sz(ans) << endl;
		for(auto v : ans) {
			cout << sz(v);
			for(auto u : v) cout << " " << u;
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
