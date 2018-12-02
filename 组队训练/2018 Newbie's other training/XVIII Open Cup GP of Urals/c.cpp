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
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 202020, SZ = 1000;

int n, k, q;
int col[N], cnt[N][2];
bool on[N];
map<pii, int> e;
vi v;
vi g[N];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> k >> q;
	rep(i, 1, n + 1) cin >> col[i];
	rep(i, 0, n + 1) {
		int u = col[i], v = col[i + 1];
		if(u == v) continue;
		++e[mp(u, v)];
		++e[mp(v, u)];
		g[u].pb(v), g[v].pb(u);
	}
	rep(i, 0, k + 1) if(sz(g[i]) >= SZ) v.pb(i);
	int ans = 0;
	rep(i, 0, q) {
		int x;
		cin >> x;
		on[x] ^= 1;
		if(sz(g[x]) < SZ) {
			rep(j, 0, sz(g[x])) {
				int y = g[x][j];
				(on[x] ^ on[y]) ? ++ans : --ans;
			}
		} else {
			ans += cnt[x][on[x] ^ 1];
			ans -= cnt[x][on[x]];
		}
		rep(j, 0, sz(v)) if(v[j] != x) {
			int u = v[j], t = e[mp(u, x)];
			cnt[u][on[x]] += t;
			cnt[u][on[x] ^ 1] -= t;
		}
		cout << (ans >> 1) << endl;
	}
	return 0;
}
