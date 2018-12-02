#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll<<(a))
#define endl "\n"
#define ls rt << 1
#define rs ls | 1
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 202020;

int n1, n2, m, s, n;
int a1[N], a2[N];
ll pre1[N], pre2[N];

ll calc(int bn, int x) {
	int t = bn / x;
	return 1ll * t * bn - (1 + t) * 1ll * t / 2 * x;
}

struct Seg2 {
	static const int N = ::N << 2;
	int mi[N], b[::N], bn, la[N];
	ll sum[N];
	void up(int rt) {
		mi[rt] = min(mi[ls], mi[rs]);
		sum[rt] = sum[ls] + sum[rs];
	}
	void build(int l, int r, int rt) {
		if(l == r) {
			mi[rt] = sum[rt] = b[l] = max(0, a2[l] + b[l - 1] - n2);
			if(l == n) bn = b[n];
			return ;
		}
		int mid = l + r >> 1;
		build(l, mid, ls);
		build(mid + 1, r, rs);
		up(rt);
	}
	void gao(int rt, int l, int r, int c) {
		la[rt] += c;
		mi[rt] += c;
		sum[rt] += (r - l + 1) * 1ll * c;
	}
	void down(int rt, int l, int r, int mid) {
		if(la[rt]) {
			gao(ls, l, mid, la[rt]);
			gao(rs, mid + 1, r, la[rt]);
			la[rt] = 0;
		}
	}
	int qry(int L, int R, int l, int r, int rt) {
		if(L <= l && r <= R && (l == r || mi[rt] > 0)) {
			if(mi[rt] > 0) return 0;
			return l;
		}
		int mid = l + r >> 1;
		down(rt, l, r, mid);
		if(L <= mid) {
			int t = qry(L, R, l, mid, ls);
			if(t) return t;
		}
		if(R > mid) {
			int t = qry(L, R, mid + 1, r, rs);
			if(t) return t;
		}
		return 0;
	}
	void upd(int L, int R, int l, int r, int rt) {
		if(L > R) return ;
		if(L <= l && r <= R) {
			gao(rt, l, r, -1);
			return ;
		}
		int mid = l + r >> 1;
		down(rt, l, r, mid);
		if(L <= mid) upd(L, R, l, mid, ls);
		if(R > mid) upd(L, R, mid + 1, r, rs);
		up(rt);
	}
}seg2;

struct Seg {
	static const int N = ::N << 2;
	int mi[N], b[N], c[N], bn, lab[N], lac[N];
	ll sum[N];
	void up(int rt) {
		mi[rt] = min(mi[ls], mi[rs]);
		sum[rt] = sum[ls] + sum[rs];
	}
	void build(int l, int r, int rt) {
		if(l == r) {
			c[l] = a1[l] + b[l - 1] - (n1 + 1);
			b[l] = max(c[l], 0);
			mi[rt] = c[l];
			sum[rt] = b[l];
			if(l == n) bn = b[n];
			return ;
		}
		int mid = l + r >> 1;
		build(l, mid, ls);
		build(mid + 1, r, rs);
		up(rt);
	}
	void gao(int rt, int l, int r, int b, int c) {
		lab[rt] += b;
		lac[rt] += c;
		mi[rt] += c;
		sum[rt] += (r - l + 1) * 1ll * b;
	}
	void down(int rt, int l, int r, int mid) {
		if(lab[rt] || lac[rt]) {
			gao(ls, l, mid, lab[rt], lac[rt]);
			gao(rs, mid + 1, r, lab[rt], lac[rt]);
			lab[rt] = 0, lac[rt] = 0;
		}
	}
	int qry(int L, int R, int l, int r, int rt) {
		if(L <= l && r <= R && (l == r || mi[rt] >= 0)) {
			if(mi[rt] >= 0) return 0;
			return l;
		}
		int mid = l + r >> 1;
		down(rt, l, r, mid);
		if(L <= mid) {
			int t = qry(L, R, l, mid, ls);
			if(t) return t;
		}
		if(R > mid) {
			int t = qry(L, R, mid + 1, r, rs);
			if(t) return t;
		}
		return 0;
	}
	void upd(int L, int R, int c1, int c2, int l, int r, int rt) {
		if(L > R) return ;
		if(L <= l && r <= R) {
			gao(rt, l, r, c1, c2);
			return ;
		}
		int mid = l + r >> 1;
		down(rt, l, r, mid);
		if(L <= mid) upd(L, R, c1, c2, l, mid, ls);
		if(R > mid) upd(L, R, c1, c2, mid + 1, r, rs);
		up(rt);
	}
}seg;

int main() {
	freopen("lanes.in","r",stdin);
	freopen("lanes.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n1 >> n2 >> m >> s;
	n = m + s;
	rep(i, 1, m + 1) cin >> a1[i] >> a2[i];
	seg2.build(1, n, 1);
	pre2[n + 1] = seg2.sum[1] + calc(seg2.bn, n2);
	for(int i = n; i; --i) {
		int p = seg2.qry(i, n, 1, n, 1);
		p = (p ? p - 1 : n);
		if(p == n) --seg2.bn;
		seg2.upd(i, p, 1, n, 1);
		pre2[i] = seg2.sum[1] + calc(seg2.bn, n2 + 1);
	}
	seg.build(1, n, 1);
	pre1[n + 1] = seg.sum[1] + calc(seg.bn, n1 + 1);
	for(int i = n; i; --i) {
		int p = seg.qry(i, n, 1, n, 1);
		if(p) {
			seg.upd(i, p, 0, 1, 1, n, 1);
			seg.upd(i, p - 1, 1, 0, 1, n, 1);
		} else {
			seg.upd(i, n, 1, 1, 1, n, 1);
		}
		if(p == 0) ++seg.bn;
		pre1[i] = seg.sum[1] + calc(seg.bn, n1);
	}
	ll ans = pw(60);
	int pos = 0;
	rep(i, 1, m+1) {
		if (pre1[i] + pre2[i+s] < ans) {
			ans = pre1[i] + pre2[i+s];
			pos = i;
		}
	}
	cout << pos << endl;
	return 0;
}
