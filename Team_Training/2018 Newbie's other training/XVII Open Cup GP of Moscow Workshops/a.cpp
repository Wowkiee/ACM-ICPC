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

const int N = 1010;

int n, tot, mi, rt;
int sz[N];
bool ans;
bool vis[N];
vi g[N];

void dfs(int u, int fa) {
	++tot;
	rep(i, 0, sz(g[u])) {
		int v = g[u][i];
		if(!vis[v] && v != fa) dfs(v, u);
	}
}
void dfs2(int u, int fa) {
	sz[u] = 1;
	int ma = 0;
	rep(i, 0, sz(g[u])) {
		int v = g[u][i];
		if(vis[v] || v == fa) continue;
		dfs2(v, u);
		sz[u] += sz[v];
		ma = max(ma, sz[v]);
	}
	ma = max(ma, tot - sz[u]);
	if(ma < mi) {
		mi = ma;
		rt = u;
	} else if(ma == mi && u < rt) {
		rt = u;
	}
}

int dfs(int u) {
	if(!ans) return 0;
	tot = 0, dfs(u, 0);
	mi = n + 1, dfs2(u, 0);
	int c = rt;
	vis[c] = 1;
	rep(i, 0, sz(g[c])) if(!vis[g[c][i]]) {
		int t = g[c][i];
		if(t != dfs(t)) {
			ans = 0;
			return 0;
		}
	}
	return c;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T;
	cin >> T >> n;
	while(T--) {
		rep(i, 1, n + 1) g[i].clear(), vis[i] = 0;
		ans = 1;
		rep(i, 1, n) {
			int u, v;
			cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs(1);
		cout << (ans ? "Centroid" : "Random") << endl;
	}
	return 0;
}
