#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 222;

int n, m;
char s[N][N];

void solve() {
	if(m >= 6 && n % 2 == 0 && m % 2 == 0) {
		rep(j, 2, m) {
			s[1][j] = '(';
			s[n][j] = ')';
		}
		rep(i, 2, n) {
			s[i][1] = '(';
			s[i][m] = ')';
		}
		rep(i, 2, n) rep(j, 2, m) {
			if((i+j) & 1) {
				s[i][j] = ')';
			} else {
				s[i][j] = '(';
			}
		}
	} else {
		rep(i, 1, n+1) {
			if(i & 1) {
				for(int j = 1; j < m; j += 2) {
					s[i][j] = '(';
					s[i][j+1] = ')';
				}
			} else {
				for(int j = 2; j < m-1; j += 2) {
					s[i][j] = '(';
					s[i][j+1] = ')';
				}
				s[i][1] = '(';
				s[i][m] = ')';
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		bool f = 0;
		if(n % 2 == 0 && m % 2 == 1) {
			swap(n, m);
			f = 1;
		} else if(n % 2 == 0 && m % 2 == 0 && n < m) {
			swap(n, m);
			f = 1;
		}
		rep(i, 1, n+1) rep(j, 1, m+1) s[i][j] = '(';
		solve();
		if(f) {
			rep(i, 1, m+1) {
				rep(j, 1, n+1) {
					cout << s[j][i];
				}
				cout << endl;
			}
		} else {
			rep(i, 1, n+1) {
				rep(j, 1, m+1) {
					cout << s[i][j];
				}
				cout << endl;
			}
		}
	}
	return 0;
}
