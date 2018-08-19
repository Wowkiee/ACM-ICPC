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
const int N=505;
const ll mod=998244353,mod2=mod*mod;
int dis[N][N],Dis[N][N];
int used[N];
pii V[N<<2];
vector<pii> v[N];
void inc(ll &a,ll b) {
	a+=b;if(a>=mod2)a-=mod2;
}
int main() {
	int T;scanf("%d",&T);while(T--) {
		int n;scanf("%d",&n);
		rep(i,1,n+1)rep(j,1,n+1)scanf("%d",&dis[i][j]),Dis[i][j]=dis[i][j];
		rep(k,1,n+1)rep(i,1,n+1)rep(j,1,n+1)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		rep(i,1,n+1)
		{
			v[i].clear();
			rep(j,1,n+1)v[i].pb({dis[i][j],j});
			sort(all(v[i]));
		}
		ll ans=0;
		rep(i,1,n+1)rep(j,i+1,n+1) {
			ll Ans=0;
			rep(k,1,n+1)used[k]=0;
			int cc=n-1;
			int p=0,p1=0,p2=0;
			while(p1<sz(v[i])&&p2<sz(v[j])) {
				if(v[i][p1].fi<v[j][p2].fi)V[p++]=v[i][p1++];
				else V[p++]=v[j][p2++];
			}
			while(p1<sz(v[i]))V[p++]=v[i][p1++];
			while(p2<sz(v[j]))V[p++]=v[j][p2++];
			rep(k,0,p) {
				pii now=V[k];
				if(used[now.se])continue;
				inc(Ans,1LL*cc*now.fi);
				used[now.se]=1;cc--;
			}
			inc(ans,Ans);
			inc(ans,1LL*Dis[i][j]*((n*n-n)/2-1));
		}
		cout<<ans%mod<<endl;
	}
	return 0;
}
