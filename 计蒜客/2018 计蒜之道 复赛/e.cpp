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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 5050;
const ll inf = 1e18;

int n, m;
vector<pair<int, pii> > g[N];
bool inq[N];
int cnt[N];
ll ma[N], mi[N];

void spfa() {
	fill_n(inq+1, n, 0);
	fill_n(cnt+1, n, 0);
	queue<int> q; q.push(1);
	cnt[1] = inq[1] = 1;
	ma[1] = mi[1] = 0;
	while(!q.empty()) {
		int u = q.front();q.pop();
		inq[u] = 0;
		for(auto i : g[u]) {
			int v = i.fi, a = i.se.fi, b = i.se.se;
			ll tma = (ma[u]==inf && a) ? ma[u] * a : ma[u] * a + b;
			ll tmi = (mi[u]==-inf && a) ? mi[u] * a : mi[u] * a + b;
			if(tma < tmi) swap(tma, tmi);
			if(cnt[v] <= 2*n && (cnt[v] == 0 || tma > ma[v] || tmi < mi[v])) {
				if(cnt[v]) {
					if(cnt[v] == 2*n) {
						ma[v] = (tma > ma[v]) ? inf : ma[v];
						mi[v] = (tmi < mi[v]) ? -inf : mi[v];
					} else {
						ma[v] = max(ma[v], tma);
						mi[v] = min(mi[v], tmi);
					}
				} else {
					ma[v] = tma;
					mi[v] = tmi;
				}
				++cnt[v];
				if(!inq[v]) {
					inq[v] = 1;
					q.push(v);
				}
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		rep(i, 1, n+1) g[i].clear();
		rep(i, 0, m) {
			int u, v, a, b;
			cin >> u >> v >> a >> b;
			g[u].pb(mp(v, mp(a, b)));
		}
		spfa();
		if(!cnt[n]) cout << "No solution" << endl;
		else if(ma[n]==inf) cout << "Infinity" << endl;
		else cout << ma[n] << endl;
	}
	return 0;
}
