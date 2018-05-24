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

int n,m;
int a[N];

bool check(int x) {
	int cnt=0;
	rep(i,1,n+1) {
		if(a[i]<=cnt) {
			++cnt;
		} else {
			if(x) {
				--x;
				++cnt;
			}
		}
	}
	return cnt>=m;
}

int main() {
	while(~scanf("%d%d",&n,&m)) {
		///read
		rep(i,1,n+1) scanf("%d",a+i);
		///solve
		int l=0, r=m, ans=-1;
		while(l<=r) {
			int mid=l+r>>1;
			if(check(mid)) {
				ans=mid;
				r=mid-1;
			} else {
				l=mid+1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

