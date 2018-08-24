#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}

const int N = 202020;

int n, m, q;
int dfn[N], low[N], id[N], st[N], _st, _;
int pre[N][22], cnt[N][2], dep[N];
bool vis[N];
vi g[N], ng[N];

void dfs2(int u, int fa) {
	vis[u] = 1;
	pre[u][0] = fa;
	rep(i, 1, 22) pre[u][i] = pre[pre[u][i-1]][i-1];
	dep[u] = dep[fa] + 1;
	for(auto v : ng[u]) if(!vis[v] && v != fa) dfs2(v, u);
}

void dfs(int c, int dep) {
	int cc = 0; st[_st++] = c;
	dfn[c] = low[c] = dep;
	for(auto t : g[c]) {
		if(!dfn[t]) {
			dfs(t, dep+1);
			low[c] = min(low[c], low[t]);
		} else if(dfn[t] != dfn[c] - 1 || cc++) {
			low[c] = min(low[c], dfn[t]);
		}
	}
	if(low[c] == dfn[c]) {
		do{id[st[--_st]] = _;}while(st[_st]!=c);
		_++;
	}
}

int lca(int u, int v) {
	if(dep[u] > dep[v]) swap(u, v);
	if(dep[u] != dep[v]) for(int i = 21; ~i; --i) if(dep[u] <= dep[pre[v][i]]) v = pre[v][i];
	if(u == v) return u;
	for(int i = 21; ~i; --i) if(pre[u][i] != pre[v][i]) u = pre[u][i], v = pre[v][i];
	return pre[u][0];
}

void dfs3(int u, int fa) {
	vis[u] = 1;
	for(auto v : ng[u]) if(!vis[v] && v != fa) {
		dfs3(v, u);
		rep(i, 0, 2) cnt[u][i] += cnt[v][i];
	}
}

bool solve() {
	rep(i, 0, q) {
		int u, v;
		cin >> u >> v;
		u = id[u-1], v = id[v-1];
		if(pre[u][21] != pre[v][21]) return 0;
		int x = lca(u, v);
		++cnt[u][0];
		--cnt[x][0];
		++cnt[v][1];
		--cnt[x][1];
	}
	memset(vis, 0, sizeof(vis));
	rep(i, 0, _) if(!vis[i]) dfs3(i, i);
	rep(i, 0, _) if(cnt[i][0] && cnt[i][1]) return 0;
	return 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> m >> q;
	rep(i, 0, m) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}
	rep(i, 0, n) if(!dfn[i]) dfs(i, 1);
	rep(i, 0, n) for(auto j : g[i]) if(id[i] != id[j]) ng[id[i]].pb(id[j]);
	rep(i, 0, _) if(!vis[i]) dfs2(i, i);
	cout << (solve()?"Yes":"No") << endl;
	return 0;
}
