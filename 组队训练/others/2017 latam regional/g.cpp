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
int G[2][2], a[N], f[N][2][2], deg[N], out[N];
vi g[N];
pii b[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	///
	cin >> n;
	///init
	G[0][0] = G[0][1] = G[1][0] = 1;
	f[0][0][0] = 1, f[0][1][1] = 1;
	///read
	rep(i, 1, n+1) {
		int x, y;
		cin >> x >> y >> a[i];
		if(x) g[x].pb(i), ++deg[i], ++out[x];
		if(y) g[y].pb(i), ++deg[i], ++out[y];
		b[i] = mp(x, y);
	}
	///solve
	vi q;
	rep(i, 1, n+1) if(!deg[i]) q.pb(i);
	rep(_, 0, sz(q)) {
		int u = q[_];
		int x = b[u].fi, y = b[u].se;
		rep(i, 0, 2) rep(j, 0, 2) rep(t, 0, 2) rep(c, 0, 2) {
			int t1 = G[i][j], t2 = G[t][c];
			if(a[u] != -1) t2 = a[u];
			f[u][t1][t2] = add(f[u][t1][t2], mul(f[x][i][t], f[y][j][c]));
		}
		for(auto v : g[u]) {
			--deg[v];
			if(deg[v] == 0) q.pb(v);
		}
	}
	int u = 1;
	rep(i, 1, n+1) if(!out[i]) u = i;
	int ans = add(f[u][0][1], f[u][1][0]);
	cout << ans << endl;
	return 0;
}
