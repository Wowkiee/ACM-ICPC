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
#define pw(a) (1ll << (a));
#define endl "\n"
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
//----
const int N = 1e6 + 7;
int sg[N];
vector<pii> g[N];
vi res;
inline int op(int x,int y) {
	if(y == 0) return 0;
	if(y == 1) return x + 1;
	if(y & 1) return x ^ 1;
	return x;
}
inline int rop(int x,int y) {
	if(y == 1) return x - 1;
	if(y & 1) return x ^ 1;
	return x;
}

void dfs1(int c) {
	sg[c] = 0;
	for(auto t : g[c]) {
		dfs1(t.fi);
		sg[c] ^= op(sg[t.fi] , t.se);
	}
}

void dfs2(int c,int val) {
	if(val < 0) return;
	for(auto t : g[c]) {
		if((sg[c] ^ op(sg[t.fi] , t.se) ^ op(sg[t.fi] , t.se - 1)) == val)
			res.pb(t.fi);
		dfs2(t.fi , rop(val ^ sg[c] ^ op(sg[t.fi] , t.se) , t.se));
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T; cin >> T; while(T--) {
		int n; cin >> n;
		rep(i, 1, n + 1) g[i].clear(); res.clear();
		rep(i, 2, n + 1) {
			int a, b; cin >> a >> b;
			g[a].pb(mp(i , b)); 
		}
		dfs1(1);
		dfs2(1, 0);
		sort(all(res));
		cout << sz(res) << endl;
		rep(i, 0, sz(res))cout << res[i] << " \n"[i == sz(res) - 1];
		if(!sz(res))cout << endl;
	}
	return 0;
}
