#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 1010, P = 998244353;

ll dis[N][N];

bool check(ll x) {
	ll t = sqrt(x);
	return t * t == x;
}

ll solve(int n) {
	rep(i, 1, n+1) rep(j, i+1, n+1) {
		for(int k = 1; ; ++k) {
			if(check(1ll * i * j * k)) {
				dis[i][j] = dis[j][i] = k;
				break;
			}
		}
	}
	rep(k, 1, n+1) rep(i, 1, n+1) rep(j, 1, n+1) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	ll ans = 0;
	rep(i, 1, n+1) rep(j, i+1, n+1) ans += dis[i][j];
	return ans;
}

ll kpow(ll a, ll b) {
	ll r = 1;
	while(b) {
		if(b & 1) (r *= a) %= P;
		(a *= a) %= P;
		b >>= 1;
	}
	return r;
}

vi BM(vi s) {
	vi C(1, 1), B(1, 1);
	int L = 0, m = 1, b = 1;
	rep(n, 0, sz(s)) {
		ll d = 0;
		rep(i, 0, L+1) d = (d + 1ll * C[i] * s[n-i]) % P;
		if(d == 0) ++m;
		else if(2 * L <= n) {
			vi T = C;
			ll c = P - d * kpow(b, P-2) % P;
			while(sz(C) < sz(B) + m) C.pb(0);
			rep(i, 0, sz(B)) C[i+m] = (C[i+m] + c * B[i]) % P;
			L = n + 1 - L, B = T, b = d, m = 1;
		} else {
			ll c = P - d * kpow(b, P-2) % P;
			while(sz(C) < sz(B) + m) C.pb(0);
			rep(i, 0, sz(B)) C[i + m] = (C[i + m] + c * B[i]) % P;
			++m;
		}
	}
	return C;
	reverse(all(C));
	rep(i, 0, sz(C)) C[i] = P - C[i];
	return vi(C.begin(), C.end()-1);
}

int linear(ll n, int m, vi a, vi c) {
	vector<ll> v(m, 0), u(m<<1, 0);
	v[0] = 1;
	for(ll x = 0, W = n ? 1ll<<(63 - __builtin_clzll(n)) : 0; W; W >>= 1, x <<= 1) {
		fill(all(u), 0);
		int b = !!(n & W); if(b) x++;
		if(x < m) u[x] = 1;
		else {
			rep(i, 0, m) rep(j, 0, m) (u[i + b + j] += v[i] * v[j]) %= P;
			per(i, m, 2*m) rep(j, 0, m) (u[i - m + j] += c[i] * u[i]) %= P;
		}
		copy(u.begin(), u.begin() + m, v.begin());
	}
	ll ans = 0;
	rep(i, 0, m) (ans += v[i] * a[i]) %= P;
	return ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	rep(i, 1, 111) dd(i), de(solve(i));
	return 0;
	vi s;
	rep(i, 1, 111) s.pb(solve(i));
	vi t = BM(s);

	rep(i, sz(t), sz(s)) {
		ll c = 0;
		rep(j, 0, sz(t)) (c += 1ll * s[i - j] * t[j]) %= P;
		de(c - s[i]);
	}

	int T;
	cin >> T;
	while(T--) {
		ll n;
		cin >> n;
		cout << linear(n-1, sz(t), vi(s.begin(), s.begin()+sz(t)), t) << endl;
	}
	return 0;
}
