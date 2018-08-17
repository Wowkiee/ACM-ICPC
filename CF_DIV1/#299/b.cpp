#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 1010101, P = 1e9+7, seed = 167, P2 = 1e9 + 9;

int n, m, len;
int x[N], ba[N], ha[N], ba2[N], ha2[N];
string s;

int mul(int a, int b, int P = ::P) {
	return 1ll * a * b % P;
}
int add(int a, int b, int P = ::P) {
	int r = a + b;
	if(r >= P) r -= P;
	return r;
}
int sub(int a, int b, int P = ::P) {
	int r = a - b;
	if(r < 0) r += P;
	return r;
}
pii get(int l, int r) {
	int r1 = sub(ha[r], mul(ha[l-1], ba[r-l+1]));
	int r2 = sub(ha2[r], mul(ha2[l-1], ba2[r-l+1], P2), P2);
	return mp(r1, r2);
}
int kpow(int a, int b) {
	int r = 1;
	while(b) {
		if(b & 1) r = mul(r, a);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}
bool check(int i) {
	if(x[i] - x[i-1] - len >= 0) return 1;
	int t = len + x[i-1] - x[i];
	return get(1, t) == get(len - t + 1, len);
}
int solve() {
	if(m == 0) return kpow(26, n);
	int cnt = x[1] - 1;
	rep(i, 2, m+1) {
		if(check(i)) cnt += max(0, x[i] - x[i-1] - len);
		else return 0;
	}
	cnt += n + 1 - x[m] - len;
	return kpow(26, cnt);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	///read
	cin >> n >> m >> s;
	rep(i, 1, m+1) cin >> x[i];
	///get s
	len = sz(s);
	s = " " + s;
	///get ha
	ba[0] = ba2[0] = 1;
	rep(i, 1, len+1) ba[i] = mul(ba[i-1], seed), ba2[i] = mul(ba2[i-1], seed, P2);
	rep(i, 1, len+1) {
		ha[i] = add(mul(ha[i-1], seed), s[i]);
		ha2[i] = add(mul(ha2[i-1], seed, P2), s[i], P2);
	}
	cout << solve() << endl;
	return 0;
}
