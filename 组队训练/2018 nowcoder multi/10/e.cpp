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

const int N = 105;
int M, n, m, a[N], f[N][N], ans[N], ans2;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> M;
	rep(i, 1, n+1) cin >> a[i];
	rep(m, 1, M+1) {
		memset(f, 0, sizeof(f));
	  f[0][0] = 1;
		rep(i, 0, n) {
			rep(mask, 0, m) f[i+1][mask] = f[i][mask];
			rep(j, 0, m) 
				rep(mask, 0, m) f[i+1][(mask + a[i+1] * j) % m] += f[i][mask];
		}
		ans[m] = f[n][0];
	}
	rep(i, 1, M+1) de(ans[i]),ans2 ^= ans[i];
	cout << ans2;
	return 0;
}
