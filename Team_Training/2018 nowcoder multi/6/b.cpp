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

const int P = 998244353;

inline int mul(int a, int b) {
	return 1ll * a * b % P;
}
inline int kpow(int a, int b) {
	int r = 1;
	while(b) {
		if(b & 1) r = mul(r, a);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}

void test() {
	int N = 1010, t = 698771050;
	rep(i, 1, N) rep(j, 1, N) {
		if(mul(i, kpow(j, P-2)) == t) dd(i*1./j), dd(i), de(j);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	test();
	return 0;
}
