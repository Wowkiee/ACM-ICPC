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
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
//----
const int N = 1e7 + 7;
unsigned n, q, x0, x1, a, b, c;
unsigned d[N];
unsigned next() {
	unsigned t = x0 * a + x1 * b + c;
	x0 = x1;
	x1 = t;
	return x0 >> 2;
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> q >> x0 >> x1 >> a >> b >> c;
	rep(i, 0, n)d[i] = 2147483647;
	int nowMin = 0;
	unsigned ans = 0, base = 1;
	while(q--) {
		base *= 10099;
		unsigned x = next() % n, y = next();
		if(x == nowMin) {
			d[x] = y; nowMin = 0;
			rep(j, 1, n)if(d[nowMin] > d[j])nowMin = j;
		}
		else {
			if(y < d[nowMin])nowMin = x;
			d[x] = y;
		}
		ans += base * d[nowMin];
	}
	cout << ans << endl;
	return 0;
}
