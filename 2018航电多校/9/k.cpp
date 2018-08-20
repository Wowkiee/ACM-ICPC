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

const int mod = 998244353;
ll sum, w1, w2, w3, ans, a, b, c, d, T; 

ll qpow(ll a, ll b){
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T) {
		cin >> a >> b >> c >> d;
		sum = qpow(2, a + b + c + d);
		w1 = qpow(2, a + c) + qpow(2, a + c) * d + qpow(2, a + c) * b;
		w2 = qpow(2, a + b);
		w3 = qpow(2, a) + qpow(2, a) * b;
		ans = sum - w1 - w2 + w3;
		ans = sum - ans;
		ans = (ans % mod + mod) % mod;
		cout << ans << endl;
	}
	
	return 0;
}
