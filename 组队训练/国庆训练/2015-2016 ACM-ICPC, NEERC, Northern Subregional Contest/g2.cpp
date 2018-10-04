#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(x) (int)x.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll<<(a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 101010;

int n, m, k;
int deg[N];
vi g[N];
vector<pii> e;

void add(int u, int v) {
	e.pb(mp(u, v));
}

int dfs(set<int> s) {
	int la = 0;
	while(sz(s)) {
		if(sz(s) > 1 && k) {
			vector<set<int> > v;
			while(sz(s) > 1 && k) {
				set<int> t;
				t.insert(*s.begin());
				v.pb(t);
				--k;
				s.erase(s.begin());
			}
			v.pb(s);
			reverse(all(v));
			rep(i, 0, sz(v)) {
				la = dfs(v[i]);
				if(i != sz(v) - 1) add(la, *v[i + 1].begin());
			}
			return la;
		}
		auto u = s.begin();
		la = *u;
		for(auto v : g[*u]) {
			--deg[v];
			if(deg[v] == 0) s.insert(v);
		}
		s.erase(u);
	}
	return la;
}

int main() {
//	freopen("graph.in","r",stdin);
//	freopen("graph.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m >> k;
	rep(i, 0, m) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		++deg[v];
	}

	set<int> s;
	rep(i, 1, n + 1) if(!deg[i]) s.insert(i);
	dfs(s);

	for(auto u : e) g[u.fi].pb(u.se);
	vi v;
	s.clear();
	memset(deg, 0, sizeof(deg));
	rep(u, 1, n + 1) {
		for(auto v : g[u]) ++deg[v];
	}
	rep(i, 1, n + 1) if(!deg[i]) s.insert(i);
	while(sz(s)) {
		auto u = s.begin();
		v.pb(*u);
		for(auto v : g[*u]) {
			--deg[v];
			if(deg[v] == 0) s.insert(v);
		}
		s.erase(u);
	}
	rep(i, 0, n) cout << v[i] << " \n"[i == n - 1];
	cout << sz(e) << endl;
	for(auto u : e) cout << u.fi << " " << u.se << endl;
	return 0;
}
