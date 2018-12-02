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
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 44;

int n, m;
int good[2], bad[2], cnt[2][N][2];
bool vis[1 << 20];
ll x;
string s;

bool check(int x, int len) {
	if(len < n) return 0;
	int inf = (1 << n) - 1;
	for(int i = 0, j = n - 1; j < len; ++i, ++j) {
		int t = len - 1 - j;
		if(vis[x >> t & inf]) return 1;
	}
	return 0;
}

void solve(int len, int &good, int &bad, int cnt[][2], bool o) {
	good = bad = 0;
	rep(i, 0, N) cnt[i][0] = cnt[i][1] = 0;
	rep(i, 0, 1 << len) {
		bool t = check(i, len);
		if(t) {
			++good;
		} else {
			++bad;
			int to = min(n - 1, len);
			if(o == 0) {
				rep(j, 1, to + 1) {
					int inf = (1 << j) - 1;
					int t = (i & inf);
					if(t == 0) cnt[j][0]++;
					else if(vis[t]) cnt[j][1]++;
				}
			} else {
				rep(j, 1, to + 1) {
					int t = (i >> (len - j));
					if(t == 0) cnt[j][0]++;
					else if(vis[t]) cnt[j][1]++;
				}
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T;
	cin >> T;
	vis[0] = 1;
	rep(i, 0, 20) vis[1 << i] = 1;
	while(T--) {
		cin >> n >> m >> s;
		x = 0;
		rep(i, 0, sz(s)) x = (x << 1 | (s[i] - '0'));
		solve(m / 2, good[0], bad[0], cnt[0], 0);
		solve(m - m / 2, good[1], bad[1], cnt[1], 1);
		ll ans = 0;
		ans = 1ll * good[0] * good[1] + 1ll * good[0] * bad[1] + 1ll * bad[0] * good[1];
		de(ans);
		rep(i, 1, n) {
			int j = n - i;
			ans += 1ll * cnt[0][i][0] * cnt[1][j][0] + 1ll * cnt[0][i][1] * cnt[1][j][0] + 1ll * cnt[0][i][0] * cnt[1][j][1];
	//		dd(i), dd(j), de(ans);
		}
		cout << ans << endl;
	}
	return 0;
}
