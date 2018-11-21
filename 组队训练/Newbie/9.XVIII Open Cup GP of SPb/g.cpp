
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
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double db;

const int N = 505;
int dx[] = {1, 0, 0};
int dy[] = {0, -1, 1};
int n, x, y, m;
string s[N], ss[N];
bool vis[N][N];

queue<pii> q;

bool check(int x, int y, int p) {
	int xx = x + dx[p];
	int yy = y + dy[p];
	if (xx < 1 || xx > n || yy < 1 || yy > m || s[xx][yy] == '#') return 0;
	return 1;
}

void add(int x, int y, int p) {
	int xx = x + dx[p];	
	int yy = y + dy[p];
	if (vis[xx][yy] == 1) return;
	vis[xx][yy] = 1;
	q.push(mp(xx, yy));
}

int main() {
	freopen("mole.in", "r", stdin);
	freopen("mole.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 1, n+1) {
		cin >> s[i]; ss[i] = s[i];s[i] = ' ' + s[i];
	}
	rep(i, 1, m+1) if (s[1][i] == '.') {
		q.push(mp(1, i));
		vis[1][i] = 1;
	}
	while (!q.empty()) {
		x = q.front().fi; y = q.front().se;
		q.pop();
		if (check(x, y, 0)) {
			//dd(x);de(y);
			add(x, y, 0);
		}else {
			if (check(x, y, 1)) {
				add(x, y, 1);
			}
			if (check(x, y, 2)) {
				add(x, y, 2);
			}
		}
	}
	rep(i, 1, n+1) rep(j, 1, m+1) {
		if (s[i][j] == '.' && vis[i][j] == 0) {
			cout << "Yes" << endl;
			ss[i][j-1] = 'X';
			rep(i, 1, n+1) cout << ss[i] << endl;
			return 0;
		}
	}
	cout << "No";
	return 0;
}
