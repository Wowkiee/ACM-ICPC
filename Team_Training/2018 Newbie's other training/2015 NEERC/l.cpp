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

int w;
int h[N], val[N], a[N];
ll n, pre[N];

struct Seg {
#define ls rt << 1
#define rs ls | 1
	static const int N = ::N << 2;
	int ma[N];
	void up(int rt) {
		ma[rt] = max(ma[ls], ma[rs]);
	}
	void build(int l, int r, int rt) {
		if(l == r) {
			ma[rt] = val[l];
			return ;
		}
		int mid = l + r >> 1;
		build(l, mid, ls);
		build(mid + 1, r, rs);
		up(rt);
	}
	// o == 0 left
	// o == 1 right
	// >= c, first
	int qry(int L, int R, int c, int o, int l, int r, int rt) {
		if(L <= l && r <= R && (l == r || ma[rt] < c)) {
			if(ma[rt] < c) return 0;
			return l;
		}
		int mid = l + r >> 1;
		if(o == 0) {
			if(L <= mid) {
				int t = qry(L, R, c, o, l, mid, ls);
				if(t) return t;
			}
			if(R > mid) {
				int t = qry(L, R, c, o, mid + 1, r, rs);
				if(t) return t;
			}
		} else {
			if(R > mid) {
				int t = qry(L, R, c, o, mid + 1, r, rs);
				if(t) return t;
			}
			if(L <= mid) {
				int t = qry(L, R, c, o, l, mid, ls);
				if(t) return t;
			}
		}
		return 0;
	}
}s1, s2;
ll solve(ll l, ll r, ll n) {
	return (l + r) * n / 2;
}
int main() {
	freopen("landscape.in", "r", stdin);
	freopen("landscape.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> w >> n;
	rep(i, 1, w + 1) {
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	rep(i, 1, w + 1)val[i] = a[i] - i;
	s1.build(1, w, 1);
	rep(i, 1, w + 1)val[i] = a[i] + i;
	s2.build(1, w, 1);
	int ans = max(a[1], a[w]);
	rep(i, 2, w) {
		int l = a[i], r = 2e9;
		while(l < r) {
			int mid = (l + r) / 2 + 1;
			int L = s1.qry(1, i - 1, mid - i, 1, 1, w, 1);
			int R = s2.qry(i + 1, w, mid + i, 0, 1, w, 1);
			if(L == 0 || R == 0) {
				r = mid - 1;
				continue;
			}
			ll down = pre[R] - pre[L - 1];
			ll up = solve(mid - i + L, mid, i - L + 1) + solve(mid - R + i, mid, R - i + 1) - mid;
			if(up - down <= n)l = mid;
			else r = mid - 1;
		}
		ans = max(ans, l);
	}
	cout << ans << endl;
	return 0;
}
