#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int N=202020;

int n;
ll x[N], y[N];

ll solve(int i, int j, int k) {
	ll x1=x[i]-x[j];
	ll y1=y[i]-y[j];
	ll x2=x[k]-x[j];
	ll y2=y[k]-y[j];
	ll res=x1*y2-x2*y1;
	if(res<0) res=-res;
	return res;
}

int main() {
	while(~scanf("%d",&n)) {
		rep(i,0,n) scanf("%lld%lld",x+i,y+i);
		ll ans=4e18;
		rep(i,0,n) {
			ans=min(ans, solve(i, (i+1)%n, (i+2)%n));
		}
		printf("%lld\n",ans);
	}
	return 0;
}

