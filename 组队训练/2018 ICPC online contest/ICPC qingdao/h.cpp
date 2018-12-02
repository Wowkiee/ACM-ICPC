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

const int N = 101010;

string s;
int n;
ll f[N][2];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> s;
		n = sz(s);
		f[n][0] = f[n][1] = 0;
		for(int i = n - 1; ~i; --i) rep(j, 0, 2) {
			int t = 1 + (s[i] - '0' == j);
			int o = (t & 1);
			f[i][j] = f[i + 1][j ^ o] + (n - i) * 1ll * t;
		}
		ll ans = 0;
		rep(i, 0, n) ans += f[i][0];
		cout << ans << endl;
	}
	return 0;
}
