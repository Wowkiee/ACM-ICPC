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
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;
//----
const int N = 2005, B = 11;
typedef unsigned long long ull;
int d[5][5], T;
ull cnt[N][B][2][3];
int __abs(int a, int b) {
	return a > b ? a - b : b - a;
}
ull solve(int x, int bit, int op) {
	ull ans = 0;
	if(x >> bit & 1) {
		ans += (cnt[x - op][bit][0][0] * cnt[x - op][bit][0][1] * cnt[x - op][bit][0][2]) << bit;
		ans += (cnt[x - op][bit][0][0] * cnt[x - op][bit][1][1] * cnt[x - op][bit][1][2]) << bit;
		ans += (cnt[x - op][bit][1][0] * cnt[x - op][bit][0][1] * cnt[x - op][bit][1][2]) << bit;
		ans += (cnt[x - op][bit][1][0] * cnt[x - op][bit][1][1] * cnt[x - op][bit][0][2]) << bit;
	}
	else {
		ans += (cnt[x - op][bit][0][0] * cnt[x - op][bit][0][1] * cnt[x - op][bit][1][2]) << bit;
		ans += (cnt[x - op][bit][0][0] * cnt[x - op][bit][1][1] * cnt[x - op][bit][0][2]) << bit;
		ans += (cnt[x - op][bit][1][0] * cnt[x - op][bit][0][1] * cnt[x - op][bit][0][2]) << bit;
		ans += (cnt[x - op][bit][1][0] * cnt[x - op][bit][1][1] * cnt[x - op][bit][1][2]) << bit;
	}
	return ans;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int ca = 0;
	cin >> T; while(T--) {
		memset(cnt, 0, sizeof cnt);
		ull ans = 0;
		rep(i, 0, 2)rep(j, 0, 3)cin >> d[i][j];
		rep(i, 0, 3) {
			rep(j, 0, d[0][i] + 1) {
				rep(k, 0, d[1][i] + 1) {
					int now = j ^ k;
					int x = __abs(j, k);
					rep(cas, 0, B) {
						cnt[x][cas][now >> cas & 1][i]++;
					}
				}
			}
		}
		rep(i, 0, N) {
			rep(cas, 0, B) {
				if(i) {
					ans -= solve(i, cas, 1);
					rep(j, 0, 2)rep(k, 0, 3)cnt[i][cas][j][k] += cnt[i - 1][cas][j][k];
				}
				ans += solve(i, cas, 0);
			}
		}
		cout << "Case #" << ++ca << ": " << ans << endl;
	}
	return 0;
}
