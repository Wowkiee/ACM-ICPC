#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define endl "\n"
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 4040, M = 1010101, inf = M;

int n, m, st, ed;
int dis[M];
int dx[] = {-1, -1, 0, 0, 1, 1};
int dy[2][6] = {-1, 0, -1, 1, -1, 0, 0, 1, -1, 1, 0, 1};
int da[] = {-1, 1, -2, 2, -1, 1};
int db[] = {-3, -3, 0, 0, 3, 3};
string s[N];
vi g[M];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		rep(i, 0, n * m) g[i].clear(), dis[i] = inf;
		getline(cin, s[0]);
		rep(i, 0, 4 * n + 3) getline(cin, s[i]);
		swap(n, m);
		rep(x, 0, n) rep(y, 0, m) {
			int a = 4 * y + 2 + 2 * (x & 1);
			int b = 6 * x + 4;
			if(s[a][b] == 'S') st = x * m + y;
			if(s[a][b] == 'T') ed = x * m + y;
			rep(o, 0, 6) {
				int nx = x + dx[o];
				int ny = y + dy[x & 1][o];
				if(0 <= nx && nx < n && 0 <= ny && ny < m) {
					int na = a + da[o];
					int nb = b + db[o];
					if(s[na][nb] == ' ') {
						int u = x * m + y, v = nx * m + ny;
						g[u].pb(v);
				//		dd(u), de(v);
					}
				}
			}
		}
		vi q;
		q.pb(st);
		dis[st] = 1;
		rep(i, 0, sz(q)) {
			int u = q[i];
			for(auto v : g[u]) if(dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				q.pb(v);
			}
		}
		int ans = dis[ed];
		if(ans == inf) ans = -1;
		cout << ans << endl;
	}
	return 0;
}
