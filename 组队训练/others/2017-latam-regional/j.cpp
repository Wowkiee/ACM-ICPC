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

const int N = 1e5 + 7;
int cnt[N], ans, now, n, ok;
string s;
vi d;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> s;
	n = sz(s);
	rep(i, 1, n) if(n % i == 0) d.pb(i);
	rep(i, 1, n) cnt[__gcd(i, n)]++;
	rep(i, 0, sz(d)) {
		rep(j, 0, d[i]) {
			now = (j + d[i]) % n;
			ok = 1;
			while (1) {
				if (s[now] == 'P') {ok = 0;break;}
				if (now == j) break;
				now = (now + d[i]) % n;
			}
			if (ok) {
				ans += cnt[d[i]];
				break;
			}
		}
	}
	cout << ans;
	return 0;
}
