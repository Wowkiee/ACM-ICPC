#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
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
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
const int N = 3e3 + 7, M = 5e1 + 7, K = 3e4 + 7, T = 1e4 + 7;
const db eps = 1e-8;
bool post[N];
db sc[N], ac[T][M], tab[N][M];
vector<pii> v[T];
pii all[K];
int n, m, k, t, sz = 0;
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//std::ios::sync_with_stdio(0);
	//std::cin.tie(0);
	scanf("%d%d%d%d", &n, &m, &k, &t);
	rep(i, 1, n + 1) {
		int a; scanf("%d",&a);
		sc[i] = a;
	}
	rep(i, 0, k) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		v[c].pb(mp(a, b));
	}
	rep(i, 1, t + 1)rep(j, 1, m) scanf("%lf", &ac[i][j]);
	int pos = 1;
	db ans = 0;
	rep(cas, 1, t + 1) {
		rep(i, 0, sz(v[cas])) {
			int a = v[cas][i].fi, b = v[cas][i].se;
			if(b == m)post[a] = true;
			else {
				tab[a][b] = 1;
				all[sz++] = v[cas][i];
			}
		}
		db _ans = 0;
		rep(i, 1, n + 1)if(post[i])_ans += sc[i];
		de(_ans);
		if(_ans - ans > eps)ans = _ans, pos = cas;
		rep(i, 0, sz) {
			int a = all[i].fi, b = all[i].se;
			//sc[a] -= (tab[a][b] - ac[cas][b]) / tab[a][b]
			sc[a] /= tab[a][b];
			tab[a][b] -= ac[cas][b];
			sc[a] *= tab[a][b];
		}
	}
	printf("%.10lf %d\n", ans, pos);
	return 0;
}
