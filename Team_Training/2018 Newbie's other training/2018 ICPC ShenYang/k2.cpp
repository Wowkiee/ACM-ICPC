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
#define endl "\n"
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;

const int N = 4e7 + 5e6;
ll T, n, m, k, x, cnt, a[N], z, p[N];
int c[N];

ll get(ll n, ll m, ll k) {
	ll x = k % (n - m + 1);
	if (x == 0) x = n - m;
	else x--;	
	for(ll i = n - m + 2; i <= n; i++) x = (x + k) % i;
	return x;
}

ll solve(ll n, ll m, ll k) {
	cnt = 0;
	a[0] = 0;  c[0] = 0;
	while (1) {
		if (m - a[cnt] <= 100 * k) {
			p[cnt] = (get(n - a[cnt], m - a[cnt], k) - c[cnt] + n - a[cnt]) % (n - a[cnt]);
			break;
		}
		z = (n - a[cnt] + c[cnt]) / k;
		if (m - a[cnt] <= z) {
			p[cnt] = (m - a[cnt]) * k - 1 - c[cnt];
			break;
		}
		cnt++;
		a[cnt] = a[cnt-1] + z;
	//	b[cnt] = b[cnt-1] - z;
		c[cnt] = (c[cnt-1] + n - a[cnt-1]) % k;
	}
	per(i, 0, cnt) {
		p[i] = p[i+1] + 1;
		while (p[i] - (p[i] + c[i]) / k < p[i+1] + 1) {
			p[i] +=  p[i+1] + 1 - (p[i] - (p[i] + c[i]) / k);
		}
		p[i]--;
	}
	//de(cnt);
	return p[0];
}



int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	//de((sizeof(c) + sizeof(a) * 2) / 1024. / 1024.);
	//return 0;
	cin >> T;
	rep(cas, 0, T) {
		cnt = 0;
		cout << "Case #" << cas +1 << ": ";
		cin >> n >> m >> k;
		//de(get(n, m, k) + 1);
		if (m <= k) cout << get(n, m, k) + 1 << endl;
		else cout << solve(n, m, k) + 1<< endl;
	//	de(cnt);
	}
	return 0;
}
