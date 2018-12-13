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
#define pw(x) (1ll << (x))
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 2020, M = 55;

int n, m, s;
int id[N], mi[M][N], a[N], b[N], c[N], d[N];
ll inf;
ll dis[N];
char str[N];
vector<pii> g[N];

void gao(int dis[], int a, int b, int c, int d) {
	int p = 0;
	rep(i, 0, c) {
		dis[i] = ((a * i + b) % c) + d;
		if(dis[p] > dis[i]) p = i;
	}
	rep(i, 1, c) {
		int u = (p - i + 1 + c) % c, v = (p - i + c) % c;
		dis[v] = min(dis[v], dis[u] + 1);
	}
}

void dij() {
	memset(dis, 0x3f, sizeof(dis));
	inf = dis[0];
	dis[1] = s;
	priority_queue<pair<ll, int> > q;
	q.push(mp(-s, 1));
	while(!q.empty()) {
		pair<ll, int> u = q.top();q.pop();
		if(dis[u.se] != -u.fi) continue;
		rep(i, 0, sz(g[u.se])) {
			int v = g[u.se][i].fi, id = g[u.se][i].se;
			int w = mi[id][dis[u.se] % c[id]];
			if(dis[v] > dis[u.se] + w) {
				dis[v] = dis[u.se] + w;
				q.push(mp(-dis[v], v));
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m >> s;
	rep(i, 1, m + 1) {
		string o;
		cin >> o >> a[i] >> b[i] >> c[i] >> d[i];
		id[o[0]] = i;
		gao(mi[i], a[i], b[i], c[i], d[i]);
	}
	rep(i, 1, n + 1) {
		cin >> (str + 1);
		rep(j, 1, n + 1) if(str[j] != '.') g[i].pb(mp(j, id[str[j]]));
	}
	dij();
	ll ans = dis[n] - s;
	if(ans == inf - s) ans = -1;
	cout << ans << endl;
	return 0;
}
