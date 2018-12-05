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
#define pw(a) (1ll << (a))
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;

const int N = 100;
__int128 b[N], ans;
ll a[N], x;
int n;
vi tmp;
const int P = 1e9 + 7;
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	rep(i, 0, 60) cin >> a[i];
	cin >> n;
	rep(i, 1, n+1) {
		cin >> x;
		per(j, 0, 60) {
			while (x >= pw(j)) {
				x -= pw(j);
				b[j]++;
			}
		}
	}
	per(i, 1, 60) {
		if (b[i] >= a[i]) {
			b[i] -= a[i];
			b[i-1] += b[i] * 2;
		}else {
			a[i] -= b[i];
			ans += (__int128)a[i] * pw(i);
			ans %= P;
		}
	}
	if (a[0] >= b[0]) {
		ans += a[0] - b[0];
		ans %= P;
		cout << (ll)ans;
	}else {
		cout << -1;
	}
	return 0;
}
