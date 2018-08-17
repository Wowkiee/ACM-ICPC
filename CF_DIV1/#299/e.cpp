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

const int N = 101010;

int n, q, _;
int f[N], ans[N], sz[N], wson[N], top[N], dep[N], id[N], par[N], who[N], pre[N];
vi g[N];
pair<int, pii> e[N];
pair<pii, pii> Q[N];

struct Seg {
#define ls rt<<1
#define rs ls|1
	static const int N = ::N << 2;
	int sum[N];
	void upd(int p, int c, int l, int r, int rt) {
		if(l == r) {
			sum[rt] = c;
			return ;
		}
		int mid = l + r >> 1;
		if(p <= mid) upd(p, c, l, mid, ls);
		else upd(p, c, mid+1, r, rs);
		sum[rt] = sum[ls] + sum[rs];
	}
	int qry(int L, int R, int l, int r, int rt) {
		if(L <= l && r <= R) return sum[rt];
		int mid = l + r >> 1, ans = 0;
		if(L <= mid) ans += qry(L, R, l, mid, ls);
		if(R >= mid+1) ans += qry(L, R, mid+1, r, rs);
		return ans;
	}
}seg;

void dfs(int c, int fa) {
	sz[c] = 1;
	par[c] = fa;
	dep[c] = dep[fa] + 1;
	int &s = wson[c] = top[c] = 0;
	for(auto v : g[c]) if(v.fi != fa) {
		dfs(v.fi, c);
		sz[c] += sz[v.fi];
		if(sz[v.fi] >= sz[s]) s = t;
	}
}
void dfs2(int c, int fa) {
	id[c] = ++_;
	who[_] = c;
	int s = wson[c];
	if(!top[c]) top[c] = c;
	if(s) top[s] = top[c], dfs2(s, c);
	for(auto v : g[c]) if(v.fi != fa && v.fi != s) dfs2(v.fi, c);
}

int find(int x) {
	if(x == pre[x]) return x;
	return pre[x] = find(pre[x]);
}
void join(int x, int y) {
	x = find(x), y = find(y);
	if(dep[x] > dep[y]) swap(x, y);
	pre[y] = x;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> q;
	rep(i, 1, n) cin >> f[i];
	rep(i, 1, n) {
		int u, v, w;
		cin >> u >> v >> w;
		e[i] = mp(w, mp(u, v));
		g[u].pb(mp(v, w));
		g[v].pb(mp(u, w));
	}
	rep(i, 1, q+1) {
		int u, v, l;
		cin >> u >> v >> l;
		Q[i] = mp(mp(l, i), mp(u, v));
	}
	sort(e+1, e+n);
	reverse(e+1, e+n);
	sort(Q+1, Q+1+q);
	reverse(Q+1, Q+1+q);
	dfs(1, 0);
	dfs2(1, 0);
	rep(i, 1, n+1) pre[i] = i;
	return 0;
}
