#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b-1);i>=(a);i--)
#define sz(x) (int)x.szie()
#define de(x) cout<<#x<<" = "<<x<<endl
#define dd(x) cout<<#x<<" = "<<x<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int T;scanf("%d",&T);
	while(T--) {
		int n,m;scanf("%d%d",&n,&m);
		int sum=0, ma=0;
		rep(i,1,n+1) {
			int x;scanf("%d",&x);
			ma=max(ma, x);
			sum+=x;
		}
		sum=(sum+m-1)/m;
		int ans=max(ma, sum);
		printf("%d\n",ans);
	}
	return 0;
}

