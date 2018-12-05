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
#define endl "\n"
#define pw(a) (1ll << (a))
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;

const int N = 101010;

int n, ans, tot;
int p[N], w[N], cnt[N], c[N];
vi g[N];
unordered_map<int, int> num[N];

void dfs(int u) {
	num[u][w[u]]++;
	if(cnt[w[u]] == 1) c[u] = 1;
	for(auto v : g[u]) {
		dfs(v);
		ans = max(ans, sz(num[v]) + tot - c[v]);
		if(sz(num[u]) < sz(num[v])) swap(num[u], num[v]), swap(c[u], c[v]);
		for(auto t : num[v]) {
			num[u][t.fi] += t.se;
			if(num[u][t.fi] == cnt[t.fi]) ++c[u];
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(i, 2, n + 1) {
		cin >> p[i];
		g[p[i]].pb(i);
	}
	rep(i, 1, n + 1) cin >> w[i], cnt[w[i]]++;
	rep(i, 0, N) tot += (cnt[i] > 0);
	dfs(1);
	cout << ans << endl;
	return 0;
}
