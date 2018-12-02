#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 202020;

int n;
int a[N], ans[N], f[N];

void solve() {
	memset(f, 0x3f, sizeof(f));
	rep(i, 1, n + 1) {
		int p = lower_bound(f + 1, f + 1 + n, a[i]) - f;
		ans[i] += p;
		f[p] = a[i];
	}
}

int main() {
	freopen("improvements.in", "r", stdin);
	freopen("improvements.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n + 1) cin >> a[i];
	solve();
	rep(i, 1, n + 1) a[i] = n + 1 - a[i];
	solve();
	int res = 0;
	rep(i, 1, n + 1) res = max(res, ans[i]);
	cout << res - 1 << endl;
	return 0;
}
