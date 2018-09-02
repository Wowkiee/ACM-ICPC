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
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define per(i,l,r) for(int i=(r)-1;i>=(l);i--)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----

const int N=10101;

pair<double, double> a[N];

int main() {
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	int n;
	while(~scanf("%d",&n)) {
		double ans=0, v=0;
		rep(i,1,n+1) {
			double x, y;scanf("%lf%lf",&x,&y);
			a[i]=mp(-x, y);
			ans-=v*y+x*y*y/2;
			v=v+x*y;
		}
		sort(a+1, a+1+n);
		v=0;
		rep(i,1,n+1) {
			double x=-a[i].fi, y=a[i].se;
			ans+=v*y+x*y*y/2;
			v=v+x*y;
		}
		printf("%.1f\n",ans);
	}
	return 0;
}
