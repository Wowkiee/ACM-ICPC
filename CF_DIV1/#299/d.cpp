#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 2020, M = 101010;

int n, m, st, ed, A, B;
int p[N], cnt[N][N], t[N][N];
ll dis[2][N], w[N][N], s[N][N], f[2][N][N], Q[2][N], F[2][N], T[2][N];
bool vis[N];
vector<pii> g[M];

void spfa(int st, ll dis[], int &len) {
	memset(vis, 0, sizeof(vis));
	vi q;
	q.pb(st);
	dis[st] = 0;
	vis[st] = 1;
	rep(i, 0, sz(q)) {
		int u = q[i];
		vis[u] = 0;
		for(auto v : g[u]) {
			if(dis[v.fi] > dis[u] + v.se) {
				dis[v.fi] = dis[u] + v.se;
				if(!vis[v.fi]) {
					vis[v.fi] = 1;
					q.pb(v.fi);
				}
			}
		}
	}
	vector<ll> V;
	rep(i, 1, n+1) V.pb(dis[i]);
	sort(all(V));
	V.erase(unique(all(V)), V.end());
	rep(i, 1, n+1) dis[i] = lower_bound(all(V), dis[i]) - V.begin() + 1;
	len = sz(V);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	///read
	cin >> n >> m >> st >> ed;
	rep(i, 1, n+1) cin >> p[i];
	rep(i, 1, m+1) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].pb(mp(v, w));
		g[v].pb(mp(u, w));
	}
	///get dis
	memset(dis, 0x3f, sizeof(dis));
	spfa(st, dis[0], A);
	spfa(ed, dis[1], B);
	///solve
	rep(i, 1, n+1) {
		int x = dis[0][i], y = dis[1][i];
		++cnt[x][y];
		w[x][y] += p[i];
	}
	for(int i = A; i; --i) {
		for(int j = B; j; --j) {
			s[i][j] = s[i+1][j] + s[i][j+1] - s[i+1][j+1] + w[i][j];
			t[i][j] = t[i+1][j] + t[i][j+1] - t[i+1][j+1] + cnt[i][j];
		}
	}
	memset(Q, 0x3f, sizeof(Q));
	memset(F, 0x3f, sizeof(Q));
	memset(T, 0x3f, sizeof(Q));
	for(int i = A; i; --i) {
		for(int j = B; j; --j) {
			if(T[0][j] < t[i][j]) Q[0][j] = min(Q[0][j], F[0][j]);
			if(T[1][i] < t[i][j]) Q[1][i] = min(Q[1][i], F[1][i]);
			f[0][i][j] = max(s[i][j], s[i][j] - Q[0][j]);
			f[1][i][j] = max(s[i][j], s[i][j] - Q[1][i]);
			if(F[1][i] > f[0][i][j] + s[i][j]) {
				F[1][i] = f[0][i][j] + s[i][j];
				T[1][i] = t[i][j];
			}
			if(F[0][j] > f[1][i][j] + s[i][j]) {
				F[0][j] = f[1][i][j] + s[i][j];
				T[0][j] = t[i][j];
			}
		}
	}
	ll ans = f[0][1][1];
	if(ans > 0) cout << "Break a heart" << endl;
	else if(ans == 0) cout << "Flowers" << endl;
	else cout << "Cry" << endl;
	return 0;
}
