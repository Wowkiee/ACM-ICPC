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
const int N=100005;
int data[N],t[N],last[N];
ll pre[N];
int main() {
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n+1)scanf("%d",&data[i]),pre[i]=pre[i-1]+data[i];
	rep(i,1,m+1)scanf("%d",&t[i]);
	int p=1;
	rep(i,1,n+1) {
		while(pre[i]-pre[p]>k)p++;
		last[i]=p-1;
	}
	int now=0;
	rep(i,1,m+1) {
		if(t[i-1]+n-now<t[i]) {
			printf("%d\n",t[i-1]+n-now);
			return 0;
		}
		now+=t[i]-t[i-1]-1;
		now=last[now];
	}
	printf("%d\n",t[m]+n-now);
	return 0;
}
