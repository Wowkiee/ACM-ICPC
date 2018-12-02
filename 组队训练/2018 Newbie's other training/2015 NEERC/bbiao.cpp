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
#define pw(a) (1ll<<(a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
//----
vi ans;
ll getdec(ll a) {
	ll ans = 0, base = 1;
	while(a) {
		ans += a % 2 * base;
		base *= 10;
		a >>= 1;
	}
	return ans;
}
ll getdig(ll a) {
	ll ans = 0;
	while(a) {
		ans++;
		a >>= 1;
	}
	return ans;
}
int main() {
	//freopen(".in", "r", stdin);
	//freopen("bbiao.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	/*rep(i,1,100000) {
		ll now = getdec(i);
		ll dig = getdig(i);
		if(now % (1ll << dig) == i)ans.pb(i), de((long long)now);
	}*/

	//de(sz(ans));
	int n = 10, cnt;
	rep(i, 1, n+1) {
		de(i);
		cnt = 0;
		rep(j, 0, i) {
			ll x = ((ll)pow(5, j) % (ll)pow(2, i + 1 - j));
			cout << x << endl;
			if (x == 1) cnt++;
		}
		//cout << pow(2, cnt) << endl;
	}
	return 0;
}
