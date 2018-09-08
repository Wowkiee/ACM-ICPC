
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

const int N = 1e5 +7;
int f[N], n, m;
ll x;
int cal(int n) {
	int res = mul(n, n + 1);
	res = mul(res, 2 * n + 1);
	res = mul(res, kpow(6, P - 2));
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	while (cin >> n >> m){
		vi d;
		/*ll tmp = 0;
		rep(i, 1, n+1) if (__gcd(i, m) == 1) tmp = add(tmp, mul(i , i + 1));
		de(tmp);*/
		for (int i = 1; i * i <= m; i++) {
			if (m % i == 0) {
				d.pb(i);
				if (i * i != m) d.pb(m / i);
			}
		}
		sort(all(d));
		per(i, 0, sz(d)) {
			f[i] = mul(mul(d[i], d[i]) , cal(n / d[i]));
			x = n / d[i];
			x = x * (x + 1) / 2 % P;
			f[i] = add(f[i], mul(d[i], x));
			rep(j, i + 1, sz(d)) if (d[j] % d[i] == 0) f[i] = sub(f[i], f[j]);
		}
		cout << f[0] << endl;
	}
	return 0;
}
