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

const int N = 101010;

int n, k, cntb, q;
int a[N];
pii b[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> k;
	rep(i, 1, n+1) cin >> a[i];
	rep(i, 1, n+1) {
		rep(j, 1, k+1) {
			b[++cntb] = mp(a[i] * j, j);
		}
	}
	sort(b+1, b+1+cntb);
	cin >> q;
	while(q--) {
		int x, ans = k+1;
		cin >> x;
		rep(i, 1, n+1) rep(j, 1, k+1) if(a[i] * j <= x) {
			if(a[i] * j == x) {
				ans = min(ans, j);
				continue;
			}
			int t = x - a[i] * j;
			int p = lower_bound(b+1, b+1+cntb, mp(t, 0)) - b;
			if(b[p].fi == t) {
				ans = min(ans, b[p].se + j);
			}
		}
		if(ans == k+1) ans = -1;
		cout << ans << endl;
	}
	return 0;
}
