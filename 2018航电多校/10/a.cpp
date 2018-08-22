#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 998244353;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---

vi BM(vi s) {
	vi C(1, 1), B(1, 1);
	int L = 0, m = 1, b = 1;
	rep(n, 0, sz(s)) {
		ll d = 0;
		rep(i, 0, L+1) (d += 1ll * C[i] * s[n-i]) %= P;
		if(d == 0) ++m;
		else {
			vi T = C;
			ll c = P - d * kpow(b, P - 2) % P;
			while(sz(C) < sz(B) + m) C.pb(0);
			rep(i, 0, sz(B)) C[i + m] = add(C[i + m], mul(c, B[i]));
			if(2 * L <= n) L = n + 1 - L, B = T, b = d, m = 1;
			else ++m;
		}
	}
	reverse(all(C));
	rep(i, 0, sz(C)) C[i] = P - C[i];
	return vi(C.begin(), C.end() - 1);
}
int linear(ll n, int m, vi a, vi c) {
	vector<ll> v(m, 0), u(m<<1, 0);
	v[0] = 1;
	for(ll x = 0, W = n ? 1ll << (63 - __builtin_clzll(n))  : 0; W; W >>= 1, x <<= 1) {
		fill(all(u), 0);
		int b = !!(n & W); if(b) x++;
		if(x < m) u[x] = 1;
		else {
			rep(i, 0, m) rep(j, 0, m) (u[i + b + j] += v[i] * v[j]) %= P;
			per(i, m, 2*m) rep(j, 0, m) (u[i - m + j] += c[j] * u[i]) %= P;
		}
		copy(u.begin(), u.begin() + m, v.begin());
	}
	ll ans = 0;
	rep(i, 0, m) (ans += v[i] * a[i]) %= P;
	return ans;
}

int A[] = {1, 1, 1, 2, 3, 5, 9, 18, 35}, B[] = {1, 1, 2, 4, 8, 17, 39, 89, 211};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n = 9;
	vi a, b;
	rep(i, 0, n) a.pb(A[i]), b.pb(B[i]);
	vi x = BM(a), y = BM(b);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		cout << linear(n - 1, sz(x), a, x) << " " << linear(n - 1, sz(y), b, y) << endl;
	}
	return 0;
}
