#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---

const int N = 4040;

int f[N][N], g[N], C[N][N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	f[0][0] = 1;
	rep(i, 1, N) rep(j, 1, N) f[i][j] = add(f[i-1][j-1], mul(f[i-1][j], j));
	rep(i, 0, N) rep(j, 0, N) g[i] = add(g[i], f[i][j]);
	rep(i, 0, N) C[i][0] = C[i][i] = 1;
	rep(i, 1, N) rep(j, 1, i) C[i][j] = add(C[i-1][j], C[i-1][j-1]);
	int n;
	while(cin >> n) {
		int ans = 0;
		rep(i, 1, n+1) {
			ans = add(ans, mul(C[n][i], g[n-i]));
		}
		cout << ans << endl;
	}
	return 0;
}
