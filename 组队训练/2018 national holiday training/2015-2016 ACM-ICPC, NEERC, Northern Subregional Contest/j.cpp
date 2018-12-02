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
const int N=50005;
ll dp[N];
int c[N],val[N];
int Q[N],L,R;
int main() {
	//freopen("journey.in","r",stdin);
	//freopen("journey.out","w",stdout);
	int n,t;scanf("%d%d",&n,&t);t-=n-1;
	rep(i,1,n)scanf("%d",&c[i]);
	per(i,1,n-1)c[i]=min(c[i],c[i+1]);
	rep(i,2,n)scanf("%d",&val[i]);val[n]=0;
	int l=1,r=n-1;
	while(l<r) {
		int mid=(l+r)>>1;
		L=0,R=0;dp[1]=0;Q[++R]=1;
		rep(i,2,n+1) {
			dp[i]=dp[Q[L+1]]+val[i];
			while(L!=R&&dp[i]<=dp[Q[R]])R--;Q[++R]=i;
			if(Q[L+1]==i-mid)L++;
		}
		if(dp[n]<=t)r=mid;
		else l=mid+1;
	}
	cout<<c[l]<<endl;
	return 0;
}
