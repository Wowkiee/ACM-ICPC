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
#define all(a) a.begin(), a.end()
#define pw(a) (1ll<<(a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 101010;

int n, m, top;
int sta[N];
bool vis[N];
vi g[N];

void dfs(int u) {
	sta[++top] = u;
	vis[u] = 1;
	if(top == n + 1) {
		rep(i, 1, top + 1) cout << sta[i] + 1 << " \n"[i == top];
		exit(0);
	}
	for(auto v : g[u]) {
		if(v == 0) {
			if(top == n) dfs(v);
		} else {
			if(!vis[v]) dfs(v);
		}
	}
	vis[u] = 0;
	--top;
}

namespace SCC {
	const int N = ::N;
	int dfn[N], low[N], id[N], st[N], _st, _, cc;
	void dfs(int c, vi g[]) {
		dfn[c] = low[c] = ++cc;
		st[_st++] = c;
		for(auto t : g[c]) {
			if(!dfn[t]) {
				dfs(t, g), low[c] = min(low[c], low[t]);
			} else if(!id[t]) {
				low[c] = min(low[c], dfn[t]);
			}
		}
		if(low[c] == dfn[c]) {
			++_;
			do{id[st[--_st]]=_;}while(st[_st]!=c);
		}
	}
	int solve(int n, vi g[]) {
		rep(i, 0, n) if(!dfn[i]) dfs(i, g);
		return _;
	}
}

int main() {
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 1, m + 1) {
		int u, v;
		cin >> u >> v;
		g[u - 1].pb(v - 1);
	}
	rep(i, 0, n) random_shuffle(all(g[i]));
	if(SCC::solve(n, g) > 1) {
		cout << "There is no route, Karl!" << endl;
		return 0;
	}
	dfs(0);
	cout << "There is no route, Karl!" << endl;
	return 0;
}
