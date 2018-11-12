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
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 44;

int n, m, tim;
int vis[N], in[N], deg[N];
string a[N], b[N];
vi g[N];
map<string, int> id;

void add(string x) {
	if(id.count(x)) return ;
	id[x] = ++n;
}

bool check() {
	vi q;
	rep(i, 1, n + 1) {
		deg[i] = in[i];
		if(!deg[i]) q.pb(i), vis[i] = tim;
	}
	rep(i, 0, sz(q)) {
		int u = q[i];
		for(auto v : g[u]) {
			--deg[v];
			if(deg[v] == 0) {
				q.pb(v);
				vis[v] = tim;
			}
		}
	}
	rep(i, 1, n + 1) if(vis[i] != tim) return 1;
	return 0;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	while(cin >> m) {
		id.clear();
		n = 0;
		rep(i, 1, m + 1) {
			cin >> a[i] >> b[i];
			add(a[i]), add(b[i]);
		}
		rep(i, 1, n + 1) g[i].clear(), in[i] = 0;
		bool ans = 1;
		rep(i, 1, m + 1) {
			++tim;
			int u = id[a[i]], v = id[b[i]];
			g[u].pb(v);
			++in[v];
			if(check()) {
				cout << a[i] << " " << b[i] << endl;
				ans = 0;
				break;
			}
		}
		if(ans) cout << 0 << endl;
	}
	return 0;
}
