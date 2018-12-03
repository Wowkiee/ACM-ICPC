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

ll ans, n, t, a[10], s[10], num, w, T, tmp;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0 , T) {
		cin >> n;
		t = 0;
		ans = pw(60);
		rep(i, 1, 8) cin >> a[i], t += a[i], s[i] = s[i-1] + a[i];
		rep(i, 1, 8) {
			num = 0;
			w = 0;
			if (n <= t - s[i-1]) {
				tmp = 0;
				rep(j, i, 8) {
					tmp += a[j];
					if (tmp == n) {ans = min(ans, 1ll * j - i + 1);break;}
				}
			}else {
				num = 8 - i;
				w = n - (t - s[i-1]);
				num += w / t * 7;
				w %= t;
				if (w == 0) {
					per(j, 1, 8) if (a[j] == 1) break;else num--;
					ans = min(ans, num);
					continue;
				}
				tmp = 0;
				rep(j, 1, 8) {
					tmp += a[j];
					if (tmp == w) {ans = min(ans, j + num);break;}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
