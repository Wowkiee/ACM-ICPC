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
vector<pii> e;
vi v;
vi g[N];

int main() {
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m >> k;
	rep(i, 0, m) {
		int u, v;
		cin >> u >> v;
		++deg[v];
		g[u].pb(v);
	}
	set<int> s0, s1;
	rep(i, 1, n + 1) if(!deg[i]) s0.insert(i);
	int pre = 0;
	while(sz(v) < n) {
		while(sz(s0) > 1 && k) {
			s1.insert(*s0.begin());
			s0.erase(s0.begin());
			--k;
		}
		if(k && sz(s0) && sz(s1)) {
			auto u = s0.end(); --u;
			auto v = s1.end(); --v;
			if(*u < *v) {
				--k;
				e.pb(mp(pre, *v));
				s0.insert(*v);
				s1.insert(*u);
				s0.erase(u);
				s1.erase(v);
			}
		}
		if(sz(s0) == 0) {
			auto u = s1.end(); --u;
			e.pb(mp(pre, *u));
			s0.insert(*u);
			s1.erase(u);
		}
		auto u = s0.begin();
		v.pb(*u);
		for(auto v : g[*u]) {
			--deg[v];
			if(deg[v] == 0) s0.insert(v);
		}
		pre = *u;
		s0.erase(u);
	}
	rep(i, 0, n) cout << v[i] << " \n"[i == n - 1];
	cout << sz(e) << endl;
	for(auto u : e) cout << u.fi << " " << u.se << endl;
	return 0;
}
