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

int A, B, n;
int l, t, m;

bool check(int r) {
	return (2 * A + (l + r - 2) * 1ll * B) * (r - l + 1) / 2 <= t * 1ll * m;
}

int solve() {
	if(t < A) return -1;
	int st = l, ed = (t - A) / B + 1, res = -1;
	if(st > ed) return -1;
	while(st <= ed) {
		int mid = st + ed >> 1;
		if(check(mid)) {
			res = mid;
			st = mid + 1;
		} else {
			ed = mid - 1;
		}
	}
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> A >> B >> n;
	while(n--) {
		cin >> l >> t >> m;
		cout << solve() << endl;
	}
	return 0;
}
