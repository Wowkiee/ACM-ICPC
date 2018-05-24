#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int N =  1007;

vi G[N], g[N], e[N];
int n, cnt, root;
int fa[N],in[N];

void init() {
	memset(fa, -1, sizeof(fa));
	memset(in, 0, sizeof(in));
	rep(i, 1, n + 1) G[i].clear();
	cnt = 0;
}

void solve(int root) {
	
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int u = q.front();	 q.pop();
		rep(i, 0, sz(G[u])) {
			int v = G[u][i];
			in[v] -- ;
			if(in[v] == 0){
				cnt++;
				fa[v] = u;
				q.push(v);
			}
		  }
	}

}

void dfs(int u) {
	rep(i,0,sz(g[u])) {
		int v=g[u][i];
		dfs(v);
		rep(j,0,sz(e[v])) e[u].pb(e[v][j]);
		e[u].pb(v);
	}
	sort(e[u].begin(), e[u].end());
	sort(G[u].begin(), G[u].end());
}

bool check() {
	rep(i,1,n+1) if(fa[i]!=-1) {
		g[fa[i]].pb(i);
	}
	dfs(root);
	rep(i,1,n+1) {
		if(sz(e[i])!=sz(G[i])) return 0;
		rep(j,0,sz(e[i])) if(e[i][j]!=G[i][j]) return 0;
	}
	return 1;
}

int main() {

	scanf("%d", &n);
	init();
	rep(i, 1, n + 1) {
		int k, v;
		scanf("%d", &k);
		while(k--) {
			scanf("%d", &v);
			in[v]++;
			G[i].pb(v);	
		}
	}	
	rep(i, 1, n + 1) if(in[i] == 0) cnt++, root = i;
//	de(root);de(cnt);
	if(cnt == 1) solve(root);
	else { printf("NO"); return 0; }
	
	if(cnt == n) {  
		if(check()) {
			printf("YES\n");
			rep(i, 1, n + 1) {
				if(fa[i] == - 1) continue;
				else printf("%d %d\n",fa[i], i); 
			}
		} else {
			printf("NO");
		}
	} 
	else { printf("NO"); return 0; }
	
	return 0;
}
