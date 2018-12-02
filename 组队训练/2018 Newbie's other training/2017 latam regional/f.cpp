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

const int N = 101010;

struct Seg {
#define ls rt << 1
#define rs ls | 1
	static const int N = ::N << 2;
	ll ma[N];
	void upd(int p, ll c, int l, int r, int rt) {
		ma[rt] = max(ma[rt], c);
		if(l == r) return ;
		int mid = l + r >> 1;
		if(p <= mid) upd(p, c, l, mid, ls);
		else upd(p, c, mid+1, r, rs);
	}
	ll qry(int L, int R, int l, int r, int rt) {
		if(L > R) return 0;
		if(L <= l && r <= R) return ma[rt];
		int mid = l + r >> 1;
		ll ans = 0;
		if(L <= mid) ans = max(ans, qry(L, R, l, mid, ls));
		if(R >= mid+1) ans = max(ans, qry(L, R, mid+1, r, rs));
		return ans;
	}
}seg;

int n;
pair<pii, int> a[N];
ll f[N];
vector<ll> V;

int find(ll x) {
	return lower_bound(all(V), x) - V.begin() + 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n+1) cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se, V.pb(a[i].fi.se), a[i].fi.se = -a[i].fi.se;
	sort(a+1, a+1+n);
	sort(all(V));
	V.erase(unique(all(V)), V.end());
	ll ans = 0;
	rep(i, 1, n+1) {
		int x = a[i].fi.fi, y = find(-a[i].fi.se);
		if(i > 1 && a[i].fi == a[i-1].fi) {
			f[i] = f[i-1] + a[i].se;
		} else {
			ll t = seg.qry(1, y - 1, 1, n, 1);
			f[i] = t + a[i].se;
		}
		if(i == n || a[i].fi != a[i+1].fi) seg.upd(y, f[i], 1, n, 1);
	}
	rep(i, 1, n+1) ans = max(ans, f[i]);
	cout << ans << endl;
	return 0;
}
