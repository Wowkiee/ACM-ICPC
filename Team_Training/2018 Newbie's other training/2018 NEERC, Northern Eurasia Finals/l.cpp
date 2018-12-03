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

const int N = 101010;

int n, k;
int a[N], b[N], ma[N];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> k;
	rep(i, 1, n + 1) cin >> a[i];
	rep(i, 1, n + 1) cin >> b[i], ma[a[i]] = max(ma[a[i]], b[i]);
	int cnt = 0;
	rep(i, 1, k + 1) cnt += (ma[i] == 0);
	vi v;
	rep(i, 1, n + 1) {
		if(b[i] == ma[a[i]]) ma[a[i]] = 0;
		else v.pb(b[i]);
	}
	sort(all(v));
	ll ans = 0;
	rep(i, 0, cnt) ans += v[i];
	cout << ans << endl;
	return 0;
}
