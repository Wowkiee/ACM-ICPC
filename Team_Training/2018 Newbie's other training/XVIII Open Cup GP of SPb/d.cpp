#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(a) cout << #a << " = " << a << " "
#define de(a) cout << #a << " = " << a << endl
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double db;
//----
const int N = 250, M = 300;

vector<pii> g[N];
char s[M][N][10];
int n, m, ans;
int dis[N];
bool vis[N];

void dfs(int u, int fa) {
	vis[u] = 1;
	rep(i, 0, sz(g[u])) {
		int v = g[u][i].fi, w = g[u][i].se;
		if(v == fa || w == 0) continue;
		if(vis[v]) {
			int t = dis[u] + w - dis[v];
			ans = __gcd(ans, abs(t));
		} else {
			dis[v] = dis[u] + w;
			dfs(v, u);
		}
	}
}

int main() {
	freopen("crossing-lights.in", "r", stdin);
	freopen("crossing-lights.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 0, m)rep(j, 0, n)cin >> s[i][j];
	rep(i, 0, m)rep(j, i + 1, m) {
		rep(k, 0, n) {
			if(s[i][k][0] == 'X' || s[j][k][0] == 'X');
			else {
				int a = atoi(s[i][k]), b = atoi(s[j][k]);
				int c = a - b;
				g[i].pb(mp(j, c)); g[j].pb(mp(i, -c));
				break;
			}
		}
	}
	rep(i, 0, m) if(!vis[i]) dfs(i, 0);
	if(ans == 0) ans = -1;
	cout << ans << endl;
	return 0;
}
