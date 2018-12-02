#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(x) (int)x.size()
#define de(x) cout<< #x<<" = "<<x<<endl
#define dd(x) cout<< #x<<" = "<<x<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N=20202;

int n, p;
int a[N];
ll s;

bool check(int x) {
	int t=0;
	rep(i,1,n+1) {
		t+=max(0, a[i]-x);
	}
	return t<=s;
}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	scanf("%d%lld",&p,&s);
	s/=p;
	int l=1, r=20000, ans=-1;
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
	return 0;
}

