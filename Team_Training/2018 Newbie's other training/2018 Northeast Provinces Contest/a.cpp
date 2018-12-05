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
string s;
int m, l, r;
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> s >> m;
	int n = sz(s);
	ll ans = 0;
	while(m--) {
		cin >> l >> r;
		ans += n - (r - l + 1);
	}
	cout << (ans & 1 ? "Alice" : "Bob") << endl;
	return 0;
}
