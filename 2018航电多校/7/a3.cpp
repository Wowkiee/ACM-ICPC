#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 303030, inf = N;

int n, m;
int dis[N], pre[N];
bool vis[N];
pii e[N];
vi g[N];
vector<pii> G[N];

int find(int x) {
	if(x == pre[x]) return x;
	return pre[x] = find(pre[x]);
}
void join(int x, int y) {
	x = find(x);
	y = find(y);
	pre[x] = y;
}
void bfs(int st, int ed) {
	dis[st] = 0;
	vis[st] = 1;
	vi q;
	q.pb(st);
	rep(i, 0, sz(q)) {
		int u = q[i];
		for(auto v : g[u]) if(!vis[v]) {
			dis[v] = dis[u] + 1;
			if(v == ed) return ;
			q.pb(v);
			vis[v] = 1;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	while(cin >> n >> m) {
		///init
		rep(i, 1, n+1) G[i].clear();
		rep(i, 1, n+m+1) g[i].clear(), pre[i] = i, dis[i] = inf, vis[i] = 0;
		///read
		rep(i, 1, m+1) {
			int u, v, w;
			cin >> u >> v >> w;
			G[u].pb(mp(w, n+i));
			G[v].pb(mp(w, n+i));
			e[i] = mp(u, v);
		}
		///build
		rep(i, 1, n+1) {
			sort(all(G[i]));
			rep(j, 1, sz(G[i])) if(G[i][j].fi == G[i][j-1].fi) {
				join(G[i][j].se, G[i][j-1].se);
			}
		}
		///solve
		rep(i, 1, m+1) {
			int u = e[i].fi, v = e[i].se, w = i+n;
			u = find(u), v = find(v), w = find(w);
			g[u].pb(w), g[v].pb(w);
			g[w].pb(u), g[w].pb(v);
		}
		bfs(find(1), find(n));
		///print
		int ans = dis[find(n)];
		assert(ans % 2 == 0);
		if(ans == inf) cout << "-1" << endl;
		else cout << ans / 2 << endl;
	}
	return 0;
}
