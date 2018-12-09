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
#define pw(a) (1ll << (a))
typedef long long ll;
typedef pair<int, int> pii;
typedef double db;
typedef vector<int> vi;

const int N = 303030;

int n, m, xl, xr, yl, yr, dx, dy;
int x[N], y[N];
pii p[N];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		rep(i, 1, n + 1) {
			int a, b;
			cin >> a >> b;
			p[i] = mp(a, b);
			x[a] = i, y[b] = i;
		}
		xl = yl = 1, xr = yr = n;
		while(m--) {
			char op[11];
			cin >> op;
			int k;
			if(op[0] != '!') cin >> k;
			if(op[0] == 'L') {
				int t = max(1, xr - k);
			} else if(op[0] == 'R') {
			} else if(op[0] == 'U') {
			} else if(op[0] == 'D') {
			} else if(op[0] == '?') {
			} else {
			}
		}
	}
	return 0;
}
