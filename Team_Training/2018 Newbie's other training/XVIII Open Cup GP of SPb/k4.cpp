#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(a) cout << #a << " = " << a << " "
#define de(a) cout << #a << " = " << a << endl
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double db;

const int N = 202020, se1 = 126, se2 = 131, p1 = 1e9 + 7, p2 = 1e9 + 9;

int n, m, L;
int deg[N], ba1[N], ba2[N], dis[N], ne[N], ind[N];
vi g[N];
string s[N], str[N], tmps[N];
pii id[N], tmpi[N];

pii Hash(const vi &v) {
	int t = 0;
	rep(i, 0, 26) {
		t = t * 1ll * se1 % p1;
		if((t += v[i]) >= p1) t -= p1;
	}
	int o = 0;
	rep(i, 0, 26) {
		o = o * 1ll * se2 % p2;
		if((o += v[i]) >= p2) t -= p2;
	}
	return mp(t, o);
}

//xiao -> da
void add(int u, int v) {
	g[u].pb(v);
	++deg[v];
}

int Find(const pii &t) {
	int p = lower_bound(id + 1, id + 1 + L, t) - id;
	if(1 <= p && p <= L && id[p] == t) return p;
	return 0;
}

int get(const pii &p, int i, int c) {
	int t = p.fi, o = p.se;
	t += c * ba1[25 - i];
	o += c * ba2[25 - i];
	if(t >= p1) t -= p1;
	if(t < 0) t += p1;
	if(o >= p2) o -= p2;
	if(o < 0) o += p2;
	return Find(mp(t, o));
}

void add(const pii &t, const string &s) {
	++L;
	tmpi[L] = t;
	tmps[L] = s;
}

void ins() {
	string s;
	cin >> s;
	vi v(26);
	rep(i, 0, sz(s)) v[s[i] - 'a']++;
	pii t = Hash(v);
	add(t, s);
}

bool cmp(int i, int j) {
	return tmpi[i] < tmpi[j];
}

int main() {
	freopen("word-chains.in", "r", stdin);
	freopen("word-chains.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	///init
	ba1[0] = ba2[0] = 1;
	rep(i, 1, N) {
		ba1[i] = ba1[i - 1] * 1ll * se1 % p1;
		ba2[i] = ba2[i - 1] * 1ll * se2 % p2;
	}
	///read
	cin >> n;
	rep(i, 1, n + 1) cin >> s[i];
	add(mp(0, 0), ".");
	cin >> m;
	rep(i, 1, m + 1) ins();
	///get m
	rep(i, 1, L + 1) ind[i] = i;
	sort(ind + 1, ind + 1 + L, cmp);
	rep(i, 1, L + 1) {
		id[i] = tmpi[ind[i]];
		str[i] = tmps[ind[i]];
	}
	rep(i, 1, L + 1) if(i == 1 || id[i] != id[i - 1]) {
		rep(j, 0, 26) {
			int c = get(id[i], j, 1);
			if(c) add(i, c);
		}
	}
	///solve
	vi q;
	rep(i, 1, L + 1) if(deg[i] == 0) q.pb(i), dis[i] = 1;
	rep(i, 0, sz(q)) {
		int u = q[i];
		rep(t, 0, sz(g[u])) {
			int v = g[u][t];
			--deg[v];
			if(deg[v] == 0) {
				dis[v] = dis[u] + 1;
				ne[v] = u;
				q.pb(v);
			}
		}
	}
	rep(i, 1, n + 1) {
		vi v(26);
		rep(j, 0, sz(s[i])) v[s[i][j] - 'a']++;
		int u = Find(Hash(v));
		cout << dis[u] << endl;
		cout << s[i];
		u = ne[u];
		while(u) {
			cout << " -> " << str[u];
			u = ne[u];
		}
		cout << endl;
	}
	return 0;
}
