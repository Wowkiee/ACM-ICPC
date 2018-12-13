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

const int N = 333, P = 1e9 + 7;

int n;
int a[N], f[N][N];
bool ok[N][N];

int add(int a, int b) {
	if((a += b) >= P) a -= P;
	return a;
}
int mul(int a, int b) {
	return 1ll * a * b % P;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n + 1) cin >> a[i], f[i][i] = 1;
	if(n == 2) {
		cout << (__gcd(a[1], a[2]) != 1) << endl;
		return 0;
	}
	if(n > 2) rep(i, 1, n) f[i][i + 1] = 1;
	rep(i, 1, n + 1) rep(j, 1, n + 1) ok[i][j] = (__gcd(a[i], a[j]) != 1);
	rep(len, 3, n + 1) {
		for(int l = 1, r = l + len - 1; r <= n; ++l, ++r) {
			f[l][r] = 0;
			if(ok[l + 1][r]) f[l][r] = f[l + 1][r];
			rep(k, l + 1, r) if(ok[l][k]) {
				f[l][r] = add(f[l][r], mul(f[l + 1][k], f[k][r]));
			}
		}
	}
	int ans = 0;
	rep(x, 1, n) if(ok[n][x]) {
		int t = mul(f[x][n], f[1][x]);
		ans = add(ans, t);
	}
	cout << ans << endl;
	return 0;
}
