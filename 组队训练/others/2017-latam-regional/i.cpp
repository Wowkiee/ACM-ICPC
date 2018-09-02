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

const int N = 2e5 + 7;
int tr[N * 4], n, m, u, v, tid[N], top[N], dep[N], fa[N], siz[N], son[N], w, uu, vv, l1, r1, x, tim, val[N], ma, q;
ll sum;
pair<int, pii> edge[N];
map<pii, int> S;
vector<pii> g[N];

int get(int x) {
	return x == fa[x] ? x : fa[x] = get(fa[x]);
}

void change(int l, int r,int now) {
	if (l1 <= l && r1 >=r) {
		tr[now] = x;
		return;
	}
	int mid = l + r >> 1;
	if (l1 <= mid) change(l, mid, now * 2);
	if (r1 > mid) change(mid + 1, r, now * 2 + 1);
	tr[now] = max(tr[now * 2], tr[now * 2 + 1]);
}

void ask(int l, int r,int now) {
	if (l1 <= l && r1 >=r) {
		ma = max(ma, tr[now]);
		return;
	}
	int mid = l + r >> 1;
	if (l1 <= mid) ask(l, mid, now * 2);
	if (r1 > mid) ask(mid + 1, r, now * 2 + 1);
}

void init() {
	memset(son, -1, sizeof(son));
	tim = 0;
	rep(i, 1, n+1) fa[i] = i;
}

void dfs1(int u, int pre, int d) {
	dep[u] = d;
	fa[u] = pre;
	siz[u] = 1;
	rep(i, 0, sz(g[u])) {
		int v = g[u][i].fi, w = g[u][i].se;
		if (v != pre) {
			val[v] = w;
			dfs1(v, u, d+1);
			siz[u] += siz[v];
			if (son[u] == -1 || siz[v] > siz[son[u]]) son[u] = v;
		}
	}
}

void dfs2(int u, int tp) {
	top[u] = tp;
	tid[u] = ++tim;
	l1 = r1 = tim; x = val[u];
	change(1, n, 1);
	if (son[u] == -1) return;
	dfs2(son[u], tp);
	rep(i, 0, sz(g[u])) {
		int v = g[u][i].fi;
		if (v != son[u] && v != fa[u]) dfs2(v, v);
	}
}

int solve(int u, int v) {
	ma = -1 << 30;
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		l1 = tid[top[u]]; r1 = tid[u];
		ask(1, n, 1);
		u = fa[top[u]];
	}
	if (u == v) return ma;
	if (dep[u] < dep[v]) swap(u, v);
	l1 = tid[v] + 1; r1 = tid[u];
	ask(1, n, 1);
	return ma;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 1, m+1) {
		cin >> u >> v >> w;
		edge[i] = mp(w, mp(u, v));
		if (u > v) swap(u , v);
		S[mp(u, v)] = w;
	}
	init();	
	//return 0;
	sort(edge + 1, edge + m + 1);
	rep(i, 1, m+1) {
		u = edge[i].se.fi; v = edge[i].se.se; w= edge[i].fi;
		uu = get(u); vv = get(v);
		if (uu == vv) continue;
		fa[uu] = vv;
		sum += w;
		g[u].pb(mp(v, w));
		g[v].pb(mp(u, w));
	}
	//return 0;
	dfs1(1, 0, 1);
	//return 0;
	dfs2(1, 1);
	//return 0;
	cin >> q;
	//de(sum);
	rep(cas, 0, q) {
		cin >> u >> v;
		if (u > v) swap(u, v);
		w = S[mp(u, v)];
		//dd(w);
		cout << sum - solve(u, v) + w << endl;
	}
	return 0;
}
