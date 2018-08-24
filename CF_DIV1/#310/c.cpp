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

const int N = 202020;

int n, m;
vi V;
struct Q {
	int x, y;
	char o;
}q[N];

int find(int x) {
	return lower_bound(all(V), x) - V.begin() + 1;
}

struct Seg {
#define ls rt<<1
#define rs ls|1
	static const int N = ::N << 3;
	int ma[N];
	void upd(int L, int R, int c, int l, int r, int rt) {
		if(L <= l && r <= R) {
			ma[rt] = max(ma[rt], c);
			return ;
		}
		int mid = l + r >> 1;
		if(L <= mid) upd(L, R, c, l, mid, ls);
		if(R >= mid+1) upd(L, R, c, mid+1, r, rs);
	}
	int qry(int p, int l, int r, int rt) {
		if(l == r) return ma[rt];
		int mid = l + r >> 1, ans = ma[rt];
		if(p <= mid) ans = max(ans, qry(p, l, mid, ls));
		else ans = max(ans, qry(p, mid+1, r, rs));
		return ans;
	}
}t1, t2;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 1, m+1) {
		string s;
		cin >> q[i].x >> q[i].y >> s;
		q[i].o = s[0];
		V.pb(q[i].x);
		V.pb(q[i].y);
	}
	V.pb(0);
	sort(all(V));
	V.erase(unique(all(V)), V.end());
	map<pii, bool> vis;
	rep(i, 1, m+1) {
		int x = q[i].x, y = q[i].y;
		int px = find(x), py = find(y);
		char o = q[i].o;
		if(vis[mp(x, y)]) {
			cout << 0 << endl;
			continue;
		}
		vis[mp(x, y)] = 1;
		if(o == 'L') {
			int t = t2.qry(py, 1, sz(V), 1);
			cout << x - t << endl;
			int pt = find(t);
			t1.upd(pt+1, px, y, 1, sz(V), 1);
		} else {
			int t = t1.qry(px, 1, sz(V), 1);
			cout << y - t << endl;
			int pt = find(t);
			t2.upd(pt+1, py, x, 1, sz(V), 1);
		}
	}
	return 0;
}
