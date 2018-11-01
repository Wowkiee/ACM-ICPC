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
#define pw(a) (1ll << (a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 101010;

int n, len;
bool vis[N];
vi ans;
string s;

void dfs(int p) {
	if(p == len) {
		rep(i, 0, n) cout << ans[i] << " \n"[i == n - 1];
		exit(0);
	}
	int x = s[p] - '0';
	if(!x) return ;
	if(!vis[x] && x >= 1 && x <= n) {
		vis[x] = 1;
		ans.pb(x);
		dfs(p + 1);
		vis[x] = 0;
		ans.pop_back();
	}
	if(p + 1 >= len) return ;
	x = x * 10 + s[p + 1] - '0';
	if(!vis[x] && x >= 1 && x <= n) {
		vis[x] = 1;
		ans.pb(x);
		dfs(p + 2);
		vis[x] = 0;
		ans.pop_back();
	}
}

int main() {
//	freopen("joke.in", "r", stdin);
//	freopen("joke.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> s;
	len = sz(s);
	if(len <= 9) n = len;
	else n = (len + 9) / 2;
	dfs(0);
	return 0;
}
