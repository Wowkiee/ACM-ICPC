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


const int N=202020;

int n;
int a[N];
ll suf[N];

int main() {
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	while(~scanf("%d",&n)) {
		rep(i,0,n+1) scanf("%d",a+i);
		suf[n]=a[n];
		for(int i=n-1;~i;--i) suf[i]=suf[i+1]+a[i];
		int l=0, r=n, ans=0;
		while(l<=r) {
			int mid=l+r>>1;
			if(suf[mid]>=mid) {
				ans=mid;
				l=mid+1;
			} else {
				r=mid-1;
			}
		}
		printf("%d\n",ans);
	}


	return 0;
}
