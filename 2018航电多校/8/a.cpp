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

const int N = 2e5 + 7;
const int mod = 998244353;

int n , m, k, jc[N], inv[N], ans, T;

int mul(int x,int y){
	return 1ll * x * y % mod;
}

int add(int x,int y){
	return (x + y) % mod;
}

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b&1) res = mul(res,a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int c(int n, int m){
	if (n<0 || m <0 || m > n) return 0;
	return mul(mul(jc[n],inv[m]),inv[n - m]);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> T;
	jc[0] = 1;
	rep(i, 1, N) jc[i] = mul(jc[i-1], i);
	inv[N-1] = qpow(jc[N-1], mod - 2);
	for (int i = N - 2; i >= 0; i--) inv[i] = mul(inv[i+1], i+1);
	//de(mul(jc[10],inv[10]));
	rep(cas, 0, T) {
		cin >> n >> m >> k;
		ans = c(k + m - 1, m - 1);
		rep(i, 1, m+1) {
			if (k - 1 - n * i + m < 0) break;
			if (i & 1)
				ans = add(ans, -1 * mul(c(k - 1 - n * i + m, m - 1), c(m, i)));	
			else  
				ans = add(ans, mul(c(k - 1 - n * i + m, m - 1), c(m, i)));	
		}
		if (ans < 0) ans += mod;
		cout << ans << endl;
	}
	return 0;
}
