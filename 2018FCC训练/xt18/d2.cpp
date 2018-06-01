#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----
const int N = 5e3 + 2, MOD = 1e9 + 7;
int add(int a, int b) { if ((a += b) >= MOD) a -= MOD; return a; }
int mul(int a, int b) { return a * 1ll * b % MOD; }
int dp[2][N], sum[2][N], dp2[N], sum2[N], dp3[N], sum3[N];
int ne, od, cur = 1;
void pre() {
	ne ^= 1; od ^= 1; ++cur;
	rep(i, 0, cur) dp[ne][i] = 0;
	dp[ne][cur] = 1;
	rep(i, cur + 1, N) dp[ne][i] = add(dp[ne][i - 1], add(dp[od][i - 1], sum[od][i - 2]));

	rep(i, 0, cur) sum[ne][i] = 0;
	sum[ne][cur] = 1;	
	rep(i, cur + 1, N) sum[ne][i] = add(sum[ne][i - 1], dp[ne][i]);

}
int n[N], m[N], ans[N];
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	ne = 1; od = 0;
	dp[0][0] = 1;
	rep(i, 0, N) sum[0][i] = 1;
	rep(i, 1, N) dp[1][i] = i, sum[1][i] = add(sum[1][i - 1], dp[1][i]);
	int casn = 0;
	while (cin >> n[casn] >> m[casn]) casn++;
	rep(i, 1, N) {
		rep(j, 1, N) dp2[j] = mul(dp[od][j], j);
		rep(j, 1, N) sum2[j] = add(sum2[j - 1], dp2[j]);
		rep(j, 1, N) dp3[j] = mul(dp2[j], j);
		rep(j, 1, N) sum3[j] = add(sum3[j - 1], dp3[j]);
		rep(cas, 0, casn) {
			int n = ::n[cas];
			int m = ::m[cas];
			if (i > min(n, m)) continue;
			int tmp = 0;
			int tmpm = add(sum3[m - 1], add(MOD - mul(2 * m, sum2[m - 1]), mul(m, mul(m, sum[od][m - 1]))));
			int tmpn = add(sum3[n - 1], add(MOD - mul(2 * n, sum2[n - 1]), mul(n, mul(n, sum[od][n - 1]))));
			tmp = add(tmp, mul(dp[ne][n], tmpm));
			tmp = add(tmp, mul(dp[ne][m], tmpn));
			/*int tmp2 = 0;
			rep(w1, 1, m - (i - 1) + 1) tmp2 = add(tmp2, mul(w1, mul(w1, mul(dp[ne][n], dp[od][m - w1]))));
			rep(b1, 1, n - (i - 1) + 1)	tmp2 = add(tmp2, mul(b1, mul(b1, mul(dp[ne][m], dp[od][n - b1]))));
			if (tmp != tmp2) {
				dd(i); dd(tmp); de(tmp2);
			}*/
			ans[cas] = add(ans[cas], tmp);
		}
		pre();
	}
	
	rep(i, 0, casn) cout << ans[i] << endl;
	return 0;
}
