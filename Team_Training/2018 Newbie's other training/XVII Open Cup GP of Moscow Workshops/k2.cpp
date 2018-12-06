#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 2e5 + 7;
const ll inf = pw(50);
ll f[N][3];
int n, n1, n2, w, u, v, x, col[N];
vector<pii> g[N];

void dfs(int u, int fa) {
	if (col[u] == 1) f[u][0] = f[u][2] = inf;
	else if (col[u] == 2) f[u][0] = f[u][1] = inf;
	rep(i, 0, sz(g[u])) {
		int v = g[u][i].fi, w = g[u][i].se;
		if (v == fa) continue;
		dfs(v, u);
		if (col[u] == 0) {
			f[u][0] += min(f[v][0], min(f[v][1], f[v][2]) + w);
			f[u][1] += min(min(f[v][0], f[v][1]), f[v][2] + w);
			f[u][2] += min(min(f[v][0], f[v][2]), f[v][1] + w);
		}else if (col[u] == 1) {
			f[u][1] += min(min(f[v][0], f[v][1]), f[v][2] + w);
		}else 
			f[u][2] += min(min(f[v][0], f[v][2]), f[v][1] + w);
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n) {
		cin >> u >> v >> w;
		g[u].pb(mp(v, w));
		g[v].pb(mp(u, w));
	}
	cin >> n1;
	rep(i, 1, n1+1) {
		cin >> x; col[x] = 1;
	}
	cin >> n2;
	rep(i, 1, n2+1) {
		cin >> x; col[x] = 2;
	}
	dfs(1, 0);
	cout << min(min(f[1][0], f[1][1]), f[1][2]);
	return 0;
}
