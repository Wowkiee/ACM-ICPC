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

const int N = 1e5 + 7;
ll ans, T, n, x, a[N], cntl, cntr, sl, sr, l, r;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n;
		ans = 0;
		a[1] = 0;
		rep(i, 2, n+1) cin >> x, a[i] = a[i-1] + x;
		l = 1; r = n;
		sl = sr = 0;
		cntl = cntr = 0;
		rep(i, 1, n+1) {
			if (i & 1) {
				ans += a[l] * cntl - sl + sr - a[l] * cntr;
				cntl++;
				sl += a[l];
				l++;
			}else {
				ans += a[r] * cntl - sl + sr - a[r] * cntr;
				cntr++;
				sr += a[r];
				r--;
			}
			cout << ans;
			if (i == n) cout << endl;else cout << " ";
		}
	}
	return 0;
}
