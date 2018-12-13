#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(x) cout << #x << " = " << x << endl 
#define dd(x) cout << #x << " = " << x << " "
#define endl "\n"
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e7 +7;
string s[N], t[N];
#define ls (x << 1)
#define rs (x << 1 | 1)
int ans[200], n, seed, b[N], len;
char a[N];

inline void add(const string &s) {
	rep(i, 0, sz(s)) ans[sz(s) - i - 1] += s[i];//, cout << (int) s[i];
	//cout << endl;
}

#define Max max
/*string Max(const string & a, const string & b) {
	int len = min(sz(a), sz(b));
	if (sz(a) > sz(b)) return a;
	if (sz(a) < sz(b)) return b;
	rep(i, 0, len) if (a[i] != b[i]) {
		if (a[i] > b[i]) return a;
		else return b;
	}
	return a;	
}*/

void dfs(int x) {
	if (ls <= n) dfs(x << 1);
	if (rs <= n) dfs((x << 1 | 1));
	if (ls > n) return;
	if ((ls << 1) > n && rs <= n) {
		s[x] = t[x] = max(a[ls], a[rs]);
		string tt;
		tt += a[ls];tt += a[rs];
		string t2;
		t2 += a[rs];t2 += a[ls];
		add(max(tt, t2));
	}
	else {
		if (sz(s[ls]) < sz(s[rs])) s[x] = a[rs] + s[rs];
		else if (sz(s[ls]) > sz(s[rs])) s[x] = a[ls] + s[ls];
		else s[x] = Max(a[ls] + s[ls], a[rs] +  s[rs]);
	
		if (sz(t[ls]) < sz(t[rs])) t[x] = t[rs] + a[rs];
		else if (sz(t[ls]) > sz(t[rs])) t[x] = t[ls] + a[ls];
		else t[x] = Max(t[ls] + a[ls],t[rs] + a[rs]);
	
	//assert(sz(t[rs]) + sz(s[ls]) == sz(t[ls]) + sz(s[rs]))
		string tt = t[rs];
		if(rs <= n) tt += a[rs];
		tt += a[ls] + s[ls];
		string t2 = t[ls] + a[ls];
		if(rs <= n) t2 += a[rs];
		t2 += s[rs];
		add(Max(tt, t2));
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> seed;
	b[1] = seed;
	rep(i, 2, n+1) b[i] = (1ll * b[i-1] * 1103515245 + 12345) & (pw(31)-1);
	rep(i, 1, n+1) a[i] = (b[i] >> 16) % 9 + 1;
	//rep(i, 1, n+1) de((int)a[i]);
	dfs(1);
	rep(i, 0, 100) {
		ans[i+1] += ans[i] / 10;
		ans[i] %= 10;
	}
	len = 100;
	while (len >= 0 && ans[len] == 0) len--;
	if (len < 0) cout << 0;
	else per(i, 0, len+1) cout << ans[i];
	return 0;
}
