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

const int N = 10101;

int n, k, tim;
int vis[N], ans[N];
vector<pii> g[N];

int main() {
	freopen("generators.in", "r", stdin);
	freopen("generators.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> k;
	int res = 0;
	rep(i, 1, n + 1) {
		int x, a, b, c;
		cin >> x >> a >> b >> c;
		++tim;
		for(int j = 0; vis[x] != tim; ++j) {
			vis[x] = tim;
			g[i].pb(mp(-x, j));
			x = (1ll * a * x + b) % c;
		}
		sort(all(g[i]));
		res -= g[i][0].fi;
		ans[i] = g[i][0].se;
	}
	int p = 1, q = 0, det = N;
	if(res % k == 0) {
		rep(i, 1, n + 1) {
			int t;
			rep(j, 1, sz(g[i])) if((t = g[i][j].fi - g[i][0].fi) % k) {
				if(t < det) {
					p = i, q = j, det = t;
				}
			}
		}
		if(det == N) {
			cout << -1 << endl;
			return 0;
		}
		res -= det;
		ans[p] = g[p][q].se;
	}
	cout << res << endl;
	rep(i, 1, n + 1) cout << ans[i] << " \n"[i == n];
	return 0;
}
