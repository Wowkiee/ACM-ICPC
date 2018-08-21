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

const int N = 1010101, P = 1e9+7;

int k;
int c[N], jc[N], in[N], pre[N];

int add(int a, int b) {
	if((a += b) >= P) a -= P;
	return a;
}
int sub(int a, int b) {
	if((a -= b) < 0) a += P;
	return a;
}
int mul(int a, int b) {
	return 1ll * a * b % P;
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
void init() {
	jc[0] = 1;
	rep(i, 1, N) jc[i] = mul(jc[i-1], i);
	in[N-1] = kpow(jc[N-1], P-2);
	for(int i = N-2; ~i; --i) in[i] = mul(in[i+1], i+1);
}
int C(int n, int m) {
	return mul(jc[n], mul(in[m], in[n-m]));
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	init();
	cin >> k;
	rep(i, 1, k+1) cin >> c[i], pre[i] = pre[i-1] + c[i];
	int ans = 1;
	rep(i, 1, k+1) ans = mul(ans, C(pre[i]-1, c[i]-1));
	cout << ans << endl;
	return 0;
}
