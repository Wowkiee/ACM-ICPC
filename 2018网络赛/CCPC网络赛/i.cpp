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

const int N = 101010;

int n;
int sz[N], f[N], val[N],jc[N];
vector<pii> g[N];

void dfs(int u, int fa) {
	sz[u] = 1;
	for(auto v : g[u]) if(v.fi != fa) {
		val[v.fi] = add(val[u], v.se);
		dfs(v.fi, u);
		sz[u] += sz[v.fi];
	}
}
void dfs2(int u, int fa) {
	for(auto v : g[u]) if(v.fi != fa) {
		int c = sz[v.fi], b = sz[1] - c;
		f[v.fi] = add(f[u], mul(v.se, sub(b, c)));
		dfs2(v.fi, u);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	jc[0] = 1;
	rep(i, 1, 1e5+1) jc[i] = mul(jc[i-1],i);
	while(cin >> n) {
		rep(i, 1, n+1) g[i].clear();
		rep(i, 1, n) {
			int u, v, w;
			cin >> u >> v >> w;
			g[u].pb(mp(v, w));
			g[v].pb(mp(u, w));
		}
		dfs(1, 0);
		f[1] = 0;
		rep(i, 1, n+1) f[1] = add(f[1], val[i]);
		dfs2(1, 0);
		int ans = 0;
		rep(i, 1, n+1) ans = add(ans, f[i]);//, dd(i), de(f[i]);
		ans = mul(ans, jc[n-1]);
		cout << ans << endl;
	}
	return 0;
}
