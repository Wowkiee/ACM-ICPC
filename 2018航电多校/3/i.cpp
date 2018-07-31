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

const int N = 102, P = 1e9+7;

int n, m, cntp;
int a[N], v[N], p2i[N][N][N], f[N][1515], g[N][N];
pair<pii, int> i2p[1515];

inline void init() {
	rep(i, 0, N) rep(j, i, N) g[i][j] = g[j][i] = __gcd(i, j);
}

inline int add(int x, int y) {
	int r = x + y;
	if(r >= P) r -= P;
	return r;
}
inline int mul(int x, int y) {
	return 1ll * x * y % P;
}
inline int kpow(int a, int b) {
	int r = 1;
	while(b) {
		if(b&1) r = mul(r, a);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	init();
	int T;
	cin >> T;
	while(T--) {
		///
		cin >> n >> m;
		///init
		cntp = 0;
		memset(f, 0, sizeof(f));
		///read
		rep(i, 1, n+1) cin >> a[i];
		rep(i, 1, m+1) cin >> v[i];
		///solve
		rep(x, 1, m+1) rep(y, 1, x+1) if(x % y == 0) rep(z, 1, y+1) if(y % z == 0) {
			p2i[x][y][z] = ++cntp;
			i2p[cntp] = mp(mp(x, y), z);
		}
		int m0 = kpow(m, P-2);
		f[0][0] = 1;
		rep(i, 0, n) rep(j, 0, cntp+1) if(f[i][j]) {
			int x = i2p[j].fi.fi, y = i2p[j].fi.se, z = i2p[j].se;
			if(a[i+1]) {
				int nj = p2i[a[i+1]][g[x][a[i+1]]][g[y][a[i+1]]];
				int c = i+1>=4 ? mul(f[i][j], v[g[z][a[i+1]]]) : f[i][j];
				f[i+1][nj] = add(f[i+1][nj], c);
			} else {
				rep(k, 1, m+1) {
					int nj = p2i[k][g[x][k]][g[y][k]];
					int c = i+1>=4 ? mul(f[i][j], mul(v[g[z][k]], m0)) : mul(f[i][j], m0);
					f[i+1][nj] = add(f[i+1][nj], c);
				}
			}
		}
		int ans = 0;
		rep(j, 1, cntp+1) ans = add(ans, f[n][j]);
		cout << ans << endl;
	}
	return 0;
}
