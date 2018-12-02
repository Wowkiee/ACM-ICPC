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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 101010;

int n;
int a[N];
vi g[N];
pii e[N];

bool cmp(int i, int j) {
	return a[i] < a[j];
}

ll solve(int u, int v, int fu, int fv) {
	ll res = 1;
	int p = 0;
	for(auto c : g[u]) if(c != fu) {
		while(p < sz(g[v]) && a[g[v][p]] <= a[c]) ++p;
		for(int i = p - 1; i >= 0 && a[g[v][i]] == a[c]; --i) if(g[v][i] != fv) res += solve(c, g[v][i], u, v);
	}
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		///
		cin >> n;
		///init
		fill_n(g + 1, n, vi());
		///read
		rep(i, 1, n + 1) cin >> a[i];
		rep(i, 1, n) {
			int u, v;
			cin >> u >> v;
			e[i] = mp(u, v);
			g[u].pb(v);
			g[v].pb(u);
		}
		///solve
		rep(i, 1, n + 1) sort(g[i].begin(), g[i].end(), cmp);
		ll ans = n;
		rep(i, 1, n) if(a[e[i].fi] == a[e[i].se]) ans += solve(e[i].fi, e[i].se, e[i].se, e[i].fi);
		rep(i, 1, n + 1) {
			rep(j, 0, sz(g[i])) {
				for(int k = j - 1; k >= 0 && a[g[i][j]] == a[g[i][k]]; --k) ans += solve(g[i][j], g[i][k], i, i);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
