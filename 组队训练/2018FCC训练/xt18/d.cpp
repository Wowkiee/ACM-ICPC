#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----

const int N=5050;

int a[N];
ll sum;
ll f[N][N];

void calc(int n) {
	vi v;
	int now=1;
	rep(i,2,n+1) {
		if(a[i]==a[i-1]) {
			++now;
		} else {
			v.pb(now);
			now=1;
		}
	}
	if(sz(v)&&a[1]==a[n]) v[0]+=now;
	else v.pb(now);
	ll res=1;
	rep(i,0,sz(v)) res*=v[i];
	sum+=res;
}

void dfs(int p,int rem,int n) {
	if(p>n) {
		if(rem==0) calc(n);
		return ;
	}
	if(n-p>=rem) dfs(p+1, rem, n);
	if(rem) {
		a[p]=1;
		dfs(p+1, rem-1, n);
	}
	a[p]=0;
}

void solve(int n,int m) {
	sum=0;
	dfs(1, n, n+m);
	f[n][m]=sum;
}

int main() {
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	rep(i,1,10) {
		rep(j,1,i+1) {
			solve(i, j);
		}
	}
	rep(i,1,10) {
		rep(j,1,i+1) {
			printf("%10lld : %d : %d ",f[i][j],i,j);
		} 
		puts("");
	}
	rep(i,1,10) {
		rep(j,1,i+1) {
			printf("%10lld : %d : %d ",f[i][j]-f[i][j-1]*(i-1)-f[i+1][j-1],i,j);
		} 
		puts("");
	}
	return 0;
}
