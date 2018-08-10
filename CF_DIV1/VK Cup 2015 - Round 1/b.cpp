#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 1010;

int n, m;
pii a[N];

int calc(int h) {
	int res = 0, k = 0;
	vi v;
	rep(i, 1, n+1) {
		if(min(a[i].fi, a[i].se) > h) return -1;
		if(a[i].se > h) {
			if(k == m) return -1;
			++k;
			res += a[i].se;
		} else {
			res += a[i].fi;
			if(a[i].se < a[i].fi && a[i].fi <= h) v.pb(a[i].fi - a[i].se);
		}
	}
	sort(all(v));
	reverse(all(v));
	rep(i, 0, min(m-k, sz(v))) res -= v[i];
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	m = n >> 1;
	rep(i, 1, n+1) {
		int x, y;
		cin >> x >> y;
		a[i] = mp(x, y);
	}
	int ans = 2e9;
	rep(i, 1, 1001) {
		int j = calc(i);
		if(~j) ans = min(ans, i * j);
	}
	cout << ans << endl;
	return 0;
}
