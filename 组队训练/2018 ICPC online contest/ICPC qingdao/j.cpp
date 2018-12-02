
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
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---

int T;
ll a, b, c, d, v, t;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T) {
		cin >> a >> b >> c >> d >> v >> t;
		ll ans = (t / a + 1) * b + (t / c + 1) * d;
		if (a <= v || c <= v) {
			cout << ans - 1 << endl;
			continue;
		}
		int g = __gcd(a, c);
		int tmp = 1;
		int r1 = c / g;
		int r2 = a / g;
		rep(i, 1, r1) if (i * a % c > v) tmp++;
		rep(i, 1, r2) if (i * c % a > v) tmp++;
		ll lcm = (a / g * c);
		ll m = t / lcm;
		t %= lcm;
		ans -= tmp * m;
		for (ll i = a; i <= t; i += a) if (i % c > v) ans--;
		for (ll i = c; i <= t; i += c) if (i % a > v) ans--;
		ans--;
		cout << ans << endl;
	}
	return 0;
}
