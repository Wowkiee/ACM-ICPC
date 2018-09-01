#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---

const int N = 202;

int n, m;
int cnt[N][2];
char ans[N];
bool mod[N];
string s, t;
vector<pii> g[N][2];

bool gao(int p, int v) {
	ans[p] = v + 'a';
	if(cnt[p][s[v] != 'C']) return 0;
	bool ok = 1;
	for(auto u : g[p][s[v] == 'C']) {
		++cnt[u.fi][u.se];
		if(u.fi < p && u.se != (s[ans[u.fi] - 'a'] == 'C')) ok = 0;
		if(u.fi > p && cnt[u.fi][u.se ^ 1]) ok = 0;
	}
	mod[p] = 1;
	return ok;
}

bool dfs(int p, bool lim) {
	if(p >= n) return 1;
	int fr = lim ? t[p] - 'a' : 0;
	assert(fr >= 0);
	rep(i, fr, sz(s)) {
		if(gao(p, i) && dfs(p + 1, lim && i == fr)) return 1;
		if(mod[p]) {
			for(auto u : g[p][s[i] == 'C']) {
				--cnt[u.fi][u.se];
				assert(cnt[u.fi][u.se] >= 0);
			}
			mod[p] = 0;
		}
	}
	return 0;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> s >> n >> m;
	rep(i, 0, m) {
		int p1, p2;
		string t1, t2;
		cin >> p1 >> t1 >> p2 >> t2;
		g[p1 - 1][t1[0] == 'C'].pb(mp(p2 - 1, t2[0] == 'C'));
	}
	cin >> t;
	if(dfs(0, 1)) {
		rep(i, 0, n) cout << ans[i];
		cout << endl;
	} else {
		cout << "-1" << endl;
	}
	return 0;
}
