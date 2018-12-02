#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll<<(a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 202020;

int n, m, k;
int fa[N], mo[N], val[N], in[N];
bool sex[N], dead[N], vis[N];
vi g[N];

void solve() {
	memset(vis, 0, sizeof(vis));
	rep(i, 1, n + 1) if(!dead[i]) {
		int x = i;
		vis[x] = 1;
		while(mo[x] && !vis[mo[x]]) {
			vis[mo[x]] = 1;
			x = mo[x];
		}
	}
	int cnt = 0;
	rep(i, 1, n + 1) if(in[i] == 0) {
		if(sex[i] == 0 && vis[i]) ++cnt;
		if(sex[i] == 1 && !dead[i]) ++cnt;
	}
	if(cnt == 1) cout << "YES" << endl;
	else cout << "POSSIBLY" << endl;
}

int main() {
	freopen("eve.in","r",stdin);
	freopen("eve.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n + 1) {
		string s;
		cin >> s;
		sex[i] = (s[0] == 'M');
	}
	cin >> m;
	rep(i, 1, m + 1) {
		int x, y;
		string s;
		cin >> x;
		if(x < 0) {
			dead[-x] = 1;
		} else {
			// x is mo
			cin >> y >> s;
			if(sex[x]) swap(x, y);
			++n;
			g[x].pb(n), g[y].pb(n);
			in[n] += 2;
			fa[n] = y, mo[n] = x;
			sex[n] = (s[0] == 'M');
		}
	}
	cin >> k;
	rep(i, 1, k + 1) {
		int x, y;
		cin >> x >> y;
		val[x] = y;
		while(mo[x] && !val[mo[x]]) {
			val[mo[x]] = y;
			x = mo[x];
		}
	}
	vi q;
	rep(i, 1, n + 1) if(sex[i] == 0 && val[i]) {
		q.pb(i);
		vis[i] = 1;
	}
	rep(i, 0, sz(q)) {
		int u = q[i];
		for(auto v : g[u]) {
			val[v] = val[u];
			if(sex[v] == 0 && !vis[v]) {
				q.pb(v);
				vis[v] = 1;
			}
		}
	}
	vi v;
	rep(i, 1, n + 1) if(!dead[i]) v.pb(val[i]);
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	if(sz(v) == 0 || (sz(v) == 1 && v[0])) cout << "YES" << endl;
	else if(sz(v) == 1 && !v[0]) solve();
	else if(sz(v) == 2 && !v[0]) cout << "POSSIBLY" << endl;
	else cout << "NO" << endl;
	return 0;
}
