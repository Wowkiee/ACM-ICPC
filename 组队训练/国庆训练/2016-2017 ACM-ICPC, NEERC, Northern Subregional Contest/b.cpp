#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(x) cout << #x << " = " << x << " "
#define de(x) cout << #x << " = " << x << endl
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 101010;

int n, x, y;
int res[N], g[2][2];
vi v;

void dfs(int c) {
	rep(t, 0, 2) {
		while(g[c][t]) {
			--g[c][t];
			if(c != t) --g[t][c];
			dfs(t);
			v.pb(c);
		}
	}
}

void get(int a, int b, int c) {
	memset(g, 0, sizeof(g));
	g[0][0] = a, g[1][1] = c, g[0][1] = g[1][0] = b;
	v.clear();
	dfs((a + b) == 0);
}

bool solve() {
	cin >> n >> x >> y;
	int a = n - y, c = n - x, b = n - a - c;
	if(b < 0 || b % 2 == 1) return 0;
	if(n & 1) {
		if(b == 0 && a && c) return 0;
		get(a, b, c);
		for(int i = 0, j = 0; i < sz(v); ++i, j = (j + 2) % n) res[j] = v[i];
		return 1;
	} else {
		if(b == 0) {
			if(a == n / 2 && c == n / 2) {
				rep(i, 0, n) res[i] = (i & 1);
				return 1;
			} else if(a == n || c == n) {
				rep(i, 0, n) res[i] = (c == n);
				return 1;
			} else return 0;
		} else if(b == 2) {
			if(a < n / 2 && c < n / 2) return 0;
			else {
				if(a >= n / 2) {
					a -= n / 2;
					for(int i = 0; i < n; i += 2) res[i] = 0;
				} else {
					c -= n / 2;
					for(int i = 0; i < n; i += 2) res[i] = 1;
				}
				get(a, b, c);
				for(int i = 1; i < n; i += 2) res[i] = v[i / 2];
				return 1;
			}
		} else {
			int t = n / 2;
			if(t & 1) --t;
			t = min(t, b - 2);
			if(b - t > n / 2) return 0;
			int ta = min(a, n / 2 - t);
			int tc = min(c, n / 2 - t - ta);
			get(ta, t, tc);
			for(int i = 0; i < n; i += 2) res[i] = v[i / 2];
			get(a - ta, b - t, c - tc);
			for(int i = 1; i < n; i += 2) res[i] = v[i / 2];
			return 1;
		}
	}
}

int main() {
	freopen("boysgirls.in","r",stdin);
	freopen("boysgirls.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	if(solve()) {
		rep(i, 0, n) cout << (res[i] ? 'G' : 'B');
		cout << endl;
	} else {
		cout << "Impossible" << endl;
	}
	return 0;
}
