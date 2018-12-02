#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 111;

int n, cnt;
pair<pii, int> ans[N * N];
vector<pii> g[N];
vi vis[N];

void dfs(int u) {
	rep(i, 0, sz(g[u])) if(!vis[u][i]) {
		vis[u][i] = 1;
		dfs(g[u][i].fi);
		ans[++cnt] = mp(mp(u, g[u][i].fi), g[u][i].se);
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(v, 2, n + 1) rep(u, 1, n + 1) if(u != v) {
		g[u].pb(mp(v, v));
		vis[u].pb(0);
	}
	int v = 1;
	rep(u, 0, n) if(u != v) g[u].pb(mp(v, v)), vis[u].pb(0);
	g[n].pb(mp(0, 1)), vis[n].pb(0);
	dfs(0);
	for(int i = cnt; i; --i) {
		cout << ans[i].fi.se << " " << ans[i].se << " " << ans[i].fi.fi << endl;
	}
	return 0;
}
