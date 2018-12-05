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
struct Gauss {
	static const int N = 100, P = 1e9 + 7;
	int a[N][N];
	ll kpow(ll a, ll b) {
		ll r = 1;
		for(; b; b >>= 1, a = a * a % P)if(b & 1)r = r * a % P;
		return r;
	}
	int solve(int n, int m) {
		int i = 0, x = 0;
		for(; i < n && x < m; ++i, ++x) {
			int r = i;
			while(r < n && !a[r][x])++r;
			if(r < n) {
				if(r != i)
					rep(j, 0, m + 1)
						swap(a[r][j], a[i][j]);
				rep(j, 0, n)
					if(i != j && a[j][x]) 
						for(int k = m; k >= x; --k)
							a[j][k] = (a[j][k] 
							 - 1ll * a[i][k] * a[j][x] % P
								* kpow(a[i][x], P - 2) % P + P) % P;
			} else --i;
		}
		rep(k, i, n)
			if(a[k][m])
				return -1;
		return i;
	}
	void output(int n, int m) {
		rep(i, 0, n) {
			rep(j, 0, m) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
}G;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n, m;	cin >> n >> m;
	rep(i, 0, n)rep(j, 0, m)cin >> G.a[i][j];
	int ans = max(1, G.solve(n, m));
	cout << min(n * m, (n + m) * ans) << endl;
	return 0;
}
