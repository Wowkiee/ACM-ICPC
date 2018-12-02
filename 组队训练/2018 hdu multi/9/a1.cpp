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
const int N=90;
int mod;
int dp[2][N][N];
int mul(int a,int b) {
	return 1LL*a*b%mod;
}
void inc(int &a,int b) {
	a+=b;if(a>=mod)a-=mod;
}
int main() {
	int T;scanf("%d",&T);while(T--) {
		memset(dp,0,sizeof(dp));
		int n,m;scanf("%d%d%d",&n,&m,&mod);
		dp[1][1][1]=n*m;
		rep(i,1,n*m) {
			int zt=i%2;
			memset(dp[zt^1],0,sizeof(dp[zt^1]));
			rep(j,1,n+1)rep(k,1,m+1)if(dp[zt][j][k]) {
				inc(dp[zt^1][j][k],mul((j*k-i),dp[zt][j][k]));
				if(j!=n)inc(dp[zt^1][j+1][k],mul((n-j)*k,dp[zt][j][k]));
				if(k!=m)inc(dp[zt^1][j][k+1],mul((m-k)*j,dp[zt][j][k]));
			}
		}
		cout<<dp[(n*m)&1][n][m]<<endl;
	}
	return 0;
}
