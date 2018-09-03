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
int ans[N], belong[N], st[N], vis[N];
vector<pii> v[N], g[N];

int F;
int ne[N], ele[N];
bool used[N];
vi q;

void dfs(int u) {
	if(st[u]) F = u;
	vis[u] = 1;
	for(auto v : g[u]) if(!vis[v.fi]) dfs(v.fi);
}
void dfs2(int u) {
	if(F) return ;
	vis[u] = 2;
	for(auto v : g[u]) if(ans[v.se] == -1 && !used[v.se]) {
		if(F) return ;
		ne[u] = v.fi, ele[u] = v.se;
		used[v.se] = 1;
		if(vis[v.fi] == 2) {
			F = v.fi;
			return ;
		}
		dfs2(v.fi);
	}
}

bool find(int u) {
	F = 0;
	dfs(u);
	if(F) {
		q.clear();
		q.pb(F);
		return 1;
	}
	F = 0;
	dfs2(u);
	if(!F) return 0;
	for(int u = F; vis[u] == 2; u = ne[u]) {
		q.pb(u);
		vis[u] = 3;
		ans[ele[u]] = (belong[ele[u]] == ne[u]);
	}
	return 1;
}

void gao() {
	rep(i, 0, sz(q)) {
		int u = q[i];
		for(auto v : g[u]) if(vis[v.fi] != 3) {
			vis[v.fi] = 3;
			if(ans[v.se] == -1) ans[v.se] = (belong[v.se] == v.fi);
			q.pb(v.fi);
		}
	}
}

bool solve() {
	rep(i, 1, n+1) if(!vis[i]) {
		if(!find(i)) return 0;
		gao();
	}
	rep(i, 1, m+1) if(ans[i] == -1) ans[i] = 0;
	return 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> m;
	fill_n(ans+1, m, -1);
	rep(i, 1, n+1) {
		int k;
		cin >> k;
		while(k--) {
			int x;
			cin >> x;
			v[abs(x)].pb(mp(i, x > 0));
		}
	}
	rep(i, 1, m+1) {
		if(sz(v[i]) == 0) {
			ans[i] = 0;
		} else if(sz(v[i]) == 1) {
			ans[i] = v[i][0].se;
			st[v[i][0].fi] = 1;
		} else {
			if(v[i][0].se == v[i][1].se) {
				ans[i] = v[i][0].se;
				st[v[i][0].fi] = st[v[i][1].fi] = 1;
			} else {
				int st = v[i][0].fi, ed = v[i][1].fi;
				g[st].pb(mp(ed, i));
				g[ed].pb(mp(st, i));
				belong[i] = v[i][0].se ? st : ed;
			}
		}
	}
	if(solve()) {
		cout << "YES" << endl;
		rep(i, 1, m+1) cout << ans[i];
		cout << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
