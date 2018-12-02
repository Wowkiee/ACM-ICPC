#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(x) cout << #x << " = " << x << " "
#define de(x) cout << #x << " = " << x << endl
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 2e5 + 7;
int top[N],ans1, ans2, val[N], p, n, s[N], du[N], q, x, now[N];
set<int> S[N];
vi g[N];
string op;

struct LCARMQ{
	static const int N = 101010 << 1;
	int a[20][N], lft[N], dep[N], lg[N], L;
	int rmin(int x, int y) {return dep[x] < dep[y] ? x : y;}
	void add(int x) { a[0][L++] = x;}
	void dfs(int c, int fa, const vi g[], int tp) {
		lft[c] = L;	
		if (du[c] == 1) s[c] = 1;
		add(c);
		top[c] = tp;
		for (auto t : g[c]) if (t != fa) {
			dep[t] = dep[c] + 1;
			if (c == 1) dfs(t, c, g, t);
			else dfs(t, c, g, tp);
			s[c] += s[t];
			add(c);
		}
	}
	void build(const vi g[]) {
		L = 0;dfs(1, -1, g, 0);
		rep(i, 2, L) lg[i] = lg[i>>1] + 1;
		rep(i, 1, 20) {
			int lim = L + 1 - (1 << i);
			rep(j, 0, lim) a[i][j] = rmin(a[i-1][j], a[i-1][j+(1<<i>>1)]);
		}
		//rep(i, 1, L) s[i] = s[i-1] + s[i];
	}
	int lca(int x, int y) {
		//x = lft[x], y = lft[y];
		if (x > y) swap(x, y);
		int i = lg[y - x + 1];
		return rmin(a[i][x], a[i][y+1-(1<<i)]);
	}
} R;

int main() {
	freopen("gangsters.in","r",stdin);
	freopen("gangsters.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> q;
	rep(i, 2, n+1) {
		cin >> x;
		du[x]++;
		du[i]++;
		g[x].pb(i);
	}
	R.build(g);
	ans1 = ans2 = 0;
	//rep(i, 1, n+1) de(top[i]);
	rep(cas, 1, q+1) {
		cin >> op >> x;
		p = top[x];
		if (op[0] == '+') {
			S[p].insert(R.lft[x]);
			if(sz(S[p]) == 1) ans1++, now[p] = x, val[p] = 0;
			else {
				now[p] = R.lca(R.lft[now[p]], R.lft[x]);	
				ans2 -= val[p];
				val[p] = s[now[p]] -sz(S[p]);
				ans2 += val[p];
			}
		}else {
			S[p].erase(R.lft[x]);
			if (sz(S[p]) == 0) {
				ans1--;val[p] = 0;
			}else {
				now[p] = R.lca(*S[p].begin(), *(--S[p].end()));
				ans2 -= val[p];
				val[p] = s[now[p]] - sz(S[p]);
				ans2 += val[p];
			}
		}
		cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}
