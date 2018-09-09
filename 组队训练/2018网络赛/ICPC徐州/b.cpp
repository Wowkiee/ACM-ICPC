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
const int N=1005,M=205;
int sg[N][M];
int A[N],B[N],C[N];
int main() {
	int n,m,s1,s2;scanf("%d%d%d%d",&n,&m,&s1,&s2);
	rep(i,0,n)scanf("%d%d%d",&A[i],&B[i],&C[i]);
	rep(i,0,201) {
		if(i-100>=s1)sg[n][i]=1;
		else if(i-100<=s2)sg[n][i]=-1;
		else sg[n][i]=0;
	}
	per(i,0,n)rep(j,0,201) {
		vector<int> V;
		if(A[i]>0)V.pb(sg[i+1][min(200,j+A[i])]);
		if(B[i]>0)V.pb(sg[i+1][max(0,j-B[i])]);
		if(C[i]>0)V.pb(sg[i+1][200-j]);
		sort(all(V));
		if(i&1)sg[i][j]=V[0];
		else sg[i][j]=V.back();
	}
	if(sg[0][m+100]==1)puts("Good Ending");
	else if(sg[0][m+100]==0)puts("Normal Ending");
	else puts("Bad Ending");
	return 0;
}
