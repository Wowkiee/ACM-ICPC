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
#define pw(a) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 101010;

int n, r1, r2;
db x[N], y[N], ma[N], mi[N];
pii a[N];

bool check(db R, bool o = 0) {
	rep(i, 1, n + 1) {
		y[i] = a[i].se - R * i;
		x[i] = a[i].fi - R * i + R;
		ma[i] = max(ma[i - 1], x[i]);
	}
	mi[n] = y[n];
	for(int i = n - 1; i; --i) mi[i] = min(mi[i + 1], y[i]);
	int ok = 0;
	rep(i, 1, n + 1) if(ma[i] >= mi[i]) {
		ok = i;
		break;
	}
	if(o) {
		int i, j;
		rep(t, 1, ok + 1) if(x[t] == ma[ok]) i = t;
		rep(t, ok, n + 1) if(y[t] == mi[ok]) j = t;
		r1 = a[j].se - a[i].fi, r2 = j - i + 1;
		int t = __gcd(r1, r2);
		r1 /= t, r2 /= t;
	}
	return ok > 0;
}

int main() {
  freopen("caravan.in", "r", stdin);
	freopen("caravan.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n + 1) cin >> a[i].fi >> a[i].se;
	sort(a + 1, a + 1 + n);
	db l = 0, r = 1e6;
	rep(i, 0, 100) {
		db mid = (l + r) / 2;
		if(check(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	check(r, 1);
	cout << r1 << "/" << r2 << endl;
	return 0;
}
