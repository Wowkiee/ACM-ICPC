#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(x) (int)x.size()
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1010;

int n, k, L, R, cnt;
int a[N], res[N];
priority_queue<pii> t1, t2;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	cin >> n >> k >> R >> L;
	R = k - R;
	ll ans = 0;
	rep(i, 1, n + 1) cin >> a[i], ans += a[i];
	rep(i, 1, n + 1) {
		int x;
		cin >> x;
		a[i] = x - a[i];
	}
	for(int i = 1, j = 0; i <= n - k + 1; ++i) {
		while(j - i + 1 < k) {
			++j;
			t1.push(mp(a[j], j));
		}
		while(cnt < L || (cnt < R && sz(t1) && t1.top().fi > 0) || (cnt == R && sz(t1) && t1.top().fi >= (sz(t2) ? -t2.top().fi : 0))) {
			auto u = t1.top();
			t1.pop();
			if(u.se < i) continue;
			dd(u.fi), dd(u.se), de(1);
			res[u.se] = 1;
			++cnt;
			t2.push(mp(-u.fi, u.se));
			while(cnt > R || (cnt > L && -t2.top().fi < 0)) {
				auto u = t2.top();
				t2.pop();
				if(u.se < i) continue;
				dd(u.se), de(0);
				res[u.se] = 0;
				--cnt;
				t1.push(mp(-u.fi, u.se));
			}
		}
		if(res[i]) --cnt;
		cout << endl;
	}
	rep(i, 1, n + 1) ans += res[i] * a[i];
	cout << ans << endl;
	rep(i, 1, n + 1) cout << (res[i] ? "E" : "S");
	cout << endl;
	return 0;
}
