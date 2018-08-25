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
const int N=10005;
int n,m,k;ll s;
bool dfn[N];
int data[N];
ll Data[N];
ll pre[N<<1];
vector<int> V[N];
ll st[20][N<<1];
void dfs(int now,int id) {
	dfn[now]=1;V[id].pb(now);
	int nxt=now+k;
	if(nxt>=n)nxt-=n;
	if(!dfn[nxt])dfs(nxt,id);
}
ll qry(int l,int r) {
	ll Min=9e18;
	int now=r;
	per(i,0,20)if(now-l+1>=pw(i))Min=min(Min,st[i][now]),now-=pw(i);
	return Min;
}
ll solve(int id) {
	int nn=sz(V[id]);
	rep(i,0,nn)Data[i+1]=data[V[id][i]];
	ll M=m%nn,cil=m/nn;
	rep(i,1,nn+1)pre[i]=pre[i-1]+Data[i],st[0][i]=pre[i];
	rep(i,1,nn+1)pre[i+nn]=pre[i+nn-1]+Data[i],st[0][i+nn]=pre[i+nn];
	rep(i,1,20)for(int j=pw(i);j<=nn*2;j++)st[i][j]=min(st[i-1][j],st[i-1][j-pw(i-1)]);
	ll ans=0;
	rep(i,1,nn+1) {
		if(!cil)ans=max(ans,pre[nn+i]-qry(i+nn-M,i+nn));
		else if(pre[nn]<=0)ans=max(ans,pre[nn+i]-qry(i+1,i+nn));
		else {
			ans=max(ans,cil*pre[nn]+pre[nn+i]-qry(i+nn-M,i+nn));
			ans=max(ans,(cil-1)*pre[nn]+pre[nn+i]-qry(i+1,i+nn-M-1));
		}
	}
	return ans;
}
int main() {
	int T;scanf("%d",&T);rep(cas,0,T) {
		memset(dfn,0,sizeof(dfn));
		scanf("%d%lld%d%d",&n,&s,&m,&k);
		int Index=0;
		rep(i,0,n)scanf("%d",&data[i]);
		ll ans=0;
		rep(i,0,n)if(!dfn[i])dfs(i,++Index);
		rep(i,1,Index+1)ans=max(ans,solve(i));
		printf("Case #%d: %lld\n",cas+1,max(s-ans,0LL));
		rep(i,1,Index+1)V[i].clear();
	}
	return 0;
}
