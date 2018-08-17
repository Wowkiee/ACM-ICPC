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

int n, m = 1e4;
bool ans[N];
pair<pii, int> a[N];

struct Seg {
#define ls rt<<1
#define rs ls|1
	static const int N = ::N;
	int cnt[N];
	void upd(int p, int l, int r, int rt) {
		++cnt[rt];
		if(l == r) return ;
		int mid = l + r >> 1;
		if(p <= mid) upd(p, l, mid, ls);
		else upd(p, mid+1, r, rs);
	}
	int qry(int L, int R, int l, int r, int rt) {
		if(L > R) return 0;
		if(L <= l && r <= R) return cnt[rt];
		int mid = l + r >> 1, ans = 0;
		if(L <= mid) ans += qry(L, R, l, mid, ls);
		if(R >= mid+1) ans += qry(L, R, mid+1, r, rs);
		return ans;
	}
}seg;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n+1) cin >> a[i].fi.fi >> a[i].fi.se, a[i].se = i;
	sort(a+1, a+1+n);
	reverse(a+1, a+1+n);
	rep(i, 1, n+1) {
		if(seg.qry(a[i].fi.se+1, m, 1, m, 1) == 0) ans[a[i].se] = 1;
		seg.upd(a[i].fi.se, 1, m, 1);
	}
	rep(i, 1, n+1) if(ans[i]) cout << i << " ";
	cout << endl;
	return 0;
}
