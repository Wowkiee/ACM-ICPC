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
const int N=4;
const ll mod=1e9+7;
struct Mat {
	ll c[N][N];
	Mat(){memset(c,0,sizeof(c));}
}A,B;
void inc(int &a,int b) {
	a+=b;if(a>=mod)a-=mod;
}
int mul(int a,int b) {
	return 1ll*a*b%mod;
}
Mat operator *(Mat a,Mat b) {
	Mat res;
	rep(i,1,4)rep(j,1,4)rep(k,1,4)inc(res.c[i][j],mul(a.c[i][k],b.c[k][j]));
	return res;
}
void kpow(ll n) {
	Mat C=B;
	while(n) {
		if(n&1)A=C*A;
		C=C*C;
		n>>=1;
	}
}
int solve(int n,int a) {
	return n/(n/a);
}
int main() {
	int T;scanf("%d",&T);while(T--) {
		int a,b,c,d,p,n;scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&p,&n);
		A.c[1][1]=b,A.c[2][1]=a;
		B.c[1][1]=d,B.c[1][2]=c,B.c[1][3]=B.c[2][1]=B.c[3][3]=1;
		int now=2;
		while(now<n) {
			now++;
			int aa=p/now;
			A.c[3][1]=aa;
			int r;
			if(aa==0)r=n;
			else r=min(n,solve(p,now));
			kpow(r-now+1);
			now=r;
		}
		printf("%lld\n",A.c[1][1]);
	}
	return 0;
}
