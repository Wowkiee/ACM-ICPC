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
//----
const int N = 1005, M = 2005;
pii dp[N][M];
bool f[N][M];
int a, b, T, n, m;
vector<int> V[N];
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	//memset(dp, -1, sizeof dp);
	//dp[0][0] = 0;
	rep(i, 1, 32)for(int j = i; i * j <= 1000 && i + j <= 2000; j++)V[i * j].pb(i + j);
	rep(i, 1, 1001) {
		sort(all(V[i]));
		V[i].erase(unique(all(V[i])), V[i].end());
	}
	/*queue<pii> Q; Q.push(mp(0, 0));
	while(!Q.empty()) {
		pii f = Q.front(); Q.pop();
		rep(i, 1, 1000 - f.fi + 1)rep(j, 0, sz(V[i])) {
			pii now = mp(f.fi + i, + f.se + V[i][j]);
			if(now.se > 1000)break;
			if(dp[now.fi][now.se].fi != -1)continue;
			dp[now.fi][now.se] = f; Q.push(now);
		}
	}*/
	int cnt = 0;
	f[0][0] = 1;
	rep(i, 1, 1001) {
		rep(j, 0, sz(V[i])) {
			a = i; b = V[i][j];
			//cnt1++;
			if (f[a][b]) continue;
			//cnt2++;
			rep(k, a, 1001)
				rep(l, b, 2001) {
					if (!f[k][l] && f[k-a][l-b]) {
						f[k][l] = 1;
						dp[k][l] = mp(a, b);
					} 
				}//f[k][l] |= f[k-a][l-b];
		}
	}
	cin >> T;
	rep(cas, 0, T) {
		cin >> n >> m;
		if (m % 2 != 0) {
			cout << "No" << endl;
			continue;
		}
		m /= 2;cnt = 0;
		if (f[n][m] == 1) {
			vector<pii> ans;
			cout << "Yes" << endl;
			while (n > 0 || m > 0) {
				a = dp[n][m].fi; b = dp[n][m].se;
				n -= a; m -= b;
				rep(i, 1, b) if (i * (b - i) == a) {
					//cout << i << " " <<  b - i << endl;
					ans.pb(mp(i, b - i));
					break;
				}
				cnt++;
			}
			cout << cnt << endl;
			rep(i, 0, sz(ans)) cout << ans[i].fi << " " << ans[i].se << endl;
		}else cout << "No" << endl;
	}
	//cout << cnt1 << " " << cnt2;
	return 0;
}
