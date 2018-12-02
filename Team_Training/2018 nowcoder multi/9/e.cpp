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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int mod = 1e9 + 7;
const int N = 1e3 + 7;
int p[N], p2[N], n, m, dp[N];

int mul(int x, int y){
	return 1ll * x * y % mod; 	
}

int add(int x, int y){
	return (x + y) % mod;
}

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1; 
	}
	return res;
}

int solve(int n) {
	if (n <= 0) return 0;
	if (dp[n] != -1) return dp[n];
	ll w = 1, res = 0;
	for (int i = n; i >= 0; i--){
			res = add(res,mul(mul(add(solve(i-1), qpow(n - i, m)), w), p2[i]));
			w = mul(w, p[i]);
	}
	dp[n] = res;
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin  >> n >> m;
	//de(m);
	rep(i, 1, n+1) cin >> p[i];
	p2[0] = 1;
	rep(i, 1, n+1) {
		p2[i] = mul(100 - p[i], qpow(100, mod - 2));
		p[i] = mul(p[i], qpow(100, mod -2));
	}
	//de(p[1] * 1ll * 100 % mod);
	memset(dp, -1, sizeof(dp));
	cout << solve(n);
	return 0;
}
