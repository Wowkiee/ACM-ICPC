#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define pw(x) (1ll << (x))
#define all(x) x.begin(), x.end()
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n, tmp, nn, t, ans1, ans2, t1, t2, g1, g2, a, b;
vi p;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	tmp = n;
	nn = n - 1;
	for (int x = 2; x * x <= n; x++) {
		if (tmp % x == 0) {
			p.pb(x);
		}
		while (tmp % x == 0) tmp /= x;
	}
	if (tmp > 1) p.pb(tmp);
	if (sz(p) == 1) {
		cout << "NO" << endl;
		return  0;
	}
	sort(all(p));
	a = p[0], b = p[1];
	rep(i, 0, a+1) {
		if (b * i > nn) break;
		if ((nn - (b * i)) % a == 0) {
			ans1 = (nn - (b * i) ) / a;
			ans2 = i;
			break;
		}
	}
	cout << "YES" << endl;
	t1 = a * ans1;
	g1 = __gcd(t1, n);
	t2 = b * ans2;
	g2 = __gcd(t2, n);
	cout << 2 << endl;
	cout << t1 / g1 << " " << n / g1 << endl;
	cout << t2 / g2 << " " << n / g2 << endl;
	return 0;
}
