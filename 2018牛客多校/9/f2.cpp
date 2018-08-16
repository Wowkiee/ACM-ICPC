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
	static const int N = ::N, M = 2;
	int ne[N][M], fail[N], fa[N], rt, L, dis[N], vis[N], pre[N], ed[N], deg[N], sta[N], top;
	vi g[N], q;
	void init() {
		fill_n(ne[fail[0] = N-1], M, 0);
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
		ed[p] = 1;
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
		rep(i, 1, L) {
			int u = fail[i], v = i;
			g[u].pb(v);
			++deg[v];
		}
		rep(i, 0, L) if(deg[i] == 0) {
			q.pb(i);
		}
		rep(i, 0, sz(q)) {
			int u = q[i];
			for(auto v : g[u]) {
				--deg[v];
				ed[v] |= ed[u];
				if(deg[v] == 0) q.pb(v);
			}
		}
		q.clear();
		rep(i, 0, L) g[i].clear();
		memset(dis, 0x3f, sizeof(dis));
		rep(i, 0, L) if(ed[i]) {
			dis[i] = 0;
			vis[i] = 1;
			q.pb(i);
		}
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
		top = 0;
		cout << dis[p] << endl;
		rep(i, 0, sz(op)) {
			if(op[i] == '-') {
				if(top) p = sta[top--];
			} else {
				sta[++top] = p;
				p = ne[p][op[i]-'a'];
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
