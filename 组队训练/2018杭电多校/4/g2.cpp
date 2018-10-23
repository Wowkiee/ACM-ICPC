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

const int N = 1010101, P = 1e9 + 7;

int n, ans, sum, p, po, cc;
int jc[N], in[N], b[N], deg[N], pre[N], pdeg[N];
vi g[N];

inline int mul(int a, int b) {
	return 1ll * a * b % P;
}
inline int add(int a, int b) {
	int r = a + b;
	if(r >= P) r -= P;
	return r;
}
inline int kpow(int a, int b) {
	int r = 1;
	while(b) {
		if(b & 1) r = mul(r, a);
		a = mul(a, a);
		b >>= 1;
	}
	return r;
}

inline void init() {
	jc[0] = 1;
	rep(i, 1, N) jc[i] = mul(jc[i-1], i);
	in[N-1] = kpow(jc[N-1], P-2);
	for(int i = N-2; ~i; --i) in[i] = mul(in[i+1], i+1);
}

void dfs(int u, int fa) {
	pre[u] = fa;
	for(auto v : g[u]) if(v != fa) dfs(v, u);
}

#define ls (rt << 1)
#define rs (ls | 1)
int cnt[N<<2];
void build(int l, int r, int rt) {
	cnt[rt] = r - l + 1;
	if(l == r) return ;
	int mid = l + r >> 1;
	build(l, mid, ls);
	build(mid+1, r, rs);
}
void upd(int p, int l, int r, int rt) {
	--cnt[rt];
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

void dfs(int u) {
	if(p > n) return ;
	if(deg[u]) {
		po = pdeg[u-1] + 1 + lower_bound(all(g[u]), b[p]) - g[u].begin();
		cc = qry(pdeg[u-1]+1, po-1, 1, pdeg[n], 1);
		ans = add(ans, mul(mul(cc, sum), mul(in[deg[u]], jc[deg[u]-1])));
		if(pre[b[p]] == u) {
			sum = mul(sum, mul(in[deg[u]], jc[deg[u]-1]));
			++p, --deg[u];
			upd(po, 1, pdeg[n], 1);
			dfs(b[p-1]);
		} else {
			p = n + 1;
			return ;
		}
	} else {
		dfs(pre[u]);
	}
}

inline void solve() {
	///
	cin >> n;
	///init
	fill_n(deg+1, n, 0);
	fill_n(g+1, n, vi());
	///read
	rep(i, 1, n+1) cin >> b[i];
	rep(i, 1, n) {
		int u, v;
		cin >> u >> v;
		++deg[u], ++deg[v];
		g[u].pb(v);
		g[v].pb(u);
	}
	///
	if(n == 1) {
		cout << "0" << endl;
		return ;
	}
	///solve1
	ans = 0, sum = 1;
	rep(i, 1, n+1) sum = mul(sum, jc[deg[i]-1]);
	rep(i, 1, b[1]) ans = add(ans, mul(sum, deg[i]));
	sum = mul(sum, deg[b[1]]);
	///solve2
	dfs(b[1], 0);
	rep(i, 1, n+1) sort(all(g[i]));
	rep(i, 1, n+1) if(i != b[1]) {
		--deg[i];
		auto t = find(all(g[i]), pre[i]);
		g[i].erase(t);
	}
	rep(i, 1, n+1) pdeg[i] = pdeg[i-1] + deg[i];
	build(1, pdeg[n], 1);
	p = 2;
	dfs(b[1]);
	///print
	cout << ans << endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	init();
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
	return 0;
}
