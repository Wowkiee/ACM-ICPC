#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(a) cout << #a << " = " << a << " "
#define de(a) cout << #a << " = " << a << endl
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double db;

const int N = 22;

int k, w, h, n;
int msk[N], cnt[N], a[N][N], p[N];
bool o[N][4];
char s[N][N][N], ans[N][N];

bool check(int i, int o) {
	if(o == 0) {
		rep(t, w - 1, 2 * w - 1) if(s[i][h - 2][t] != '.' || s[i][h - 1][t] == '.') return 0;
	} else if(o == 1) {
		rep(t, h - 1, 2 * h - 1) if(s[i][t][w - 2] != '.' || s[i][t][w - 1] == '.') return 0;
	} else if(o == 2) {
		rep(t, w - 1, 2 * w - 1) if(s[i][2 * h - 2][t] == '.' || s[i][2 * h - 1][t] != '.') return 0;
	} else {
		rep(t, h - 1, 2 * h - 1) if(s[i][t][2 * w - 2] == '.' || s[i][t][2 * w - 1] != '.') return 0;
	}
	return 1;
}

void Set(int i, int x, int y) {
	rep(a, 0, 3 * h - 2) rep(b, 0, 3 * w - 2) {
		int xx = x - h + 1 + a, yy = y - w + 1 + b;
		if('A' <= s[i][a][b] && s[i][a][b] <= 'Z' && 0 <= xx && xx < n * h && 0 <= yy && yy < n * w) {
			s[i][a][b] = 'A' + i;
			ans[xx][yy] = s[i][a][b];
		}
	}
}
void gao() {
	rep(i, 0, k) if(o[i][0] && o[i][1]) {
		Set(i, 0, 0);
		break;
	}
	rep(i, 0, k) if(o[i][1] && o[i][2]) {
		Set(i, (n - 1) * h, 0);
		break;
	}
	rep(i, 0, k) if(o[i][2] && o[i][3]) {
		Set(i, (n - 1) * h, (n - 1) * w);
		break;
	}
	rep(i, 0, k) if(o[i][3] && o[i][0]) {
		Set(i, 0, (n - 1) * w);
		break;
	}
}
void Reset() {
	rep(i, 0, n * h) rep(j, 0, n * w) ans[i][j] = '.';
}

bool check() {
	rep(i, 0, n * h) rep(j, 0, n * h) if(ans[i][j] == '.') return 0;
	return 1;
}

void solve() {
	Reset();
	gao();
	do {
		do {
			do {
				do {
					do {
						Set(a[0][0], 0, w);
						Set(a[0][1], 0, w * 2);
						Set(a[1][0], h, 0);
						Set(a[1][1], h * 2, 0);
						Set(a[2][0], (n - 1) * h, w);
						Set(a[2][1], (n - 1) * h, 2 * w);
						Set(a[3][0], h, (n - 1) * w);
						Set(a[3][1], h * 2, (n - 1) * w);
						Set(a[4][0], h, w);
						Set(a[4][1], h + h, w);
						Set(a[4][2], h, w + w);
						Set(a[4][3], h + h, w + w);
					} while(next_permutation(a[4], a[4] + 4));
				} while(next_permutation(a[3], a[3] + 2));
			} while(next_permutation(a[2], a[2] + 2));
		} while(next_permutation(a[1], a[1] + 2));
	} while(next_permutation(a[0], a[0] + 2));
	if(check()) return ;
}

int main() {
//	freopen("ascii.in", "r", stdin);
//	freopen("ascii.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> k >> w >> h;
	rep(i, 0, k) {
		rep(j, 0, 3 * h - 2) cin >> s[i][j];
		bool find = 0;
		rep(t, 0, 4) {
			bool _ = o[i][t] = check(i, t);
			if(_) msk[t] |= pw(i), find = 1, ++cnt[i];
		}
		if(!find) msk[4] |= pw(i);
	}
	for(n = 1; ; ++n) if(n * n == k) break;
	if(k == 1) {
		rep(i, 0, h) rep(j, 0, w) ans[i][j] = 'A';
	} else if(k == 4) {
		gao();
	} else if(k == 9) {
		Reset();
		gao();
		rep(i, 0, k) if(o[i][0] && cnt[i] == 1) {
			Set(i, 0, w);
			break;
		}
		rep(i, 0, k) if(o[i][1] && cnt[i] == 1) {
			Set(i, h, 0);
			break;
		}
		rep(i, 0, k) if(o[i][2] && cnt[i] == 1) {
			Set(i, (n - 1) * h, w);
			break;
		}
		rep(i, 0, k) if(o[i][3] && cnt[i] == 1) {
			Set(i, h, (n - 1) * w);
			break;
		}
		rep(i, 0, k) if(cnt[i] == 0) {
			Set(i, h, w);
			break;
		}
	} else {
		memset(p, 0, sizeof(p));
		rep(i, 0, k) {
			if(cnt[i] == 2) {
				if(o[i][0] && o[i][1]) {
					a[5][p[5]++] = i;
				} else if(o[i][1] && o[i][2]) {
					a[6][p[6]++] = i;
				} else if(o[i][2] && o[i][3]) {
					a[7][p[7]++] = i;
				} else {
					a[8][p[8]++] = i;
				}
			} else if(cnt[i] == 1) {
				if(o[i][0]) {
					a[0][p[0]++] = i;
				} else if(o[i][1]) {
					a[1][p[1]++] = i;
				} else if(o[i][2]) {
					a[2][p[2]++] = i;
				} else {
					a[3][p[3]++] = i;
				}
			} else {
				a[4][p[4]++] = i;
			}
		}
		solve();
	}
	cout << n * w << " " << n * h << endl;
	rep(i, 0, n * h) {
		rep(j, 0, n * w) cout << ans[i][j];
		cout << endl;
	}
	return 0;
}
