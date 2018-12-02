#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(c) cout << #c << " = " << c << endl
#define dd(c) cout << #c << " = " << c << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 404040;

int n;
int pre[4][N];
vi v[4];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n + 1) {
		int x, y;
		cin >> x >> y;
		if(x == 10) x = 2;
		if(x == 11) x = 3;
		v[x].pb(-y);
	}
	rep(i, 0, 4) sort(all(v[i]));
	rep(i, 0, 4) {
		rep(j, 0, sz(v[i])) pre[i][j + 1] = pre[i][j] - v[i][j];
	}
	int ans = 0, now = 0;
	int t = sz(v[3]), a = sz(v[1]), b = sz(v[2]), c = sz(v[0]);
	for(int z = t; ~z; --z) {
		int L = z - t, R = t - z;
		int y = b, x = R + y;
		if(x <= a) now = max(now, pre[1][x] + pre[2][y]);
		x = a, y = x - L;
		if(y <= b) now = max(now, pre[1][x] + pre[2][y]);
		if(z <= c) ans = max(ans, now + pre[0][z] + pre[3][t]);
	}
	cout << ans << endl;
	return 0;
}
