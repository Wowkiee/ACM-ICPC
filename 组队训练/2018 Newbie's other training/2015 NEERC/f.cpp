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
typedef long double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
//----
typedef pair<int, db> pid;
const int N = 2100;
db dis[N], One = 1.0;
int x[N], y[N], m, n, last[N], vis[N];
vector<pid> V[N];
void spfa() {
	queue<int> Q;Q.push(2 * n);vis[2 * n] = 1;
	dis[2 * n] = 0;
	while(!Q.empty()) {
		int u = Q.front();Q.pop();
		vis[u] = 0;
		rep(i, 0, sz(V[u])) {
			pid nxt = V[u][i];
			if(max(dis[u], nxt.se) < dis[nxt.fi]) {
				dis[nxt.fi] = max(dis[u], nxt.se);
				last[nxt.fi] = u;
				if(!vis[nxt.fi])Q.push(nxt.fi);
			}
		}
	}
}
void print(int a, int b) {
	cout << setiosflags(ios::fixed);
	cout << setprecision(3);
	if(a == n * 2 && b == n * 2 + 1)cout << m / 2.0 << " " << 0 << endl;
	else if(a == n * 2)cout << x[b / 2] / 2.0 << " " << y[b / 2] << endl;
	else if(b == n * 2 + 1)cout << (m + x[a / 2]) / 2.0 << " " << y[a / 2] << endl;
	else cout << (x[a / 2] + x[b / 2]) / 2.0 << " " << (y[a / 2] + y[b / 2]) / 2.0 <<endl;
}
int main() {
	freopen("froggy.in", "r", stdin);
	freopen("froggy.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> m >> n;
	rep(i, 0, n)cin >> x[i] >> y[i];
	rep(i, 0, n) {
		V[n * 2].pb(mp(i * 2, x[i]));
		V[n * 2].pb(mp(i * 2 + 1, x[i] / 2.0));
		V[i * 2].pb(mp(n * 2 + 1, (m - x[i]) / 2.0));
		V[i * 2 + 1].pb(mp(n * 2 + 1, m - x[i]));
	}
	rep(i, 0, n)rep(j, i + 1, n) {
		db dis = sqrtl(One * (x[i] - x[j]) * (x[i] - x[j]) + One * (y[i] - y[j]) * (y[i] - y[j]));
		V[i * 2].pb(mp(j * 2, dis));V[j * 2].pb(mp(i * 2, dis));
		V[i * 2].pb(mp(j * 2 + 1, dis / 2.0));V[j * 2].pb(mp(i * 2 + 1, dis / 2.0));
		V[i * 2 + 1].pb(mp(j * 2 + 1, dis));V[j * 2 + 1].pb(mp(i * 2 + 1, dis));
	}
	V[2 * n].pb(mp(2 * n + 1, m / 2.0));
	rep(i, 0, 2 * n + 2)dis[i] = 1e12;
	spfa();
	int now = 2 * n + 1;
	while(now != 2 * n) {
		if(now % 2 == 1 && last[now] % 2 == 0)print(last[now], now);
		now = last[now];
	}
	return 0;
}
