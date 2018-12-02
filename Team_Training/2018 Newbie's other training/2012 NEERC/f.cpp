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

const int N = 22;

int n = 15, top;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int a[][2] = {0, 0, 1, 0, 2, 0, 2, 3, 2, 6, 1, 6, 0, 6, 0, 7, 0, 8, 1, 8, 1, 7, 2, 7, 2 ,4 ,2, 1,1, 1, 0, 1, 0, 2, 0, 5, 0, 4, 0, 3, 1, 3, 1, 4, 1, 5 ,1, 2, 2, 2, 2, 5, 2, 8};
char s[N][N], sta[N * N], ans[3][9];
bool vis[N][N];

void dfs(int i, int j) {
	vis[i][j] = 1;
	sta[++top] = s[i][j];
	if(top == 27) {
		rep(i, 0, 27) ans[a[i][0]][a[i][1]] = sta[i + 1];
		rep(i, 0, 3) {
			rep(j, 0, 9) {
				cout << ans[i][j];
				if(j % 3 == 2 && j != 8) cout << " ";
			}
			cout << endl;
		}
		exit(0);
	}
	rep(t, 0, 4) {
		int x = i + dx[t], y = j + dy[t];
		if(0 <= x && x < n && 0 <= y && y < n && s[x][y] != '.' && !vis[x][y]) dfs(x, y);
	}
	vis[i][j] = 0;
	--top;
}

int main() {
	freopen("folding.in", "r", stdin);
	freopen("folding.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	rep(i, 0, n) cin >> s[i];
	rep(i, 0, n) rep(j, 0, n) if(s[i][j] != '.') {
		top = 0;
		memset(vis, 0, sizeof(vis));
		dfs(i, j);
	}
	return 0;
}
