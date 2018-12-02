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
const int N=505,mod=998244353;
int dis[N][N],Dis[N][N];
int used[N];
pii V[N<<2];
void inc(ll &a,ll b) {
	a+=b;if(a>=mod*mod)a-=mod*mod;
}
int main() {
	int T;scanf("%d",&T);while(T--) {
		int n;scanf("%d",&n);
		rep(i,1,n+1)rep(j,1,n+1)scanf("%d",&dis[i][j]),Dis[i][j]=dis[i][j];
		rep(k,1,n+1)rep(i,1,n+1)rep(j,1,n+1)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		ll ans=0;
		rep(i,1,n+1)rep(j,i+1,n+1) {
			ll Ans=0;
			rep(k,1,n+1)used[k]=0;
			int cc=n-1;
			int p=0;
			rep(k,1,n+1) {
				V[p++]={dis[i][k],k};
				V[p++]={dis[j][k],k};
			}
			sort(V,V+p);
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
