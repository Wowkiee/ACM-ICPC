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
int a[N], f[N][N][2];
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
	rep(i, 1, n + 1) cin >> a[i], f[i][i][0] = f[i][i][1] = 1;
	if(n == 2) {
		cout << (__gcd(a[1], a[2]) != 1) << endl;
		return 0;
	}
	rep(i, 1, n + 1) rep(j, 1, n + 1) ok[i][j] = (__gcd(a[i], a[j]) != 1);
	if(n > 2) rep(i, 1, n) {
		f[i][i + 1][1] = 1;
		f[i][i + 1][0] = ok[i][i + 1];
	}
	rep(len, 3, n + 1) {
		for(int l = 1, r = l + len - 1; r <= n; ++l, ++r) {
			f[l][r][1] = f[l + 1][r][0];
			rep(k, l + 1, r) if(ok[l][k])     f[l][r][1] = add(f[l][r][1], mul(f[l][k][1], f[k][r][1]));
			f[l][r][0] = 0;
			rep(k, l + 1, r + 1) if(ok[l][k]) f[l][r][0] = add(f[l][r][0], mul(f[l][k][1], f[k][r][0]));
		}
	}
	int ans = 0;
	rep(x, 2, n + 1) if(ok[1][x]) {
//		dd(x), dd(f[1][x][1]), de(f[x][n][0]);
		ans = add(ans, mul(f[1][x][1], f[x][n][0]));
	}
	cout << ans << endl;
	return 0;
}
