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
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---

const int N = 8;

int n, m, t;
int a[N][N], b[N][N];

struct Mat {
	static const int N = ::N * ::N;
	ull a[N], b[N];
	void init() {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(a));
	}
	void set(int i, int j) {
		a[i] |= (1ull << j);
		b[j] |= (1ull << i);
	}
	void set() {
		rep(i, 0, n*n) set(i, i);
	}
	Mat operator * (const Mat &c) const {
		Mat res;
		res.init();
		rep(i, 0, n*n) rep(j, 0, n*n) {
			ull t = (a[i] & c.b[j]);
			bool r = 0;
			while(t) {
				if(t & 1) r ^= 1;
				t >>= 1;
			}
			if(r) res.set(i, j);
		}
		return res;
	}
};

Mat kpow(Mat a, int b) {
	Mat r;
	r.init();
	r.set();
	while(b) {
		if(b & 1) r = r * a;
		a = a * a;
		b >>= 1;
	}
	return r;
}

Mat A;

void solve() {
	cin >> n >> m >> t;
	rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
	rep(i, 0, m) rep(j, 0, m) cin >> b[i][j];
	m = m / 2;
	A.init();
	rep(i, 0, n) rep(j, 0, n) {
		rep(p, i - m, i + m + 1) if(p >= 0 && p < n) rep(q, j - m, j + m + 1) if(q >= 0 && q < n) {
			int t = (b[p - i + m][q - j + m] & 1);
			if(t) A.set(i * n + j, p * n + q);
		}
	}
	A = kpow(A, t);
	ull ini = 0;
	rep(i, 0, n) rep(j, 0, n) if(a[i][j] & 1) ini |= (1ull << (i * n + j));
	int ans = 0;
	rep(i, 0, n*n) {
		ull t = (A.a[i] & ini);
		int r = 0;
		while(t) {
			if(t & 1) r ^= 1;
			t >>= 1;
		}
		ans += r;
	}
	cout << ans << endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
