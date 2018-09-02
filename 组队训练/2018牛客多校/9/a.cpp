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

const int mod = 1e9 + 7;
int x, n, Inv2;
vi ans, a, b;

int mul(int a, int b) {
	return 1ll * a * b % mod;	
}

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = mul(res, a);
		a= mul(a, a);
		b >>= 1;
	}
	return res;
}

int add(int x, int y){
	x += y;
	x %= mod;
	if (x < 0) x+= mod;
	return x;
}

int inv(int x) {
	return qpow(x, mod - 2);
}


vi solve(int n, vi a, vi b){
	int mid = n / 2;
	vi ans, tmp1, tmp2, aa, bb;
	if (n == 1) {
		ans.pb(mul(b[0],inv(a[0])));
		return ans;
	}
	rep(i, 0, mid) {
		aa.pb(add(a[i], -a[i+mid]));
		bb.pb(add(b[i], -b[i+mid]));
	}
	tmp1 = solve(mid, aa, bb);
	//aa.clear();
	//bb.clear();
	rep(i, 0, mid){
		aa[i] = (add(a[i], a[i+mid]));
		bb[i] = (add(b[i], b[i+mid]));
	}
	tmp2 = solve(mid, aa, bb);
	rep(i, 0, mid) ans.pb(mul(add(tmp1[i],tmp2[i]),Inv2));
	rep(i, 0, mid) ans.pb(mul(add(-tmp1[i],tmp2[i]),Inv2));
	return ans;
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	rep(i, 0, n) cin >> x, a.pb(x);
	rep(i, 0, n) cin >> x, b.pb(x);
	Inv2 = inv(2);
	ans = solve(n, a, b);
	rep(i, 0, n) cout << ans[i] << endl;
	return 0;
}
