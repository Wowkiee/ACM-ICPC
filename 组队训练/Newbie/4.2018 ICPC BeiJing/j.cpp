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
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef __int128 ll;
typedef long double db;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

const int N = 2020, P = 998244353;
const db eps = 1e-10;

int n, m, pw3;
pii p[N], vec[N][N];
pair<int, int> val[N][N];

pii operator - (const pii &a, const pii &b) {
	return mp(a.fi - b.fi, a.se - b.se);
}
ll cross(const pii &a, const pii &b) {
	return a.fi * b.se - a.se * b.fi;
}
ll dot(const pii &a, const pii &b) {
	return a.fi * b.fi + a.se * b.se;
}
bool cmp(const pii &a, const pii &b) {
	int o = a > pii(0, 0), t = b > pii(0, 0);
	if(o != t) return o < t;
	return cross(a, b) > 0;
}
bool check(int i, int j, int r) {
	ll t = cross(vec[i][j], vec[i][r]);
	if(t > 0) return 1;
	if(t < 0) return 0;
	return dot(vec[i][j], vec[i][r]) > 0;
}
void add(int &a, int b) {
	if((a += b) >= P) a -= P;
}
void sub(int &a, int b) {
	if((a -= b) < 0) a += P;
}
int mul(int a, int b) {
	return 1ll * a * b % P;
}
int kpow(int a, int b) {
	int r = 1;
	while(b) {
		if(b & 1) r = mul(r, a);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}
bool che(const pii &a, const pii &b) {
	if(cross(a, b)) return 1;
	return dot(a, b) < 0;
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T;
	cin >> T;
	pw3 = kpow(3, P - 2);
	while(T--) {
		cin >> n;
		rep(i, 0, n) {
			long long x, y;
			cin >> x >> y;
			p[i] = mp(x, y);
		}
		m = n - 1;
		rep(i, 0, n) rep(j, 0, n) if(j != i) vec[i][j - (j > i)] = p[j] - p[i];
		rep(i, 0, n) sort(vec[i], vec[i] + m, cmp);
		rep(i, 0, n) rep(j, 0, m) {
			auto t = vec[i][j];
			t.fi %= P, t.se %= P;
			if(t.fi < 0) t.fi += P;
			if(t.se < 0) t.se += P;
			val[i][j] = t;
		}
		int tot = 0, ans = 0;
		rep(i, 0, n) {
			int l = 0, r = 0, c = 0, cnt = 0;
			int sumx = 0, sumy = 0, sx = 0, sy = 0;
			rep(j, 0, m) {
				if(j == 0 || che(vec[i][j], vec[i][j - 1])) while(c < m && check(i, j, r)) {
					++cnt;
					++c;
					add(sumx, val[i][r].fi);
					add(sumy, val[i][r].se);
					add(sx, val[i][r].fi);
					add(sy, val[i][r].se);
					r = (r + 1) % m;
				}
				while(cnt && dot(vec[i][j], vec[i][l]) > 0) {
					--cnt;
					sub(sx, val[i][l].fi);
					sub(sy, val[i][l].se);
					l = (l + 1) % m;
				}
				add(tot, mul(val[i][j].fi, sumy));
				sub(tot, mul(val[i][j].se, sumx));
				add(ans, mul(val[i][j].fi, sy));
				sub(ans, mul(val[i][j].se, sx));
				--c;
				sub(sumx, val[i][j].fi);
				sub(sumy, val[i][j].se);
			}
		}
		tot = mul(tot, pw3);
		sub(tot, ans);
		cout << (int)tot << endl;
	}
	return 0;
}
