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

const int N = 111, inf = 1e9 + 7;

vector<pii> v;
int k, b, s;
int a[N], pre[N];

void gao() {
	cin >> k >> b >> s;
	rep(i, 1, k + 1) cin >> a[i], pre[i] = pre[i - 1] + a[i];
	rep(i, 0, k + 1) v.pb(mp(b + i * s, pre[i]));
	v.pb(mp(inf, pre[k]));
}

bool solve() {
	rep(i, 0, sz(v)) {
		if(i && v[i].se < v[i - 1].se) return 0;
		if(i && v[i].fi == v[i - 1].fi && v[i].se != v[i - 1].se) return 0;
	}
	return 1;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	gao();
	gao();
	sort(all(v));
	cout << (solve() ? "Yes" : "No") << endl;
	return 0;
}
