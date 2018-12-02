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
#define pw(a) (1ll << (a));
#define endl "\n"
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

ll solve(int n, int m, int s) {
	ll ans = 0;
	rep(i, 0, n + 1) rep(j, 0, m + 1) rep(a, 0, n + 1) rep(b, 0, m + 1) if(a != i || b != j) {
		rep(c, 0, n + 1) rep(d, 0, m + 1) if(c != i || d != j) if(a != c || b != d) {
			int x1 = a - i, x2 = c - i;
			int y1 = b - j, y2 = d - j;
			if(x1 * y2 - x2 * y1 == s && x1 * x2 + y1 * y2 == 0) ++ans;
		}
	}
	return ans;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	rep(n, 2, 3) rep(m, n, 20) {
		rep(s, 1, 20) if(solve(n, m, s)) dd(n), dd(m), dd(s), de(solve(n, m, s));
		cout << endl;
	}
	return 0;
}
