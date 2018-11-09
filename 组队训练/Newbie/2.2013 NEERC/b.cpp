#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(a) cout << #a << " = " << a << " "
#define de(a) cout << #a << " = " << a << endl
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double db;
//----
const int N = 3005;
int n;
int a, b;
db dp[N][N];
db solve(int z) {
	if(a + b <= n)return 1;
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	rep(i, 0, n)rep(j, 0, min(i, a) + 1) {
		int xa = a - j, xb = b - i + j;
		if(xa > 0)dp[i + 1][j + 1] += dp[i][j] * xa * 2 / (xa * 2.0 + xb);
		if(xb > 0)dp[i + 1][j] += dp[i][j] * xb / (xa * 2.0 + xb);
	}
	db ans = 0.0;
	if(!z)rep(i, 0, min(n, a) + 1)ans += dp[n][i] * i / a;
	else rep(i, 0, min(n, b) + 1) ans += dp[n][n - i] * i / b;
	return ans;
}
int main() {
	freopen("bonus.in", "r", stdin);
	freopen("bonus.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cout << setiosflags(ios::fixed);
	cout << setprecision(12);
	cin >> n >> a >> b;
	a++; cout << solve(0) << endl; a--;
	b++; cout << solve(1) << endl; b--;
	return 0;
}
