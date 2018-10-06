
#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 505;
int n, m, p, use[N], must[N], op[N], s, t, x;
vi g[N], V0[2], V[N], ans;
int vis[N];
string S[N];

void dfs(int u, int d) {
	vis[u] = 1;
	for (auto v : g[u]) if (!vis[v]) {
		dfs(v, d ^ 1);
	}
  V0[d].pb(u);
}

template <class T> 
struct Dinic{
	const static int N = 10101, M = N * 10;
	int s, t , n, h[N], cur[N], level[N], q[N], e, ne[M], to[M];
	T cap[M], flow;
	void liu(int u, int v, T w) {to[e] = v;ne[e] = h[u];cap[e] = w;h[u] = e++;}
	void link(int u, int v, T w) {liu(u, v, w); liu(v, u, 0);}
	void ini(int _n = N) {fill(h, h + (n = _n), -1); e = 0;}
	bool bfs(){
		int L = 0, R = 0;
		fill(level, level + n, - 1);
		level[q[R++] = s] = 0;
		while (L < R && level[t] == -1) {
			int c = q[L++];
			for (int k = h[c];~k;k = ne[k]) 
				if (cap[k] > 0 && level[to[k]] == -1)
						level[q[R++] = to[k]] = level[c] + 1;
		}
		return ~level[t];
	}
	T dfs(int c, T mx) {
		if (c == t) return mx;
		T ret = 0;
		for (int &k = cur[c];~k;k = ne[k]) {
			if (level[to[k]] == level[c] + 1 && cap[k] > 0) {
				T flow = dfs(to[k], min(mx, cap[k]));
				ret += flow;cap[k] -= flow, cap[k^1] += flow; mx -= flow;
				if (!mx) return ret;
			}
		}
		level[c] = -1;
		return ret;
	}
	T run (int _s, int _t){
		s = _s; t = _t;
		flow = 0;
		while (bfs()) {
			copy(h, h+n, cur);
			flow += dfs(s, ~0U >> 1);
		}
		return flow;
	} 
};

Dinic<int> G;

void dfs2(int u, int ok) {
	vis[u] = ok;
	if (ok == 0){
		for (auto v : g[u]) if (vis[v] == -1) {
			dfs2(v, ok ^ 1);
		}
	}else {
		int v = op[u];
		if (vis[v] == -1) dfs2(v, ok^1);
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 1, m+1) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	G.ini(n + 5);
	m = 0;
	rep(i, 1, n+1) if (!vis[i]) dfs(i, 0);
	s = n + 1; t = n + 2;
	for (auto u : V0[0]) {
		for (auto v : g[u])
			G.link(u, v, 1);
	}
	for (auto u : V0[0]) G.link(s, u, 1);
	for (auto u : V0[1]) G.link(u, t, 1);
	int flow = G.run(s, t);
	if (flow == 0) {
		cout << 1 << endl << 1;
	}else {
		p = 0;
		for (auto u : V0[0])
			for (auto v : g[u]) {
				if (G.cap[p] == 0) use[u] = 1, op[u] = v, use[v] = 1, op[v] = u;
				p += 2;
			}
		//rep(i, 1, n+1) de(use[i]);
		memset(vis, -1, sizeof(vis));
		rep(i, 1, n+1) if (vis[i] == -1 && !use[i]) dfs2(i, 0);
		//rep(i, 1, n+1) if (vis[i] == -1 && use[i]) dfs2(i, 0);
		for (auto u : V0[0]) {
			if (use[u] == 1) {
				if (vis[u] == 1 || vis[op[u]] != 1) ans.pb(u);else ans.pb(op[u]);
			}
		}
		cout << sz(ans) << endl;
		rep(i, 0, sz(ans)) cout << ans[i] << (i == sz(ans) - 1 ? "\n" : " ");
	}
	return 0;
}
