#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
#define endl "\n"
#define ls rt << 1
#define rs ls | 1
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 101010;

int n, m;
int a[N];

struct Seg {
	static const int N = ::N << 2;
	ll sum[N], add[N], la[N], mi[N], ma[N];
	void up(int rt) {
		mi[rt] = min(mi[ls], mi[rs]);
		ma[rt] = max(ma[ls], ma[rs]);
		sum[rt] = sum[ls] + sum[rs];
	}
	void build(int l, int r, int rt) {
		add[rt] = la[rt] = 0;
		if(l == r) {
			mi[rt] = ma[rt] = sum[rt] = a[l];
			return ;
		}
		int mid = l + r >> 1;
		build(l, mid, ls);
		build(mid + 1, r, rs);
		up(rt);
	}
	void gao(int l, int r, bool o, ll c, int rt) {
		if(!c) return ;
		if(o == 0) {
			add[rt] = 0;
			la[rt] = mi[rt] = ma[rt] = c;
			sum[rt] = c * (r - l + 1);
		} else {
			add[rt] += c;
			mi[rt] += c;
			ma[rt] += c;
			sum[rt] += c * (r - l + 1);
		}
	}
	void down(int l, int r, int rt, int mid) {
		gao(l, mid, 0, la[rt], ls);
		gao(mid + 1, r, 0, la[rt], rs);
		gao(l, mid, 1, add[rt], ls);
		gao(mid + 1, r, 1, add[rt], rs);
		la[rt] = add[rt] = 0;
	}
	void upd(int L, int R, bool o, ll c, int l, int r, int rt) {
		if(L <= l && r <= R) {
			gao(l, r, o, c, rt);
			return ;
		}
		int mid = l + r >> 1;
		down(l, r, rt, mid);
		if(L <= mid) upd(L, R, o, c, l, mid, ls);
		if(R > mid) upd(L, R, o, c, mid + 1, r, rs);
		up(rt);
	}
	void upd(int L, int R, int l, int r, int rt) {
		if(L <= l && r <= R && ma[rt] - mi[rt] <= 1) {
			ll o = sqrt(ma[rt]), c = sqrt(mi[rt]);
			if(o == c) {
				gao(l, r, 0, o, rt);
			} else {
				gao(l, r, 1, o - ma[rt], rt);
			}
			return ;
		}
		int mid = l + r >> 1;
		down(l, r, rt, mid);
		if(L <= mid) upd(L, R, l, mid, ls);
		if(R > mid) upd(L, R, mid + 1, r, rs);
		up(rt);
	}
	ll qry(int L, int R, int l, int r, int rt) {
		if(L <= l && r <= R) return sum[rt];
		int mid = l + r >> 1;
		ll ans = 0;
		down(l, r, rt, mid);
		if(L <= mid) ans += qry(L, R, l, mid, ls);
		if(R > mid) ans += qry(L, R, mid + 1, r, rs);
		up(rt);
		return ans;
	}
}seg;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 1, n + 1) cin >> a[i];
	seg.build(1, n, 1);
	while(m--) {
		int o, l, r;
		cin >> o >> l >> r;
		if(o == 1) {
			int x;
			cin >> x;
			seg.upd(l, r, 1, x, 1, n, 1);
		} else if(o == 2) {
			seg.upd(l, r, 1, n, 1);
		} else {
			cout << seg.qry(l, r, 1, n, 1) << endl;
		}
	}
	return 0;
}
