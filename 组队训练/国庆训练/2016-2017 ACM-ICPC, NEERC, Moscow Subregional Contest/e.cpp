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

int n, inf;
int a[N], f[N][4][4];
pii pre[N][4][4];

int dig(int x) {
	int r = 0;
	while(x) {
		++r;
		x /= 10;
	}
	return r;
}
int calc(int o, int x) {
	if(o == 0) return dig(x) + 1;
	else return 2 * (dig(x) + 1);
}
bool check(int x, int y) {
	if(x == 2 && y % 2) return 1;
	if(x == 3 && y % 2 == 0) return 1;
	return 0;
}

void upd(int i, int x, int y, int z, int c) {
	if(f[i][y][z] > f[i - 1][x][y] + c) {
		f[i][y][z] = f[i - 1][x][y] + c;
		pre[i][y][z] = mp(x, y);
	}
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
			if(x == y) {
				if(x == 0) {
					f[2][x][y] = calc(x, a[1]) + calc(y, a[2]);
				} else if(x == 1) {
					if(a[1] + 1 == a[2]) f[2][x][y] = dig(a[1]) + dig(a[2]) + 2;
				} else if(x == 2) {
					if(a[1] + 2 == a[2]) f[2][x][y] = dig(a[1]) + dig(a[2]) + 2;
				} else {
					if(a[1] + 2 == a[2]) f[2][x][y] = dig(a[1]) + dig(a[2]) + 2;
				}
			} else {
				f[2][x][y] = calc(x, a[1]) + calc(y, a[2]);
			}
		}
	}
	rep(i, 3, n + 1) rep(x, 0, 4) if(!check(x, a[i - 2])) {
		rep(y, 0, 4) if(!check(y, a[i - 1])) {
			rep(z, 0, 4) if(!check(z, a[i])) {
				if(z == 0) {
					upd(i, x, y, z, dig(a[i]) + 1);
				} else if(z == 1) {
					if(a[i - 1] + 1 == a[i]) upd(i, x, y, z, dig(a[i]) - dig(a[i - 1]));
				} else {
					if(a[i - 1] + 2 == a[i] && y == z) upd(i, x, y, z, dig(a[i]) - dig(a[i - 1]));
					if(a[i - 2] + 2 == a[i] && x == z) upd(i, x, y, z, dig(a[i]) - dig(a[i - 2]));
					upd(i, x, y, z, dig(a[i]) * 2 + 2);
				}
			}
		} 
	}
	int a = 0, b = 0;
	rep(x, 0, 4) rep(y, 0, 4) {
		if(f[n][a][b] > f[n][x][y]) a = x, b = y;
	}
	vector<pii> v;
	v.pb(mp(a, b));
	for(int i = n; i >= 3; --i) {
		auto t = pre[i][a][b];
		v.pb(t);
		a = t.fi, b = t.se;
	}
	reverse(all(v));
	de(f[n][a][b]);
	return 0;
}
