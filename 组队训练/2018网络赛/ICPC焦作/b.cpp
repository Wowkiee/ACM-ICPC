
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

const ll inf = pw(60);
const int N = 1e3 + 7;
int T, n, m, k;
ll ma[N][6], mi[N][6];
int a[N];
string s;

ll solve(ll x, char op, int p) {
	if (x == inf) return inf;
	if (op == '+') return x + a[p];
	if (op == '-') return x - a[p];
	if (op == '*') return x * a[p];
	return x / a[p];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n >> m >> k;
		rep(i, 1, n+1) cin >> a[i];
		cin >> s; s = "0" + s;
		rep(i, 0, n+1) rep(j, 1, m+1) ma[i][j] = mi[i][j] = inf;
		rep(i, 0, n+1) ma[i][0] = mi[i][0] = k;
		rep(i, 1, n+1) rep(j, 1, m+1) {
			ma[i][j] = ma[i-1][j];
			mi[i][j] = mi[i-1][j];
			ll x = solve(ma[i-1][j-1], s[j], i);
			ll y = solve(mi[i-1][j-1], s[j], i);
			if (x != inf) {
				if (ma[i][j] == inf) ma[i][j] = x;
				else ma[i][j] = max(ma[i][j], x);
				if (mi[i][j] == inf) mi[i][j] = x;
				else mi[i][j] = min(mi[i][j], x);
			}
			if (y != inf) {
				if (ma[i][j] == inf) ma[i][j] = y;
				else ma[i][j] = max(ma[i][j], y);
				if (mi[i][j] == inf) mi[i][j] = y;
				else mi[i][j] = min(mi[i][j], y);
			}
		}
		cout << ma[n][m] << endl;
	}
	return 0;
}
