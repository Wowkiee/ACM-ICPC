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
typedef long double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e5 + 7;
pii a[N];
db v0, tr, t;
int n, T;
double ans, L;
bool ok;

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cout << setiosflags(ios :: fixed);
	cout << setprecision(12);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n >> L;
		L *= 1000;
		rep(i, 1, n+1) {
			cin >> a[i].fi >> a[i].se;
		}
		sort(a + 1, a + n + 1);
		v0 = 0;
		ok = 0;
		ans = 0;
		per(i, 1, n+1) {
			tr = 1.0 * a[i].se / 1000000;
			//de(tr);
			//de(L);
			t = -v0 + sqrt(v0 * v0 + 2 * a[i].fi * L);
			//de(t);
			t /= a[i].fi;
			if (t >= tr) {
				L -= v0 * tr + a[i].fi * tr * tr / 2;
				v0 += tr * a[i].fi;
				//de(L);
				ans += tr;
			}else {
				ok = 1;
				ans += t;
				break;
			}
		}
		if (ok) cout << ans << endl;
		else cout << ans + L / v0 << endl;
	}
	return 0;
}
