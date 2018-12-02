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
typedef __int128 ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double db;

int main() {
	freopen("xorsep.in", "r", stdin);
	freopen("xorsep.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	cin >> n;
	long long x;
	ll sum = 0;
	rep(i, 1, n + 1) {
		cin >> x;
		sum ^= x;
	}
	if(n == 1 || sum) cout << 0 << endl;
	else cout << pw(n) - 2 << endl;
	return 0;
}
