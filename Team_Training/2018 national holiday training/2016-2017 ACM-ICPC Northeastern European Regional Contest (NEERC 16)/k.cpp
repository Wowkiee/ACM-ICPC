#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1010, AD = 1000;

int n[3], m[3], dx[3], dy[3];
int g[N * 3][N * 3];
pii u[3];
string s[3][N];

bool solve(int a, int b, int c) {
	memset(g, 0, sizeof(g));
	rep(i, 0, n[a]) rep(j, 0, m[a]) if(s[a][i][j] == '*') {
		g[i + AD][j + AD] = 1;
	}
	dx[1] = u[b].fi - u[a].fi;
	dy[1] = u[b].se - u[a].se;
	rep(i, 0, n[b]) rep(j, 0, m[b]) if(s[b][i][j] == '*') {
		g[i + AD - dx[1]][j + AD - dy[1]] ^= 1;
	}
	int x = 0, y = 0;
	bool find = 0;
	for(int i = 0; !find && i < N * 3; ++i) rep(j, 0, N * 3) if(g[i][j]) {
		x = i, y = j;
		find = 1;
		break;
	}
	if(!find) return 0;
	dx[2] = u[c].fi + AD - x;
	dy[2] = u[c].se + AD - y;
	int cnt = 0;
	rep(i, 0, N * 3) rep(j, 0, N * 3) {
		cnt += g[i][j];
	}
	rep(i, 0, n[c]) rep(j, 0, m[c]) if(s[c][i][j] == '*') {
		--cnt;
		if(cnt < 0 || !g[i + AD - dx[2]][j + AD - dy[2]]) return 0;
	}
	return cnt == 0;
}
pii get(int o) {
	rep(i, 0, n[o]) rep(j, 0, m[o]) if(s[o][i][j] == '*') return mp(i, j);
}

int main() {
	freopen("kids.in", "r", stdin);
	freopen("kids.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	rep(o, 0, 3) {
		cin >> n[o] >> m[o];
		rep(i, 0, n[o]) cin >> s[o][i];
	}
	rep(o, 0, 3) u[o] = get(o);
	solve(0, 1, 2);
	if(solve(0, 1, 2)) {
		cout << "YES" << endl;
		cout << -dy[1] << " " << -dx[1] << endl;
		return 0;
	} else if(solve(0, 2, 1)) {
		cout << "YES" << endl;
		cout << -dy[2] << " " << -dx[2] << endl;
		return 0;
	} else if(solve(1, 2, 0)) {
		cout << "YES" << endl;
		cout << dy[2] - dy[0] << " " << dx[2] - dx[0] << endl;
		return 0;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
