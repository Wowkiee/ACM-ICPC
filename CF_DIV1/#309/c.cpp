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

const int N = 101010, P = 1e9 + 7;

int n, m;
int pre[N], col[N];
bool ok;
pair<pii, int> e[N];
vi g[N];

int find(int x) {
	if(x == pre[x]) return x;
	return pre[x] = find(pre[x]);
}
void join(int x, int y) {
	x = find(x), y = find(y);
	pre[x] = y;
}
void dfs(int u, int c) {
	if(!ok || col[u] == c) return ;
	if(col[u] == (c ^ 1)) {
		ok = 0;
		return ;
	}
	col[u] = c;
	for(auto v : g[u]) dfs(v, c ^ 1);
}
int solve() {
	rep(i, 1, m+1) if(!e[i].se) {
		if(find(e[i].fi.fi) == find(e[i].fi.se)) return 0;
	}
	rep(i, 1, m+1) if(!e[i].se) {
		int u = e[i].fi.fi, v = e[i].fi.se;
		u = find(u), v = find(v);
		g[u].pb(v), g[v].pb(u);
	}
	memset(col, -1, sizeof(col));
	ok = 1;
	rep(i, 1, n+1) if(i == find(i) && col[i] == -1) dfs(i, 0);
	if(!ok) return 0;
	rep(i, 1, m+1) if(!e[i].se) {
		join(e[i].fi.fi, e[i].fi.se);
	}
	int cnt = 0;
	rep(i, 1, n+1) if(i == find(i)) ++cnt;
	int ans = 1;
	rep(i, 1, cnt) ans = ans * 2 % P;
	return ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 1, n+1) pre[i] = i;
	rep(i, 1, m+1) {
		int u, v, w;
		cin >> u >> v >> w;
		e[i] = mp(mp(u, v), w);
		if(w) join(u, v);
	}
	cout << solve() << endl;
	return 0;
}
