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
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 222, P = 1e9+7;

int add(int a, int b) {
	if((a += b) >= P) a -= P;
	return a;
}
int sub(int a, int b) {
	if((a -= b) < 0) a += P;
	return a;
}
int mul(int a, int b) {
	return 1ll * a * b % P;
}
int kpow(int a, int b) {
	int r = 1;
	while(b) {
		if(b & 1) r = mul(r, a);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}

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
			if(2 * L <= n) {
				L = n + 1 - L, B = T, b = d, m = 1;
			} else {
				++m;
			}
		}
	}
	reverse(all(C));
	rep(i, 0, sz(C)) C[i] = P - C[i];
	return vi(C.begin(), C.end() - 1);
}

int linear_recurrence(ll n, int m, vi a, vi c) {
	vector<ll> v(m, 0), u(m<<1, 0);
	v[0] = 1;
	for(ll x = 0, W = n ? 1ll<<(63 - __builtin_clzll(n)) : 0; W; W >>= 1, x <<= 1) {
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

namespace S {
	int n;
	int a[N][N];
	int det() {
		int ans = 1;
		rep(i, 1, n) {
			rep(j, i+1, n) while(a[j][i]) {
				int t = a[i][i] / a[j][i];
				rep(k, i, n) a[i][k] = sub(a[i][k], mul(a[j][k], t));
				rep(k, i, n) swap(a[i][k], a[j][k]);
				ans = P - ans;
			}
			if(a[i][i] == 0) return 0;
			ans = mul(ans, a[i][i]);
		}
		return ans;
	}

	int solve(int k, int n) {
		memset(a, 0, sizeof(a));
		rep(i, 0, n) {
			a[i][i] = k;
			rep(j, 1, k+1) a[i][(i+j)%n] = P-1;
		}
		S::n = n;
		return det();
	}
}

int len;
vi s;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int k, n;
	cin >> k >> n;
	rep(i, 2*k+1, N) s.pb(S::solve(k, i));
	vi T = BM(s);
	int ans = linear_recurrence(n - 2 * k - 1, sz(T), s, T);
	int res = 1;
	rep(i, 1, k) res = mul(res, i);
	ans = mul(ans, kpow(res, n));
	cout << ans << endl;
	return 0;
}
