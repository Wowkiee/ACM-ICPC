#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(a) cout << #a << " = " << a << " "
#define de(a) cout << #a << " = " << a << endl
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;

const int N = 66;

int n;
int dig[N];
ll ans = 1e18;
string s;

ll calc(ll x) {
	if(x == 0) return 0;
	int t = -1;
	ll tmp = x;
	while(x) {
		t++;
		x >>= 1;
	}
	x = tmp;
	ll ans = (x - pw(t) + 1) * (t + 1);
	rep(i, 0, t) ans += (i + 1) * pw(i);
	return ans;
}

void solve(int i, int p) {
	ll x = 0, y = 0;
	if(n - p + 1 == i) {
		rep(t, p, n + 1) x = x * 2 + dig[t];
	} else {
		rep(t, p, n + 1) x = x * 2 + dig[t];
		rep(t, max(p - i, 1), p) y = y * 2 + dig[t];
		++y;
		int a[N], b[N], k;
		rep(t, 0, i) a[t] = b[t] = -1;
		ll t = y;
		for(k = 0; t; ++k) {
			b[k] = t & 1;
			t >>= 1;
		}
		if(k > i) return ;
		t = x;
		for(k = 0; t; ++k) {
			a[k] = t & 1;
			t >>= 1;
		}
		for(int t = k - 1; ~t; --t) a[i - k + t] = a[t];
		rep(t, 0, i - k) a[t] = -1;
		rep(t, 0, i) if(a[t] != -1 && b[t] != -1 && a[t] != b[t]) return ;
		rep(t, 0, i) if(a[t] == -1) a[t] = b[t];
		rep(t, 0, i) if(a[t] == -1) a[t] = 0;
		x = 0;
		for(int t = i - 1; ~t; --t) x = x * 2 + a[t];
	}
	ll res = calc(x - 1) + n - p + 1;
	--p;
	y = 0;
	while(p) {
		if(y == 0) --x, y = x;
		if(y == 0) return ;
		if(dig[p] != (y & 1)) return ;
		--p;
		y >>= 1;
	}
	ans = min(ans, res);
}

bool check(ll x, int p) {
	ll y = 0;
	while(p) {
		if(y == 0) --x, y = x;
		if(y == 0) return 0;
		if(dig[p] != (y & 1)) return 0;
		--p;
		y >>= 1;
	}
	return 1;
}

const int MAXN = 101010;
int P = 0;
int Dig[MAXN];
void init() {
	for(ll i = 1; ; ++i) {
		ll x = i;
		vi v;
		while(x) {
			v.pb(x & 1);
			x >>= 1;
		}
		reverse(all(v));
		rep(i, 0, sz(v)) {
			Dig[P++] = v[i];
			if(P == MAXN) return ;
		}
	}
}
bool check(int p) {
	rep(i, 1, n + 1) {
		if(p >= MAXN) return 0;
		if(Dig[p] != dig[i]) {
			return 0;
		}
		p++;
	}
	return 1;
}
int work() {
	rep(i, 0, MAXN) if(check(i)) {
		return i + n;
	}
	return -1;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	init();
	rep(i, 0, 10) cout << Dig[i];cout << endl;
	cin >> n;
	rep(ca, 0, 1 << n) {
		int tt = ca;
		rep(i, 1, n + 1) {
			dig[i] = (tt & 1);
			tt >>= 1;
		}
		ans = 1e18;
		//	cin >> s;
		//	n = sz(s);
		//	rep(i, 0, n) dig[i + 1] = s[i] - '0';
		rep(i, 1, n + 1) {
			rep(p, n - i + 1, n + 1) if(dig[p]) {
				solve(i, p);
			}
		}
		if(dig[1] == 0) {
			rep(i, 1, n + 1) if(dig[i]) {
				ll x = 0;
				rep(j, i, n + 1) x = x * 2 + dig[j];
				x = x * 2;
				rep(j, 1, i) x = x * 2 + dig[j];
				++x;
				ans = min(ans, calc(x - 1) + n - i + 1);
			}
			ll x = 1;
			rep(i, 1, n + 1) x = x * 2 + dig[i];
			ans = min(ans, calc(x));
		}
		int p = 0;
		for(int i = n; i; --i) if(dig[i]) {
			p = i;
			break;
		}
		if(p) rep(len, n - p + 1, n + 2) {
			ll x = pw(len - 1), res = calc(x - 1) + n - p + 1;
			if(check(x, p - 1)) ans = min(ans, res);
		}
		if(ans != work()) {
			rep(i, 1, n + 1) cout << dig[i];cout << endl;
			dd(ans);
			de(work());
			break;
		}
	}
	return 0;
}
