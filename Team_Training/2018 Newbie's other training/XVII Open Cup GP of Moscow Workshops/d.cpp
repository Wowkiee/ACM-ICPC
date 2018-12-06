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
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 603030, inf = 1e9 + 7, dx = 300000;

struct Seg {
#define ls rt << 1
#define rs ls | 1
	static const int N = ::N << 2;
	int ma[N];
	void build(int l, int r, int rt) {
		if(rt == 1) l += dx, r += dx;
		ma[rt] = -inf;
		if(l == r) return ;
		int mid = l + r >> 1;
		build(l, mid, ls);
		build(mid + 1, r, rs);
	}
	void up(int rt) {
		ma[rt] = max(ma[ls], ma[rs]);
	}
	void upd(int p, int c, int l, int r, int rt) {
		if(rt == 1) {
			l += dx, r += dx, p += dx;
		}
		if(l == r) {
			ma[rt] = c;
			return ;
		}
		int mid = l + r >> 1;
		if(p <= mid) upd(p, c, l, mid, ls);
		else upd(p, c, mid + 1, r, rs);
		up(rt);
	}
	int qry(int L, int R, int l, int r, int rt) {
		if(rt == 1) {
			l += dx, r += dx, L += dx, R += dx;
		}
		if(L > R)return -inf;
		if(L <= l && r <= R) return ma[rt];
		int mid = l + r >> 1, ans = -inf;
		if(L <= mid) ans = max(ans, qry(L, R, l, mid, ls));
		if(R > mid) ans = max(ans, qry(L, R, mid + 1, r, rs));
		return ans;
	}
}seg;
int a[N], p[N], dp[N], n, l, r;
deque<int> Q[N];
void in(deque<int>& Q, int id) {
	while(!Q.empty() && dp[Q.back()] <= dp[id])Q.pop_back();
	Q.pb(id);
}
void out(deque<int>& Q, int id) {
	if(!Q.empty() && Q.front() == id)Q.pop_front();
}
void gao(int id) {
	dp[id] = max(dp[id], seg.qry(-dx, p[id] - 1, -dx, dx, 1) + 1);
	dp[id] = max(dp[id], seg.qry(p[id], p[id], -dx, dx, 1));
	dp[id] = max(dp[id], seg.qry(p[id] + 1, dx, -dx, dx, 1) - 1);
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	seg.build(-dx, dx, 1);
	cin >> n >> l >> r;
	rep(i, 0, n + 1)dp[i] = -inf;
	dp[0] = 0;
	rep(i, 1, n + 1) {
		cin >> a[i];
		p[i] = p[i - 1] + a[i];
	}
	rep(i, 1, n + 1) {
		if(i >= l) {
			in(Q[p[i - l] + dx], i - l);
			if(Q[p[i - l] + dx].empty())seg.upd(p[i - l], -inf, -dx, dx, 1);
			else seg.upd(p[i - l], dp[Q[p[i - l] + dx].front()], -dx, dx, 1);
		}
		gao(i);
		if(i >= r) {
			out(Q[p[i - r] + dx], i - r);
			if(Q[p[i - r] + dx].empty())seg.upd(p[i - r], -inf, -dx, dx, 1);
			else seg.upd(p[i - r], dp[Q[p[i - r] + dx].front()], -dx, dx, 1);
		}
	}
	if(dp[n] < -n)cout << "Impossible" << endl;
	else cout << dp[n] << endl;
	return 0;
}
