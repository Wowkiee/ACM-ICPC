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

const int P = 1e9 + 7;
const int N = 6006;
int n, m, vis[N], p[N], a[N], b[N], x, T, s[N];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	n = 3000;
	rep(i, 2, n+1) {
		if (vis[i] == 0) {
			p[++m] = i;
			for (int j = i + i; j <= n; j += i) vis[j] = 1;
		}
	}
	a[0] = 1;
	rep(i, 1, m+1) {
		rep(j, 0, n+1) b[j] = a[j];
		x = p[i];
		while(x <= n) {
			rep(j, 0, n+1) b[j+x] += a[j], b[j+x] %= P;
			x *= p[i];
		}
		rep(j, 0, n+1) a[j] = b[j];
	}
	s[0] = a[0];
	rep(i, 1, n+1) s[i] = (s[i-1] + a[i]) % P;
	cin >> T;
	rep(cas, 0, T) {
		cin >> n;
		cout << s[n] << endl;
	}
	return 0;
}
