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
#define endl "\n"
#define pw(a) (1ll << (a))
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;

const int N = 101010, p1 = 1e9 + 7, p2 = 1e9 + 9, se1 = 127, se2 = 167;

int n, m;
int ba1[N], ba2[N], ha1[N], ha2[N], len[22], ne[22][N], cnt[22][N];
bool ok[22][N];
ll ans;
pii ha[22];
char s[N], t[N], tmp[N];
vector<string> v;

int add(int a, int b, int P) {
	if((a += b) >= P) a -= P;
	return a;
}
int sub(int a, int b, int P) {
	if((a -= b) < 0) a += P;
	return a;
}
int mul(int a, int b, int P) {
	return 1ll * a * b % P;
}

void init() {
	ba1[0] = 1;
	rep(i, 1, N) ba1[i] = mul(ba1[i - 1], se1, p1);
	ba2[0] = 1;
	rep(i, 1, N) ba2[i] = mul(ba2[i - 1], se2, p2);
	ha1[0] = 0;
	rep(i, 1, n + 1) ha1[i] = add(mul(ha1[i - 1], se1, p1), s[i], p1);
	ha2[0] = 0;
	rep(i, 1, n + 1) ha2[i] = add(mul(ha2[i - 1], se2, p2), s[i], p2);
}
pii get(int l, int r) {
	int t1 = sub(ha1[r], mul(ha1[l - 1], ba1[r - l + 1], p1), p1);
	int t2 = sub(ha2[r], mul(ha2[l - 1], ba2[r - l + 1], p2), p2);
	return mp(t1, t2);
}
pii gao(string &s) {
	int t1 = 0;
	for(auto u : s) t1 = add(mul(t1, se1, p1), u, p1);
	int t2 = 0;
	for(auto u : s) t2 = add(mul(t2, se2, p2), u, p2);
	return mp(t1, t2);
}

bool check(int i, int j) {
	if(n - j + 1 < len[i]) return 0;
	pii t = get(j, j + len[i] - 1);
	return t == ha[i];
}

ll gao(int st) {
	rep(i, 1, sz(v)) {
		int t = ne[i][st];
		if(t == -1) return 0;
		if(i != sz(v) - 1) st = t + len[i];
		else st = t;
	}
	if(t[m - 1] == '*') {
		return n - (st + len[sz(v) - 1] - 1) + 1;
	} else {
		return cnt[sz(v) - 1][st];
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> (s + 1) >> t;
	n = strlen(s + 1), m = strlen(t);
	init();
	v.pb("1");
	rep(i, 0, m) tmp[i] = t[i];
	tmp[m] = '\0';
	for(char *p = strtok(tmp, "*"); p; p = strtok(NULL, "*")) v.pb(p);
	//for(auto u : v) de(u);
	rep(i, 1, sz(v)) ha[i] = gao(v[i]);
	rep(i, 0, sz(v)) len[i] = sz(v[i]);
	rep(i, 1, sz(v)) rep(j, 1, n + 1) ok[i][j] = check(i, j);
	rep(i, 1, sz(v)) {
		ne[i][n + 1] = -1;
		for(int j = n; j; --j) {
			ne[i][j] = ne[i][j + 1];
			if(ok[i][j]) ne[i][j] = j;
			cnt[i][j] = cnt[i][j + 1] + ok[i][j];
		}
	}
	if(t[0] == '*') rep(i, 1, n + 1) ans += gao(i);//, de(gao(i));
	else rep(i, 1, n + 1) if(ok[1][i]) {
		if(sz(v) > 2) ans += gao(i);
		else {
			if(t[m - 1] == '*') {
				ans += n - (i + len[1] - 1) + 1;
			} else {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
