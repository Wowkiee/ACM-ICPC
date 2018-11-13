#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ull<<(a))
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 50505;

int n, m, q;
ll s[1 << 10];
ull bs[N][1 << 10];
vi g[N];

namespace SCC {
	const int N = ::N;
	int dfn[N], low[N], id[N], st[N], _st, _, cc, out[N];
	void dfs(int c,vi g[]){
		dfn[c]=low[c]=++cc;
		st[_st++]=c;
		for(auto t:g[c])
			if(!dfn[t])
				dfs(t,g),low[c]=min(low[c],low[t]);
			else if(!id[t])
				low[c] =min(low[c],dfn[t]);
		if(low[c]==dfn[c]){
			++_;
			do{id[st[--_st]]=_;}while(st[_st]!=c);
		}
	}
	vi ng[N];
	void solve(int n, vi g[]) {
		memset(bs, 0, sizeof(bs));
		memset(s, 0, sizeof(s));
		fill_n(dfn + 1, n, cc = 0);
		fill_n(low + 1, n, _st = 0);
		fill_n(id + 1, n, _ = 0);
		fill_n(out + 1, n, 0);
		rep(i, 1, n + 1) if(!dfn[i]) dfs(i, g);
		fill_n(ng + 1, _, vi());
		rep(i, 1, n + 1) for(auto j : g[i]) if(id[i] != id[j]) ng[id[j]].pb(id[i]), out[id[i]]++;
		rep(i, 1, n + 1) bs[id[i]][i >> 6] |= (1ull << (i & 63));
		vi q;
		rep(i, 1, _ + 1) if(out[i] == 0) q.pb(i);
		rep(i, 0, sz(q)) {
			int v = q[i];
			for(auto u : ng[v]) {
				--out[u];
				rep(i, 0, 1 << 10) bs[u][i] |= bs[v][i];
				if(out[u] == 0) q.pb(u);
			}
		}
		rep(i, 1, n + 1) {
			rep(j, 0, 1 << 10) {
				s[j] += __builtin_popcountll(bs[id[i]][(i >> 6) ^ j]);
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> n >> m >> q;
		rep(i, 1, n + 1) g[i].clear();
		rep(i, 1, m + 1) {
			int u, v;
			cin >> u >> v;
			g[u].pb(v);
		}
		SCC::solve(n, g);
		while(q--) {
			int k;cin >> k;
			int ans = pw(10) - 1;
			while(ans && s[ans] < k) k -= s[ans--];
			for(int i = pw(6) - 1; ~i; --i) {
				int t = 0;
				rep(u, 1, n + 1) {
					t += (bs[SCC::id[u]][(u >> 6) ^ ans] >> ((u & 63) ^ i) & 1);
				}
				if(t < k) k -= t;
				else {
					ans = (ans << 6 | i);
					break;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}
