#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
//----
const int N = 50;
int T, n, m;
char s[N];
struct Trie {
	static const int N = 2000, M = 2;
	int ne[N][M], fail[N], fa[N], rt, L, ac[N];
	ll dp[::N][N][2];
	void ini() { fill_n(ne[fail[0] = N - 1], M, 0); L = 0; rt = newnode(); memset(ac, 0, sizeof(ac));}
	int newnode(){fill_n(ne[L], M, 0); return L++;}
	void add(char *s) {
		int p = rt;
		for(int i = 0; s[i]; i++) {
			int c = s[i] - '0';
			if(!ne[p][c])ne[p][c] = newnode(), fa[L - 1] = p;
			p = ne[p][c];
		}
		ac[p] = 1;
	}
	void Build() {
		vi v; v.pb(rt);
		rep(i, 0, sz(v)) {
			int c = v[i];
			rep(i, 0, M)ne[c][i] ?
			v.pb(ne[c][i]), fail[ne[c][i]] = ne[fail[c]][i] :
			ne[c][i] = ne[fail[c]][i];
		}
	}
	ll gao() {
		rep(i, 0, ::m + 1)rep(j, 0, L)rep(k, 0, 2)dp[i][j][k] = 0;
		dp[0][rt][0] = 1;
		rep(i, 1, ::m + 1)rep(j, 0, L) {
			rep(k, 0, 2) {
				dp[i][ne[j][k]][ac[ne[j][k]]] += dp[i - 1][j][0];
				dp[i][ne[j][k]][1] += dp[i - 1][j][1];
			}
		}
		ll ans = 0;
		rep(j, 0, L)ans += dp[::m][j][1];
		return ans;
	}
}trie;
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> T; while(T--) {
		trie.ini();
		cin >> n >> m >> s;
		trie.add(s);
		rep(i, 0, n) {
			s[i] ^= 1;
			trie.add(s);
			s[i] ^= 1;
		}
		trie.Build();
		cout << trie.gao() << endl;
	}
	return 0;
}
