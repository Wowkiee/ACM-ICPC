#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m;

int main() {
	freopen("alter.in", "r", stdin);
	freopen("alter.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m;
	cout << n / 2 + m / 2<< endl;
	rep(i, 1, m+1) if (i % 2 == 0) {
		cout << 1 << " " << i << " " << n << " " << i << endl;
	}
	rep(i, 1, n+1) if (i % 2 == 0) {
		cout << i << " " << 1 << " " << i << " " << m << endl;
	}
	return 0;
}
