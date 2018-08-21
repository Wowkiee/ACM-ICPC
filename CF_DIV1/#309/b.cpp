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

const int N = 55;

ll f[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	///read
	int n;
	ll k;
	cin >> n >> k;
	///get f
	f[0] = f[1] = 1;
	rep(i, 2, N) f[i] = f[i-1] + f[i-2];
	///solve
	vi ans;
	set<int> s;
	rep(i, 1, n+1) s.insert(i);
	rep(i, 1, n+1) {
		if(k <= f[n-i]) {
			ans.pb(*s.begin());
			s.erase(s.begin());
		} else {
			k -= f[n-i];
			auto t = s.begin();
			++t;
			ans.pb(*t);
			s.erase(t);
		}
	}
	rep(i, 0, sz(ans)) cout << ans[i] << " ";
	cout << endl;
	return 0;
}
