#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define per(i,l,r) for(int i=(r)-1;i>=(l);i--)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----
const int N = 1e5 + 7;
int n, a[N], pre[N];
vector<pii> g[N];
queue<int> que;
int b[N];
bool in[N];
void gao() {
	while (!que.empty()) {
		int u = que.front(); que.pop();
		for (auto e : g[u]) {
			if (b[e.fi] < b[u] + e.se) {
				b[e.fi] = b[u] + e.se;
				if (!in[e.fi]) {
					in[e.fi] = true;
					que.push(e.fi);
				}
			}
		}
		in[u] = false;
	}
}
bool use[N];
int main() {
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	cin >> n;
	rep(i, 0, n) cin >> a[i];
	fill_n(pre, N, -1);
	per(i, 0, n) {
		if (~pre[a[i] - 1]) g[i].pb({pre[a[i] - 1], 1});
		if (~pre[a[i] + 1]) g[pre[a[i] + 1]].pb({i, 1});
		if (~pre[a[i]]) g[pre[a[i]]].pb({i, 1});
		pre[a[i]] = i;
	}
	rep(i, 0, n) b[i] = 1;
	rep(i, 0, n) que.push(i), in[i] = true;
	gao();
	rep(i, 0, n) {
		while (use[b[i]]) b[i]++;
		use[b[i]] = true;
		que.push(i); in[i] = true; gao();
//		de("++++"); rep(i, 0, n) de(b[i]);
	}
	rep(i, 0, n) cout << b[i] << " \n"[i == n - 1];
	return 0;
}
