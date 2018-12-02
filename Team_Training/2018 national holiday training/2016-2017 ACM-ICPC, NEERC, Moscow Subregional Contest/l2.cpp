
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 2e5 + 7;
int n, l, x, w[N], siz[N];
db val[N]; 
bool f[N];
string op;
vi g[N];
void dfs1(int u, int fa) {
	siz[u] = 1;
	for (auto v : g[u]) if (v != fa) {
		dfs1(v, u);
		siz[u] += siz[v];
		w[u] += w[v];
	}
}

void dfs2(int u, int fa) {
	int s = w[u] - (siz[u] - 1 - w[u]);
	for (auto v : g[u]) if (v != fa) {
		int t = w[v] - (siz[v] - w[v]);
		val[v] += 1.0 * t / s * val[u];
		dfs2(v, u);
	}
}

int main() {
	cin >> n;
	l = 1;
	rep(i, 1, 2 * n + 1) {
		cin >> op >> x;
		if (op == "+") {
			w[i] = 1;
			f[i] = 1;
			val[i] = -x;
		}else {
			rep(j, l, i) g[i].pb(j);
			val[i] = x;
			l = i;
		}
	}
	dfs1(2 * n, 0);
	dfs2(2 * n, 0);
	//de(w[2 * n]);
	rep(i, 1, 2 * n + 1) if (f[i]) printf("%.10f\n", val[i]); 
	return 0;
}
