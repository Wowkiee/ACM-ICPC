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

const int N = 202020;

int n;
int pre[N], ty[N];
pair<int, pii> e[N];

int find(int x) {
	return x == pre[x] ? x : pre[x] = find(pre[x]);
}
void join(int x, int y) {
	x = find(x);
	y = find(y);
	pre[x] = y;
	ty[x] = max(ty[x], ty[y]);
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n) {
		int u, v, w;
		cin >> u >> v >> w;
		e[i] = mp(w, mp(u, v));
	}
	rep(i, 1, n + 1) pre[i] = i, ty[i] = -1;
	int k;
	cin >> k;
	rep(i, 0, k) {
		int x;
		cin >> x;
		ty[x] = 0;
	}
	cin >> k;
	rep(i, 0, k) {
		int x;
		cin >> x;
		ty[x] = 1;
	}
	sort(e + 1, e + n);
	reverse(e + 1, e + n);
	ll ans = 0;
	rep(i, 1, n) {
		int u = e[i].se.fi, v = e[i].se.se;
		u = find(u), v = find(v);
		if(ty[u] != -1 && ty[v] != -1 && ty[u] != ty[v]) {
			ans += e[i].fi;
		} else {
			join(u, v);
		}
	}
	cout << ans << endl;
	return 0;
}
