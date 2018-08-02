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

const int N = 202020;

int n;
int b[N], po[N];

struct Seg {
#define ls (rt << 1)
#define rs (ls | 1)
	static const int N = ::N << 2;
	int la[N], mi[N];
	void build(int l, int r, int rt) {
		la[rt] = 0;
		mi[rt] = l;
		if(l == r) return ;
		int mid = l + r >> 1;
		build(l, mid, ls);
		build(mid+1, r, rs);
	}
	void down(int rt) {
		if(!la[rt]) return ;
		la[ls] += la[rt];
		la[rs] += la[rt];
		mi[ls] += la[rt];
		mi[rs] += la[rt];
		la[rt] = 0;
	}
	void upd(int L, int R, int c, int l, int r, int rt) {
		if(L <= l && r <= R) {
			la[rt] += c;
			mi[rt] += c;
			return ;
		}
		int mid = l + r >> 1;
		down(rt);
		if(L <= mid) upd(L, R, c, l, mid, ls);
		if(R >= mid+1) upd(L, R, c, mid+1, r, rs);
		mi[rt] = min(mi[ls], mi[rs]);
	}
}seg;
struct Fenwick {
#define lb(x) ((x) & -(x))
	static const int N = ::N;
	int n;int a[N];
	void ini(int _n) {
		fill_n(a + 1, n = _n, 0);
	}
	void add(int x, int d) {
		for(; x<=n; x+=lb(x)) a[x] +=d;
	}
	int sum(int x) {
		int r = 0;
		for(; x>=1; x^=lb(x)) r += a[x];
		return r;
	}
}fen;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n; n >>= 1;
	rep(i, 1, n+1) cin >> b[i], po[b[i]] = i, b[i] >>= 1;
	seg.build(1, n, 1);
	ll ans = 0;
	rep(i, 1, n+1) {
		ans += i-1+min(0, seg.mi[1]);
		seg.upd(po[i<<1], n, -2, 1, n, 1);
	}
	fen.ini(n);
	for(int i = n; i; --i) {
		ans += fen.sum(b[i]-1);
		fen.add(b[i], 1);
	}
	cout << ans << endl;
	return 0;
}
