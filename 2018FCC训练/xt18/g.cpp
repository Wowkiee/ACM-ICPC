#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----
vi gao(string str) {
	vi ret;
	for (int l = 0, r; l < sz(str); l = r + 1) {
		r = l; while (r < sz(str) && str[r] != 'c') r++;
		int a = 0, b = 0;
		rep(i, l, r) {
			if (str[i] == 'a') a ^= 1;
			if (str[i] == 'b') b ^= 1;
		}
		ret.pb(a << 1 | b);
	}
	return ret;
}
int main() {
	__int128 a;
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	string s, t;
	while (cin >> s >> t) {
		s += "aa";
		t += "aa";
		auto vs = gao(s), vt = gao(t);
		cout << (vs != vt ? "No" : "Yes") << endl;
	}
	return 0;
}
