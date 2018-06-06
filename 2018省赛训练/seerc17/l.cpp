#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define per(i,l,r) for(int i=(r)-1;i>=(l);i--)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----

const int N=101010;

int n, cw, cb, nb;
int cnt[N], pre[N], bla[N], col[N];
vi g[2][N];

int top[N], par[N], fa[N];
struct HeavyChain {
	static const int N = ::N, inf = ~0U>>1;
	int sz[N], wson[N], dep[N], id[N], _, who[N];
	void dfs(int c, int fa, vi g[]) {
		sz[c] = 1; dep[c] = dep[par[c] = fa] + 1;
		int &s = wson[c] = top[c] = 0;
		for (auto t : g[c]) if (t != fa) {
			dfs(t, c, g), sz[c] += sz[t], (sz[t] >= sz[s]) && (s == t);
		}
	}
	void dfs2(int c, int fa, vi g[]) {
		who[id[c]=++_] = c;
		int s = wson[c];
		if (!top[c]) top[c] = c;
		if (s) top[s] = top[c], dfs2(s, c, g);
		for (auto t : g[c]) if (t != fa && t != s) dfs2(t, c, g);
	}
	void bud(vi g[]) {
		dfs(1, 0, g);
		_ = 0;
		dfs2(1, 0, g);
	}
}hc;

int find(int x) {
	if(x==pre[x]) return x;
	return pre[x]=find(pre[x]);
}
void join(int x,int y) {
	int fx=find(x);
	int fy=find(y);
	pre[fx]=fy;
}

void add(int u, int c) {
	col[u]=1;
	bla[nb++]=u;
	++cb;
	int cc=0;
	for(auto v : g[c^1][u]) {
		if(col[v]==1) {
			join(u, v);
			--cb;
			++cc;
		}
	}
	if(cc=sz(g[c^1][u])) --cw;
	for(auto v : g[c^1][u]) if(fa[v]==u) {
		if(col[v]==0) ++cw;
	}
	if(u==1||col[fa[u]]==1) --cw;
}

void dfs(int u,int c) {
	add(u, c);
	for(auto v : g[c][u]) if(v!=par[u]) dfs(v, c);
}

void work(int u,int s,int c) {
	add(u, c);
	for(auto v : g[c][u]) {
		if(v!=par[u]&&v!=s) dfs(v, c);
	}
	cnt[cw+cb]++;
	if(top[u]!=u) work(par[u], u, c);
}

void dfs2(int u,int f,int c) {
	fa[u]=f;
	for(auto v : g[c][u]) if(v!=f) {
		dfs2(v, u, c);
	}
}

void solve(int c) {
	dfs2(1, 0, c^1);
	hc.bud(g[c]);
	cb=0;cw=1;
	rep(i,1,n+1) pre[i]=i;
	rep(i,2,n+1) if(sz(g[c][i])==1) {
		work(i, 0, c);
		rep(j,0,nb) pre[bla[j]]=bla[j], col[bla[j]]=0;
		nb=0;
	}
}

int main() {
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	scanf("%d",&n);
	rep(i,0,2) rep(j,1,n) {
		int u,v;scanf("%d%d",&u,&v);
		g[i][u].pb(v);
		g[i][v].pb(u);
	}
	solve(0);solve(1);
	if(cnt[2]) {
		printf("2 %d\n",cnt[2]/2);
	} else {
		printf("3 %d\n",cnt[3]);
	}
	return 0;
}
