#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N =1e5+7;
int tim, son[N], fa[N], dep[N], siz[N], n, p1, p, pos[N], u, v, w, op, T, q, tid[N], top[N];
bool vis[N], use[N];
ll ans, tmp;
vector<pii> g[N];


struct edge{
	int u, v, w;	
} edge[N];

template<class T>
struct Fenwick{
    static const int N =2e5+7;
    int n;T a1[N],a2[N];
    void ini(int _n){ 
		fill_n(a1+1,n=_n,0);fill_n(a2+1,n=_n,0);
	}
	void add(T *a,int p,T d) { for(; p<=n; p+=p & -p) a[p]+=d; }
	void add(int l,int r,T d) {
		add(a1, l, d), add(a1, r + 1, -d);
		add(a2, l, d * (l - 1)), add(a2, r + 1, -d * r);
	} 
	T sum(T *a,int p) { T r=0; for(; p>=1; p-=p & -p) r+=a[p]; return r; }
	T pre(int p) { return !p ? 0 : sum(a1, p) * p - sum(a2, p);}
	T qry(int l,int r) {return pre(r)-pre(l-1); }
};

Fenwick<ll> fen;

void init() {
	memset(son,-1,sizeof(son));
	memset(vis,0,sizeof(vis));
	memset(use,0,sizeof(use));
	tim=0;
	fen.ini(n+1);
}

void dfs1(int u,int pre,int d) {
    dep[u]=d;
    vis[u]=1;
    fa[u]=pre;
    siz[u]=1;
    rep(i, 0 ,sz(g[u])){
        int v=g[u][i].fi;
        if(!vis[v]){
						use[g[u][i].se] = 1;
						pos[v] = g[u][i].se;
            dfs1(v,u,d+1);
            siz[u]+=siz[v];
            if(son[u]==-1||siz[v]>siz[son[u]])
                son[u]=v;
        }
    }
}

void dfs2(int u,int tp) {
    top[u]=tp;
    tid[u]=++tim;
    if(son[u]==-1) return;
    dfs2(son[u],tp);
    rep(i, 0, sz(g[u])) {
        int v=g[u][i].fi;
        if (pos[v] != g[u][i].se) continue;
        if(v!=son[u]&&v!=fa[u])
            dfs2(v,v);
    }
}

ll ask(int u, int v) {
	if (u == v) return 0;
	ll res = 0;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		res += fen.qry(tid[top[u]],tid[u]);
		u = fa[top[u]];
	}
	if (dep[u] < dep[v]) swap(u, v);
	if (u != v) {
		res += fen.qry(tid[v]+1,tid[u]);
	}
	return res;
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0,  T) {
		cin >> n >> q;
		rep(i,1,n+1)g[i].clear();
		rep(i, 1, n+1) {
			cin >> u >> v >> w;
			g[u].pb(mp(v,i));
			g[v].pb(mp(u,i));
			edge[i] = {u, v, w};
		}
		//rep(i, 1, n+1) dd(edge[i].u),dd(edge[i].v),de(edge[i].w);
		init();
		dfs1(1,0,1);
		dfs2(1,1);
		rep(i, 1, n+1) if (!use[i]) p1 = i;
	//	rep(i, 1, n+1) dd(pos[i]);
		rep(i, 2, n+1) fen.add(tid[i],tid[i],edge[pos[i]].w);
		//return 0;
		rep(i, 1, q+1) {
			cin >> op;
			if (op == 0) {
				cin >> p >> w;
				if (p == p1) edge[p].w = w;
				else {
					u = edge[p].u; v = edge[p].v;
					if (dep[u]< dep[v]) swap(u, v);
					tmp = fen.qry(tid[u],tid[u]);
					fen.add(tid[u],tid[u], -tmp + w);
				}
			}else {
				cin >> u >> v;
				ans = ask(u, v);
				ans = min(ans, ask(u, edge[p1].u) + edge[p1].w + ask(v, edge[p1].v));
				ans = min(ans, ask(u, edge[p1].v) + edge[p1].w + ask(v, edge[p1].u));
				cout << ans << endl;
			}
		}
	}
	return 0;
}
