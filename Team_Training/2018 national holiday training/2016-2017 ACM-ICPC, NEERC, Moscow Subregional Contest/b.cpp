#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

ll l, r, w;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> l >> r >> w;
	ll d = __gcd(r, w);
	ll x = (r - 1) / d * d;
	if(x > l - w) {
		cout << "DEADLOCK" << endl;
	} else {
		cout << "OK" << endl;
	}
	return 0;
}
