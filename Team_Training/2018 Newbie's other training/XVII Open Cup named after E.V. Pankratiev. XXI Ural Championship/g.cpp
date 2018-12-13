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
typedef long double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
//----
const int N = 40;
map<int, int> M;
int n, aa, bb;
int a[N], b[N];
ll ans = 0;
void gao() {
	int nn = n / 2;
	rep(i, 1, 1 << nn) {
		int suma = 0, sumb = 0;
		rep(j, 0, nn)if(i >> j & 1)suma += a[j], sumb += b[j];
		if(suma * bb == sumb * aa)ans++;
		M[suma * bb - sumb * aa]++;
	}
}
void solve() {
	int nn = n - n / 2;
	rep(i, 1, 1 << nn) {
		int suma = 0, sumb = 0;
		rep(j, 0, nn)if(i >> j & 1)suma += a[j + n / 2], sumb += b[j + n / 2];
		if(sumb * aa == suma * bb)ans++;
		ans += M[sumb * aa - suma * bb];
	}
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> aa >> bb;
	rep(i, 0, n)cin >> a[i] >> b[i];
	gao(); solve();
	cout << ans << endl;
	return 0;
}
