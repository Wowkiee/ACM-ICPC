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

const int N = 1e6 + 7;
int T, a[N], p[N], n, val[N], sta[N], top;
vector<pii> v[2];

bool check(const vector<pii> &v) {
	top = 0;
	fill_n(val + 1, n, 0);
	rep(i, 0, sz(v)) {
		val[v[i].fi] = i + 1;
		val[v[i].se] = -i - 1;
	}
	rep(i, 1, n + 1) if(val[i]) {
		if(val[i] > 0) {
			sta[++top] = val[i];
		} else {
			if(top == 0 || sta[top] + val[i] != 0) return 1;
			--top;
		}
	}
	return 0;
}

bool solve() {
	if(check(v[0])) return 0;
	if(check(v[1])) return 0;
	rep(o, 0, 2) {
		rep(i, 0, sz(v[o])) {
			int l = n + 1 - v[o][i].se;
			int r = n + 1 - v[o][i].fi;
			v[o][i] = mp(l, r);
		}
	}
	if(check(v[0])) return 0;
	if(check(v[1])) return 0;
	return 1;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n;
		rep(i, 1, n+1) cin >> a[i], p[a[i]] = i;
		v[0].clear();
		v[1].clear();
		rep(i, 1, n) {
			if (p[i] < p[i+1])
				v[i&1].pb(mp(p[i], p[i+1]));
			else v[i&1].pb(mp(p[i+1], p[i]));
		}
		cout << (solve() ? "Yes" : "No") << endl;
	}
	return 0;
}
