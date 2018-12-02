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
#define pw(a) (1ll << (a));
#define endl "\n"
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 505;
int dp[N][2][2][2][N * 2], ans, a[N], tmp, m, n;
string s;
const int P = 1e9 + 7;
int add(int a, int b) {return (a + b) % P;}

int mul(int a, int b) {return 1ll * a * b % P;}

int dfs(int pos, bool lim1, bool lim2, bool ok, int tim) {
	if (pos == 0) {
		if (!ok) return tim == 0;
		return tim == 0 && lim2 == 0;
	}
	if (tim < 0 || tim > pos * 2) return 0;
	if (dp[pos][lim1][lim2][ok][tim] != -1) return dp[pos][lim1][lim2][ok][tim]; 
	int res = 0;
	if (ok == 0) {
		int up1 = lim1 ? a[pos] : 1;
		rep(i, 0, up1+1) {
			int up2 = lim2 ? i : 1;
			rep(j, 0, up2+1) {
				if (i == 0 && j == 0) res = add(res, dfs(pos-1, lim1&(i == up1), lim2 & (j == up2), ok, tim));
				if (i == 1 && j == 0)  {
					res = add(res, dfs(pos-1, lim1&(i == up1), lim2 & (j == up2), ok, tim-1));
					res = add(res, dfs(pos-1, lim1&(i == up1), 1, 1, tim-1));
				}
				if (i == 1 && j == 1) res = add(res, dfs(pos-1, lim1&(i == up1), lim2 & (j == up2), ok, tim));
				/*if (i == 0 && j == 1) res = add(res, dfs(pos-1, lim1&(i == up1), lim2 & (j == up2), ok, tim-1));*/
			}
		}
	}
	if (ok == 1) {
		rep(j, 0, 2) {
			int up1 = lim1 ? a[pos] : 1;
			int up2 = lim2 ? j : 1;
			rep(i, 0, min(up1, up2)+1) {
				if (i == 0 && j == 0) res = add(res, dfs(pos-1, lim1&(i == up1), lim2 & (i == up2), 1, tim-1));
				if (i == 1 && j == 0) res = add(res, dfs(pos-1, lim1&(i == up1), lim2 & (i == up2), 1, tim-2));
				if (i == 1 && j == 1) res = add(res, dfs(pos-1, lim1&(i == up1), lim2 & (i == up2), 1, tim-1));
				if (i == 0 && j == 1) res = add(res, dfs(pos-1, lim1&(i == up1), lim2 & (i == up2), 1, tim));
			}
		}
	}
	dp[pos][lim1][lim2][ok][tim] = res;
	return res;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(cas, 1, n+1) {
		//memset(dp, -1, sizeof(dp));
		cin >> s;	
		reverse(all(s));
		m = sz(s);
		ans = 0;
		rep(i, 1, m+1) {
			rep(j, 0, 2 * m+1) {
				dp[i][0][0][0][j] = dp[i][0][0][1][j] = -1;
				dp[i][0][1][0][j] = dp[i][0][1][1][j] = -1;
				dp[i][1][0][0][j] = dp[i][1][0][1][j] = -1;
				dp[i][1][1][0][j] = dp[i][1][1][1][j] = -1;
			}
		}
		rep(i, 1, m+1) a[i] = s[i-1] - '0';
		rep(i, 1, m * 2 + 1) {
			tmp = dfs(m, 1, 1, 0, i);
			ans = add(ans, mul(tmp, i));
		}
		cout << ans << endl;
	}

	return 0;
}
