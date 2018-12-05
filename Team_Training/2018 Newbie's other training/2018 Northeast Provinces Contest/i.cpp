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
#define endl "\n"
#define pw(a) (1ll << (a))
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;
//----
const int N = 505;
struct Card {
	int w, x, ism, iss;
}a[N];
bool operator <(Card a, Card b) {
	if(a.iss != b.iss)return a.iss < b.iss;
	if(a.ism != b.ism)return a.ism > b.ism;
	return a.w < b.w;
}
int n, W;
int dp[N][N][N];
void update(int &a, int b) {
	if(b > a)a = b;
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	memset(dp, 0xf0, sizeof dp);
	cin >> n >> W;
	rep(i, 1, n + 1) cin >> a[i].w >> a[i].x >> a[i].ism >> a[i].iss;
	sort(a + 1, a + n + 1);
	dp[0][0][0] = 0;
	rep(i, 0, n) {
		rep(j, 0, n + 1)rep(k, 0, W + 1)update(dp[i + 1][j][k], dp[i][j][k]);
		rep(j, 0, n) {
			int rcost = max(0, a[i + 1].w - a[i + 1].iss * j);
			rep(k, 0, W - rcost + 1)update(dp[i + 1][j + a[i + 1].ism][k + rcost], dp[i][j][k] + a[i + 1].x);
		}
	}
	int ans = 0xf0f0f0f0;
	rep(j, 0, n + 1)rep(k, 0, W + 1)ans = max(dp[n][j][k], ans);
	cout << ans << endl;
	return 0;
}
