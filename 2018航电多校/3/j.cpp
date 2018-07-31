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

const int N = 101010, M = N * 10, inf = 1e9+7;

int n, m, a0, b0, c0, d0, p, q, r, MOD, k, rprod, rma, rmi;
int y[N], w[N], xl[M], xr[M], yl[M], yr[M], prod[M], ma[M], mi[M], Q[M], tmp[M];

bool cmpl(int i, int j) {
	return xl[i] > xl[j];
}
bool cmpr(int i, int j) {
	return xr[i] < xr[j];
}
inline void calc(int &a, int &b, int &c, int x, int y, int z) {
	a = 1ll * a * x % k;
	b = max(b, y);
	c = min(c, z);
}

struct Seg {
#define ls rt<<1
#define rs rt<<1|1
	static const int N = ::N << 2;
	int prod[N], ma[N], mi[N];
	void init() {
		fill_n(prod, N, 1);
		fill_n(ma, N, 0);
		fill_n(mi, N, inf);
	}
	void init(int l, int r, int rt) {
		if(mi[rt] == inf) return ;
		prod[rt] = 1, ma[rt] = 0, mi[rt] = inf;
		if(l == r) return ;
		int mid = l + r >> 1;
		init(l, mid, ls);
		init(mid+1, r, rs);
	}
	void upd(int p, int c, int l, int r, int rt) {
		calc(prod[rt], ma[rt], mi[rt], c, c, c);
		if(l == r) return ;
		int mid = l + r >> 1;
		if(p <= mid) upd(p, c, l, mid, ls);
		else upd(p, c, mid+1, r, rs);
	}
	void qry(int L, int R, int l, int r, int rt) {
		if(L <= l && r <= R) {
			calc(rprod, rma, rmi, prod[rt], ma[rt], mi[rt]);
			return ;
		}
		int mid = l + r >> 1;
		if(L <= mid) qry(L, R, l, mid, ls);
		if(R >= mid+1) qry(L, R, mid+1, r, rs);
	}
}seg;

void solve(int l, int r, int L, int R) {
	///
	if(l > r || L > R) return ;
	///get v
	int mid = l + r >> 1;
	int pl = L-1, pr = R+1;
	vi v;
	rep(i, L, R+1) {
		int j = Q[i];
		if(xr[j] < mid) tmp[++pl] = j;
		else if(xl[j] > mid) tmp[--pr] = j;
		else v.pb(j);
	}
	rep(i, L, R+1) Q[i] = tmp[i];
	///solve l
	sort(all(v), cmpl);
	p = mid + 1;
	for(auto i : v) {
		while(p > xl[i]) {
			--p;
			seg.upd(y[p], w[p], 1, n, 1);
		}
		rprod = 1, rma = 0, rmi = inf;
		seg.qry(yl[i], yr[i], 1, n, 1);
		calc(prod[i], ma[i], mi[i], rprod, rma, rmi);
	}
	seg.init(1, n, 1);
	///solve r
	sort(all(v), cmpr);
	p = mid;
	for(auto i : v) {
		while(p < xr[i]) {
			++p;
			seg.upd(y[p], w[p], 1, n, 1);
		}
		rprod = 1, rma = 0, rmi = inf;
		seg.qry(yl[i], yr[i], 1, n, 1);
		calc(prod[i], ma[i], mi[i], rprod, rma, rmi);
	}
	seg.init(1, n, 1);
	///
	solve(l, mid-1, L, pl);
	solve(mid+1, r, pr, R);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		///read
		cin >> n;
		rep(i, 1, n+1) cin >> y[i] >> w[i];
		cin >> m >> a0 >> b0 >> c0 >> d0 >> p >> q >> r >> MOD >> k;
		///init
		fill_n(prod+1, m, 1);
		fill_n(mi+1, m, inf);
		fill_n(ma+1, m, 0);
		seg.init();
		///get q
		rep(i, 1, m+1) {
			int a = (1ll * p * a0 + 1ll * q * b0 + r) % MOD;
			int b = (1ll * p * b0 + 1ll * q * a0 + r) % MOD;
			int c = (1ll * p * c0 + 1ll * q * d0 + r) % MOD;
			int d = (1ll * p * d0 + 1ll * q * c0 + r) % MOD;
			a0 = a, b0 = b, c0 = c, d0 = d;
			xl[i] = min(a % n, b % n) + 1;
			xr[i] = max(a % n, b % n) + 1;
			yl[i] = min(c % n, d % n) + 1;
			yr[i] = max(c % n, d % n) + 1;
		}
		///solve
		rep(i, 1, m+1) Q[i] = i;
		solve(1, n, 1, m);
		///print
		ll ans = 0;
		rep(i, 1, m+1) if(ma[i]) ans += prod[i] ^ ma[i] ^ mi[i];
		cout << ans << endl;
	}
	return 0;
}
