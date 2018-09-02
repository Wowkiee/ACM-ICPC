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
int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---
const int N=1005;
char s[N];
int dp[N][N];
int main() {
	scanf("%s%d",s,&P);
	int n=strlen(s);
	dp[n][0]=1;
	per(i,0,n) {
		if(s[i]=='?') {
			rep(j,0,10) {
				int zt=mul(j,kpow(10,n-i-1));
				rep(k,0,P)dp[i][k]|=dp[i+1][sub(k,zt)];
			}
		}
		else {
			int zt=mul(s[i]-'0',kpow(10,n-i-1));
			rep(k,0,P)dp[i][k]=dp[i+1][sub(k,zt)];
		}
	}
	if(!dp[0][0]) {
		puts("*");
		return 0;
	}
	int now=0;
	rep(i,0,n) {
		if(s[i]=='?')per(j,i==0,10) {
			int zt=mul(j,kpow(10,n-i-1));
			if(dp[i+1][sub(0,add(now,zt))])s[i]=j+'0';
		}
		now=add(now,mul(s[i]-'0',kpow(10,n-i-1)));
	}
	puts(s);
	return 0;
}
