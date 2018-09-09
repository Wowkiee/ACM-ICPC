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
//---

const int N = 500 * 500 + 7;

int n, m;
int pre[N];
vector<pair<int, pii> > e;
vi g[N];
int Fa[20][N],Dep[N];
void add(int u, int v, int w) {
	e.pb(mp(-w, mp(u, v)));
}

int find(int x) {
	if(x == pre[x]) return x;
	return pre[x] = find(pre[x]);
}
void join(int x, int y) {
	pre[find(x)] = find(y);
}

void dfs(int a,int fa,int dep) {
	Fa[0][a]=fa;Dep[a]=dep;
	rep(i,0,sz(g[a])) {
		int nxt=g[a][i];
		if(nxt==fa)continue;
		dfs(nxt,a,dep+1);
	}
}
int lca(int a,int b) {
	if(Dep[a]<Dep[b])swap(a,b);
	per(i,0,20)if((1<<i)<=Dep[a]-Dep[b])a=Fa[i][a];
	if(a==b)return a;
	per(i,0,20)if(Fa[i][a]!=Fa[i][b])a=Fa[i][a],b=Fa[i][b];
	assert(Fa[0][a]==Fa[0][b]);
	return Fa[0][a];
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 0, n) {
		rep(j, 0, m) {
			string u, v;
			int a, b;
			cin >> u >> a >> v >> b;
			if(u[0] == 'D' && i != n-1) add(i * m + j, (i + 1) * m + j, a);
			if(v[0] == 'R' && j != m-1) add(i * m + j, i * m + j + 1, b);
		}
	}
	sort(all(e));
	rep(i, 0, n * m) pre[i] = i;
	rep(i, 0, sz(e)) {
		int u = e[i].se.fi, v = e[i].se.se;
		if(find(u) != find(v)) {
			join(u, v);
			g[u].pb(v), g[v].pb(u);
		}
	}
	dfs(0,0,1);
	rep(i,1,20)rep(j,0,n*m)Fa[i][j]=Fa[i-1][Fa[i-1][j]];
	int q;
	cin >> q;
	while(q--) {
		int a1, b1, a2, b2;
		cin >> a1 >> b1 >> a2 >> b2;
		--a1, --b1, --a2, --b2;
		int u = a1 * m + b1, v = a2 * m + b2;
		int Lca=lca(u,v);
		cout<<Dep[u]+Dep[v]-2*Dep[Lca]<<endl;
	}
	return 0;
}
