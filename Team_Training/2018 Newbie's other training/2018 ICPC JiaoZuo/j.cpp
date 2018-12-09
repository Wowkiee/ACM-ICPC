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
#define pw(a) (1ll << (a))
typedef long long ll;
typedef pair<int, int> pii;
typedef double db;
typedef vector<int> vi;

const int N = 303030, M = 1500 + 7;

int n, m;
int pre[3][M][M], val[N], tmp[N];
ll cnt[M][M], sum[2][M][M];
pair<pii, pii> a[N];

void gao(ll cnt[][M], int l, int r, int u, int v, ll c) {
	cnt[l][u] += c;
	cnt[l][v + 1] -= c;
	cnt[r + 1][u] -= c;
	cnt[r + 1][v + 1] += c;
}

ll Sqrt(ll x) {
	ll t = sqrt(x);
	for(ll i = max(0ll, t - 2); i < t + 3; ++i) if(i * i == x) return i;
	return 1;
}

int upd(int o, int w) {
	int res = val[o] + val[w];
	int xl = max(a[o].fi.fi, a[w].fi.fi) - 1;
	int xr = min(a[o].fi.se, a[w].fi.se);
	int yl = max(a[o].se.fi, a[w].se.fi) - 1;
	int yr = min(a[o].se.se, a[w].se.se);
	return res + pre[2][xr][yr] + pre[2][xl][yl] - pre[2][xr][yl] - pre[2][xl][yr];
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		rep(i, 0, m + 1) rep(j, 0, m + 1) {
			rep(o, 0, 3) pre[o][i][j] = 0;
			rep(o, 0, 2) sum[o][i][j] = 0;
			cnt[i][j] = 0;
		}
		rep(i, 1, n + 1) {
			int l, r, u, v;
			cin >> l >> r >> u >> v;
			a[i] = mp(mp(l, r), mp(u, v));
			gao(cnt, l, r, u, v, 1);
			gao(sum[0], l, r, u, v, i);
			gao(sum[1], l, r, u, v, i * 1ll * i);
		}
		rep(i, 1, m + 1) rep(j, 1, m + 1) {
			cnt[i][j] = cnt[i][j] + cnt[i][j - 1] + cnt[i - 1][j] - cnt[i - 1][j - 1];
			rep(o, 0, 2) sum[o][i][j] += sum[o][i - 1][j] + sum[o][i][j - 1] - sum[o][i - 1][j - 1];
			if(cnt[i][j] && cnt[i][j] < 3) pre[cnt[i][j]][i][j] = 1;
			if(cnt[i][j]) pre[0][i][j] = 1;
		}
		rep(i, 1, m + 1) rep(j, 1, m + 1) {
			rep(o, 0, 3) pre[o][i][j] += pre[o][i][j - 1] + pre[o][i - 1][j] - pre[o][i - 1][j - 1];
		}
		rep(i, 1, n + 1) {
			int xl = a[i].fi.fi - 1, xr = a[i].fi.se;
			int yl = a[i].se.fi - 1, yr = a[i].se.se;
			tmp[i] = val[i] = pre[1][xr][yr] + pre[1][xl][yl] - pre[1][xr][yl] - pre[1][xl][yr];
		}
		sort(val + 1, val + 1 + n);
		int ans = val[n] + val[n - 1];
		rep(i, 1, n + 1) val[i] = tmp[i];
		rep(i, 1, m + 1) rep(j, 1, m + 1) if(cnt[i][j] == 2) {
			ll t1 = sum[0][i][j], t2 = sum[1][i][j];
			ll det = Sqrt(2 * t2 - t1 * t1);
			ll x = (t1 + det) / 2, y = (t1 - det) / 2;
			ans = max(ans, upd(x, y));
		}
		cout << pre[0][m][m] - ans << endl;
	}
	return 0;
}
