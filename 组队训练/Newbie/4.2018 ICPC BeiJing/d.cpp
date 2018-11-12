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
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 444;

ll m;
int p, st, ed;
int dig[N];
vector<pii> ans;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	while(cin >> m) {
		if(m == 0) {
			cout << 2 << endl;
			cout << 1 << " " << 1 << endl;
			cout << 2 << " " << 1 << endl;
			continue;
		}
		ans.clear();
		p = 0;
		while(m) {
			dig[p++] = m % 2;
			m >>= 1;
		}
		st = ed = 200;
		for(int i = p - 2; ~i; --i) {
			ans.pb(mp(ed + 1, ed + 3));
			ans.pb(mp(ed + 2, ed + 3));
			ed += 3;
			if(dig[i]) {
				ans.pb(mp(st - 1, ed));
				st -= 2;
			}
		}
		rep(i, 0, sz(ans)) {
			int u = ans[i].fi, v = ans[i].se;
			u = u - st + 3;
			v = v - st + 3;
			ans[i] = mp(u, v);
		}
		ed = ed - st + 3;
		st = st - st + 3;
		ans.pb(mp(1, st));
		ans.pb(mp(2, 2));
		ans.pb(mp(ed, 199));
		cout << sz(ans) << endl;
		for(auto u : ans) cout << u.fi << " " << u.se << endl;
	}
	return 0;
}
