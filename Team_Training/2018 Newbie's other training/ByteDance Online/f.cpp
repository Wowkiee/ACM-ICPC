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
//----
const int mod = 1e9 + 7;
int add(int a, int b) {
	int res = a + b;
	if(res >= mod)res -= mod;
	return res;
}
int mul(int a, int b) {
	return 1ll * a * b % mod;
}
int solve(int x, int y, int n, int m) {
	return mul(mul(n - x + 1, m - y + 1), n + 1);
}
int jian(int a, int b) {
	int res = a - b;
	if(res < 0)res += mod;
	return res;
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n, m, s; cin >> n >> m >> s;
		int ans = 0;
		for(int i = 1; i * i <= s; i++)if(s % i == 0) {
			if(i <= n && s / i <= m)rep(j, 0, 2)ans = add(ans, solve(i, s / i, n, m));
			if(i <= m && s / i <= n)rep(j, 0, 2)ans = add(ans, solve(i, s / i, m, n));
			if(i * i == s && i <= n && i <= m)ans = jian(ans, mul(4, mul(n - i + 1, m - i + 1)));
		}
		cout << ans << endl;
	}
	return 0;
}
