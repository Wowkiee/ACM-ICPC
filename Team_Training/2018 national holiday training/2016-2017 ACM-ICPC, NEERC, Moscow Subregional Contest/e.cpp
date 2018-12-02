#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 202020;

int n, inf, p;
int a[N], f[N][4][4];
pii pre[N][4][4];
char res[N * 10];

int dig(int x) {
	int r = 0;
	while(x) {
		++r;
		x /= 10;
	}
	return max(r, 1);
}
bool check(int x, int y) {
	if(x == 2 && y % 2) return 1;
	if(x == 3 && y % 2 == 0) return 1;
	return 0;
}
int calc(int o, int c) {
	if(o == 0) return dig(c) + 1;
	else return dig(c) * 2 + 2;
}

void upd(int i, int x, int y, int z, int c) {
	if(f[i][y][z] > f[i - 1][x][y] + c) {
		f[i][y][z] = f[i - 1][x][y] + c;
		pre[i][y][z] = mp(x, y);
	}
}
void upd(int &a, int b) {
	if(a > b) a = b;
}
void gao(int c) {
	if(!c) c = 1;
	vi v;
	while(c) {
		v.pb(c % 10);
		c /= 10;
	}
	reverse(all(v));
	for(auto u : v) res[++p] = u + '0';
}
vector<pii> solve() {
	vector<pii> t;
	rep(i, 0, n) t.pb(mp(0, a[i + 1]));
	int a = 0, b = 0;
	rep(x, 0, 4) rep(y, 0, 4) {
		if(f[n][a][b] > f[n][x][y]) a = x, b = y;
	}
	vi v;
	v.pb(b), v.pb(a);
	for(int i = n; i >= 3; --i) {
		auto u = pre[i][a][b];
		v.pb(u.fi);
		b = a, a = u.fi;
	}
	reverse(all(v));
	rep(i, 0, n) t[i].fi = v[i];
	sort(all(t));
	return t;
}
void gao(int o, int c) {
	if(o == 0) gao(c), res[++p] = ',';
	else if(o == 1) gao(c), res[++p] = '-', gao(c), res[++p] = ',';
	else if(o == 2) gao(c), res[++p] = '%', gao(c), res[++p] = ',';
	else if(o == 3) gao(c), res[++p] = '#', gao(c), res[++p] = ',';
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n + 1) cin >> a[i];
	sort(a + 1, a + 1 + n);
	if(n == 1) {
		cout << a[1] << endl;
		return 0;
	} else if(n == 2) {
		cout << a[1] << "," << a[2] << endl;
		return 0;
	}
	memset(f, 0x3f, sizeof(f));
	inf = f[0][0][0];
	rep(x, 0, 4) if(!check(x, a[1])) {
		rep(y, 0, 4) if(!check(y, a[2])) {
			f[2][x][y] = calc(x, a[1]) + calc(y, a[2]);
			if(x == y) {
				if(x == 1 && a[1] + 1 == a[2]) upd(f[2][x][y], dig(a[1]) + dig(a[2]) + 2);
				if(x >= 2 && a[1] + 2 == a[2]) upd(f[2][x][y], dig(a[1]) + dig(a[2]) + 2);
			}
		}
	}
	rep(i, 3, n + 1) rep(y, 0, 4) if(!check(y, a[i - 1])) {
		rep(z, 0, 4) if(!check(z, a[i])) {
			rep(x, 0, 4) if(!check(x, a[i - 2])) {
				upd(i, x, y, z, calc(z, a[i]));
				if(z == 0) {
				} else if(z == 1) {
					if(a[i - 1] + 1 == a[i] && y == z) upd(i, x, y, z, dig(a[i]) - dig(a[i - 1]));
				} else {
					if(a[i - 1] + 2 == a[i] && y == z) upd(i, x, y, z, dig(a[i]) - dig(a[i - 1]));
					if(a[i - 2] + 2 == a[i] && x == z) upd(i, x, y, z, dig(a[i]) - dig(a[i - 2]));
				}
			} 
		}
	}
	vector<pii> v = solve();
	int pre = 0, o = 0;
	for(auto u : v) {
		if(u.fi == 0) {
			gao(0, u.se);
		} else if(u.fi == 1) {
			if(u.se - pre > 1 || o != u.fi) {
				gao(1, u.se);
			} else {
				p -= dig(pre) + 1;
				gao(u.se), res[++p] = ',';
			}
		} else {
			if(u.se - pre > 2 || o != u.fi) {
				gao(u.fi, u.se);
			} else {
				p -= dig(pre) + 1;
				gao(u.se), res[++p] = ',';
			}
		}
		o = u.fi;
		pre = u.se;
	}
	rep(i, 1, p) cout << res[i];
	cout << endl;
	return 0;
}
