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
int dp[10005];
void getdp(int a,int b) {
	vector<int> V[10005];
	rep(i,0,10001)V[i%a].pb(dp[i]);
	int now[10005]={0};
	rep(i,0,10001) {
		int x=i%a,xx=i/a;
		now[x]=add(now[x],V[x][xx]);
		dp[i]=now[x];
		if(xx>=b)now[x]=sub(now[x],V[x][xx-b]);
	}
}

int main() {
	int T;scanf("%d",&T);while(T--) {
		memset(dp,0,sizeof(dp));dp[0]=1;
		int n,m;scanf("%d%d",&n,&m);
		while(n--) {
			int a,b;scanf("%d%d",&a,&b);
			b=1<<b;
			getdp(a,b-1);
		}
		while(m--) {
			int a;scanf("%d",&a);
			printf("%d\n",dp[a]);
		}
	}
	return 0;
}
