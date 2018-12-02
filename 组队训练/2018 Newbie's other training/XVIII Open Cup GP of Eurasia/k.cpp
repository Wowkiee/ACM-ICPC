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
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 111;

int n, m;
int g[N][N];
vi p;

int calc(const vi &p) {
	int cnt = 0;
	rep(i, 2, n + 1) {
		if(~g[1][i]) {
			cnt += (g[1][i] == 0);
		} else {
			rep(j, 0, sz(p)) {
				int u = p[j];
				if(~g[i][u]) {
					cnt += (g[1][u] == g[i][u]);
					break;
				}
			}
		}
	}
	return cnt;
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	memset(g, -1, sizeof(g));
	cin >> n >> m;
	rep(i, 1, m + 1) {
		int u, v, w;
		cin >> u >> v >> w;
		if(v == 1) swap(u, v);
		if(u == 1) p.pb(v);
		g[u][v] = g[v][u] = w;
	}
	if(sz(p) == 0) {
		cout << 0 << endl;
		cout << endl;
		return 0;
	}
	srand(time(0));
	random_shuffle(all(p));
	int now = calc(p);
	if(sz(p) > 1) rep(i, 0, 1000000) {
		vi tmp = p;
		int l = rand() % sz(p), r = rand() % sz(p);
		if(l > r) swap(l, r);
		random_shuffle(p.begin() + l, p.begin() + r + 1);
		int t = calc(p);
		if(t > now) {
			now = t;
		} else {
			p = tmp;
		}
	}
	cout << setiosflags(ios::fixed);
	cout << setprecision(10);
	cout << now * 1. / (n - 1) << endl;
	rep(i, 0, sz(p)) cout << p[i] << " \n"[i == sz(p) - 1];
	return 0;
}
