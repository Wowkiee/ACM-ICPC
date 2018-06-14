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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 202020;

int n, m;
int a[N], fa[22][N], dep[N];
ll b[N], pre[N];
vi g[N];

int cntn;
int rt[N], ls[N*22], rs[N*22];
ll sum[N*22];

void upd(int pre, int &now, int p, ll c, int l = 1, int r = 200001) {
	now = ++cntn;
	sum[now] = (sum[pre] ^ c);
	ls[now] = ls[pre];
	rs[now] = rs[pre];
	if(l == r) return ;
	int mid = l+r>>1;
	if(p<=mid) upd(ls[pre], ls[now], p, c, l, mid);
	else upd(rs[pre], rs[now], p, c, mid+1, r);
}

void dfs(int u, int f) {
	upd(rt[f], rt[u], a[u], b[a[u]]);
	fa[0][u] = f;
	rep(i, 1, 18) fa[i][u] = fa[i-1][fa[i-1][u]];
	dep[u] = dep[f] + 1;
	for(auto v : g[u]) if(v != f) dfs(v, u);
}

inline int lca(int x, int y) {
	if(dep[x] > dep[y]) swap(x, y);
	rep(i, 0, 18) if((dep[y]-dep[x])>>i&1) y = fa[i][y];
	if(x == y) return x;
	for(int i = 17; ~i; --i) if(fa[i][x] != fa[i][y]) x = fa[i][x], y = fa[i][y];
	return fa[0][x];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	srand(time(0));
	rep(i, 1, N) b[i] = (1ll*rand()<<32)^(1ll*rand()<<16)^rand(), pre[i] = b[i] ^ pre[i-1];
	int T; cin >> T;
	while(T--) {
		///
		cin >> n >> m;
		///init
		fill_n(g+1, n, vi());
		cntn = 0;
		///read
		rep(i, 1, n+1) cin >> a[i];
		rep(i, 1, n) {
			int u, v;
			cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}
		///solve
		dfs(1, 0);
		while(m--) {
			int x, y;
			cin >> x >> y;
			int z = lca(x, y);
			int l = 1, r = 200001;
			int t1 = rt[x], t2 = rt[y], t3 = rt[z], t4 = rt[fa[0][z]];
			while(l < r) {
				int mid = l+r>>1;
				if((sum[ls[t1]] ^ sum[ls[t2]] ^ sum[ls[t3]] ^ sum[ls[t4]]) != (pre[mid] ^ pre[l-1])) {
					r = mid;
					t1 = ls[t1];
					t2 = ls[t2];
					t3 = ls[t3];
					t4 = ls[t4];
				} else {
					l = mid+1;
					t1 = rs[t1];
					t2 = rs[t2];
					t3 = rs[t3];
					t4 = rs[t4];
				}
			}
			cout << l << endl;
		}
	}
	return 0;
}
