#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll<<(a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
//----
const int N = 10005, M = 45;
char s[N][M];
unordered_set<string> S[M];
int flag[M];
int n;
struct Trie {
	static const int N = 410000, M = 26;
	int ne[N][M], fail[N], fa[N], rt, L, ac[N];
	void ini() { fill_n(ne[fail[0] = N - 1], M, 0); L = 0; rt = newnode(); }
	int newnode() { fill_n(ne[L], M, 0); return L++; }
	void add(char *s) {
		int p = rt;
		for(int i = 0; s[i]; i++) {
			int c = s[i] - 'a';
			if(!ne[p][c]) ne[p][c] = newnode(), fa[L - 1] = p;
			p = ne[p][c];
		}
		ac[p] = 1;
	}
	ll solve(int now) {
		ll ans = ac[now];
		rep(i, 0, 26) {
			if(ne[now][i]) {
				ac[ne[now][i]] |= flag[i];
				ans += solve(ne[now][i]);
			}
			else ans += sz(::S[i]);
		}
		return ans;
	}
	ll gao() {
		ll ans = 0;
		rep(i, 0, 26)if(ne[rt][i])ans += solve(ne[rt][i]);
		return ans;
	}
}tree;
int main() {
	freopen("dictionary.in","r",stdin);
	freopen("dictionary.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n; tree.ini();
	rep(i, 0, n)cin >> s[i], tree.add(s[i]);
	rep(i, 0, n) {
		int l = strlen(s[i]);
		flag[s[i][l - 1] - 'a'] = 1;
		for(int j = 0; s[i][j]; j++) {
			string a = s[i] + j;
			S[s[i][j] - 'a'].insert(a);
		}
	}
	cout << tree.gao() << endl;
	return 0;
}
