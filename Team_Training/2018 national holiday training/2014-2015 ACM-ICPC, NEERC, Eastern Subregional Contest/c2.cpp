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
	int cnt[N], a[N];
	void upd(int p, int c, int l, int r, int rt) {
		if(l == r) {
			a[l] = c;
			cnt[rt] = (c != 0);
			return ;
		}
		int mid = l + r >> 1;
		if(p <= mid) upd(p, c, l, mid, ls);
		else upd(p, c, mid + 1, r, rs);
		cnt[rt] = cnt[ls] + cnt[rs];
	}
	int qry(int L, int R, int o, int l, int r, int rt) {
		if(L <= l && r <= R && (l == r || cnt[rt] == 0)) {
			if(cnt[rt] == 0) return 0;
			return l;
		}
		int mid = l + r >> 1;
		if(o == 0) {
			if(L <= mid) {
				int t = qry(L, R, o, l, mid, ls);
				if(t) return t;
			}
			if(R > mid) {
				int t = qry(L, R, o, mid + 1, r, rs);
				if(t) return t;
			}
		} else {
			if(R > mid) {
				int t = qry(L, R, o, mid + 1, r, rs);
				if(t) return t;
			}
			if(L <= mid) {
				int t = qry(L, R, o, l, mid, ls);
				if(t) return t;
			}
		}
		return 0;
	}
}s1, s2;

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
	ll sum = 0;
	rep(i, 1, n + 1) {
		int t = b[i].fi, x = b[i].se, c = abs(x);
		if(x > 0) {
			while(c) {
				int p = s2.qry(t, n, 0, 1, n, 1);
				if(!p) break;
				int ret = min(s2.a[p], c);
				c -= ret;
				sum -= ret;
				s2.upd(p, s2.a[p] - ret, 1, n, 1);
			}
			if(c) s1.upd(t, c, 1, n, 1);
		} else {
			sum += c;
			while(c) {
				int p = s1.qry(1, t, 1, 1, n, 1);
				if(!p) break;
				int ret = min(s1.a[p], c);
				c -= ret;
				sum -= ret;
				s1.upd(p, s1.a[p] - ret, 1, n, 1);
			}
			if(c) s2.upd(t, c, 1, n, 1);
		}
		printf("%lld\n", -sum);
	}
	return 0;
}
