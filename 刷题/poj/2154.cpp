#include<vector>
#include<iostream>
#include<cstdio>
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

const int N = 101010;

int n, P;
bool vis[N];
vi p;

inline void init() {
	rep(i, 2, N) {
		if(!vis[i]) p.pb(i);
		for(int j = 0; j < sz(p) && i * p[j] < N; ++j) {
			vis[i * p[j]] = 1;
			if(i % p[j] == 0) break;
		}
	}
}
inline int phi(int n) {
	int res = n;
	for(int i = 0; 1ll * p[i] * p[i] <= n; ++i) if(n % p[i] == 0) {
		res = res - res/p[i];
		while(n % p[i] == 0) n /= p[i];
	}
	if(n > 1) {
		res = res - res/n;
	}
	return res % P;
}
inline int add(int a, int b) {
	int r = a + b;
	if(r >= P) r -= P;
	return r;
}
inline int mul(int a, int b) {
	return a * b % P;
}
inline int kpow(int a, int b) {
	a = a % P;
	int res = 1;
	while(b) {
		if(b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	init();
	int T;
	cin >> T;
	while(T--) {
		///
		cin >> n >> P;
		///solve
		int ans = 0;
		for(int i = 1; 1ll * i * i <= n; ++i) if(n % i == 0) {
			ans = add(ans, mul(kpow(n, i-1), phi(n/i)));
			if(i != n/i) {
				ans = add(ans, mul(kpow(n, n/i-1), phi(i)));
			}
		}
		cout << ans << endl;
	}
	return 0;
}
