#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(a) cout << #a << " = " << a << " "
#define de(a) cout << #a << " = " << a << endl
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;

const int N = 5005;
short f[N][N][2]; 
int a[N], s, sum, sum2, ss[N], T, n, p, x;

int solve(int l, int r, int o) {
	if (l == r) return o ^ a[l];
	if (f[l][r][o] != -1) return f[l][r][o];
	//int x = (ss[r] ^ ss[l-1]);
	//x = ss[s] ^ x;
	int t1 = solve(l, r-1, ss[r-1] ^ ss[l-1] ^ ss[n] ^ (o ^ a[r]));
	int t2 = solve(l+1, r, ss[r] ^ ss[l] ^ ss[n] ^ (o ^ a[l]));
	if (t1 == t2 && t1 == 1) f[l][r][o] = 0;else f[l][r][o] = 1;
	return f[l][r][o];
}

/*void dfs(int n) {
	if (n > s) {
		int cnt = 0;
		//sum++;
		rep(i, 1, s + 1) cnt ^= a[i];
		if (cnt == 0) return;	
		sum++;
		rep(i, 1, s + 1) rep(j, i, s + 1) f[i][j][0] = f[i][j][1]  = -1;	
		rep(i, 1, s + 1) ss[i] = ss[i-1] ^ a[i];
		int res = solve(1, s, 0);
		if (res == 0) return;
		sum2++;
		//rep(i, 1, s + 1) cout << a[i];
		//cout << endl;
		//de(res);
		return;
	}
	a[n] = 0;
	dfs(n + 1);
	a[n] = 1;
	dfs(n + 1);
}*/

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n;
		x = 0;
		rep(i, 1, n+1) cin >> a[i], x ^= a[i];
		//de(x);
		if (x == 0) {
			cout << "Draw" << endl;
			continue;
		}
		per(i, 0, 31) if (pw(i) & x) {
			p = i;break;
		}
		rep(i, 1, n+1) a[i] = (a[i] & pw(p)) > 0;
		if (n > 5000) {
			if (n % 2 == 0) cout << "First" << endl;
			else {
				if(!a[1] && !a[n]) cout << "Second" << endl;
				else cout << "First" << endl;
			}
			continue;
		}
		//rep(i, 1, n+1) dd(a[i]);
		rep(i, 1, n + 1) rep(j, i, n + 1) f[i][j][0] = f[i][j][1]  = -1;	
		rep(i, 1, n + 1) ss[i] = ss[i-1] ^ a[i];
		int ans = solve(1, n, 0);
		if (ans) cout << "First" << endl;
		else cout << "Second" << endl;
	}
	return 0;
}
