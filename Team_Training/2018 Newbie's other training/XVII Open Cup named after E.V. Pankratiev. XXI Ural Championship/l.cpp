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

const int M = 1594323 + 7, N = 13;

int n, top[2], pw[N];
char s[N + 2][N + 2];
bool vis[N][M];
pair<pii, ll> que[M][2];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	pw[0] = 1;
	rep(i, 1, N) pw[i] = pw[i - 1] * 3;
	cin >> n;
	rep(i, 0, n + 2) cin >> s[i];
	int msk = 0;
	rep(i, 1, n + 1) {
		int t = (s[0][i] != '#') + (s[n + 1][i] != '#');
		msk += t * pw[i - 1];
	}
	int o = 0;
	top[o] = 0;
	que[++top[o]][o] = mp(mp(0, msk), 1);
	rep(i, 0, n + 1) {
		int o = (i & 1);
		top[o ^ 1] = 0;
		rep(j, 1, top[o] + 1) {
			int x = que[j][o].fi.fi, y = que[j][o].fi.se;
			ll w = que[j][o].se;
		}
	}
	return 0;
}
