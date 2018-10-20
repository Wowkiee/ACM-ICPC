#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(c) cout << #c << " = " << c << endl
#define dd(c) cout << #c << " = " << c << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T>
struct Dinic{
	const static int N = 10101, M = N * 10;
	int s, t, n, h[N], cur[N], level[N], q[N], e, ne[M], to[M];
	T cap[M], flow;
	void liu(int u, int v, T w) {to[e] = v;ne[e] = h[u]; cap[e] = w;h[u] = e++;}
	void link(int u, int v, T w) {liu(u, v, w);liu(v, u, 0);}
	void ini(int _n = N) {fill(h, h+(n = _n), -1); e = 0;}
	bool bfs(){
		int L = 0, R = 0;
		fill(level, level + n, -1);
		level[q[R++] = s] = 0;
		while ( L < R && level[t] == -1) {
			int c = q[L++];
			for (int k = h[c];~k;k = ne[k]) if (cap[k] > 0 && level[to[k]] == -1) 
				level[q[R++] = to[k]] = level[c] + 1; 
		}
		return ~level[t];
	}
	T dfs(int c, T mx) {
		if (c == t) return mx;
		T ret = 0;
		for (int &k = cur[c]; ~k; k = ne[k]){
			if (level[to[k]] == level[c] + 1 && cap[k] > 0) {
				T flow = dfs(to[k], min(mx, cap[k]));
				ret += flow; cap[k] -= flow, cap[k^1] += flow;mx -= flow;
				if (!mx) return ret;
			}
		}
		level[c] = -1;
		return ret;
	}
	T run(int _s, int _t) {
		s = _s; t = _t;
		flow = 0;
		while (bfs()) {
			copy(h, h + n, cur);
			flow += dfs(s, ~0U >> 1);
		}
		return flow;
	}
};

Dinic<int> G;

const int N = 1005;
int du[N], ans[N], tid, n, m, k, a[N], b[N], s, t, sum, T, p;
vi tmp[N];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n >> m >> k;
		G.ini(n + m + 10);
		s = n + m + 1; t = s + 1;
		rep(i, 1, n+1) du[i] = 0;
		rep(i, 1, m+1) {
			cin >> a[i] >> b[i];
			du[a[i]]++;
			du[b[i]]++;
		}
		sum = 0;
		rep(i, 1, m+1) {
			G.link(a[i], i + n, 1);
			G.link(b[i], i + n, 1);
		}
		rep(i, 1, n+1) if (du[i] > k) G.link(s, i, (du[i] - k) * 2), sum += (du[i] - k) * 2;
		rep(i, 1, m+1) G.link(i + n, t, 1);
		rep(i, 1, m+1) ans[i] = 0;
		int flow = G.run(s, t);	
		if (flow == sum) {
			tid = 0;
			for (int i = 0; i < m * 4; i += 2) if (G.cap[i] == 0) {
				p = i / 4 + 1;
				if (i % 4 == 0) tmp[a[p]].pb(p);else tmp[b[p]].pb(p);
			}
			rep(i, 1, n+1) {
				for (int j = 0; j < sz(tmp[i]); j += 2) 
					ans[tmp[i][j]] = ans[tmp[i][j+1]] = ++tid;
				tmp[i].clear();	
			}
			rep(i, 1, m+1) if (!ans[i]) ans[i] = ++tid;
		}
		rep(i, 1, m) cout << ans[i] << " ";
		cout << ans[m] << endl;
	} 
	return 0;
}
