#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(a) cout << #a << " = " << a << " "
#define de(a) cout << #a << " = " << a << endl
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;

const int N = 1e5 + 7;
const int P = 1e9 + 7;
int jc[N], inv[N], n, ans, siz[N], m, u, v, w, s[N], p[3000][3000];
vector<pii> g[N];

int add(int a, int b) { return (a + b) % P;}
int mul(int a, int b) { return 1ll * a * b % P;}
int sub(int a, int b) { return (a >= b ? a - b : a - b + P);}
int kpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}


int C(int n, int m) {
	if (m < 0 || m > n) return 0;
	return 1ll * jc[n] * inv[m] % P * inv[n - m] % P;
}

void dfs(int u, int fa) {
	siz[u] = 1;
	rep(i, 0, sz(g[u])) if (g[u][i].fi != fa){
		int v = g[u][i].fi, w = g[u][i].se;
		dfs(v, u);
		siz[u] += siz[v];
		rep(j, 0, m+1) {
			//s[j] = mul(kpow(siz[v], j), kpow(n - siz[v], m - j));
			s[j] = mul(p[siz[v]][j], p[n-siz[v]][m-j]);
			s[j] = mul(s[j], C(m, j));
			if (j > 0) s[j] = add(s[j], s[j-1]);
		}
		rep(a, 0, m) {
			int ta = a > 0 ? sub(s[a], s[a-1]) : s[0];
			int tb = s[m - a - 1];
			ans = add(ans, mul(2, mul(mul(ta, tb), mul(a, w))));
		}
		/*rep(a, 0, m) {
			int ta = sub(s[a], s[a-1]);
			int tb = s[m - a - 1];
			ans = add(ans, mul(mul(ta, tb), mul(a, w)));
		}*/
		rep(j, 0, m+1) {
			//s[j] = mul(kpow(n - siz[v], j), kpow(siz[v], m - j));
			s[j] = mul(p[n-siz[v]][j], p[siz[v]][m-j]);
			s[j] = mul(s[j], C(m, j));
			if (j > 0) s[j] = add(s[j], s[j-1]);
		}
		rep(a, 0, m+1) {
			int ta = a > 0 ? sub(s[a], s[a-1]) : s[0];
			int tb = s[m - a];
			ans = add(ans, mul(2, mul(mul(ta, tb), mul(a, w))));
		}
		/*rep(a, 0, m+1) {
			int ta = sub(s[a], s[a-1]);
			int tb = s[m - a];
			ans = add(ans, mul(mul(ta, tb), mul(a, w)));
		}*/


	/*	rep(a, 0, m+1)
			rep(b, 0, m+1) {
				int cnt = min(a, m - b) + min(m - a, b);
				de(cnt);
				int t1 = mul(cal(siz[v], a), cal(siz[v], b));
				int t2 = mul(cal(n - siz[v], m - a), cal(n - siz[v], m - b));
				t1 = mul(t1, t2);
				t1 = mul(t1, C(m, a));
				t1 = mul(t1, C(m, b));
				ans = add(ans, mul(mul(cnt, w), t1)); 
			}*/
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m;
	jc[0] = 1;
	rep(i, 1, N) jc[i] = mul(jc[i-1], i);
	inv[N-1] = kpow(jc[N-1], P-2);
	per(i, 0, N-1) inv[i] = mul(inv[i+1], i+1);
	rep(i, 1, n+1) {
		p[i][0] = 1;
		rep(j, 1, m+1) {
			p[i][j] = mul(p[i][j-1], i);
		}
	}
	rep(i, 1, n) {
		cin >> u >> v >> w;
		g[u].pb(mp(v, w));
		g[v].pb(mp(u, w));
	}
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}
