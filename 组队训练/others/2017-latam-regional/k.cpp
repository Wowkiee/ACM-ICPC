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
const int N=100;
char s[N][N];
int main() {
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF) {
		rep(i,0,n)scanf("%s",s[i]);
		int cc[2]={0};
		rep(i,0,n)rep(j,0,m)if(s[i][j]=='o')cc[(i+j)&1]++;
		if((cc[0]+cc[1])&1) {
			puts("N");
			return 0;
		}
		int c=(cc[0]-cc[1])/2;
		puts(c==((n*m)&1)?"Y":"N");
	}
	return 0;
}
