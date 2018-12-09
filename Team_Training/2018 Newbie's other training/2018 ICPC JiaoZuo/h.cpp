#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define endl "\n"
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
typedef long long ll;
typedef pair<int, int> pii;
typedef double db;
typedef vector<int> vi;

const int N = 202020, M = 1010101;

int n;
int a[N], Log[N], b[N], Find[M], l[N], r[N];

void init() {
	Log[0] = -1;
	rep(i, 1, N) Log[i] = Log[i - 1] + (i == (i & (-i)));
}

struct Seg {
#define ls rt << 1
#define rs ls | 1
	static const int N = ::N << 2;
	int ma[N], la[N];
	ll sum[N];
	void build(int l, int r, int rt) {
		ma[rt] = la[rt] = sum[rt] = 0;
		if(l == r) return ;
		int mid = l + r >> 1;
		build(l, mid, ls);
		build(mid + 1, r, rs);
	}
	void gao(int rt, int c, int l, int r) {
		ma[rt] = la[rt] = c;
		sum[rt] = c * 1ll * (r - l + 1);
	}
	void down(int rt, int l, int r, int mid) {
		if(la[rt]) {
			gao(ls, la[rt], l, mid);
			gao(rs, la[rt], mid + 1, r);
			la[rt] = 0;
		}
	}
	void up(int rt) {
		ma[rt] = max(ma[ls], ma[rs]);
		sum[rt] = sum[ls] + sum[rs];
	}
	void upd(int L, int R, int c, int l, int r, int rt) {
		if(L > R) return ;
		if(L <= l && r <= R) {
			gao(rt, c, l, r);
			return ;
		}
		int mid = l + r >> 1;
		down(rt, l, r, mid);
		if(L <= mid) upd(L, R, c, l, mid, ls);
		if(R > mid) upd(L, R, c, mid + 1, r, rs);
		up(rt);
	}
	ll qry(int L, int R, int l, int r, int rt) {
		if(L > R) return 0;
		if(L <= l && r <= R) return sum[rt];
		int mid = l + r >> 1;
		down(rt, l, r, mid);
		ll ans = 0;
		if(L <= mid) ans += qry(L, R, l, mid, ls);
		if(R > mid) ans += qry(L, R, mid + 1, r, rs);
		up(rt);
		return ans;
	}
	int qry(int L, int R, int c, int l, int r, int rt) {
		if(L <= l && r <= R && (l == r || ma[rt] < c)) {
			if(ma[rt] < c) return 0;
			return l;
		}
		int mid = l + r >> 1, ans = 0;
		down(rt, l, r, mid);
		if(L <= mid) ans = qry(L, R, c, l, mid, ls);
		if(!ans && R > mid) ans = qry(L, R, c, mid + 1, r, rs);
		up(rt);
		return ans;
	}
}seg;

namespace Doubling {
	const int N = ::N;
	int t[N], wa[N], wb[N], sa[N], h[N];
	void sort(int *x, int *y, int n, int m) {
		rep(i, 0, m) t[i] = 0;
		rep(i, 0, n) t[x[y[i]]]++;
		rep(i, 1, m) t[i] += t[i - 1];
		per(i, 0, n) sa[--t[x[y[i]]]] = y[i];
	}
	bool cmp(int *x, int a, int b, int d) {
		return x[a] == x[b] && x[a + d] == x[b + d];
	}
	void da(int *s, int n, int m) {
		int *x = wa, *y = wb;
		rep(i, 0, n) x[i] = s[i], y[i] = i;
		sort(x, y, n, m);
		for(int j = 1, p = 1; p < n; m = p, j <<= 1) {
			p = 0;
			rep(i, n - j, n) y[p++] = i;
			rep(i, 0, n) if(sa[i] >= j) y[p++] = sa[i] - j;
			sort(x, y, n, m);
			swap(x, y);
			p = 1;
			x[sa[0]] = 0;
			rep(i, 1, n) x[sa[i]] = cmp(y, sa[i], sa[i - 1], j) ? p - 1 : p++;
		}
	}
	void cal_h(int *s, int n, int *rk) {
		int j, k = 0;
		for(int i = 1; i <= n; ++i) rk[sa[i]] = i;
		for(int i = 0; i < n; h[rk[i++]] = k) {
				for(k && --k, j = sa[rk[i] - 1]; s[i + k] == s[j + k]; ++k);
		}
	}
}
struct DA {
	static const int N = ::N;
	int p[20][N], rk[N], in[N], n;
	void Build() {
		int ma = 0;
		rep(i, 0, n) ma = max(ma, in[i]);
		Doubling::da(in, n + 1, ma+1);
		Doubling::cal_h(in, n, rk);
		for(int i = 1; i <= n; ++i) p[0][i] = Doubling::h[i];
		for(int j = 1; 1 << j <= n; ++j) {
			int lim = n + 1 - (1 << j);
			for(int i = 1; i <= lim; ++i) {
				p[j][i] = min(p[j - 1][i], p[j - 1][i + (1 << j >> 1)]);
			}
		}
	}
	void solve() {
		rep(i, 1, n + 1) {
			int lcp = Doubling::h[i];
			int sa = Doubling::sa[i] + 1;
			l[sa] = sa + lcp;
			r[sa] = n;
		}
	}
}da;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	init();
	int T;
	cin >> T;
	while(T--) {
		cin >> n;
		rep(i, 1, n + 1) cin >> a[i], b[i] = a[i];
		sort(b + 1, b + 1 + n);
		rep(i, 1, n + 1) Find[b[i]] = i;
		da.n = n;
		rep(i, 1, n + 1) da.in[i - 1] = Find[a[i]];
		da.in[n] = 0;
		da.Build();
		da.solve();
		ll ans = 0;
		seg.build(1, n, 1);
		for(int i = n; i; --i) {
			int p = (seg.ma[1] < a[i]) ? n : (seg.qry(i, n, a[i], 1, n, 1) - 1);
			seg.upd(i, p, a[i], 1, n, 1);
			ans += seg.qry(l[i], r[i], 1, n, 1);
		}
		cout << ans << endl;
	}
	return 0;
}
