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
pii a[N];

int main() {
	while(~scanf("%d",&n)) {
		///read
		rep(i,0,n) {
			int x,y;scanf("%d%d",&x,&y);
			a[i]=mp(x, y);
		}
		a[n]=mp(2e9, 2e9);
		///solve
		sort(a, a+n);
		vi ans;
		int mi=2e9;
		rep(i,0,n+1) {
			if(a[i].fi>mi) {
				ans.pb(mi);
				mi=a[i].se;
			} else {
				mi=min(mi, a[i].se);
			}
		}
		printf("%d\n",sz(ans));
		rep(i,0,sz(ans)) printf("%d%c",ans[i]," \n"[i==sz(ans)-1]);
	}
	return 0;
}

