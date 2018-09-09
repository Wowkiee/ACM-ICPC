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
const int N=1000005;
char seed[5],s[N];
int S[N*2];
int __abs(int a) {
	return a>0?a:-a;
}
int count(int a) {
	if(a<10)return 1;
	if(a<100)return 2;
	else return 3;
}
int main() {
	int T;scanf("%d",&T);while(T--) {
		int n;scanf("%d%s%s",&n,seed,s);
		for(int i=0;s[i];i++) {
			int now=__abs(s[i]-seed[0]);
			S[i*2]=now/10,S[i*2+1]=now%10;
		}
		int p=0;
		while(p<2*n) {
			if(S[p]==0)p++;
			else break;
		}
		printf("%d\n",max(1,2*n-p));
	}
	return 0;
}
