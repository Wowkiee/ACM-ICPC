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
int sub(int a, int b) {if((a -= b) < P) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---
const int N=100005;
vector<int> V[N],ss[N],vec[N];
int Index=0,trn[N],rtrn[N];
int Fa[20][N],Dep[N];
int data[N],Ans[N],S[N],exi[N],root;
void dfs(int a,int dep) {
	Dep[a]=dep;
	trn[++Index]=a;
	rtrn[a]=Index;
	rep(i,0,sz(V[a]))dfs(V[a][i],dep+1);
}
int lca(int a,int b) {
	if(Dep[a]<Dep[b])swap(a,b);
	per(i,0,20)if(pw(i)<=Dep[a]-Dep[b])a=Fa[i][a];
	if(a==b)return a;
	per(i,0,20)if(Fa[i][a]!=Fa[i][b])a=Fa[i][a],b=Fa[i][b];
	assert(Fa[0][a]==Fa[0][b]);
	return Fa[0][a];
}
int cmp(int a,int b) {
	return rtrn[a]<rtrn[b];
}
void Dfs(int a,int fa,int now) {
	if(a==root||sz(vec[a])>1)Ans[a]=now;
	rep(i,0,sz(vec[a])) {
		if(fa==vec[a][i])continue;
		Dfs(vec[a][i],a,now);
	}
	vec[a].clear();
}
int main() {
	memset(Ans,-1,sizeof(Ans));
	int n;scanf("%d",&n);
	rep(i,2,n+1) {
		int a;scanf("%d",&a);
		V[a].pb(i);Fa[0][i]=a;
	}
	dfs(1,1);
	rep(i,1,20)rep(j,1,n+1)Fa[i][j]=Fa[i-1][Fa[i-1][j]];
	rep(i,1,n+1)scanf("%d",&data[i]);
	rep(i,1,n+1) {
		int now=trn[i];
		for(int j=1;j*j<=data[now];j++)if(data[now]%j==0) {
			ss[j].pb(now);
			if(j*j!=data[now])ss[data[now]/j].pb(now);
		}
	}
	rep(cas,1,100001)if(sz(ss[cas])>1){
		int p=0;S[p++]=ss[cas][0];
		rep(i,0,sz(ss[cas]))exi[ss[cas][i]]=1;
		rep(i,1,sz(ss[cas])) {
			int u=ss[cas][i];
			int v=S[p-1];
			int Lca=lca(u,v);
			for(;p>1;v=S[p-1]) {
				int w=S[p-2];
				if(Dep[w]>=Dep[Lca]) {
					vec[v].pb(w);
					vec[w].pb(v);
					p--;
				}
				else break;
			}
			if(Lca!=v) {
				vec[Lca].pb(v);
				vec[v].pb(Lca);
				p--;
				S[p++]=Lca;
			}
			S[p++]=u;
		}
		while(p>1) {
			assert(S[p-1]!=S[p-2]);
			vec[S[p-1]].pb(S[p-2]);
			vec[S[p-2]].pb(S[p-1]);
			p--;
		}
		root=S[0];
		Dfs(root,-1,cas);
		rep(i,0,sz(ss[cas]))exi[ss[cas][i]]=0;
	}
	rep(i,1,n+1)cout<<Ans[i]<<endl;
	return 0;
}
