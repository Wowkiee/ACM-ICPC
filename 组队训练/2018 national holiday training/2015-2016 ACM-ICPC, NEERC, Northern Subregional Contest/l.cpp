#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(x) (int)x.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll<<(a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---
const int N=105;
int data[N][N];
int main() {
	freopen("lucky.in","r",stdin);
	freopen("lucky.out","w",stdout);
	int n,m;scanf("%d%d",&n,&m);
	rep(i,1,n+1)rep(j,1,m+1)scanf("%d",&data[i][j]);
	int ans=0;
	rep(i,1,n+1) {
		int Max=0;
		rep(j,1,m+1) {
			if(data[i][j]>Max)ans++,Max=data[i][j];
		}
		Max=0;
		per(j,1,m+1) {
			if(data[i][j]>Max)ans++,Max=data[i][j];
		}
	}
	rep(j,1,m+1) {
		int Max=0;
		rep(i,1,n+1) {
			if(data[i][j]>Max)ans++,Max=data[i][j];
		}
		Max=0;
		per(i,1,n+1) {
			if(data[i][j]>Max)ans++,Max=data[i][j];
		}
	}
	cout<<ans<<endl;
	return 0;
}
