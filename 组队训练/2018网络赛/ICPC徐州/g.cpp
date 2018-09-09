#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---

const int N = 50505;

int n;
int x[N], y[N], b[N];
ll ans;
pii a[N];

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
			ma[rt] = a[l].se;
			return ;
		}
		int mid = l + r >> 1;
		build(l, mid, ls);
		build(mid + 1, r, rs);
		up(rt);
	}
	int qry(int L, int R, int c, int l, int r, int rt) {
		if(L > R) return 0;
		if(L <= l && r <= R && (l == r || ma[rt] <= c)) {
			if(ma[rt] <= c) return 0;
			return ma[rt];
		}
		int mid = l + r >> 1;
		if(L <= mid) {
			int t = qry(L, R, c, l, mid, ls);
			if(t) return t;
		}
		if(R > mid) {
			int t = qry(L, R, c, mid+1, r, rs);
			if(t) return t;
		}
		return 0;
	}
}seg;

void solve() {
	sort(a + 1, a + 1 + n);
	seg.build(1, n, 1);
	rep(i, 1, n+1) {
		int t = seg.qry(i + 1, n, a[i].se, 1, n, 1);
		ans += b[a[i].se] - b[t];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n+1) cin >> x[i] >> y[i];
	rep(i, 1, n+1) a[i] = mp(x[i], i), b[i] = y[i];
	solve();
	rep(i, 1, n+1) a[i] = mp(y[i], i), b[i] = x[i];
	solve();
	cout << ans << endl;
	return 0;
}
