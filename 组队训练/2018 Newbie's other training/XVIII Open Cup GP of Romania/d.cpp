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
#define pw(a) (1ll << (a))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;

const int N = 66;

string s;

bool check(ll x) {
	vi v;
	while(sz(v) < sz(s)) {
		if(x <= 0) {
			return 0;
		}
		ll t = x;
		while(t) {
			v.pb(t & 1);
			t >>= 1;
		}
		--x;
	}
	rep(i, 0, sz(s)) if(s[i] - '0' != v[i]) {
		return 0;
	}
	return 1;
}
ll calc(ll x) {
	int t = -1;
	ll tmp = x;
	while(x) {
		t++;
		x >>= 1;
	}
	x = tmp;
	ll ans = (x - pw(t) + 1) * (t + 1);
	rep(i, 0, t) ans += (i + 1) * pw(i);
	return ans;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> s;
	reverse(all(s));
	ll x = 0;
	rep(i, 0, sz(s)) {
		x += pw(i) * (s[i] - '0');
		if(s[i] == '1' && check(x)) {
			cout << calc(x) << endl;
			return 0;
		}
	}
	cout << calc(x + pw(sz(s))) << endl;
	return 0;
}
