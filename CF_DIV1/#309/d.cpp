#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef double db;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 101010;

int n, m, k;
int cnt[N];
bool ok[N], in[N], inq[N];
vi g[N];

bool check(db x) {
	rep(i, 1, n+1) if(ok[i]) in[i] = 1;
	memset(cnt, 0, sizeof(cnt));
	rep(i, 1, n+1) if(in[i]) {
		for(auto v : g[i]) cnt[i] += in[v];
	}
	memset(inq, 0, sizeof(inq));
	vi q;
	rep(i, 1, n+1) if(in[i] && cnt[i] * 1. / sz(g[i]) < x) {
		q.pb(i);
		inq[i] = 1;
	}
	rep(i, 0, sz(q)) {
		int u = q[i];
		in[u] = inq[u] = 0;
		for(auto v : g[u]) if(in[v]) {
			--cnt[v];
			if(!inq[v] && cnt[v] * 1. / sz(g[v]) < x) {
				q.pb(v);
				inq[v] = 1;
			}
		}
	}
	rep(i, 1, n+1) if(in[i]) return 1;
	return 0;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> m >> k;
	fill_n(ok+1, n, 1);
	rep(i, 1, k+1) {
		int x;
		cin >> x;
		ok[x] = 0;
	}
	rep(i, 1, m+1) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	db l = 0, r = 1, ans = 0;
	int _ = 200;
	while(_--) {
		db mid = (l + r) / 2;
		if(check(mid)) {
			ans = mid;
			l = mid;
		} else {
			r = mid;
		}
	}
	check(ans);
	vi v;
	rep(i, 1, n+1) if(in[i]) v.pb(i);
	cout << sz(v) << endl;
	rep(i, 0, sz(v)) cout << v[i] << " ";
	cout << endl;
	return 0;
}
