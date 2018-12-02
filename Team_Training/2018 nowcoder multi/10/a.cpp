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

const int N = 1e5 + 7;
const int mod = 998244353;

int n, l, r, a[N], m, op, T;

ll qpow(ll a, ll b){
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

int mul(int x, int y) {
	return 1ll * x * y % mod;	
}

int add(int x, int y) {
	x = (x + y) % mod;
	if (x < 0) x += mod;
	return x;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n >> m;
		int w = qpow(2, 1ll * n * m);
		rep(i, 1, n+1) cin >> a[i], a[i] = add(a[i-1], a[i]);
		rep(i, 1, m+1) {
			cin >> op >> l >> r;
			if (op == 2) {
				cout << mul(add(a[r], -a[l-1]), w) << endl;
			}
		
		}
	}
	return 0;
}
