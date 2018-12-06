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

int n, m;
int cnt[N << 1], val[N];
bool vis[N], ok[N];
vi g[N], ng[N], col[N];
unordered_map<int, int> pos[N];

vi dcc[N];//, key[N];
int dfn[N], low[N], st[N], _st, _;
void dfs(int c, int dep) {
	int cc = 0;//, out = 1 < dep; 
	st[_st++] = c;
	dfn[c] = low[c] = dep;
	rep(i, 0, sz(g[c])) {
		int t = g[c][i];
		if(!dfn[t]) {
			dfs(t, dep + 1);
			low[c] = min(low[c], low[t]);
			if(low[t] >= dfn[c]) {
//				if(++out == 2) key.pb(c);
				while(st[--_st] != t) dcc[st[_st]].pb(_);
				dcc[c].pb(_);dcc[t].pb(_++);
			} 
		} else if(dfn[t] != dfn[c] - 1 || cc++) {
			low[c] = min(low[c], dfn[t]);
		}
	}
}
void solve() {
	rep(i, 0, n) if(!dfn[i]) dfs(i, 1);
	rep(i, 0, n) if(sz(dcc[i]) == 0) dcc[i].pb(_++);
	rep(i, 0, n) {
		rep(j, 0, sz(dcc[i])) pos[i][dcc[i][j]] = j;
	}
}
int find(int u, int dc) {
	if(pos[u].count(dc)) {
		return pos[u][dc];
	} else {
		return -1;
	}
	int p = lower_bound(all(dcc[u]), dc) - dcc[u].begin();
	if(p < sz(dcc[u]) && dcc[u][p] == dc) {
		return p;
	} else {
		return -1;
	}
}

void dfs(int u) {
	vis[u] = 1;
	rep(t, 0, sz(g[u])) {
		int v = g[u][t];
		rep(i, 0, sz(dcc[v])) {
			int c = find(u, dcc[v][i]);
			if(c == -1) {
				if(vis[v] == 0) col[v][i] = dcc[v][i] << 1;
			} else {
				if(vis[v]) {
					if(col[v][i] == col[u][c]) ok[dcc[v][i]] = 0;
				} else {
					col[v][i] = (col[u][c] ^ 1);
				}
			}
		}
		if(!vis[v]) dfs(v);
	}
}
bool check(int u, int v) {
	rep(i, 0, sz(dcc[u])) {
		int c = find(v, dcc[u][i]);
		if(c != -1 && !ok[dcc[v][c]]) return 0;
	}
	return 1;
}

void dfs2(int u, int c) {
	++cnt[c];
	val[u] = c;
	vis[u] = 1;
	rep(i, 0, sz(ng[u])) {
		int v = ng[u][i];
		if(vis[v]) continue;
		dfs2(v, c ^ 1);
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 1, m + 1) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}
	solve();
	fill_n(ok, _, 1);
	rep(i, 0, n) col[i] = vi(sz(dcc[i]));
	rep(i, 0, sz(dcc[0])) col[0][i] = dcc[0][i] << 1;
	dfs(0);
	rep(u, 0, n) {
		rep(i, 0, sz(g[u])) {
			int v = g[u][i];
			if(check(u, v)) ng[u].pb(v);
		}
	}
	fill_n(vis, n, 0);
	rep(i, 0, n) if(!vis[i]) dfs2(i, i << 1);
	ll r1 = 0, r2 = 0;
	rep(i, 0, n) {
		r1 += cnt[val[i]] - 1;
		r2 += cnt[val[i] ^ 1];
	}
	assert(r1 % 2 == 0);
	assert(r2 % 2 == 0);
	cout << r1 / 2 << " " << r2 / 2 << endl;
	return 0;
}
