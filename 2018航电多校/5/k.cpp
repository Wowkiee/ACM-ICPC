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
typedef __int128 ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 66;

int n, p;
int c[N], a[N];
ll P;
ll f[N][N], C[N][N];

inline ll add(ll a, ll b) {
	ll r = a + b;
	if(r >= P) r -= P;
	return r;
}
inline ll mul(ll a, ll b) {
	return a * b % P;
}

inline void init() {
	rep(i, 0, N) C[i][0] = C[i][i] = 1;
	rep(i, 0, N) rep(j, 1, i) C[i][j] = add(C[i-1][j], C[i-1][j-1]);
}

inline ll solve(int m) {
	rep(i, 1, n+1) a[i] = (c[i] + m - 1) / m;
	memset(f, 0, sizeof(f));
	f[0][0] = 1;
	rep(i, 1, n+1) rep(j, a[i], 60/m+1) {
		rep(k, 0, j-a[i]+1) {
			f[i][j] = add(f[i][j], mul(f[i-1][k], C[60/m-k][j-k]));
		}
	}
	return f[n][60/m];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		///
		cin >> n >> p;
		///read
		rep(i, 1, n+1) cin >> c[i];
		///solve
		P = p * 60ll;
		init();
		ll ans = 0;
		ans = add(ans, mul(solve(1), 1));
		ans = add(ans, mul(solve(5), 24));
		ans = add(ans, mul(solve(2), 15));
		ans = add(ans, mul(solve(3), 20));
		long long res = ans / 60;
		cout << res << endl;
	}
	return 0;
}
