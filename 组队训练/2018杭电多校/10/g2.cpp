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
const int P = 998244353;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---

const int N = 101010;

int f[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	f[1] = f[3] = f[4] = 1;
	rep(i, 5, N) {
		f[i] = add(mul(i - 2, f[i - 1]), mul(i - 1, f[i - 2]));
		if(i & 1) f[i] = add(f[i], 1);
		else f[i] = sub(f[i], 1);
	}
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		cout << f[n] << endl;
	}
	return 0;
}
