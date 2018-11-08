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
#define pw(a) (1ll<<(a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 101010;

int n, q;
int ans[N];
vector<pair<pii, int> > a;

struct Seg {
#define ls rt << 1
#define rs ls | 1
	static const int N = ::N << 2;
	int cnt[N];
	void upd(int p, int l, int r, int rt) {
		cnt[rt]++;
		if(l == r) return ;
		int mid = l + r >> 1;
		if(p <= mid) upd(p, l, mid, ls);
		else upd(p, mid + 1, r, rs);
	}
	int qry(int L, int R, int l, int r, int rt) {
		if(L <= l && r <= R) return cnt[rt];
		int mid = l + r >> 1, ans = 0;
		if(L <= mid) ans += qry(L, R, l, mid, ls);
		if(R > mid) ans += qry(L, R, mid + 1, r, rs);
		return ans;
	}
}seg;

int main() {
	freopen("distance.in", "r", stdin);
	freopen("distance.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n - 3 + 1) {
		int l, r;
		cin >> l >> r;
		if(l > r) swap(l, r);
		a.pb(mp(mp(r, 0), l));
		a.pb(mp(mp(l + n, 0), r));
	}
	cin >> q;
	rep(i, 1, q + 1) {
		int l, r;
		cin >> l >> r;
		if(l > r) swap(l, r);
		if(l != r) {
			a.pb(mp(mp(r, i), l));
			a.pb(mp(mp(l + n, i), r));
		}
		ans[i] = r - l;
	}
	sort(all(a));
	for(auto u : a) {
		if(u.fi.se) {
			int t = u.fi.fi - u.se - seg.qry(u.se, u.fi.fi, 1, n << 1, 1);
			ans[u.fi.se] = min(ans[u.fi.se], t);
		} else {
			seg.upd(u.se, 1, n << 1, 1);
		}
	}
	rep(i, 1, q + 1) cout << ans[i] << endl;
	return 0;
}
