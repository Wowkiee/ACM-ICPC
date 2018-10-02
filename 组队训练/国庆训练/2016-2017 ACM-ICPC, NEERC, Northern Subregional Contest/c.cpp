#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(x) cout << #x << " = " << x << " "
#define de(x) cout << #x << " = " << x << endl
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 7;
struct node{
	int x, y, i;
}a[N];

int n, x, y; 
vi g[N];

namespace SCC{
	const int N  = 1e5 + 10;
	int siz[N], dfn[N], low[N], id[N], st[N], _st, _, cc;
	bool vis[N];
	void dfs(int c, vi g[]){
		dfn[c] = low[c] = ++cc;
		st[_st++] = c;
		for (auto t : g[c]) 
				if (!dfn[t]) 
					dfs(t, g), low[c] = min(low[c], low[t]);
				else if (!id[t]) 
					low[c] = min(low[c], dfn[t]);
		if (low[c] == dfn[c]) {
			++_;
			do{id[st[--_st]] = _;} while (st[_st] != c);
		}
	}
	vi ng[N];
	int du[N], rt;
	void dfs2(int u) {
		vis[u] = 1;
		for (auto v : ng[u]) {
			if (!vis[v]) {
				dfs2(v);
				siz[u] += siz[v];
			}
		}	
	}

	int solve(int n, vi g[]){
		fill_n(dfn, n, cc = 0);
		fill_n(low, n, _st = 0);
		fill_n(id, n, _ = 0);
		rep(i, 0, n) if(!dfn[i]) dfs(i, g);
		rep(i, 0, n) --id[i], siz[id[i]]++;
		fill_n(ng, _, vi());
		rep(i, 0, n) for (auto j : g[i]) if(id[i] != id[j]) ng[id[i]].pb(id[j]), du[id[j]]++;
		rep(i, 0, _) if (du[i] == 0) rt = i;
		dfs2(rt);
		rep(i, 0, n) cout << siz[id[i]] - 1 << endl;
		return _;
	}
}

bool cmp1(node a, node b) {return a.x < b.x;}
bool cmp2(node a, node b) {return a.y < b.y;}

int main() {
	freopen("codecoder.in","r",stdin);
	freopen("codecoder.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(i, 0, n) {
		cin >> x >> y;
		a[i] = {x, y, i};
	}
	sort(a, a+n, cmp1);
	rep(i, 0, n-1) g[a[i+1].i].pb(a[i].i);
	sort(a, a+n, cmp2);
	rep(i, 0, n-1) g[a[i+1].i].pb(a[i].i);
	SCC :: solve(n, g);
	return 0;
}
