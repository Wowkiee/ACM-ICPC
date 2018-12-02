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

const int N = 202020, SZ = 633;

int n, k, q;
int col[N], cnt[N][2], id[N], e[1010][1010];
bool on[N];
vi v;
vi g[N];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> k >> q;
	rep(i, 1, n + 1) cin >> col[i];
	rep(i, 0, n + 1) {
		int u = col[i], v = col[i + 1];
		if(u != v) g[u].pb(v), g[v].pb(u);
	}
	v.pb(-1);
	rep(i, 0, k + 1) if(sz(g[i]) >= SZ) v.pb(i), id[i] = sz(v) - 1, cnt[i][0] = sz(g[i]);
	memset(e, 0, sizeof(e));
	rep(i, 0, n + 1) {
		int u = col[i], v = col[i + 1];
		if(u != v && id[u] && id[v]) {
			++e[id[u]][id[v]];
			++e[id[v]][id[u]];
		}
	}
	int ans = 0;
	rep(i, 0, q) {
		int x;
		cin >> x;
		on[x] ^= 1;
		if(sz(g[x]) < SZ) {
			rep(j, 0, sz(g[x])) {
				int y = g[x][j];
				bool t = (on[x] ^ on[y]);
				t ? ++ans : --ans;
				if(id[y]) ++cnt[y][on[x]], --cnt[y][on[x] ^ 1];
			}
		} else {
			ans += cnt[x][on[x] ^ 1];
			ans -= cnt[x][on[x]];
			rep(j, 1, sz(v)) if(id[x] != j) {
				int y = v[j], c = e[id[x]][j];
				cnt[y][on[x]] += c, cnt[y][on[x] ^ 1] -= c;
			}
		}
		cout << (ans >> 1) << endl;
	}
	return 0;
}
