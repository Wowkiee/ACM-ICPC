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
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
//	freopen("c.in", "w", stdout);
	int c = 4;
	int n = c * 2 + 1, m = c * 3;
	cout << n << " " << m << endl;
	rep(i, 1, n) {
		cout << i << " " << n << endl;
	}
	for(int i = 1; i < n; i += 2) cout << i << " " << i + 1 << endl;
	return 0;
}
