#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long double db;

const int N = 205;
db c[N][N], f[N][25];
int n, k;
db F(int n, int k){
	if (n <= k) return 0;
	if (k == 0) return n;
	if (f[n][k] > -1) return f[n][k];
	db res = 0;
	rep(m, 1, n) {
		db tmp = 0;
		rep(i, 0, min(m, k)+1) if (m - i <= n - k) {
			tmp += F(n - m - (k - i), k - i) * c[k][i] * c[n - k][m - i] / c[n][m];
		}
		res = max(res, tmp);
	}
	return f[n][k] =  res;
}

int main() {
//	std::ios::sync_with_stdio(0);
//	std::cin.tie(0);
	cin >> n >> k;
	rep(i, 0, n+1) rep(j, 0, k+1) f[i][j] = -2;
	c[0][0] = 1;
	rep(i, 1, n+1){
		c[i][0] = 1;
		rep(j, 1, n+1) c[i][j] = c[i-1][j-1] + c[i-1][j]; 
	}
	printf("%.10Lf", F(n - k, k));
	return 0;
}
