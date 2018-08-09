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
typedef double db;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<db, db> pdd;
typedef vector<int> vi;
//---

const int N = 3030;

int n;
pair<pdd, db> line[N];

db calc(pair<pdd, db> a) {
	return atan2(a.fi.fi, -a.fi.se);
}
bool cmp(pair<pdd, db> i, pair<pdd, db> j) {
	return calc(i) < calc(j);
}
inline pdd inter(int i, int j) {
	db a1 = line[i].fi.fi, b1 = line[i].fi.se, c1 = line[i].se;
	db a2 = line[j].fi.fi, b2 = line[j].fi.se, c2 = line[j].se;
	db r = a1 * b2 - a2 * b1;
	return mp((b1 * c2 - b2 * c1) / r, (a2 * c1 - a1 * c2) / r);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	rep(i, 0, n) {
		db a, b, c;
		cin >> a >> b >> c;
		if(a < 0) a = -a, b = -b, c = -c;
		line[i] = mp(mp(a, b), c);
	}
	sort(line, line+n, cmp);
	db ans = 0;
	rep(i, 0, n) {
		pdd u = mp(0, 0);
		rep(_j, 1, n) {
			int j = (i + _j) % n;
			pdd v = inter(i, j);
			ans += u.fi * v.se - u.se * v.fi;
			u.fi += v.fi, u.se += v.se;
		}
	}
	ans = fabs(ans) * 3 / n / (n-1) / (n-2);
	cout << setiosflags(ios::fixed);
	cout << setprecision(6);
	cout << ans << endl;
	return 0;
}
