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

ll n1, n2, ma, xx, yy, zz, x, y, z, T, sw, mi;
vi a, b;
int solve() {
	n1 = sz(a); n2 = sz(b);
	int ok1 = 0, ok2 = 0;
	x = y = z = xx = yy = zz = -1ll<<60;
	x = a[0] + 2;
	//x = a[0];
	if (n1 > 1) y = a[1] + 1;
	//if (n1 > 1) y = a[1];
	if (n1 > 2) z = a[2];
	xx = b[0] + 2;
	//xx = b[0];
	if (n2 > 1) yy = b[1] + 1;
	//if (n2 > 1) yy = b[1];
	if (n2 > 2) zz = b[2];
	//dd(n1);de(n2);
	//dd(x);dd(y);de(z);
	//dd(xx);dd(yy);de(zz);
	//de(mi);
	if (n1 <= 2 && n2 <= 2){
		if (x == mi || y == mi) ok1 = 1;
		if (xx == mi || yy == mi) ok2 =1;
		if (ok1 && ok2) return 0;
		if (ok1) return 1;
		return -1;
	}
	if (n1 <= 2) {
		if (zz == mi || yy == mi) return -1;
		if (xx == mi) ok2 = 1;
		if (x == mi || y == mi) ok1 = 1;
		if (ok1 && ok2) return 0;
		if (ok1) return 1;
		return -1;
	} 
	if (yy > zz) swap(zz, yy);
	if (y > z) swap(z, y);
	if (yy == mi) ok2 = 1; 
	if (y == mi) ok1 = 1;
	if (ok2 && ok1) {
		if (zz < z) return -1;
		if (zz > z) return 1;
		return 0;
	} 
	if (ok1) return 1;
	if (ok2) return -1;
	if (x < xx) return 1;
	if (x > xx) return -1;
	return 0;
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n1 >> n2;
		mi = 1 << 30;
		a.clear();b.clear();
		rep(i, 1, n1+1) cin >> x, a.pb(x), mi = min(mi, x + 3 - i);
		rep(i, 1, n2+1) cin >> x, b.pb(x), mi = min(mi, x + 3 - i);
		sw = 0;
		if (n1 > n2) {
			swap(a,b);
			sw = 1;
		}
		int ans = solve();
		if(sw) ans *= -1;
		cout << ans << endl;
	}
	return 0;
}
