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
//---
const int N=1e7+7,M=5000;
char n[N];
ll x1,a,b,c,d,e,k,all,dp[2][M];
int last[M],cc[M];
ll f(ll x) {
	return (a*x*x*x*x+
				 b*x*x*x+
				 c*x*x+
				 d*x+
				 e-1)%k+1;
}
ll kpow(ll a,ll b) {
	ll ans=1;
	while(b) {
		if(b&1)ans=ans*a%P;
		a=a*a%P;
		b>>=1;
	}
	return ans;
}
ll getn(ll mod) {
	ll ans=0;all=0;
	for(int i=0;n[i];i++)
	{
		ans=ans*10+n[i]-'0';ans%=mod;
		all=all*10+n[i]-'0';all%=P-1;
	}
	return ans;
}
int main() {
	scanf("%s%lld%lld%lld%lld%lld%lld%lld",n,&x1,&a,&b,&c,&d,&e,&k);
	if(strlen(n)<=5) {
		ll realn=getn(10000000);
		ll x=x1;
		rep(i,0,realn) {
			cc[x]=1;
			x=f(x);
		}
	}
	else {
		ll x=x1;
		last[x]=1;x=f(x);
		int p;
		for(p=2;!last[x];x=f(x),p++)last[x]=p;
		int cir=p-last[x];
		ll _x=x1;
		rep(i,1,last[x]) {
			cc[_x]=1;
			_x=f(_x);
		}
		ll res=(getn(cir<<1)-last[x]+1+cir*2)%(cir*2);
		rep(i,0,cir*2) {
			cc[_x]=1;
			_x=f(_x);
		}
	}
	int exi=0;
	dp[0][0]=1;
	rep(i,1,1<<12)exi+=cc[i];
	rep(i,1,1<<12)rep(j,0,1<<12) {
		int now=i&1;
		dp[now][j]=dp[now^1][j];
		if(cc[i])dp[now][j]=add(dp[now][j],dp[now^1][j^i]);
	}
	ll ans=dp[1][0];
	ans=mul(ans,kpow(2,(all-exi+P-1)));
	ans=sub(kpow(2,all),ans);
	cout<<ans<<endl;
	return 0;
}
