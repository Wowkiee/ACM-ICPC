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

int d, s;
pii pre[505][5005];
int f[505][5005], x, y;
queue<pii> q;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> d >> s;
	memset(f, -1, sizeof(f));
	rep(i, 0, 501) rep(j, 0, 5001) pre[i][j] = {-1, -1};
	rep(i, 1, 10) {
			x = i % d;
			y = i;
			if (f[x][y] == -1) pre[x][y] = {-1, -1}, f[x][y] = i, q.push({x, y});
	}
	while (!q.empty()) {
		pii u = q.front(); q.pop();
		rep(i, 0, 10) {
			x = (u.fi * 10 + i) % d;
			y = u.se + i;
			if (y <= s && f[x][y] == -1) pre[x][y] = u, f[x][y] = i, q.push({x, y});
		}
	}
	x = 0; y = s;
	vi ans;
	while (1) {
		ans.pb(f[x][y]);
		if (pre[x][y].fi == -1) break;
		pii tmp = pre[x][y];
		x = tmp.fi;
		y = tmp.se;
	}
	reverse(all(ans));
	rep(i, 0, sz(ans)) cout << ans[i];
	return 0;
}
