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
#define endl "\n"
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;

const int K = 10000001, N = 6001;

int n, m, ca, tim;
int vis[N][N], val[N][N];
ll ans;
vector<pii> v[K];

void init() {
	for(int x = 0; x * x < K; ++x) {
		for(int y = 0; x * x + y * y < K; ++y) {
			int t = x * x + y * y;
			v[t].pb(mp(x, y));
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T;
	cin >> T;
	init();
	while(T--) {
		cout << "Case #" << ++ca << ":" << endl;
		cin >> n >> m;
		++tim;
		rep(i, 1, n + 1) {
			int x, y, w;
			cin >> x >> y >> w;
			val[x][y] = w;
			vis[x][y] = tim;
		}
		ans = 0;
		while(m--) {
			int o, x, y, k, w;
			cin >> o >> x >> y;
			x = (x + ans) % 6000 + 1;
			y = (y + ans) % 6000 + 1;
			if(o == 1) {
				cin >> w;
				vis[x][y] = tim;
				val[x][y] = w;
			} else if(o == 2) {
				vis[x][y] = tim - 1;
			} else if(o == 3) {
				cin >> k >> w;
				for(auto u : v[k]) {
					int dx = u.fi, dy = u.se;
					for(int i = (dx ? -1 : 1); i <= 1; i += 2) {
						for(int j = (dy ? -1 : 1); j <= 1; j += 2) {
							int nx = x + dx * i, ny = y + dy * j;
							if(1 <= nx && nx <= 6000 && 1 <= ny && ny <= 6000 && vis[nx][ny] == tim) val[nx][ny] += w;
						}
					}
				}
			} else {
				cin >> k;
				ans = 0;
				for(auto u : v[k]) {
					int dx = u.fi, dy = u.se;
					for(int i = (dx ? -1 : 1); i <= 1; i += 2) {
						for(int j = (dy ? -1 : 1); j <= 1; j += 2) {
							int nx = x + dx * i, ny = y + dy * j;
							if(1 <= nx && nx <= 6000 && 1 <= ny && ny <= 6000 && vis[nx][ny] == tim) ans += val[nx][ny];
						}
					}
				}
				cout << ans << endl;
			}
		}
	}
	return 0;
}
