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
void inc(ll &a,ll b) {
	a+=b;if(a>=mod)a-=mod;
}
int main() {
	int T;scanf("%d",&T);while(T--) {
		int n;scanf("%d",&n);
		rep(i,1,n+1)rep(j,1,n+1)scanf("%d",&dis[i][j]),Dis[i][j]=dis[i][j];
		rep(k,1,n+1)rep(i,1,n+1)rep(j,1,n+1)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		ll ans=0;
		rep(i,1,n+1)rep(j,i+1,n+1) {
			ll Ans=0;
			int used[N]={0},cc=n-1;
			vector<pii> V;
			rep(k,1,n+1) {
				V.pb({dis[i][k],k});
				V.pb({dis[j][k],k});
			}
			sort(all(V));
			rep(k,0,sz(V)) {
				pii now=V[k];
				if(used[now.se])continue;
				inc(Ans,cc*now.fi);
				used[now.se]=1;cc--;
			}
			inc(ans,Ans);
			inc(ans,1LL*Dis[i][j]*((n*n-n)/2-1)%mod);
		}
		cout<<ans<<endl;
	}
	return 0;
}
