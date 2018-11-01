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
const int N=100005;
int data[N],pre[N];
vector<int> V;
int main() {
	int n,m;scanf("%d%d",&n,&m);
	rep(i,1,n+1)scanf("%d",&data[i]);
	rep(i,1,n+1)pre[i]=pre[i-1]+data[i];
	if(pre[n]%m) {
		puts("No");
		return 0;
	}
	ll aa=pre[n]/m;
	int now=0;
	rep(i,1,m+1) {
		ll Now=aa*i;
		int p=lower_bound(pre+now,pre+n+1,Now)-pre;
		if(pre[p]==Now) {
			V.pb(p-now);
			now=p;
		}
		else {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	rep(i,0,sz(V))printf("%d%c",V[i]," \n"[i==sz(V)-1]);
	return 0;
}
