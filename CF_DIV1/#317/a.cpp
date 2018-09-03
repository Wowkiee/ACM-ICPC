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

ll ans;

void gao(int a, int b, int c, int l) {
	rep(i, 0, l+1) {
		int r = min(l - i, c + i - a - b);
		if(r >= 0) ans -= (r + 2) * 1ll * (r + 1) / 2;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int a, b, c, l;
	cin >> a >> b >> c >> l;
	ans = (l + 3) * 1ll * (l + 2) * (l + 1) / 6;
	gao(a, b, c, l);
	gao(a, c, b, l);
	gao(b, c, a, l);
	cout << ans << endl;
	return 0;
}
