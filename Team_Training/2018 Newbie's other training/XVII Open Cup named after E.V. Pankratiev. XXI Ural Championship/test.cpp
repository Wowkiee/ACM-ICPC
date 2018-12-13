#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(x) cout << #x << " = " << x << endl 
#define dd(x) cout << #x << " = " << x << " "
#define endl "\n"
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n = 23;
	de(pw(n));
	ll ans = 0;
	rep(i, 1, n + 1) {
		ans += pw(i) * (64 - 2 * i);
	}
	de(ans);
	return 0;
}
