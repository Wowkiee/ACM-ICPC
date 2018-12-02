#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll<<(a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 101010;

int n, m;
int deg[N], dfn[N];
vi g[N];

void dfs(int u, int fa) {
	if(deg[u] == 1) dfn[++m] = u;
	for(auto v : g[u]) if(v != fa) {
		dfs(v, u);
	}
}

int main() {
	freopen("kingdom.in","r",stdin);
	freopen("kingdom.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
		++deg[u], ++deg[v];
	}
	rep(i, 1, n + 1) if(deg[i] > 1) {
		dfs(i, 0);
		break;
	}
	vector<pii> ans;
	rep(i, 1, m / 2 + 1) ans.pb(mp(dfn[i], dfn[i + m / 2]));
	if(m & 1) ans.pb(mp(dfn[1], dfn[m]));
	cout << sz(ans) << endl;
	for(auto u : ans) cout << u.fi << " " << u.se << endl;
	return 0;
}
