#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double db;
//---
vector<int> V;
int main() {
	int n,k,p;
	scanf("%d%d%d",&n,&k,&p);
	rep(i,0,n-k)V.pb(1);
	int now=2;
	db fz=n-k;
	rep(i,n-k,n) {
		if(fz/i<p/100.0)now++,fz=i;
		V.pb(now);
	}
	ll sum=0;
	rep(i,0,n)sum+=V[i];
	printf("%lld\n",sum);
	rep(i,0,n)printf("%d%c",V[i],i==n-1?'\n':' ');
	return 0;
}
