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
const int N = 1005, M = 4005;
pii dp[N][M];
vector<int> V[N];
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	memset(dp, -1, sizeof dp);
	dp[0][0] = mp(0, 0);
	rep(i, 1, 32)for(int j = i; i * j <= 1000 && i + j <= 1000; j++)V[i * j].pb(i + j);
	rep(i, 1, 1001) {
		sort(all(V[i]));
		V[i].erase(unique(all(V[i])), V[i].end());
	}
	queue<pii> Q; Q.push(mp(0, 0));
	while(!Q.empty()) {
		pii f = Q.front(); Q.pop();
		rep(i, 1, 1000 - f.fi + 1)rep(j, 0, sz(V[i])) {
			pii now = mp(f.fi + i, + f.se + V[i][j]);
			if(now.se > 1000)break;
			if(dp[now.fi][now.se].fi != -1)continue;
			dp[now.fi][now.se] = f; Q.push(now);
		}
	}
	return 0;
}
