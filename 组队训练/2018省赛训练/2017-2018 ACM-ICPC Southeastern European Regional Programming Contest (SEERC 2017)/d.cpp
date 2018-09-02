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

const int N=1e5+5;
int n,m,k,x,y,ans;
vi g[N],a[N];
bool f[N];


void dfs(int x){
	f[x]=1;
	rep(i,0,sz(g[x])) {
		y=g[x][i];
		if (!f[y]) dfs(y);
	}
}

int main() {
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) {
		scanf("%d",&k);
		rep(j,1,k+1) {
			scanf("%d",&x);
			a[x].pb(i);
		}
	}
	rep(i,1,m+1) {
		x=a[i][0];y=a[i][1];
		g[x].pb(y);
		g[y].pb(x);
	}
	ans=n;
	rep(i,1,n+1) if (!f[i]){
		dfs(i);
		ans--;
	}
	printf("%d",ans);
	return 0;
}
