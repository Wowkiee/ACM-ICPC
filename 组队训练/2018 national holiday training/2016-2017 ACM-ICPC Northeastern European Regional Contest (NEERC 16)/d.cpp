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
			if(a[j] > 0) {
				++cnt;
				res[j] = 1;
				t1.push(mp(-a[j], j));
				while(cnt > R && sz(t1)) {
					auto u = t1.top();
					t1.pop();
					if(u.se < i) continue;
					--cnt;
					res[u.se] = 0;
					u.fi = -u.fi;
					t2.push(u);
				}
			} else {
				t2.push(mp(a[j], j));
			}
		}
		while(cnt < R && sz(t2)) {
			auto u = t2.top();
			t2.pop();
			if(u.se < i) continue;
			if(u.fi <= 0 && cnt >= L) break;
			++cnt;
			res[u.se] = 1;
			u.fi = -u.fi;
			t1.push(u);
		}
		if(res[i]) --cnt;
	}
	rep(i, 1, n + 1) ans += res[i] * a[i];
	cout << ans << endl;
	rep(i, 1, n + 1) cout << (res[i] ? "E" : "S");
	cout << endl;
	return 0;
}
