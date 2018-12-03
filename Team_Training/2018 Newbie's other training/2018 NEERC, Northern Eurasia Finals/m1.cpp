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
#define pw(x) (1ll << (x))
#define all(x) x.begin(), x.end()
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
//----
const int N = 105;
namespace SCC {
	const int N = ::N;
	int dfn[N], low[N], id[N], st[N], _st, _, cc;
	void dfs(int c, vi g[]) {
		dfn[c] = low[c] = ++cc;
		st[_st++] = c;
		for(auto t : g[c])
			if(!dfn[t])
				dfs(t, g), low[c] = min(low[c], low[t]);
			else if(!id[t])
				low[c] = min(low[c], dfn[t]);
		if(low[c] == dfn[c]) {
			++_;
			do{id[st[--_st]] = _;}while(st[_st] != c);
		}
	}
	vi ng[N];
	int solve(int n, vi g[]) {
		fill_n(dfn, n, cc = 0);
		fill_n(low, n, _st = 0);
		fill_n(id, n, _ = 0);
		rep(i, 0, n)if(!dfn[i]) dfs(i, g);
		rep(i, 0, n)--id[i];
		fill_n(ng, _, vi());
		rep(i, 0, n)for(auto j : g[i])if(id[i] != id[j])ng[id[i]].pb(id[j]);
		return _;
	}
}
vi g[N];
int id[N];
char ma[N][N][N];
int cnt[N], top[N];
int pos[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n; cin >> n;
	rep(i, 0, n)rep(j, 0, n) {
		int a; cin >> a;
		if(a)g[i].pb(j);
	}
	int nn = SCC::solve(n, g);
	rep(i, 0, nn) {
		rep(j, 0, N)rep(k, 0, N)ma[i << 1][j][k] = '.';
		rep(j, 0, N)rep(k, 0, N)ma[i << 1 | 1][j][k] = '#';
	}
	queue<int> Q;
	rep(i, 0, nn)for(auto v : SCC::ng[i])id[v]++;
	rep(i, 0, nn)if(!id[i])Q.push(i);
	vi topo;
	int tot = 0;
	while(!Q.empty()) {
		int u = Q.front(); Q.pop();
		top[u] = sz(topo);
		topo.pb(u);
		for(auto v : SCC::ng[u]) {
			if(!--id[v])Q.push(v);
		}
	}
	rep(u, 0, nn) {
		for(auto v : SCC::ng[u]) {
			tot++;
			int a = top[u], b = top[v];
			rep(i, a, b) {
				int now = topo[i];
				int x, y;
				if(tot <= 40)x = 3, y = tot * 2 + 1;
				else x = 53, y = (tot - 40) * 2 + 1;
				if(i != a) {
					ma[now << 1][x][y] = '.';
					rep(j, 0, 4)ma[now << 1][x + pos[j][0]][y + pos[j][1]] = '#';
				}
				ma[now << 1 | 1][x][y] = '.';
				rep(j, 0, 4)ma[now << 1 | 1][x + pos[j][0]][y + pos[j][1]] = '#';
			}
		}
	}
	rep(i, 0, n) {
		int now = SCC::id[i];
		ma[now << 1][0][cnt[now]++] = i + 1 + '0';
	}
	cout << N << " " << N << " " << nn * 2 + 1 << endl;
	rep(i, 0, sz(topo)) {
		int now = topo[i];
		rep(j, 0, N)rep(k, 0, N) {
			cout << ma[now << 1][j][k];
			if(k == N - 1)cout << endl;
		}
		cout << endl;
		rep(j, 0, N)rep(k, 0, N) {
			cout << ma[now << 1 | 1][j][k];
			if(k == N - 1)cout << endl;
		}
		cout << endl;
	}
	rep(j, 0, N)rep(k, 0, N) {
		cout << '.';
		if(k == N - 1)cout << endl;
	}
	return 0;
}
