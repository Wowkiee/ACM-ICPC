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

int n, ans;
int f[N];
pii a[N];
vi V;

struct Seg {
#define ls (rt << 1)
#define rs (ls | 1)
	static const int N = ::N << 2;
	int ma[N];
	void upd(int p, int c, int l, int r, int rt) {
		ma[rt] = max(ma[rt], c);
		if(l == r) return ;
		int mid = l + r >> 1;
		if(p <= mid) upd(p, c, l, mid, ls);
		else upd(p, c, mid+1, r, rs);
	}
	int qry(int L, int R, int l, int r, int rt) {
		if(L > R) return 0;
		if(L <= l && r <= R) return ma[rt];
		int mid = l + r >> 1, ans = 0;
		if(L <= mid) ans = max(ans, qry(L, R, l, mid, ls));
		if(R >= mid+1) ans = max(ans, qry(L, R, mid+1, r, rs));
		return ans;
	}
}seg;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n+1) {
		int x, y;
		cin >> x >> y;
		a[i] = mp(x, y);
		V.pb(x + y);
	}
	sort(all(V));
	V.erase(unique(all(V)), V.end());
	sort(a+1, a+1+n);
	rep(i, 1, n+1) {
		int p = upper_bound(all(V), a[i].fi-a[i].se) - V.begin();
		f[i] = seg.qry(1, p, 1, sz(V), 1) + 1;
	//	dd(i);dd(a[i].fi);dd(p);de(f[i]);
		ans = max(ans, f[i]);
		p = lower_bound(all(V), a[i].fi+a[i].se) - V.begin() + 1;
		seg.upd(p, f[i], 1, sz(V), 1);
	}
	cout << ans << endl;
	return 0;
}
