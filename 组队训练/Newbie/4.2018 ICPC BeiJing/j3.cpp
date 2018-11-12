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
typedef double db;
typedef pair<ll, ll> pii;
typedef vector<int> vi;

const int N = 2020, P = 998244353;
const db pi = acos(-1), eps = 1e-8;

int sign(db x) {
	return (x > eps) - (x < -eps);
}

int n, pw3, pw2;
//int prex[N][N], prey[N][N];
pii p[N], vec[N][N];

int add(int a, int b) {
	if(a < 0) a += P;
	if(b < 0) b += P;
	if((a += b) >= P) a -= P;
	return a;
}
int sub(int a, int b) {
	if(a < 0) a += P;
	if(b < 0) b += P;
	if((a -= b) < 0) a += P;
	return a;
}
int mul(int a, int b) {
	if(a < 0) a += P;
	if(b < 0) b += P;
	return 1ll * a * b % P;
}
int kpow(int a, int b) {
	int r = 1;
	while(b) {
		if(b & 1) r = mul(a, r);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}

pii operator - (const pii &a, const pii &b) {
	return mp(a.fi - b.fi, a.se - b.se);
}
db ang(const pii &a) {
	return atan2((db)a.se, (db)a.fi);
}
bool cmp(const pii &a, const pii &b) {
	return atan2((db)a.se, (db)a.fi) < atan2((db)b.se, (db)b.fi);
}
ll cross(const pii &a, const pii &b) {
	return a.fi * b.se - a.se * b.fi;
}
ll dot(const pii &a, const pii &b) {
	return a.fi * b.fi + a.se * b.se;
}
void print(ll x) {
	cout << (long long)x;
}
void print(pii a) {
	print(a.fi);cout << " ";
	print(a.se);cout << " ";
}

int main() {
//	std::ios::sync_with_stdio(0);
//	std::cin.tie(0);
	int T;
	cin >> T;
	pw3 = kpow(3, P - 2);
	pw2 = kpow(2, P - 2);
	while(T--) {
		cin >> n;
		rep(i, 0, n) {
			long long x, y;
			cin >> x >> y;
			p[i] = mp(x, y);
		}
		rep(i, 0, n) rep(j, 0, n) if(j != i) vec[i][j - (j > i)] = p[j] - p[i];
		int t = n - 1;
		rep(i, 0, n) sort(vec[i], vec[i] + t, cmp);
		///solve
		ll tot = 0, ans = 0;
		rep(i, 0, n) {
			int k = 0, sumx = vec[i][0].fi % P, sumy = vec[i][0].se % P;
			if(sumx < 0) sumx += P;
			if(sumy < 0) sumy += P;
			int l = 0, sx = sumx, sy = sumy;
			int cnt = 1;
			rep(j, 0, t) print(vec[i][j]), cout << endl;
			rep(j, 0, t) {
				de(cnt);
				dd(l);de(k);
				dd(sx);de(sy);
				if(j == 0 || sign(ang(vec[i][j - 1]) - ang(vec[i][j]))) while((k + 1) % t != j && cross(vec[i][j], vec[i][(k + 1) % t]) >= 0) {
					k = (k + 1) % t;
					sumx = add(sumx, vec[i][k].fi % P);
					sumy = add(sumy, vec[i][k].se % P);
					sx = add(sx, vec[i][k].fi % P);
					sy = add(sy, vec[i][k].se % P);
					++cnt;
				}
				while(cnt > 0 && dot(vec[i][j], vec[i][(l + 1) % t]) > 0) {
					sx = sub(sx, vec[i][l].fi % P);
					sy = sub(sy, vec[i][l].se % P);
					l = (l + 1) % t;
					--cnt;
				}
				de(cnt);
				dd(l);de(k);
				dd(sx);de(sy);
				tot = add(tot, mul(vec[i][j].fi % P, sumy));
				tot = sub(tot, mul(vec[i][j].se % P, sumx));
				ans = add(ans, mul(vec[i][j].fi % P, sy));
				ans = sub(ans, mul(vec[i][j].se % P, sx));
				sumx = sub(sumx, vec[i][j].fi % P);
				sumy = sub(sumy, vec[i][j].se % P);
				if(k == j) {
					k = (k + 1) % t;
					sumx = add(sumx, vec[i][k].fi % P);
					sumy = add(sumy, vec[i][k].se % P);
					sx = add(sx, vec[i][k].fi % P);
					sy = add(sy, vec[i][k].se % P);
					++cnt;
				}
				if(l == j && cnt > 0) {
					l = (l + 1) % t;
					sx = sub(sx, vec[i][j].fi % P);
					sy = sub(sy, vec[i][j].se % P);
					--cnt;
				}
				cout << "-----" << (int)ans << endl;
			}
			cout << (int)ans << endl;
			cout << endl;
		}
		tot = mul(tot, pw3);
		tot = sub(tot, ans);
		tot = ans;
		cout << (int)tot << endl;
	}
	return 0;
}
