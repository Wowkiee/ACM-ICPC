#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(a) cout << #a << " = " << a << " "
#define de(a) cout << #a << " = " << a << endl
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;

const int N = 2020;

int n, m, L;
int id[N][N], val[N * N], pre[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<pii> v[N * N];
bool in[N][N], ans[N][N];
char s[N][N];
priority_queue<pii> q;

void dfs(int x, int y) {
	id[x][y] = L;
	v[L].pb(mp(x, y));
	rep(i, 0, 4) {
		int nx = x + dx[i], ny = y + dy[i];
		if(in[nx][ny] && s[nx][ny] == '#' && !id[nx][ny]) dfs(nx, ny);
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 1, n + 1) cin >> (s[i] + 1);
	rep(i, 1, n + 1) rep(j, 1, m + 1) in[i][j] = 1;
	rep(i, 1, n + 1) rep(j, 1, m + 1) if(s[i][j] == '#' && !id[i][j]) ++L, dfs(i, j);
	memset(val, 0x3f, sizeof(val));
	++n, ++L, val[L] = 0;
	q.push(mp(0, L));
	rep(j, 1, m + 1) s[n][j] = '#', id[n][j] = L, v[L].pb(mp(n, j));
	rep(j, 1, m + 1) {
		int p = 0;
		rep(i, 1, n + 1) {
			pre[i][j] = p;
			if(s[i][j] == '#') p = i;
		}
	}
	while(!q.empty()) {
		pii u = q.top();q.pop();
		if(val[u.se] != -u.fi) continue;
		rep(i, 0, sz(v[u.se])) {
			pii c = v[u.se][i];
			int x = c.fi, y = c.se, t = -u.fi;
			int nx = pre[x][y];
			if(id[nx][y] == id[x][y]) continue;
			t += x - nx - 1;
			if(val[id[nx][y]] > t) {
				val[id[nx][y]] = t;
				q.push(mp(-t, id[nx][y]));
			}
		}
	}
	rep(i, 1, n) rep(j, 1, m + 1) if(s[i][j] == '#') {
		ans[i + val[id[i][j]]][j] = 1;
	}
	rep(i, 1, n) {
		rep(j, 1, m + 1) cout << (ans[i][j] ? '#' : '.');
		cout << endl;
	}
	return 0;
}
