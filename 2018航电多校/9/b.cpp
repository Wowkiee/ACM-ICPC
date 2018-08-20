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

const int N = 2020, P = 998244353;

int n, m, k;
int a[N][N], f[N][N], g[N][N], s[N][N];

int add(int a, int b) {
	if((a += b) >= P) a -= P;
	return a;
}
int sub(int a, int b) {
	if((a -= b) < 0) a += P;
	return a;
}
int mul(int a, int b) {
	return 1ll * a * b % P;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> n >> m >> k;
		rep(i, 1, n+1) {
			string t;
			cin >> t;
			rep(j, 1, m+1) a[i][j] = t[j-1] - '0';
		}
		rep(j, 1, m+1) {
			f[1][j] = 1;
			if(j == 1 || a[1][j] != a[1][j-1]) g[1][j] = 1;
			else g[1][j] = 0;
			s[1][j] = s[1][j-1] + g[1][j];
		}
		rep(i, 2, n+1) {
			rep(j, 1, m+1) {
				int l = max(1, j - k), r = min(m, j + k);
				f[i][j] = add(f[i-1][l], sub(s[i-1][r], s[i-1][l]));
				if(j == 1 || a[i][j] != a[i][j-1]) g[i][j] = f[i][j];
				else {
					int t = min(m, j-1+k);
					if(t == r) g[i][j] = 0;
					else g[i][j] = g[i-1][r];
				}
				s[i][j] = add(s[i][j-1], g[i][j]);
			}
		}
		int ans = f[n][1];
		rep(j, 2, m+1) ans = add(ans, g[n][j]);
		cout << ans << endl;
	}
	return 0;
}
