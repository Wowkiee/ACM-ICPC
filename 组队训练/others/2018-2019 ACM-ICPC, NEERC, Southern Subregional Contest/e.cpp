#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(c) cout << #c << " = " << c << endl
#define dd(c) cout << #c << " = " << c << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---
const int N=200005;
int n,m;
ll t;
int data[N];

int cal(int mid) {
	ll now=0,cc=0,last=0,ans=0;
	rep(i,1,n+1)if(data[i]<=mid) {
		if(now+data[i]<=t)now+=data[i],cc++,last+=data[i],ans++;
		else return ans;
		if(cc==m) {
			now+=last;
			if(now>t)return ans;
			last=0;cc=0;
		}
	}
	return ans;
}
vector<int> V;
int main() {
	int T;scanf("%d",&T);while(T--) {
		V.clear();
		scanf("%d%d%lld",&n,&m,&t);
		rep(i,1,n+1)scanf("%d",&data[i]),V.pb(data[i]);
		sort(all(V));V.erase(unique(all(V)),V.end());
		int l=0,r=sz(V)-1;
		while(r-l>2) {
			int mid=(l+r)/2,midd=(mid+r)/2;
			if(cal(V[mid])>=cal(V[midd]))r=midd;
			else l=mid;
		}
		if(r-l<=1) {
			int l1=cal(V[l]),l2=cal(V[r]);
			if(l1>=l2)printf("%d %lld\n",l1,min(t,(ll)V[l]));
			else printf("%d %lld\n",l2,min(t,(ll)V[r]));
		}
		else {
			int l1=cal(V[l]),l2=cal(V[l+1]),l3=cal(V[r]);
			if(l1>=l2&&l1>=l3)printf("%d %lld\n",l1,min(t,(ll)V[l]));
			else if(l2>=l1&&l2>=l3)printf("%d %lld\n",l2,min(t,(ll)V[l+1]));
			else printf("%d %lld\n",l3,min(t,(ll)V[r]));
		}
	}
	return 0;
}
