#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double db;

const int N = 101010;

int n[3];
pii p[3][N];
vi V;
vector<pair<int, pair<db, bool> > > v;

void gao(int n, const pii p[]) {
	int j = 0;
	for(int i = 0; i + 1 < n && j < sz(V); ++i) {
		while(j < sz(V) && V[j] <= p[i + 1].se) {
			db a = p[i].fi + (p[i + 1].fi - p[i].fi) * 1.0 * (V[j] - p[i].se) / (p[i + 1].se - p[i].se);
			v.pb(mp(V[j], mp(a, 1)));
			++j;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	rep(o, 0, 2) {
		cin >> n[o];
		rep(i, 0, n[o]) {
			cin >> p[o][i].fi >> p[o][i].se;
			v.pb(mp(p[o][i].se, mp(p[o][i].fi, 0)));
			V.pb(p[o][i].se);
		}
	}
	int o = 2;
	cin >> n[o];
	rep(i, 0, n[o]) {
		cin >> p[o][i].fi >> p[o][i].se;
		if(p[0][0].se <= p[o][i].se && p[o][i].se <= p[0][n[0] - 1].se) {
			v.pb(mp(p[o][i].se, mp(p[o][i].fi, 0)));
			V.pb(p[o][i].se);
		}
	}
	sort(all(V));
	V.erase(unique(all(V)), V.end());
	rep(o, 0, 2) gao(n[o], p[o]);
	sort(all(v));
	db mi = 1e18;
	for(int i = 0, j = 0; i < sz(v); i = j) {
		j = i;
		while(j < sz(v) && v[j].fi == v[i].fi) ++j;
		while(v[i].se.se == 0) ++i;
		db ma = 0;
		rep(t, i + 1, j) {
			ma = max(ma, v[t].se.fi - v[t - 1].se.fi);
			if(v[t].se.se) break;
		}
		mi = min(mi, ma);
	}
	cout << setiosflags(ios::fixed);
	cout << setprecision(8);
	cout << mi << endl;
	return 0;
}
