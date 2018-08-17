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
int f[N], ans[N], sz[N], wson[N], top[N], dep[N], id[N], par[N], who[N], vis[N];
vi g[N];
pair<int, pii> e[N];
pair<pii, pii> Q[N];

// sum, len, llen, rlen
pair<pii, pii> join(pair<pii, pii> A, pair<pii, pii> B) {
	int s = A.fi.fi + B.fi.fi;
	s -= f[A.se.se] + f[B.se.fi];
	s += f[A.se.se + B.se.fi];
	int ll = A.se.fi;
	if(A.se.fi == A.fi.se) ll += B.se.fi;
	int rl = B.se.se;
	if(B.se.se == B.fi.se) rl += A.se.se;
	return mp(mp(s, A.fi.se + B.fi.se), mp(ll, rl));
}

struct Seg {
#define ls rt<<1
#define rs ls|1
	static const int N = ::N << 2;
	int sum[N], llen[N], rlen[N];
	void upd(int p, int l, int r, int rt) {
		if(l == r) {
			sum[rt] = f[1];
			vis[l] = llen[rt] = rlen[rt] = 1;
			return ;
		}
		int mid = l + r >> 1;
		if(p <= mid) upd(p, l, mid, ls);
		else upd(p, mid+1, r, rs);
		auto u = join({{sum[ls], mid-l+1}, {llen[ls], rlen[ls]}}, {{sum[rs], r-mid}, {llen[rs], rlen[rs]}});
		sum[rt] = u.fi.fi;
		llen[rt] = u.se.fi, rlen[rt] = u.se.se;
	}
	pair<pii, pii> qry(int L, int R, int l, int r, int rt) {
		if(L > R) return {{0, 0}, {0, 0}};
		if(L <= l && r <= R) return {{sum[rt], r-l+1}, {llen[rt], rlen[rt]}};
		int mid = l + r >> 1;
		if(L > mid) return qry(L, R, mid+1, r, rs);
		if(R < mid+1) return qry(L, R, l, mid, ls);
		return join(qry(L, R, l, mid, ls), qry(L, R, mid+1, r, rs));
	}
}seg;

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
void solve(int u, int v, int index) {
	pair<pii, pii> r1 = {{0, 0}, {0, 0}}, r2 = r1;
	while(top[u] != top[v]) {
		if(dep[top[u]] > dep[top[v]]) {
			r1 = join(seg.qry(id[top[u]]+1, id[u], 1, _, 1), r1);
			u = top[u];
			r1 = join({{f[vis[id[u]]], 1}, {vis[id[u]], vis[id[u]]}}, r1);
			u = par[u];
		} else {
			r2 = join(seg.qry(id[top[v]]+1, id[v], 1, _, 1), r2);
			v = top[v];
			r2 = join({{f[vis[id[v]]], 1}, {vis[id[v]], vis[id[v]]}}, r2);
			v = par[v];
		}
	}
	if(dep[u] > dep[v]) {
		r1 = join(seg.qry(id[v]+1, id[u], 1, _, 1), r1);
	} else if(dep[u] < dep[v]) {
		r2 = join(seg.qry(id[u]+1, id[v], 1, _, 1), r2);
	}
	swap(r1.se.fi, r1.se.se);
	auto r = join(r1, r2);
	ans[index] = r.fi.fi;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	///read
	cin >> n >> q;
	rep(i, 1, n) cin >> f[i];
	rep(i, 1, n) {
		int u, v, w;
		cin >> u >> v >> w;
		e[i] = mp(w, mp(u, v));
		g[u].pb(v);
		g[v].pb(u);
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
	///hc
	dfs(1, 0);
	dfs2(1, 0);
	///solve
	int p = 1;
	rep(i, 1, q+1) {
		int l = Q[i].fi.fi, u = Q[i].se.fi, v = Q[i].se.se;
		while(p < n && e[p].fi >= l) {
			if(dep[e[p].se.fi] > dep[e[p].se.se]) swap(e[p].se.fi, e[p].se.se);
			seg.upd(id[e[p].se.se], 1, _, 1);
			++p;
		}
		solve(u, v, Q[i].fi.se);
	}
	rep(i, 1, q+1) cout << ans[i] << endl;
	return 0;
}
