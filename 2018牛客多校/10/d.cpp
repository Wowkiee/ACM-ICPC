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

const int N = 202020, P = 998244353;

int n, m;
int jc[N], in[N];

struct Q {
	int o, l, r, w;
}q[N];

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
	if(n < m) return 0;
	return mul(jc[n], mul(in[m], in[n-m]));
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	init();
	int T;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		rep(i, 1, m+1) {
			cin >> q[i].o;
			if(q[i].o == 1) {
				cin >> q[i].l >> q[i].r >> q[i].w;
				q[i].w %= P;
			} else if(q[i].o == 3) {
				int l, r;
				cin >> l >> r;
				int k = 1, ans = 0;
				for(int j = i-1; j; --j) {
					if(q[j].o == 1) {
						int p = q[j].l;
						if(p <= r) {
							int res = sub(C(k+r-p, k), C(k+l-1-p, k));
							ans = add(ans, mul(q[j].w, res));
						}
						p = q[j].r+1;
						if(p <= r) {
							int res = sub(C(k+r-p, k), C(k+l-1-p, k));
							ans = add(ans, mul(P - q[j].w, res));
						}
					} else if(q[j].o == 2) {
						++k;
					}
				}
				cout << ans << endl;
			}
		}
	}
	return 0;
}
