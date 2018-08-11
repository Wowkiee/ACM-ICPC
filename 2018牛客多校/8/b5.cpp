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

const int N = 603030, P = 998244353;

int mul(int a, int b) {
	return 1ll * a * b % P;
}
int add(int a, int b) {
	int r = a + b;
	if(r >= P) r -= P;
	return r;
}
int sub(int a, int b) {
	int r = a - b;
	if(r < 0) r += P;
	return r;
}

int n;
int jc[N], in[N];

int kpow(int a, int b) {
	int r = 1;
	while(b) {
		if(b & 1) r = mul(r, a);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}

int C(int n, int m) {
	if(n < m) return 0;
	return mul(jc[n], mul(in[m], in[n-m]));
}

void init() {
	jc[0] = 1;
	rep(i, 1, N) jc[i] = mul(jc[i-1], i);
	in[N-1] = kpow(jc[N-1], P-2);
	for(int i = N-2; ~i; --i) in[i] = mul(in[i+1], i+1);
}
int g(int n) {
	return sub(C(2*n-2, n-1), C(2*n-2, n-2));
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	init();
	while(cin >> n) {
		int r = 0;
		rep(i, 0, n) {
			r = add(r, mul(g(n-i), C(2*n-2-i, i)));
		}
		cout << r << endl;
	}
	return 0;
}
