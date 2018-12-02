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
//---
const int N=1e6+7;
int isblk[N];
vector<pii> V[N];
vector<int> Qry;
ll Dis[N],Ans[N];
int Fa[22][N],Dep[N];
void dfs(int a,int fa,ll dis,ll ddis,int dep) {
	if(isblk[a])ddis=0;
	Dis[a]=dis;Fa[0][a]=fa;Dep[a]=dep;Ans[a]=ddis;
	rep(i,0,sz(V[a])) {
		pii nxt=V[a][i];
		if(V[a][i].fi==fa)continue;
		dfs(V[a][i].fi,a,dis+V[a][i].se,ddis+V[a][i].se,dep+1);
	}
}
int cmp(int a,int b) {
	if(Ans[a]==Ans[b])return a>b;
	return Ans[a]>Ans[b];
}
int lca(int a,int b) {
	if(Dep[a]<Dep[b])swap(a,b);
	per(i,0,22)if((1<<i)<=Dep[a]-Dep[b])a=Fa[i][a];
	if(a==b)return a;
	per(i,0,22)if(Fa[i][a]!=Fa[i][b])a=Fa[i][a],b=Fa[i][b];
	assert(Fa[0][a]==Fa[0][b]);
	return Fa[0][a];
}
int main() {
	int T;scanf("%d",&T);while(T--) {
		int n,m,q;scanf("%d%d%d",&n,&m,&q);
		rep(i,1,n+1)isblk[i]=0,V[i].clear();
		while(m--) {
			int a;scanf("%d",&a);
			isblk[a]=1;
		}
		rep(i,1,n) {
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			V[a].pb(mp(b,c));
			V[b].pb(mp(a,c));
		}
		dfs(1,1,0,0,1);
		rep(i,1,22)rep(j,1,n+1)Fa[i][j]=Fa[i-1][Fa[i-1][j]];
		while(q--) {
			Qry.clear();
			int s;scanf("%d",&s);
			while(s--) {
				int a;scanf("%d",&a);
				Qry.pb(a);
			}
			sort(all(Qry),cmp);
			Qry.pb(1);
			int now,last;
			ll Maxdis;
			int i;
			for(i=0;i<sz(Qry)-1;i++) {
				if(i==0)now=last=Qry[i],Maxdis=Dis[now];
				else {
					now=lca(now,Qry[i]),Maxdis=max(Maxdis,Dis[now]);
					ll nowans=Maxdis-Dis[now];
					if(nowans>=Ans[Qry[i+1]])break;
					last=now;
				}
			}
			ll ans1=0,ans2=0;
			rep(j,0,i+1)ans1=max(ans1,min(Ans[Qry[j]],Dis[Qry[j]]-Dis[now]));
			rep(j,i+1,sz(Qry))ans1=max(ans1,Ans[Qry[j]]);
			rep(j,0,i)ans2=max(ans2,min(Ans[Qry[j]],Dis[Qry[j]]-Dis[last]));
			rep(j,i,sz(Qry))ans2=max(ans2,Ans[Qry[j]]);
			printf("%lld\n",min(ans1,ans2));
		}
	}
	return 0;
}
