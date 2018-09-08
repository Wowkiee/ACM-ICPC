#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 101010, SZ = 150;

int n, q, top;
int dep[N], dfn[N], st[N], ed[N], B[N], cnt[N];
ll ans[N], f[N], add[N], s[N];
vi g[N];
pii Q[N];
vector<pii> v[N];

void dfs(int u, int fa) {
	dfn[++top] = u;
	st[u] = top;
	for(auto v : g[u]) if(v != fa) {
		dep[v] = dep[u] + 1;
		dfs(v, u);
	}
	ed[u] = top;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> q;
	rep(i, 1, n) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v), g[v].pb(u);
	}
	dfs(1, 0);
	rep(i, 0, q) B[i] = i / SZ;
	//rep(i, 1, n+1) d[i] = dep[dfn[i]];

	rep(i, 0, q) {
		int t, u;
		cin >> t >> u;
		if(t == 1) {
			int x;
			cin >> x;
			add[u] += x;
			ans[i] = -1;
			Q[i] = mp(u, x);
		} else {
			ans[i] = s[ed[u]] - s[st[u] - 1];
			for(int j = i - 1; j >= 0 && B[j] == B[i]; --j) if(ans[j] == -1) {
				int t = j + 1;
				v[st[u]-1].pb({-t, i});
				v[ed[u]].pb({t, i});
			}
		}
		if(i < q - 1 && B[i] != B[i+1]) {
			rep(i, 1, n+1) s[i] = add[dep[dfn[i]]] + s[i-1];
		} 
	}
	rep(i, 1, top+1) {
		++cnt[dep[dfn[i]]];
		for(auto u : v[i]) {
			int j = abs(u.fi) - 1;
			int x = Q[j].fi, y = Q[j].se;
			if(u.fi < 0) y = -y;
			ans[u.se] += 1ll * cnt[x] * y;
		}
	}
	rep(i, 0, q) if(~ans[i]) cout << ans[i] << endl;
	return 0;
}
