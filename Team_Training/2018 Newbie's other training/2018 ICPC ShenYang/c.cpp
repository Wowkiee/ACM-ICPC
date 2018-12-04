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
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;
//----
const int N = 55;
int T, n, m, mod, f[N];
ll fac[N] = {1};
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int ca = 0;
	cin >> T; while(T--) {
		cin >> n >> m >> mod;
		rep(i, 1, n + 1)fac[i] = fac[i - 1] * i % mod;
		int c = 1;
		rep(i, 1, n + 1) {
			rep(j, 1, n + 1)f[j] = j;
			per(j, 1, i)swap(f[j], f[j + 1]);
			rep(j, 1, n + 1) {
				if(j != i && j != i - 1) {
					int fl = 1;
					rep(k, 1, m)if(f[k] > f[k + 1])fl = 0;
					c += fl;
					if(c >= mod) c -= mod;
				}
				swap(f[j], f[j + 1]);
			}
		}
		cout << "Case #" << ++ca << ": " << c * fac[m] % mod << endl;
	}
	return 0;
}
