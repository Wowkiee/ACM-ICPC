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
int mul(int a, int b) {return 1ll * a * b % P;}
//---
struct Mar {
	int M[10][10];
	Mar(){memset(M,0,sizeof(M));}
};
Mar operator *(Mar a,Mar b) {
	Mar c;
	rep(i,1,10)rep(j,1,10)rep(k,1,10)c.M[i][j]=add(c.M[i][j],mul(a.M[i][k],b.M[k][j]));
	return c;
}
Mar kpow(Mar a,ll b) {
	Mar ans;
	rep(i,1,10)ans.M[i][i]=1;
	while(b) {
		if(b&1)ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}
int main() {
	int T;scanf("%d",&T);while(T--) {
		ll n;scanf("%lld",&n);
		if(n==1) {
			puts("3");
			continue;
		}
		Mar A,B;
		rep(i,1,10)B.M[i][1]=1;
		A.M[1][4]=A.M[1][7]=1;
		A.M[2][1]=A.M[2][7]=1;
		A.M[3][1]=A.M[3][4]=A.M[3][7]=1;
		A.M[4][2]=A.M[4][5]=1;
		A.M[5][2]=A.M[5][8]=1;
		A.M[6][5]=A.M[6][8]=1;
		A.M[7][3]=A.M[7][6]=A.M[7][9]=1;
		A.M[8][3]=A.M[8][9]=1;
		A.M[9][3]=A.M[9][6]=1;
		B=kpow(A,n-2)*B;
		int ans=0;
		rep(i,1,10)ans=add(ans,B.M[i][1]);
		printf("%d\n",ans);
	}
	return 0;
}

