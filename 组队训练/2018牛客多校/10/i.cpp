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
const int N=2005,mod=998244353;
ll pro[N],Pro[N];
int n,m;
struct edge {
	int nxt,l,r;
	edge(int a=0,int b=0,int c=0) {
		nxt=a;l=b;r=c;
	}
};
vector<edge> V[N];
ll kpow(ll a,ll b) {
	ll ans=1;
	while(b) {
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
ll mul(ll &a,ll b) {
	a=(a*b)%mod;
}
void dfs(int a,int fa,ll pro,int b) {
	Pro[a]=pro;
	rep(i,0,sz(V[a])) {
		ll now=pro;
		edge cur=V[a][i];
		if(cur.nxt==fa)continue;
		if(b>cur.r)mul(now,1);
		else if(b<=cur.l)now=0;
		else {
			ll fm=(cur.r-cur.l+1);
			ll fz=b-cur.l;
			mul(now,fz);mul(now,kpow(fm,mod-2));
		}
		dfs(cur.nxt,a,now,b);
	}
}
int main() {
	de(374341633LL*8%mod);
	de(37*kpow(64,mod-2)%mod);
	int T;scanf("%d",&T);while(T--) {
		scanf("%d%d",&n,&m);
		rep(i,1,n+1)pro[i]=1,V[i].clear();
		rep(i,1,n) {
			int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
			V[a].pb(edge(b,c,d));
			V[b].pb(edge(a,c,d));
		}
		rep(i,0,m) {
			memset(Pro,0,sizeof(Pro));
			int a,b;scanf("%d%d",&a,&b);
			dfs(a,-1,1,b);
			rep(j,1,n+1)dd(j),de(Pro[j]);
			rep(j,1,n+1)mul(pro[j],1-Pro[j]+mod);
		}
		ll ans=1;
		rep(i,1,n+1)mul(ans,1-pro[i]+mod);
		cout<<(1-ans+mod)%mod<<endl;
	}
	return 0;
}
