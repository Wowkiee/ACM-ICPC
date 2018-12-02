#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(x) (int)x.size()
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 101010;

struct R {
	char o;
	int a, b, c;
	R() {}
	R(char _o, int _a, int _b) {
		o = _o, a = _a, b = _b;
	}
	R(char _o, int _a, int _b, int _c) {
		o = _o, a = _a, b = _b, c = _c;
	}
};

int n, m, cnte, cntv;
int dep[N], fa[N], pre[N];
bool vis[N], visv[N];
pii e[N];
vi G[N];
vector<pii> g[N];
vector<R> res;

int find(int x) {
	return x == pre[x] ? x : (pre[x] = find(pre[x]));
}
void join(int x, int y) {
	x = find(x), y = find(y);
	pre[x] = y;
}

void dfs(int u) {
	visv[u] = 1;
	for(auto v : g[u]) if(!visv[v.fi]) {
		vis[v.se] = 1;
		dep[v.fi] = dep[u] + 1;
		fa[v.fi] = u;
		dfs(v.fi);
	}
}

void solve(int u) {
	vis[u] = 1;
	for(auto v : G[u]) if(!vis[v]) {
		if(v <= n) {
			solve(v);
			res.pb(R('r', v, 1, 3));
			res.pb(R('j', u, v));
			res.pb(R('c', u, 1, 3));
			res.pb(R('r', u, 3, 2));
		} else {
			vis[v] = 1;
			int ind = 0;
			rep(i, 0, sz(G[v])) {
				int c = G[v][i];
				if(vis[c]) {
					ind = i;
				} else {
					solve(c);
				}
			}
			int c = u;
			rep(i, ind + 1, sz(G[v])) {
				int t = G[v][i];
				res.pb(R('r', c, 1, 3));
				res.pb(R('j', c, t));
				res.pb(R('c', c, 1, 3));
				res.pb(R('r', c, 3, 2 + 2 * (c == u)));
				c = t;
			}
			rep(i, 0, ind) {
				int t = G[v][i];
				res.pb(R('r', c, 1, 3));
				res.pb(R('j', c, t));
				res.pb(R('c', c, 1, 3));
				res.pb(R('r', c, 3, 2 + 2 * (c == u)));
				c = t;
			}
			res.pb(R('c', c, 1, 4));
			res.pb(R('r', c, 1, 2));
			res.pb(R('r', c, 4, 1));
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	freopen("cactus.in", "r", stdin);
	freopen("cactus.out", "w", stdout);
	cin >> n >> m;
	rep(i, 0, m) {
		int k;
		cin >> k;
		int u = 0, v;
		while(k--) {
			cin >> v;
			if(u) e[++cnte] = mp(u, v);
			u = v;
		}
	}
	rep(i, 1, cnte + 1) if(e[i].fi > e[i].se) swap(e[i].fi, e[i].se);
	sort(e + 1, e + 1 + cnte);
	cnte = unique(e + 1, e + 1 + cnte) - e - 1;
	rep(i, 1, cnte + 1) {
		int u = e[i].fi, v = e[i].se;
		g[u].pb(mp(v, i));
		g[v].pb(mp(u, i));
	}
	dfs(1);
	cntv = n;
	rep(i, 1, n + 1) pre[i] = i;
	rep(i, 1, cnte + 1) if(!vis[i]) {
		int u = e[i].fi, v = e[i].se;
		if(dep[u] > dep[v]) swap(u, v);
		++cntv;
		while(v != u) {
			G[v].pb(cntv);
			G[cntv].pb(v);
			join(v, fa[v]);
			v = fa[v];
		}
		G[v].pb(cntv);
		G[cntv].pb(v);
	}
	rep(i, 1, cnte + 1) if(find(e[i].fi) != find(e[i].se)) {
		int u = e[i].fi, v = e[i].se;
		G[u].pb(v), G[v].pb(u);
	}
	memset(vis, 0, sizeof(vis));
	solve(1);
	cout << sz(res) << endl;
	for(auto u : res) {
		cout << u.o << " " << u.a << " " << u.b;
		if(u.o != 'j') cout << " " << u.c << endl;
		else cout << endl;
	}
	return 0;
}
