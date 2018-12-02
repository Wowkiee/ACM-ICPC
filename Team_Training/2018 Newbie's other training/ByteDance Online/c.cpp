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
#define pw(a) (1ll << (a));
#define endl "\n"
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
//----
const int N = 1e6 + 7;
int sg[N], fl[N];
vi g[2][N], res;
void dfs1(int u) {
	fl[u] = sg[u] = 0;
	for(auto v : g[0][u])dfs1(v);
	for(auto v : g[1][u]) {
		dfs1(v);
		sg[u] ^= sg[v] + 1;
	}
}
void dfs2(int u, int val) {
	fl[u] = 1;
	for(auto v : g[0][u]) {
		if(((sg[v] + 1) ^ sg[u]) == val)res.pb(v);
		fl[v] = 1;
	}
	for(auto v : g[1][u]) {
		if(((sg[v] + 1) ^ sg[u]) == val)res.pb(v);
		else dfs2(v, (val ^ (sg[v] + 1) ^ sg[u]) - 1);
	}
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T; cin >> T; while(T--) {
		int n; cin >> n;
		rep(j, 0, 2)rep(i, 1, n + 1)g[j][i].clear(); res.clear();
		rep(i, 2, n + 1) {
			int a, b; cin >> a >> b;
			g[b & 1][a].pb(i);
		}
		dfs1(1);
		dfs2(1, 0);
		if(sg[1] == 0)rep(i, 1, n + 1)if(!fl[i])res.pb(i);
		sort(all(res));
		cout << sz(res) << endl;
		rep(i, 0, sz(res))cout << res[i] << " \n"[i == sz(res) - 1];
		if(!sz(res))cout << endl;
	}
	return 0;
}
