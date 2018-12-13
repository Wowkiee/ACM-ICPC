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
#define pw(a) (1ll << (a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
//----
typedef pair<pii, int> ppi;
const int N = 305;
int dp[N][N * N];
ppi x[N];
int cmp(ppi a, ppi b) {
	if(a.fi.se * b.fi.se <= 0)return a.fi.se > b.fi.se;
	if(a.fi.se > 0)return a.fi.fi < a.fi.se;
	return a.fi.fi > a.fi.se;
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	memset(dp, 0xf0, sizeof dp);
	int n; cin >> n;
	dp[0][0] = 0;
	rep(i, 1, n + 1) {
		string a; cin >> a; x[i].se = sz(a);
		rep(j, 0, x[i].se) {
			x[i].fi.se += (a[j] == '(' ? 1 : -1);
			x[i].fi.fi = min(x[i].fi.fi, x[i].fi.se);
		}
		x[i].fi.fi = -x[i].fi.fi;
	}
	sort(x + 1, x + n + 1, cmp);
	rep(i, 1, n + 1) {
		rep(j, 0, 90001)dp[i][j] = dp[i - 1][j];
		rep(j, x[i].fi.fi, 90001)if(0 <= j + x[i].fi.se && j + x[i].fi.se <= 90000)dp[i][j + x[i].fi.se] = max(dp[i - 1][j] + x[i].se, dp[i][j + x[i].fi.se]);
	}
	cout << dp[n][0] << endl;
	return 0;
}
