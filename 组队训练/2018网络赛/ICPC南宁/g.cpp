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

const int N = 101010, inf = 1e9+7;

int a[N], ans1[N], ans2[N], n, m, now, t, q, p;

struct Seg {
#define ls rt<<1
#define rs ls|1
	static const int N = ::N << 2;
	int mi[N];
	void up(int rt) {
		mi[rt] = min(mi[ls], mi[rs]);
	}
	void build(int l, int r, int rt) {
		if(l == r) {
			mi[rt] = a[l];
			return ;
		}
		int mid = l + r >> 1;
		build(l, mid, ls);
		build(mid+1, r, rs);
		up(rt);
	}
	void upd(int p, int l, int r, int rt) {
		if(l == r) {
			mi[rt] = inf;
			return ;
		}
		int mid = l + r >> 1;
		if(p <= mid) upd(p, l, mid, ls);
		else upd(p, mid+1, r, rs);
		up(rt);
	}
	int qry(int L, int R, int c, int l, int r, int rt) {
		if (L > R) return -1;
		if(L <= l && r <= R && (l == r ||mi[rt] > c)) {
			if(mi[rt] <= c) return l;
			return -1;
		}
		int mid = l + r >> 1;
		if(L <= mid) {
			int t = qry(L, R, c, l, mid, ls);
			if(~t) return t;
		}
		if(R >= mid+1) {
			int t = qry(L, R, c, mid+1, r, rs);
			if(~t) return t;
		}
		return -1;
	}
}seg;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 1, n+1) cin >> a[i];
	seg.build(1, n, 1);
	now = 0;
	rep(i, 1, 1e5+1) {
		ans1[i] = ans1[i-1];
		if (ans1[i-1] == n) {
			ans1[i] = ans1[i-1];
			ans2[i] = ans2[i-1];
		}else {
			now += m;
			p = 0;
			while(p != -1 && p != n) {
				p = seg.qry(p+1, n, now, 1, n, 1);
				if (p != -1) {
					now -= a[p];
					ans1[i]++;
					seg.upd(p, 1, n, 1);
				}
			}
			ans2[i] = now;
		}
	}
	cin >> q;
	rep(i, 1, q+1) {
		cin >> t;
		cout << ans1[t] << " " << ans2[t] << endl;
	}
	return 0;
}
