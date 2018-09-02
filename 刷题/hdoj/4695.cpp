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

const int N = 222, P = 1e9 + 7;

ll k;
bool vis[N];
int n, m, ma;
int a[N], b[N], len[N], f[N];

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
int linear(ll n, int m, int a[], int c[]) {
	vector<ll> v(m, 0), u(m<<1, 0);
	v[0] = 1;
	for(ll x = 0, W = n ? 1ll << (63 - __builtin_clzll(n)) : 0; W; W >>= 1, x <<= 1) {
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

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	while(cin >> k) {
		///init
		ma = 0;
		///read
		cin >> n;
		rep(i, 1, n+1) cin >> a[i];
		cin >> m;
		rep(i, 1, m+1) cin >> b[i], ma = max(ma, b[i]);
		///get vis
		rep(i, 0, ma+1) vis[i] = 0;
		rep(i, 1, m+1) vis[b[i]] = 1;
		///get len
		len[0] = 1;
		rep(i, 1, ma+1) {
			len[i] = 0;
			rep(j, 1, n+1) if(i - a[j] >= 0) {
				len[i] = add(len[i], len[i - a[j]]);
			}
		}
		rep(i, 1, ma+1) if(!vis[i]) len[i] = 0;
		///get f
		f[0] = 1;
		rep(i, 1, ma+1) {
			f[i] = 0;
			rep(j, 0, i) f[i] = add(f[i], mul(f[j], len[i - j]));
		}
		///solve
		reverse(len + 1, len + 1 + ma);
		cout << linear(k-1, ma, f+1, len+1) << endl;
	}
	return 0;
}
