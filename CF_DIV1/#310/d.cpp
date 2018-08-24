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

const int N = 202020;

int n, m, i, l, len, pre, cnt;
int x[N];
bool dir;
pii a[N];

bool gao() {
	if(dir) {
		int t = x[i] + l;
		int p = upper_bound(a+1, a+1+n, mp(t, n+1)) - a - 1;
		if(a[p].se == i) {
			++cnt;
			if(cnt >= 2) return 0;
		} else {
			cnt = 0;
		}
		int ni = a[p].se;
		len = x[ni] - x[i];
		dir ^= 1;
		l -= len;
		pre = i;
		i = ni;
	} else {
		int t = x[i] - l;
		int p = lower_bound(a+1, a+1+n, mp(t, -1)) - a;
		if(a[p].se == i) {
			++cnt;
			if(cnt >= 2) return 0;
		} else {
			cnt = 0;
		}
		int ni = a[p].se;
		len = x[i] - x[ni];
		dir ^= 1;
		l -= len;
		pre = i;
		i = ni;
	}
	return 1;
}

int solve() {
	cin >> i >> l;
	dir = 1;
	cnt = 0;
	while(1) {
		if(!gao()) return i;
		if(l >= len) {
			if(!gao()) return i;
			int t = l / len;
			if(t & 1) {
				dir ^= 1;
				swap(i, pre);
			}
			l %= len;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 1, n+1) {
		cin >> a[i].fi, a[i].se = i;
		x[i] = a[i].fi;
	}
	sort(a + 1, a + 1 + n);
	while(m--) cout << solve() << endl;
	return 0;
}
