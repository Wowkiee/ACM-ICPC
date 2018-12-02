#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(x) (int)x.size()
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 101010;

int n, m;
int deg[N << 1], vis[N << 1];
bool ne[N << 1][2];
vi g[N << 1];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> n >> m;
	rep(i, 0, m) {
		int u, v;
		cin >> u >> v;
		g[v].pb(u + n);
		g[v + n].pb(u);
		++deg[u];
		++deg[u + n];
	}
	queue<int> q;
	set<int> s;
	rep(i, 1, n << 1 | 1) if(!deg[i]) {
		vis[i] = -1;
		q.push(i);
	}
	while(sz(s) || !q.empty()) {
		for(auto u : s) {
			if(vis[u] == 0) {
				vis[u] = -1;
				q.push(u);
			}
		}
		s.clear();
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			for(auto v : g[u]) if(vis[v] == 0) {
				--deg[v];
				ne[v][vis[u] == 1] = 1;
				if(v <= n) {
					if(deg[v] == 0) {
						if(ne[v][0]) vis[v] = 1;
						else vis[v] = -1;
						q.push(v);
					}
				} else {
					if(ne[v][0]) {
						vis[v] = 1;
						q.push(v);
					} else if(ne[v][1]) {
						if(deg[v] == 0) {
							vis[v] = -1;
							q.push(v);
						} else {
							s.insert(v);
						}
					}
				}
			}
		}
	}
	rep(i, 1, n << 1 | 1) {
		if(vis[i] == -1) cout << "L";
		else if(vis[i] == 0) cout << "D";
		else cout << "W";
		if(i == n || i == n * 2) cout << endl;
	}
	return 0;
}
