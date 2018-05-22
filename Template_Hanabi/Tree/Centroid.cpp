// id starts from 1
namespace Centriod {
    const int N = 101010;
    int vis[N],sz[N];
    // 每棵树都要先初始化!! 表示该点是否被选为重心
    void ini() {
		memset(vis,0,sizeof(vis));
	}
    void dfssz(int c,int fa,int Sz,int &rt){
        sz[c] = 1;
        for(auto t : g[c]) if(!vis[t]&&t!=fa) dfssz(t,c,Sz,rt) , sz[c]+=sz[t];
        if(!rt && sz[c]*2>Sz) rt=c;
    }
    void dfs(int c){
        int rt=0;dfssz(c,0,0,rt);dfssz(c,0,sz[c],rt=0);
        // cal something
        vis[rt] = true;
        for(auto t : g[rt]) if(!vis[t]) dfs(t);
    }
}


// 求带权树上距离小等于 k 的点对个数
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N=10101;
int n,k,ans;
vector<pii> g[N];

namespace Cen {
	const int N=10101;
	int vis[N],sz[N],d[N];
	vi dep;
	void ini() {
		memset(vis,0,sizeof(vis));
	}
	void dfssz(int c,int fa,int Sz,int &rt) {
		sz[c]=1;
		rep(i,0,sz(g[c])) {
			pii _=g[c][i];
			int t=_.fi;
			if(!vis[t]&&t!=fa) dfssz(t,c,Sz,rt), sz[c]+=sz[t];
		}
		if(!rt && sz[c]*2>Sz) rt=c;
	}
	void getDep(int u,int fa) {
		dep.pb(d[u]);
		rep(i,0,sz(g[u])) {
			pii _=g[u][i];
			int t=_.fi;
			if(!vis[t]&&t!=fa) {
				d[t]=d[u]+_.se;
				getDep(t,u);
			}
		}
	}
	int calc(int u,int fa,int init) {
		d[u]=init;
		dep.clear();
		getDep(u,fa);
		sort(dep.begin(),dep.end());
		int ret=0;
		for(int l=0,r=sz(dep)-1;l<r;) {
			if(dep[l]+dep[r]<=k) {
				ret += r-l;
				l++;
			} else {
				r--;
			}
		}
		return ret;
	}
	void dfs(int c) {
		int rt=0;dfssz(c,0,0,rt);dfssz(c,0,sz[c],rt=0);
		ans+=calc(rt,rt,0);
		vis[rt]=1;
		rep(i,0,sz(g[rt])) {
			pii _=g[rt][i];
			int t=_.fi;
			if(!vis[t]) {
				ans-=calc(t,rt,_.se);
				dfs(t);
			}
		}
	}
}

void solve() {
	using namespace Cen;
	ini();
	dfs(1);
}

int main() {
	while(~scanf("%d%d",&n,&k)) {
		if(n==0&&k==0) break;
		///init
		rep(i,0,n+1) g[i].clear();
		///read
		rep(i,1,n) {
			int u,v,w;scanf("%d%d%d",&u,&v,&w);
			g[u].pb(mp(v,w));
			g[v].pb(mp(u,w));
		}
		///solve
		ans=0;
		solve();
		///print
		printf("%d\n",ans);
	}
	return 0;
}
