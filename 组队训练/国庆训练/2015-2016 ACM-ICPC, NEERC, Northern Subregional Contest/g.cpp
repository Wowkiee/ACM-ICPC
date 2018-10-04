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
vi v;
vi g[N];
vector<pii> res;
set<int> s;

int main() {
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m >> k;
	rep(i, 0, m) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		++deg[v];
	}
	rep(i, 1, n + 1) if(!deg[i]) s.insert(i);
	while(sz(s)) {
		while(k > 1 && sz(s) > 1) {
			auto v = s.begin();
			auto u = v; ++u;
			--k;
			++deg[*v];
			g[*u].pb(*v);
			res.pb(mp(*u, *v));
			s.erase(v);
		}
		while(k && sz(s) > 1) {
			auto v = s.begin(), u = s.end();
			--u;
			--k;
			++deg[*v];
			g[*u].pb(*v);
			res.pb(mp(*u, *v));
			s.erase(v);
		}
		auto c = s.begin();
		v.pb(*c);
		s.erase(c);
		for(auto v : g[*c]) {
			--deg[v];
			if(deg[v] == 0) s.insert(v);
		}
	}
	rep(i, 0, n) cout << v[i] << " \n"[i == n-1];
	cout << sz(res) << endl;
	for(auto u : res) cout << u.fi << " " << u.se << endl;
	return 0;
}
