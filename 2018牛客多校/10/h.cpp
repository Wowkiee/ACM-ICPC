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

int solve(int a, int b, int n) {
	ll r = 0;
	rep(x, 1, n+1) {
		r += 1ll * a * x / b;
	}
	return r;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	rep(a, 1, 10) rep(b, 1, 10) {
		rep(n, 1, 10) {
			dd(a), dd(b), dd(n), de(solve(a, b, n));
		}
	}
	return 0;
}
