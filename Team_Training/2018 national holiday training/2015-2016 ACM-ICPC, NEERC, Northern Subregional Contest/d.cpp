#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(x) (int)x.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll<<(a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll inf = 1e18;

ll n;
map<ll, bool> s2, s3;

void solve() {
	cin >> n;
	ll t = 1;
	while(n % 2 == 0) {
		t <<= 1;
		n >>= 1;
	}
	while(n % 3 == 0) {
		t *= 3;
		n /= 3;
	}
	if(n == 1) {
		cout << 1 << endl << t << endl;
	} else {
		for(auto u : s2) if(s3[n - u.fi]) {
			cout << 2 << endl;
			cout << u.fi * t << " " << n * t - u.fi * t << endl;
			break;
		}
	}
}

int main() {
	freopen("distribution.in","r",stdin);
	freopen("distribution.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T;
	cin >> T;
	ll t = 2;
	while(t <= inf) {
		s2[t] = 1;
		t <<= 1;
	}
	t = 3;
	while(t <= inf) {
		s3[t] = 1;
		t *= 3;
	}
	while(T--) solve();
	return 0;
}
