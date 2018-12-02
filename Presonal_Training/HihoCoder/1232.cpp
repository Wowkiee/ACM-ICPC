#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double db;

const int N = 101010;

int n, m;
int pre[2][22][N], dep[2][N];

int solve(int u, int v) {
	while(u != v) {
		for(int i = 21; ~i; --i) {
			if(dep[pre[0][i][u]] > dep[v]) u = pre[0][i][u];
			if(dep[u] < dep[pre[1][i][v]]) v = pre[1][i][v];
		}
		if(u > v) u = pre[0][0][u];
		else if(u < v) v = pre[1][0][v];
	}
	return u;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	while(cin >> n >> m) {
		memset(pre, 0, sizeof(pre));
		memset(dep, 0, sizeof(dep));
		rep(o, 0, 2) {
			rep(i, 2, n + 1) cin >> pre[o][0][i];
			rep(i, 1, n + 1) {
				dep[o][i] = dep[o][pre[o][0][i]] + 1;
				for(int j = 0; pre[o][j][i]; ++j) {
					pre[o][j + 1][i] = pre[o][j][pre[o][j][i]];
				}
			}
		}
		int x = 0;
		while(m--) {
			int u, v;
			cin >> u >> v;
			u = (u + x) % n + 1;
			v = (v + x) % n + 1;
			x = solve(u, v);
			cout << x << " " << dep[0][u] - dep[0][x] + 1 << " " << dep[1][v] - dep[1][x] + 1 << endl;
		}
	}
	return 0;
}
