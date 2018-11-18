#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(a) cout << #a << " = " << a << " "
#define de(a) cout << #a << " = " << a << endl
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

string s, ans;
int n, x;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(cas, 0, n) {
		cin >> s;
		ans = "";
		reverse(all(s));
		while(sz(s) % 4 != 0) s = s + '0';
		for (int i = 0; i < sz(s); i += 4) {
			x = 0;
			rep(j, 0, 4) x += (s[i+j] - '0') * pw(j);
			if (x <= 9) ans += (x + '0');else ans += (x - 10 + 'A');
		}
		reverse(all(ans));
		cout << ans << endl;
	}
	return 0;
}
