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
#define pw(x) (1ll << (x))
#define all(x) x.begin(), x.end()
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n; cin >> n; n++;
	vector<pii> ans;
	if(n <= 51) {
		n -= 2;
		rep(i, 1, 8) {
			if(i & 1)rep(j, 1, 8) {
				if(sz(ans) < n)ans.pb(mp(i, j));
			}
			else per(j, 1, 8) {
				if(sz(ans) < n)ans.pb(mp(i, j));
			}
		}
		ans.pb(mp(8, ans.back().se));
		ans.pb(mp(8, 8));
	}
	else if(n <= 58) {
		n -= 2;
		rep(i, 1, 9)if(sz(ans) < n)ans.pb(mp(1, i));
		per(j, 1, 9) {
			if(j & 1)per(i, 2, 8) {
				if(sz(ans) < n)ans.pb(mp(i, j));
			}
			else rep(i, 2, 8) {
				if(sz(ans) < n)ans.pb(mp(i, j));
			}
		}
		ans.pb(mp(8, ans.back().se));
		ans.pb(mp(8, 8));
	}
	else {
		n--;
		rep(i, 1, 9)if(sz(ans) < n)ans.pb(mp(1, i));
		per(j, 1, 9) {
			if(j & 1)per(i, 2, 8) {
				if(sz(ans) < n)ans.pb(mp(i, j));
			}
			else rep(i, 2, 8) {
				if(sz(ans) < n)ans.pb(mp(i, j));
			}
		}
		rep(i, 1, 8)if(sz(ans) < n)ans.pb(mp(8, i));
		ans.pb(mp(8, 8));
	}
	rep(i, 0, sz(ans))cout <<  (char)(ans[i].se + 'a' - 1) << ans[i].fi << " \n"[i == sz(ans) - 1];
	return 0;
}
