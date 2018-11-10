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
#define pw(a) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 202020;

int n, top;
int cnt[4], sta[N];
bool Find;
bool vis[N];

void dfs(int x) {
	if(Find) return ;
	vis[x] = 1;
	sta[++top] = x;
	if(top == n) {
		Find = 1;
		rep(i, 1, top + 1) cout << sta[i] << " \n"[i == top];
		return ;
	}
	int p[4];
	rep(i, 1, 4) p[i] = i;
	random_shuffle(p + 1, p + 4);
	rep(i, 1, 4) if(cnt[p[i]]) {
		--cnt[p[i]];
		if(x + p[i] < n && !vis[x + p[i]]) dfs(x + p[i]);
		if(x - p[i] > 0 && !vis[x - p[i]]) dfs(x - p[i]);
		++cnt[p[i]];
	}
	vis[x] = 0;
	--top;
}

int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	srand(time(0));
	int T;
	cin >> T;
	while(T--) {
		Find = top = 0, n = 1;
		rep(i, 1, 4) cin >> cnt[i], n += cnt[i];
		fill_n(vis + 1, n, 0);
		dfs(0);
	}
	return 0;
}
