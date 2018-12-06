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
#define pw(a) (1ll << (a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e6 + 1;

int n;
int val[N], pre[N];
vi p;
bool isp[N];
vi v[N];

const int mad = 20;
void init() {
	rep(i, 2, N) isp[i] = 1;
	rep(i, 2, N) {
		if(isp[i]) p.pb(i);
		for(int j = 0; j < sz(p) && i * p[j] < N; ++j) {
			isp[i * p[j]] = 0;
			if(i % p[j] == 0) break;
		}
	}
}

void gao(int x) {
	int t = x;
	for(auto u : p) {
		if(u * 1ll * u > x) break;
		int cnt = 0;
		while(x % u == 0) {
			x /= u;
			++cnt;
		}
		if(cnt & 1) v[u].pb(t);
	}
	if(isp[x] && x != t) v[x].pb(t);
}
void dfs(int pos) {
	if(pos > n) {
		int pp = 0;
		rep(i, 1, n + 1) pp += val[i], assert(abs(pp) <= mad);
		rep(i, 1, n + 1) {
			for(int j = 2; j * j <= i; ++j) if(i % j == 0) assert(val[i] = val[j] * val[i / j]);
		}
		for(auto u : p) {
			if(u > n) break;
			cout << val[u] << ",";
		}
		cout << endl;
		de(1);
		exit(0);
	}

	if(rand() & 1) {
		pre[pos] = pre[pos - 1] + val[pos];
		if(abs(pre[pos]) <= mad) dfs(pos + 1);

		if(isp[pos]) {
			val[pos] = -1;
			for(auto u : v[pos]) val[u] *= -1;
			pre[pos] = pre[pos - 1] + val[pos];
			if(abs(pre[pos]) <= mad) dfs(pos + 1);
		}
	} else {
		if(isp[pos]) {
			val[pos] = -1;
			for(auto u : v[pos]) val[u] *= -1;
			pre[pos] = pre[pos - 1] + val[pos];
			if(abs(pre[pos]) <= mad) dfs(pos + 1);
			val[pos] = 1;
			for(auto u : v[pos]) val[u] *= -1;
			pre[pos] = pre[pos - 1] + val[pos];
			if(abs(pre[pos]) <= mad) dfs(pos + 1);
		} else {
			pre[pos] = pre[pos - 1] + val[pos];
			if(abs(pre[pos]) <= mad) dfs(pos + 1);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	srand(time(0));
	n = 1000000;
	init();
	rep(i, 1, n + 1) gao(i), val[i] = 1;
	dfs(1);
	return 0;
}
