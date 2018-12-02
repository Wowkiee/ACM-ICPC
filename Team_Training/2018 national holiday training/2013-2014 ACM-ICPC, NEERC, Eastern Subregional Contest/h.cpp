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

const int N = 1010;

int n, x, y;
int m[2];
int a[2][N];
vi g[N];

namespace MaxMatch {
	const int N = ::N;
	int link[N], vis[N];
	int dfs(int c) {
		for(auto t : g[c]) {
			if(!vis[t]) {
				vis[t] = 1;
				if(link[t] == -1 || dfs(link[t])) return link[t] = c, 1;
			}
		}
		return 0;
	}
	int solve(int n, int m) {
		fill_n(link, m, -1);
		int ret = 0;
		rep(i, 0, n) {
			memset(vis, 0, m * sizeof(int));
			ret += dfs(i);
		}
		return ret;
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> x >> y >> n;
	rep(i, 0, n) {
		int t, d;
		cin >> t >> d;
		a[d][m[d]++] = t;
	}
	rep(i, 0, m[0]) rep(j, 0, m[1]) if(a[1][j] >= a[0][i]) {
		int t = a[1][j] - a[0][i];
		if(t >= x || t <= y) g[i].pb(j);
	}
	if(m[0] == m[1] && MaxMatch::solve(m[0], m[1]) == m[0]) {
		cout << "No reason" << endl;
		rep(i, 0, m[0]) cout << a[0][MaxMatch::link[i]] << " " << a[1][i] << endl;
	} else {
		cout << "Liar" << endl;
	}
	return 0;
}
