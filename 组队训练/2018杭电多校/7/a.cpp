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
int dis[N];
vector<pii> g[N], G[N];

void add(int u, int v, int w) {
	g[u].pb(mp(v, w)); 
	g[v].pb(mp(u, w));
}

void dij() {
	priority_queue<pii> q;
	fill_n(dis+1, n+m, inf);
	dis[1] = 0;
	q.push(mp(0, 1));
	while(!q.empty()) {
		pii u = q.top();q.pop();
		if(dis[u.se] != -u.fi) continue;
		for(auto v : g[u.se]) {
			if(dis[v.fi] > dis[u.se] + v.se) {
				dis[v.fi] = dis[u.se] + v.se;
				q.push(mp(-dis[v.fi], v.fi));
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	while(cin >> n >> m) {
		///init
		rep(i, 1, n+1) G[i].clear();
		rep(i, 1, n+m+1) g[i].clear();
		///read
		rep(i, 1, m+1) {
			int u, v, w;
			cin >> u >> v >> w;
			add(u, n+i, 1);
			add(v, n+i, 1);
			G[u].pb(mp(w, n+i));
			G[v].pb(mp(w, n+i));
		}
		///build
		rep(i, 1, n+1) {
			sort(all(G[i]));
			rep(j, 1, sz(G[i])) if(G[i][j].fi == G[i][j-1].fi) {
				add(G[i][j].se, G[i][j-1].se, 0);
			}
		}
		///solve
		dij();
		int ans = dis[n];
		if(ans == inf) cout << "-1" << endl;
		else cout << ans / 2 << endl;
	}
	return 0;
}
