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

const int N = 1e6 + 7;
int w, f[N], s[N], T, n, k;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	//cin >> n >> k;
	/*k = 2;
	s = 1 << k;
	rep(i, 0, s)
		rep(j, 0, s)
			rep(k, 0, s)
				rep(l, 0, s) if (!check(i, j) && !check(j, k) && !check(k, l)) ans ++;
	cout << ans;*/
	cin >> T;
	rep(cas, 0, T) {
		cin >> n >> k;
		w = kpow(2, k);
		f[1] = s[1] = w;
		f[2] = s[2] = mul(w, w - 1);
		rep(i, 3, n+1) s[i] = mul(s[i-1], w - 1);
		rep(i, 3, n+1) f[i] = add(sub(s[i], s[i-1]), f[i - 2]);
		cout << f[n] << endl;
	}
	return 0;
}
