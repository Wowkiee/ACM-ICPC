#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(x) cout << #x << " = " << x << endl 
#define dd(x) cout << #x << " = " << x << " "
#define endl "\n"
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 55, M = 10101;

int n, mi, ma;
int m[N], c[N], a[N];
bool f[N][M];

bool check(int mid) {
	rep(i, 1, n + 1) a[i] = c[i] / mid;
	f[0][0] = 1;
	rep(i, 1, n + 1) {
		rep(o, 0, m[i]) {
			int cnt = 0;
			for(int j = o; j <= ma; j += m[i]) {
				cnt += f[i - 1][j];
				ll t = j - m[i] - a[i] * 1ll * m[i];
				if(t >= 0) cnt -= f[i - 1][t];
				f[i][j] = (cnt > 0);
			}
		}
	}
	rep(i, mi, ma + 1) if(f[n][i]) return 1;
	return 0;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> mi >> ma;
	rep(i, 1, n + 1) cin >> m[i] >> c[i];
	int l = 1, r = 1e6, ans = 0;
	while(l <= r) {
		int mid = l + r >> 1;
		if(check(mid)) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}
