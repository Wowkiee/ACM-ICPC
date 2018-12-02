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
#define pw(a) (1ll<<(a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 101010;

int n, m, top, tot;
int sta[N], pre[N], sz[N], pp[N], in[N], id[N], nn[N];
bool vis[N], ban[N], can[N];
vi g[N], v[N], ng[N];
pii e[N];

int find(int x) {
	return (x == pre[x]) ? x : (pre[x] = find(pre[x]));
}

void dfs(int u) {
	sta[++top] = u;
	vis[u] = 1;
	tot += sz[u];
	if(tot - sz[u] == n) {
		vi ans;
		rep(i, 1, top) for(auto u : v[sta[i]]) ans.pb(u + 1);
		int p = 0;
		rep(i, 0, sz(ans)) if(ans[i] == 1) p = i;
		rep(i, p, sz(ans)) cout << ans[i] << " ";
		rep(i, 0, p) cout << ans[i] << " ";
		cout << 1 << endl;
		exit(0);
	}
	for(auto v : ng[u]) {
		if(v == find(0)) {
			if(tot == n) dfs(v);
		} else {
			if(!vis[v]) dfs(v);
		}
	}
	vis[u] = 0;
	--top;
	tot -= sz[u];
}

namespace SCC {
	const int N = ::N;
	int dfn[N], low[N], id[N], st[N], _st, _, cc;
	void dfs(int c, vi g[]) {
		dfn[c] = low[c] = ++cc;
		st[_st++] = c;
		for(auto t : g[c]) {
			if(!dfn[t]) {
				dfs(t, g), low[c] = min(low[c], low[t]);
			} else if(!id[t]) {
				low[c] = min(low[c], dfn[t]);
			}
		}
		if(low[c] == dfn[c]) {
			++_;
			do{id[st[--_st]]=_;}while(st[_st]!=c);
		}
	}
	int solve(int n, vi g[]) {
		rep(i, 0, n) if(!dfn[i]) dfs(i, g);
		return _;
	}
}

int main() {
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 1, m + 1) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		++in[v];
		pp[v] = u;
		id[v] = i;
		e[i] = mp(u, v);
	}
	if(SCC::solve(n, g) > 1) {
		cout << "There is no route, Karl!" << endl;
		return 0;
	}
	rep(i, 0, n) can[i] = (in[i] == 1) && (sz(g[i]) == 1);
	rep(i, 0, n) pre[i] = i, sz[i] = 1;
	rep(i, 0, n) if(can[i] && can[pp[i]] && find(i) != find(pp[i])) {
	//	dd(i), de(pp[i]);
		int x = find(i), y = find(pp[i]);
		nn[pp[i]] = i;
		ban[id[i]] = 1;
		pre[x] = y;
		sz[y] += sz[x];
	}
	rep(i, 1, m + 1) if(!ban[i]) {
		int u = e[i].fi, v = e[i].se;
		ng[find(u)].pb(find(v));
	}
	rep(i, 0, n) if(i == find(i)) {
		int t = i;
		while(sz(v[i]) < sz[i]) {
			v[i].pb(t);
			t = nn[t];
		}
	}
	/*
	rep(i, 0, n) if(i == find(i)) {
		de(i);
		for(auto u : v[i]) cout << u << " ";
		cout << endl;
	}
	*/
	dfs(find(0));
	cout << "There is no route, Karl!" << endl;
	return 0;
}
