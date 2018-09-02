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

const int N = 101010, SZ = 2000, P = 1e9+7;

struct Q {
	int o, x, y;
}q[N];

int n, m, k;
int b[N], d[N], res[N], a[N];

int add(int a, int b) {
	int r = a + b;
	if(r >= P) r -= P;
	return r;
}
int mul(int a, int b) {
	return 1ll * a * b % P;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> m >> k;
	a[1] = 1;
	rep(i, 1, k+1) {
		rep(t, 2, n+1) a[t] = add(a[t], a[t-1]);
	}
	rep(i, 0, m+1) b[i] = i/SZ;
	rep(i, 0, m) {
		int o, x, y;
		cin >> o;
		if(o == 0) {
			cin >> x >> y;
			d[x] = add(d[x], y);
		} else {
			cin >> x;
			int ans = res[x];
			for(int j = i-1; j >= 0 && b[j] == b[i]; --j) if(q[j].o == 0 && q[j].x <= x) {
				ans = add(ans, mul(a[x-q[j].x+1], q[j].y));
			}
			cout << ans << endl;
		}
		if(b[i] != b[i+1]) {
			rep(j, 1, k+1) {
				rep(t, 2, n+1) d[t] = add(d[t], d[t-1]);
			}
			rep(t, 1, n+1) res[t] = add(res[t], d[t]), d[t] = 0;
		}
		q[i].o = o, q[i].x = x, q[i].y = y;
	}
	return 0;
}
