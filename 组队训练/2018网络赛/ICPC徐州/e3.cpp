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
//---

const int N = 77;
const ll inf = 2e18;

int n, m, t, T;
int a[N];
pii e[N * N];

struct Mat {
	static const int N = ::N << 1;
	ll a[N][N];
	int st, ed;
	void init(int l, int r) {
		st = l, ed = r;
		rep(i, st, ed+1) rep(j, st, ed+1) a[i][j] = -inf;
	}
	/*
	void init(int l, int r, ll w) {
		st = l, ed = r;
		rep(i, st, ed+1) a[i][i] = w;
	}
	*/
	Mat operator * (const Mat &c) const {
		Mat res;
		res.init(st, ed);
		rep(i, st, ed+1) rep(j, st, ed+1) rep(k, st, ed+1) res.a[i][j] = max(res.a[i][j], a[i][k] + c.a[k][j]);
		return res;
	}
	void print() {
		rep(i, st, ed+1) {
			rep(j, st, ed+1) cout << (double)a[i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}
};

Mat mt, mm;

Mat kpow(Mat a, int b) {
	Mat res = a;
	--b;
	while(b) {
		if(b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> m >> t >> T;
	rep(i, 0, m) cin >> e[i].fi >> e[i].se;
	rep(i, 1, n+1) cin >> a[i];

	mt.init(0, n);
	rep(i, 0, n+1) mt.a[i][i] = 0;
	rep(i, 0, m) {
		int u = e[i].fi, v = e[i].se;
		mt.a[u][v] = max(a[v] * ll(2), mt.a[u][v]);
	}
	rep(i, 1, n+1) mt.a[0][i] = 2 * a[i];
//	mt.print();
	mt = kpow(mt, T);
//	mt.print();

	mm.init(0, 2*n);
	rep(i, 0, 2*n+1) mm.a[i][i] = 0;
	rep(i, 1, n+1) mm.a[0][i] = a[i];
	rep(i, 1, n+1) mm.a[0][i+n] = mt.a[0][i];
	rep(i, 0, m) {
		int u = e[i].fi, v = e[i].se;
		mm.a[u][v] = max(mm.a[u][v], (ll)a[v]);
		u += n, v += n;
		mm.a[u][v] = max(mm.a[u][v], (ll)a[v-n]);
	}
	rep(u, 1, n+1) rep(v, 1, n+1) mm.a[u][v+n] = mt.a[u][v];
//	mm.print();
	mm = kpow(mm, t - T + 1);
//	mm.print();

	ll ans = mm.a[0][1];
	rep(i, 1, n*2+1) ans = max(ans, mm.a[0][i]);
	cout << ans << endl;
/*	
	vi r;
	while(ans) {
		r.pb(ans%10);
		ans/=10;
	}
	if(sz(r)) {
		rep(i, 0, sz(r)) cout << r
	} else {
		cout << 0 << endl;
	}
	*/
	return 0;
}
