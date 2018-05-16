// 点分治
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(x) (int)x.size()
#define de(x) cout<< #x<<" = "<<x<<endl
#define dd(x) cout<< #x<<" = "<<x<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N=202020, P=1e9+7;

int n;
int a[N], cnt[2][N];
vi g[N];
ll ans;
ll sum[2][N];

int vis[N], sz[N];

void upd(ll &a, ll b) {
	if(b<0) b+=P;
	a+=b;
	if(a>=P) a-=P;
}

void dfssz(int c,int fa,int Sz,int &rt) {
	sz[c]=1;
	rep(i,0,sz(g[c])) {
		int t=g[c][i];
		if(!vis[t]&&t!=fa) dfssz(t, c, Sz, rt), sz[c]+=sz[t];
		if(!rt && sz[c]*2>Sz) rt=c;
	}
}

void dfs2(int u,int fa) {
	cnt[0][u]=1;
	cnt[1][u]=sum[0][u]=sum[1][u]=0;
	rep(i,0,sz(g[u])) {
		int v=g[u][i];
		if(vis[v]||v==fa) continue;
		dfs2(v, u);
		cnt[0][u]+=cnt[1][v];
		cnt[1][u]+=cnt[0][v];
		upd(sum[0][u], sum[1][v]);
		upd(sum[1][u], sum[0][v]);
	}
	upd(sum[0][u], 1ll*cnt[0][u]*a[u]%P);
	upd(sum[1][u], -1ll*cnt[1][u]*a[u]%P);
}

void dfs(int c) {
	int rt=0;
	dfssz(c,0,0,rt);
	dfssz(c,0,sz[c],rt=0);
	dfssz(c=rt,0,sz[c],rt);
	///
	dfs2(c, 0);
	rep(i,0,sz(g[c])) {
		int t=g[c][i];
		if(vis[t]) continue;
		upd(ans, sum[0][t]*(cnt[1][c]-cnt[0][t])%P*2%P);
		upd(ans, sum[1][t]*(cnt[0][c]-cnt[1][t])%P*2%P);
		upd(ans, 1ll*cnt[0][t]*cnt[0][t]%P*a[c]%P);
		upd(ans, -1ll*cnt[1][t]*cnt[1][t]%P*a[c]%P);
	}
	upd(ans, 1ll*cnt[0][c]*cnt[0][c]%P*a[c]%P);
	upd(ans, -1ll*cnt[1][c]*cnt[1][c]%P*a[c]%P);
	///
	vis[c]=1;
	rep(i,0,sz(g[c])) {
		int t=g[c][i];
		if(!vis[t]) dfs(t);
	}
}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%d",a+i);
		if(a[i]<0) a[i]+=P;
	}
	rep(i,1,n) {
		int u,v;scanf("%d%d",&u,&v);
		g[u].pb(v);
		g[v].pb(u);
	} 
	dfs(1);
	if(ans<0) ans+=P;
	printf("%lld\n",ans);
	return 0;
}
