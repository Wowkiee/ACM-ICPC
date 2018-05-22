#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b-1);i>=(a);i--)
#define sz(x) (int)x.size()
#define de(x) cout<<#x<<" = "<<x<<endl
#define dd(x) cout<<#x<<" = "<<x<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N=20202;
int n,m;
pii a[N];

int main() {
	int T;scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		vi ans;
		rep(i,1,n+1) {
			int h, mi, s;scanf("%d:%d:%d",&h,&mi,&s);
			a[i]=mp(h*60*60+mi*60+s, i);
		}
		sort(a+1, a+1+n);
		int pre;
		rep(i,1,n+1) {
			if(i==1||a[i].fi-pre>=m) ans.pb(a[i].se), pre=a[i].fi;
		}
		sort(ans.begin(), ans.end());
		printf("%d\n",sz(ans));
		rep(i,0,sz(ans)) printf("%d%c",ans[i]," \n"[i==sz(ans)-1]);
	}
	return 0;
}

