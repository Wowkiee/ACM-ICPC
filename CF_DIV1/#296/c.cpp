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

const int N = 101010;

int n, m, p;
int deg[N], ind[N];
bool vis[N * 5];
vector<pii> ans;
vector<pii> g[N];

void dfs(int u) {
	while(ind[u] < sz(g[u])) {
		if(vis[g[u][ind[u]].se]) ++ind[u];
		else {
			auto v = g[u][ind[u]];
			vis[v.se] = 1;
			dfs(v.fi);
			ans.pb(mp(v.fi, u));
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 1, m+1) {
		int u, v;
		cin >> u >> v;
		++deg[u], ++deg[v];
		g[u].pb(mp(v, i));
		g[v].pb(mp(u, i));
	}
	p = m;
	int u = 0;
	rep(v, 1, n+1) if(deg[v] & 1) {
		if(u) {
			++p;
			g[u].pb(mp(v, p));
			g[v].pb(mp(u, p));
			u = 0;
		} else {
			u = v;
		}
	}
	if(p & 1) {
		++p;
		g[1].pb(mp(1, p));
		g[1].pb(mp(1, p));
	}
	dfs(1);
	cout << sz(ans) << endl;
	rep(i, 0, sz(ans)) {
		int u = ans[i].fi, v = ans[i].se;
		if(i & 1) swap(u, v);
		cout << u << " " << v << endl;
	}
	return 0;
}

