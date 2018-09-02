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

int n, m;
int pre1[N], pre12[N], sz[N], sz1[N], sz12[N], dep[N], pre[N];
map<pii, int> e;
vi g[N];

void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	pre[u] = fa;
	for(auto v : g[u]) if(v != fa) dfs(v, u);
}

int find(int x, int pre[]) {
	if(x == pre[x]) return x;
	return pre[x] = find(pre[x], pre);
}
inline void join1(int x, int y) {
	x = find(x, pre1);
	y = find(y, pre1);
	if(x == y) return ;
	if(dep[x] > dep[y]) swap(x, y);
	pre1[y] = x;
	sz1[x] += sz1[y];
	sz[x] += sz[y];
}
inline void join12(int x, int y, int t) {
	int a = find(x, pre1);
	int b = find(y, pre1);
	if(dep[a] > dep[b]) swap(a, b);
	x = find(x, pre12);
	y = find(y, pre12);
	if(dep[x] > dep[y]) swap(x, y);
	if(x == y) return ;

	if(t == 2) {
		sz[a] -= sz12[find(b, pre12)];
		if(pre[x]) sz[find(pre[x], pre1)] += sz12[y];
	}

	pre12[y] = x;
	sz12[x] += sz12[y];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		///
		cin >> n >> m;
		///init
		fill_n(g+1, n, vi());
		rep(i, 1, n+1) pre1[i] = pre12[i] = i, sz1[i] = sz12[i] = 1, sz[i] = 0;
		e.clear();
		///read
		rep(i, 1, n) {
			int u, v, w;
			cin >> u >> v >> w;
			g[u].pb(v);
			g[v].pb(u);
			if(u > v) swap(u, v);
			e[mp(u, v)] = w;
		}
		///solve
		dfs(1, 0);
		for(auto t : e) {
			int u = t.fi.fi, v = t.fi.se, w = t.se;
			if(w <= 1) join1(u, v);
			if(w <= 2) join12(u, v, 1);
		}
		rep(i, 1, n+1) if(i == find(i, pre12)) {
			if(pre[i]) sz[find(pre[i], pre1)] += sz12[i];
		}
		while(m--) {
			int u, v, s, t;
			cin >> u >> v >> s >> t;
			if(u > v) swap(u, v);
			int w = e[mp(u, v)] = max(0, e[mp(u, v)] - 1);
			if(w) {
				if(w == 1) join1(u, v);
				else if(w == 2) join12(u, v, 2);
			}
			int f1s = find(s, pre1);
			int cnt = sz12[find(s, pre12)] + sz[f1s];
			if(pre[f1s] && e[mp(min(f1s, pre[f1s]), max(f1s, pre[f1s]))] == 3) cnt += sz12[find(pre[f1s], pre12)];
			int ok = 0;
			if(find(s, pre12) == find(t, pre12)) ok = 1;
			if(pre[f1s]) if(find(t, pre12) == find(pre[f1s], pre12)) ok = 1;
			int f12t = find(t, pre12);
			if(pre[f12t]) if(f1s == find(pre[f12t], pre1)) ok = 1;
			cout << ok << " " << cnt << endl;
		}
	}
	return 0;
}
