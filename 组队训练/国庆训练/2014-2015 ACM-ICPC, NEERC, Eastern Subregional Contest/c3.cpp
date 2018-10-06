#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> iii;
typedef vector<int> vi;

const int N = 101010;

int n;
pair<iii, pii> a[N];
pii b[N];

struct Seg {
#define ls rt << 1
#define rs ls | 1
	static const int N = ::N << 2;
	ll mi[N], la[N];
	void gao(int rt, ll c) {
		mi[rt] += c;
		la[rt] += c;
	}
	void down(int rt) {
		if(!la[rt]) return ;
		gao(ls, la[rt]);
		gao(rs, la[rt]);
		la[rt] = 0;
	}
	void up(int rt) {
		mi[rt] = min(mi[ls], mi[rs]);
	}
	void upd(int L, int R, ll c, int l, int r, int rt) {
		if(L <= l && r <= R) {
			gao(rt, c);
			return ;
		}
		int mid = l + r >> 1;
		down(rt);
		if(L <= mid) upd(L, R, c, l, mid, ls);
		if(R > mid) upd(L, R, c, mid + 1, r, rs);
		up(rt);
	}
}seg;

int main() {
	scanf("%d", &n);
	rep(i, 1, n + 1) {
		int x, m, d, hh, mm;
		scanf("%d%d.%d %d:%d", &x, &d, &m, &hh, &mm);
		auto u = mp(mp(m, d), mp(hh, mm));
		a[i] = mp(u, mp(i, x));
	}
	sort(a + 1, a + 1 + n);
	rep(i, 1, n + 1) b[a[i].se.fi] = mp(i, a[i].se.se);
	rep(i, 1, n + 1) {
		int t = b[i].fi, x = b[i].se;
		seg.upd(t, n, x, 1, n, 1);
		cout << min(0ll, seg.mi[1]) << endl;
	}
	return 0;
}
