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

const int N = 303030;

int n, m;
int a[N], b[N], pre[N], ma[N], mi[N];
ll res[N];
pair<int, pii> e[N];

int find(int x) {
	return x == pre[x] ? x : (pre[x] = find(pre[x]));
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 1, n + 1) cin >> a[i] >> b[i];
	rep(i, 1, m + 1) cin >> e[i].se.fi >> e[i].se.se >> e[i].fi;
	ll sum = 0;
	rep(i, 1, n + 1) pre[i] = i, mi[i] = b[i], ma[i] = a[i], res[i] = 1ll * a[i] * b[i], sum += res[i];
	sort(e + 1, e + 1 + m);
	rep(i, 1, m + 1) if(find(e[i].se.fi) != find(e[i].se.se)) {
		int u = find(e[i].se.fi), v = find(e[i].se.se);
		ll c = 1ll * min(mi[v], mi[u]) * max(max(ma[u], ma[v]), e[i].fi);
		ll t = sum - res[u] - res[v] + c;
		pre[u] = v;
		mi[v] = min(mi[v], mi[u]);
		ma[v] = max(ma[v], ma[u]);
		res[v] = res[u] + res[v];
		if(sum >= t) {
			sum = t;
			ma[v] = max(ma[v], e[i].fi);
			res[v] = c;
		}
	}
	cout << sum << endl;
	return 0;
}
