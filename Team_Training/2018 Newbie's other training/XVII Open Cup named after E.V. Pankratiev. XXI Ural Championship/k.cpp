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
#define pw(x) (1ll << (x))
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

int dx, dy, x, y, n;
vector<pii> ans, tmp;
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	/*rep(i, 13, 100) {
		x = 12; y = i;
		int z = sqrt(x * x + y * y) + 0.5;
		if (x * x + y * y == z * z) cout << i << endl;
	}*/
	//return 0;
	if (n == 3) {
		cout << "0 0" << endl;
		cout << "4 3"  << endl;
		cout << "-20 21" << endl;
	}else {
		dx = -80; dy = 84;
		x = 0; y = 0;
		rep(i, 1, (n + 1) / 2 + 1) {
			//cout << x << " " << y << endl;
			//cout << x << " " << y + 1 << endl;
			//x ++; y ++;
			ans.pb(mp(x, y));
			if (i & 1) x += 16, y += 12;
			else x += 35, y -= 12;
		}
		rep(i, 0, sz(ans)) cout << ans[i].fi + dx << " " << ans[i].se + dy << endl, tmp.pb(mp(ans[i].fi + dx, ans[i].se + dy));
		per(i, (n & 1) ? 1 : 0, sz(ans)) cout << ans[i].fi<< " " << ans[i].se<< endl, tmp.pb(ans[i]);
		tmp.pb(tmp[0]);
		rep(i, 0, sz(tmp) - 1) {
			x = tmp[i].fi - tmp[i+1].fi;
			y = tmp[i].se - tmp[i+1].se;
		int 	z = sqrt(x * x + y * y) + 0.5;
			assert(x * x + y * y == z * z);
		}
	}
	return 0;
}
