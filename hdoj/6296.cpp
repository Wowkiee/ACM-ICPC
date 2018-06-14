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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 101010, M = 1010;

int n;
int sum[M][M];
pair<pii, pii> a[N];

ll solve() {
	memset(sum, 0, sizeof(sum));
	ll ans = 0;
	rep(i, 1, n + 1) {
		int x1 = a[i].fi.fi;
		int x2 = a[i].fi.se;
		int y1 = a[i].se.fi;
		int y2 = a[i].se.se;
		if(x1 > x2 || y1 > y2) continue;
		sum[x1][y1]++;
		sum[x1][y2 + 1]--;
		sum[x2 + 1][y1]--;
		sum[x2 + 1][y2 + 1]++;
	}
	rep(i, 1, M) rep(j, 1, M) sum[i][j] += sum[i][j - 1];
	rep(i, 1, M) rep(j, 1, M) sum[i][j] += sum[i - 1][j];
	rep(i, 1, M) rep(j, 1, M) {
		int t = sum[i][j];
		if(t >= 3) ans += 1ll * t * (t - 1) * (t - 2) / 6;
	}
	return ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		///
		cin >> n;
		///read
		rep(i, 1, n + 1) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			a[i] = mp(mp(x1, x2), mp(y1, y2));
		}
		///solve
		ll ans = 0;
		ans += solve();
		rep(i, 1, n + 1) a[i].fi.fi++;
		ans -= solve();
		rep(i, 1, n + 1) a[i].se.fi++;
		ans += solve();
		rep(i, 1, n + 1) a[i].fi.fi--;
		ans -= solve();
		cout << ans << endl;
	}
	return 0;
}
