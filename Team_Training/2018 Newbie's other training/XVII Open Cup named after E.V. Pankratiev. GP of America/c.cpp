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

const int P = 1e9 + 7;
const int N = 305;
int f[N][N], ok[N][N], a[N], n;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n+1) cin >> a[i];
	rep(i, 1, n+1) rep(j, i+1, n+1) if (__gcd(a[i], a[j]) > 1) ok[i][j] = 1;
	rep(len, 1, n+1)
		rep(i, 1, n - len + 1) {
			int j = i + len - 1;
			rep(st, i, j+1)
				rep(ed, st+1, j+1) if (ok[st][ed] && (st != i || ed != j)) f[i][j] += f[st][ed], f[i][j] %= P;
		}
	cout << f[1][n] << endl;
	return 0;
}
