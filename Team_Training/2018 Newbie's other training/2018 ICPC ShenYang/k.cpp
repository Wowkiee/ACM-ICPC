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
#define endl "\n"
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;

ll T, n, m, k, x, cnt;

ll get(ll n, ll m, ll k) {
	ll x = k % (n - m + 1);
	if (x == 0) x = n - m;
	else x--;	
	for(ll i = n - m + 2; i <= n; i++) x = (x + k) % i;
	return x;
}

ll solve(ll n, ll m, ll k, ll st) {
	cnt++;
	assert(cnt <= 500000);
	assert(n > 0);
	assert(m > 0);
	assert(n >= m);
	//<F2>if (cnt > 260000) return 0;
	if (m <= k) return (get(n, m, k) - st + n) % n;
	ll z = (n + st) / k;
	ll p;
	if (m <= z) {
		assert(m * k - 1 - st >= 0);
		return m * k - 1 - st;
	}
	p = solve(n - z, m - z, k, (n + st) % k);
	//de(p);
	ll l = 1, r = n, mid, res = 0;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (mid - (mid + st) / k >= p+1) {
			res = mid;
			r = mid - 1;
		}else l = mid + 1;
	}
	assert(res >= 1);
	return res - 1;
}


int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	n = 1e18; k = 2e6;
	while (n > k) {
		cnt ++;
		n -= n / k;
	}
	de(cnt);
	cin >> T;
	rep(cas, 0, T) {
		cnt = 0;
		cout << "Case #" << cas +1 << ": ";
		cin >> n >> m >> k;
		//de(get(n, m, k) + 1);
		if (m <= k) cout << get(n, m, k) + 1 << endl;
		else cout << solve(n, m, k, 0) + 1<< endl;
	//	de(cnt);
	}
	return 0;
}
