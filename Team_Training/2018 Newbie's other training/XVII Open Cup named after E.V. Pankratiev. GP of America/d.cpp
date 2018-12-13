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
#define pw(a) (1ll << (a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 202020, M = 10101010;

int n, root;
int val[N], rt[N];
vi v;
vi g[N];

int cntp;
int sum[M], ls[M], rs[M];

void upd(int p, int c, int l, int r, int &rt) {
	if(!rt) rt = ++cntp;
	sum[rt] += c;
	if(l == r) return ;
	int mid = l + r >> 1;
	if(l <= mid) upd(p, c, l, mid, ls[rt]);
	else upd(p, c, mid + 1, r, rs[rt]);
}
int qry(int L, int R, int l, int r, int rt) {
	if(!rt || L > R) return 0;
	if(L <= l && r <= R) return sum[rt];
	int mid = l + r >> 1, ans = 0;
	if(L <= mid) ans += qry(L, R, l, mid, ls[rt]);
	if(R > mid) ans += qry(L, R, mid + 1, r, rs[rt]);
	return ans;
}
int merge(int x, int y) {
	if(x && y) {
		sum[x] += sum[y];
		ls[x] = merge(ls[x], ls[y]);
		rs[x] = merge(rs[x], rs[y]);
		return x;
	} else {
		return x + y;
	}
}

int F(int x) {
	return lower_bound(all(v), x) - v.begin() + 1;
}

int get(int c, int rt) {
	if(sum[rt] < c) return sz(v) + 1;
	int l = 1, r = sz(v);
	int mid = l + r >> 1;
	while(l < r) {
		int sl = sum[ls[rt]];
		int sr = sum[rs[rt]];
		if(sl >= c) {
			r = mid;
			rt = ls[rt];
		} else {
			l = mid + 1;
			rt = rs[rt];
		}
	}
	return l;
}

void dfs(int u) {
	int c = 1;
	rep(i, 0, sz(g[u])) {
		int v = g[u][i];
		c += qry(1, val - 1, 1, sz(v), rt[v]);
	}
	rep(i, 0, sz(g[u])) rt[u] = merge(rt[u], rt[g[u][i]]);
	int L = val, R = get(c, rt[u]);
	if(L < R) {
		int valL = qry(1, L - 1, 1, sz(v), rt[u]);
		int valR = qry(1, R, 1, sz(v), rt[u]);
		upd(L, c - valL, 1, sz(v), rt[u]);
		upd(R, valR - c, 1, sz(v), rt[u]);
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n + 1) {
		int p;
		cin >> val[i] >> p;
		v.pb(val[i]);
		if(p == 0) {
			root = i;
		} else {
			g[p].pb(i);
		}
	}
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	rep(i, 1, n + 1) val[i] = F(val[i]);
	dfs(root);
	cout << qry(1, sz(v), 1, sz(v), rt[root]) << endl;
	return 0;
}
