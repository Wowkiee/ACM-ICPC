#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(c) cout << #c << " = " << c << endl
#define dd(c) cout << #c << " = " << c << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 111;

int n, m;
int a[N], b[N], h[N], ind[N];
bool vis[N];
vi res;

bool go(int u, int t) {
	int c = h[u];
	if(u <= t) {
		rep(i, u, t + 1) {
			c += b[i];
			if(c < 0) return 0;
		}
	} else {
		for(int i = u; i >= t; --i) {
			c += b[i];
			if(c < 0) return 0;
		}
	}
	return 1;
}

bool check(int t, int o) {
	rep(i, 1, n + 1) b[i] = a[i];
	vi v;
	if(o == 0) {
		for(int i = t; i; --i) if(h[i]) v.pb(i);
		rep(i, t + 1, n + 1) if(h[i]) v.pb(i);
	} else {
		rep(i, t, n + 1) if(h[i]) v.pb(i);
		for(int i = t - 1; i; --i) if(h[i]) v.pb(i);
	}
	for(auto u : v) if(go(u, t)) {
		rep(i, u, t + 1) b[i] = 0;
		rep(i, t, u + 1) b[i] = 0;
		res.pb(ind[u]);
	}
	rep(i, 1, t + 1) if(h[i]) {
		if(!go(i, t)) return 0;
		break;
	}
	for(int i = n; i >= t; --i) if(h[i]) {
		if(!go(i, t)) return 0;
		break;
	}
	return 1;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 1, m + 1) {
		int x, y;
		cin >> x >> y;
		h[x] = y;
		ind[x] = i;
	}
	rep(i, 1, n + 1) cin >> a[i];
	rep(t, 1, n + 1) rep(j, 0, 2) {
		res.clear();
		if(check(t, j)) {
			cout << t << endl;
			for(auto u : res) cout << u << " ", vis[u] = 1;
			rep(i, 1, m + 1) if(!vis[i]) cout << i << " ";
			cout << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}
