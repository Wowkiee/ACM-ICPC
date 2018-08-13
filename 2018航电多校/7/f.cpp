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
const int N=45;
const int mod=19260817;
ll dp[N][N][N]={0};
ll jc[N], inv[N];
char s1[N],s2[N];
ll C(ll a,ll b) {
	ll ans=1;
	for(int i=1;i<=b;i++)ans=ans*(a-i+1)/i;
	return ans%mod;
}
void inc(ll &a,ll b) {
	a+=b;if(a>=mod)a-=mod;
}
void sub(ll &a,ll b) {
	a-=b;if(a<0)a+=mod;
}
ll kpow(ll a,ll b) {
	ll ans=1;
	while(b) {
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int main() {
	jc[0] = 1;
	rep(i, 1, N) jc[i] = jc[i-1] * i % mod;
	inv[N-1] = kpow(jc[N-1], mod-2);
	for(int i = N - 2; ~i; --i) inv[i] = inv[i+1] * (i+1) % mod;
	rep(len,3,41) {
		dp[len][0][0]=1;
		rep(i,0,len)rep(j,0,len+1) {
			if(j>=3&&len-j>=0)inc(dp[len][i+1][j-3],dp[len][i][j]*C(j,3)%mod);//111->000
			if(j>=2&&len-j>=1)inc(dp[len][i+1][j-1],dp[len][i][j]*C(j,2)%mod*C(len-j,1)%mod);//110->001
			if(j>=1&&len-j>=2)inc(dp[len][i+1][j+1],dp[len][i][j]*C(j,1)%mod*C(len-j,2)%mod);//100->011
			if(j>=0&&len-j>=3)inc(dp[len][i+1][j+3],dp[len][i][j]*C(len-j,3)%mod);//000->111
		}
	}
//	ll tt = 0;
//	rep(i, 0, 5+1) tt += dp[5][3][i];
//	de(tt);
	int cas=0;
	int n,m;while(scanf("%d%d",&n,&m)!=EOF) {
		if(n==0&&m==0)break;
		cas++;
		scanf("%s%s",s1,s2);
		int k=0;
		for(int i=0;s1[i];i++)k+=(s1[i]!=s2[i]);
		de(k);
		ll ans=dp[n][m][k];
		de(ans);
		if(m>=2)sub(ans,m*dp[n][m-2][k]%mod);
		//ans=ans*kpow(C(n,k),mod-2)%mod;
		printf("Case #%d: %lld\n",cas,ans);
	}
	return 0;
}
