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
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---

const int N = 101010, inf = ~0U>>1;

int n, m;
int par[N], sz[N], wson[N], top[N], dep[N], id[N], _, who[N];
vi g[N];
ull res;

void dfs(int c, int fa) {
	sz[c] = 1;
	par[c] = fa;
	dep[c] = dep[fa] + 1;
	int &s = wson[c] = top[c] = 0;
	for(auto t : g[c]) if(t != fa) {
		dfs(t, c);
		sz[c] += sz[t];
		if(sz[t] >= sz[s]) s = t;
	}
}
void dfs2(int c, int fa) {
	id[c] = ++_;
	who[_] = c;
	int s = wson[c];
	if(!top[c]) top[c] = c;
	if(s) top[s] = top[c], dfs2(s, c);
	for(auto t : g[c]) if(t != fa && t != s) dfs2(t, c);
}

struct Seg {
#define ls rt << 1
#define rs ls | 1
	static const int N = ::N << 2;
	ull sum[N], add[N], mul[N];
	void build(int n) {
		fill_n(sum, n << 2, 0);
		fill_n(add, n << 2, 0);
		fill_n(mul, n << 2, 1);
	}
	void gao(int rt, ull c, bool o, int l, int r) {
		if(o == 0) {
			add[rt] += c;
			sum[rt] += c * (r - l + 1);
		} else {
			add[rt] *= c;
			mul[rt] *= c;
			sum[rt] *= c;
		}
	}
	void down(int rt, int l, int r, int mid) {
		if(mul[rt] != 1) {
			gao(ls, mul[rt], 1, l, mid);
			gao(rs, mul[rt], 1, mid+1, r);
			mul[rt] = 1;
		} 
		if(add[rt]) {
			gao(ls, add[rt], 0, l, mid);
			gao(rs, add[rt], 0, mid+1, r);
			add[rt] = 0;
		}
	}
	void up(int rt) {
		sum[rt] = sum[ls] + sum[rs];
	}
	void upd(int L, int R, ull c, bool o, int l, int r, int rt) {
		if(L <= l && r <= R) {
			gao(rt, c, o, l, r);
			return ;
		}
		int mid = l + r >> 1;
		down(rt, l, r, mid);
		if(L <= mid) upd(L, R, c, o, l, mid, ls);
		if(R > mid) upd(L, R, c, o, mid + 1, r, rs);
		up(rt);
	}
	ull qry(int L, int R, int l, int r, int rt) {
		if(L <= l && r <= R) return sum[rt];
		int mid = l + r >> 1;
		ull ans = 0;
		down(rt, l, r, mid);
		if(L <= mid) ans += qry(L, R, l, mid, ls);
		if(R > mid) ans += qry(L, R, mid + 1, r, rs);
		up(rt);
		return ans;
	}
}seg;

void qry(int a, int b, int o, ull c = 0) {
	int fa = top[a], fb = top[b];
	while(fa != fb) {
		if(dep[fa] < dep[fb]) swap(a, b), swap(fa, fb);
		if(o <= 1) {
			seg.upd(id[fa], id[a], c, o, 1, n, 1);
		} else {
			res += seg.qry(id[fa], id[a], 1, n, 1);
		}
		a = par[fa]; fa = top[a];
	}
	if(dep[a] < dep[b]) swap(a, b);
	if(o <= 1) {
		seg.upd(id[b], id[a], c, o, 1, n, 1);
	} else {
		res += seg.qry(id[b], id[a], 1, n, 1);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	while(cin >> n) {
		///init
		rep(i, 1, n+1) g[i].clear();
		///read
		rep(i, 2, n+1) {
			cin >> par[i];
			g[par[i]].pb(i);
		}
		///solve
		dfs(1, 0);
		_ = 0;
		dfs2(1, 0);
		cin >> m;
		seg.build(n);
		while(m--) {
			int o, a, b;
			ull c;
			cin >> o >> a >> b;
			if(o == 1) {
				cin >> c;
				qry(a, b, 1, c);
			} else if(o == 2) {
				cin >> c;
				qry(a, b, 0, c);
			} else if(o == 3) {
				qry(a, b, 0, 1);
				ull x = -1;
				qry(a, b, 1, x);
			} else {
				res = 0;
				qry(a, b, 2);
				cout << res << endl;
			}
		}
	}
	return 0;
}
