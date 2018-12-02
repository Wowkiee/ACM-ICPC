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

const int N = 202020, inf = 1e9+7, P = 998244353;

int n, m, cnt, prod;
int ans[N];
pii e[N], g[N];

inline int mul(int a, int b) {
	return 1ll * a * b % P;
}

struct Seg {
#define ls (rt<<1)
#define rs (ls|1)
	static const int N = ::N << 2;
	int ma[N];
	void up(int rt) {
		ma[rt] = max(ma[ls], ma[rs]);
	}
	void build(int l, int r, int rt) {
		if(l == r) {
			ma[rt] = e[g[l].se].se;
			return ;
		}
		int mid = l + r >> 1;
		build(l, mid, ls);
		build(mid+1, r, rs);
		up(rt);
	}
	void qry(int L, int R, int x, int i, int l, int r, int rt) {
		if(L > R) return ;
		if(L <= l && r <= R && (ma[rt] < x || l == r)) {
			if(ma[rt] >= x) {
				ma[rt] = -inf;
				++cnt;
				prod = mul(prod, g[l].se);
				ans[g[l].se] = i;
			}
			return ;
		}
		int mid = l + r >> 1;
		if(L <= mid) qry(L, R, x, i, l, mid, ls);
		if(R >= mid+1) qry(L, R, x, i, mid+1, r, rs);
		up(rt);
	}
}seg;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	rep(ca, 1, T+1) {
		///
		cin >> n >> m;
		///init
		memset(ans, 0, sizeof(ans));
		///read
		rep(i, 1, n+1) {
			int l, r;
			cin >> l >> r;
			e[i] = mp(l, r);
			g[i] = mp(l, i);
		}
		///solve
		sort(g+1, g+1+n);
		seg.build(1, n, 1);
		prod = cnt = 0;
		cout << "Case #" << ca << ": \n";
		rep(i, 1, m+1) {
			int x; 
			cin >> x;
			x = x ^ prod;
			prod = 1, cnt = 0;
			int p = upper_bound(g+1, g+1+n, mp(x, n+1)) - g - 1;
			seg.qry(1, p, x, i, 1, n, 1);
			cout << cnt << endl;
			if(!cnt) prod = 0;
		}
		rep(i, 1, n+1) cout << ans[i] << " \n"[i==n];
	}
	return 0;
}
