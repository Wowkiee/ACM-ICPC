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
typedef __int128 ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 101010;

int n;
int sz[N];
ll ans;
ll f[N];
vector<pii> g[N];

void dfs(int u, int fa) {
	sz[u] = 1, f[u] = 0;
	for(auto v : g[u]) if(v.fi != fa) {
		dfs(v.fi, u);
		sz[u] += sz[v.fi];
		f[u] += f[v.fi] + 1ll * v.se * sz[v.fi];
	}
}
void dfs2(int u, int fa) {
	for(auto v : g[u]) if(v.fi != fa) {
		int A = sz[v.fi], B = sz[1] - A;
		f[v.fi] = f[u] - 1ll * A * v.se + 1ll * B * v.se;
		dfs2(v.fi, u);
	}
}

void print() {
	vi res;
	while(ans) {
		res.pb(ans%10);
		ans/=10;
	}
	reverse(all(res));
	for(auto u : res) cout << u;
	cout << endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	rep(ca, 1, T+1) {
		///
		cin >> n;
		///init
		fill_n(g+1, n, vector<pii>());
		///read
		rep(i, 1, n) {
			int u, v, w;
			cin >> u >> v >> w;
			g[u].pb(mp(v, w));
			g[v].pb(mp(u, w));
		}
		///solve
		dfs(1, 0);
		dfs2(1, 0);
		sort(f+1, f+1+n);
		ans = 0;
		rep(i, 1, n+1) ans += f[i] * (n-i);
		cout << "Case #" << ca << ": ";
		print();
	}
	return 0;
}
