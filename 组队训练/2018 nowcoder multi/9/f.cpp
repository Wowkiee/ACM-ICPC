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

const int N = 101010;

int n;
string s[4], op;

struct Trie {
	static const int N = ::N, M = 26;
	int ne[N][M], fail[N], fa[N], rt, L, ed[4], dis[N], vis[N], pre[N];
	vi g[N], q;
	void init() {
		fill_n(ne[fail[0] = N-1], M, 0);
		memset(dis, 0x3f, sizeof(dis));
		L = 0;
		rt = newnode();
	}
	int newnode() {
		fill_n(ne[L], M, 0);
		return L++;
	}
	void add(string s) {
		int p = rt;
		for(auto i : s) {
			int c = i - 'a';
			if(!ne[p][c]) ne[p][c] = newnode(), fa[L-1] = p;
			p = ne[p][c];
		}
		dis[p] = 0;
		if(!vis[p]) {
			q.pb(p);
			vis[p] = 1;
		}
	}
	void Build() {
		vi v;v.pb(rt);
		rep(i, 0, sz(v)) {
			int c = v[i];
			rep(i, 0, M) ne[c][i] ? 
				v.pb(ne[c][i]), fail[ne[c][i]] = ne[fail[c]][i] :
				ne[c][i] = ne[fail[c]][i];
		}
	}
	void solve() {
		rep(u, 0, L) rep(c, 0, M) {
			int v = ne[u][c];
			g[v].pb(u);
		}
		rep(i, 0, sz(q)) {
			int u = q[i];
			for(auto v : g[u]) if(!vis[v]) {
				vis[v] = 1;
				dis[v] = dis[u] + 1;
				q.pb(v);
			}
		}
		int p = rt;
		cout << dis[p] << endl;
		rep(i, 0, sz(op)) {
			if(op[i] == '-') {
				if(p != rt) p = pre[p];
			} else {
				int k = ne[p][op[i]-'a'];
				pre[k] = p;
				p = k;
			}
			cout << dis[p] << endl;
		}
	}
}ac;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	ac.init();
	rep(i, 0, n) {
		cin >> s[i];
		ac.add(s[i]);
	}
	cin >> op;
	ac.Build();
	ac.solve();
	return 0;
}
