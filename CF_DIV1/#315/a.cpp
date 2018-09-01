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

const int N = 10101010;

int pi[N], rub[N];
bool vis[N];

bool check(int x) {
	vi v;
	while(x) {
		v.pb(x % 10);
		x /= 10;
	}
	for(int i = 0, j = sz(v) - 1; i < j; ++i, --j) if(v[i] != v[j]) return 0;
	return 1;
}

void init() {
	vi p;
	for(int i = 2; i < N; ++i) {
		if(!vis[i]) p.pb(i);
		for(int j = 0; j < sz(p) && i * p[j] < N; ++j) {
			vis[i * p[j]] = 1;
			if(i % p[j] == 0) break;
		}
	}
	for(auto u : p) pi[u] = 1;
	rep(i, 1, N) rub[i] = rub[i-1] + check(i), pi[i] += pi[i-1];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	init();
	int p, q;
	while(cin >> p >> q) {
		int ans = 0;
		rep(i, 1, N) if(pi[i] * 1ll * q <= rub[i] * 1ll * p) {
			ans = i;
		}
		if(ans) {
			cout << ans << endl;
		} else {
			cout << "Palindromic tree is better than splay tree" << endl;
		}
	}
	return 0;
}
