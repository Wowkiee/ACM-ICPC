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
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int ans = 0;
	rep(i, 0, 6)rep(j, 0, 6)rep(k, 0, 6)rep(l, 0, 6)rep(m, 0, 6){
		vi v;
		v.pb(i);v.pb(j);v.pb(k);v.pb(l);v.pb(m);
		sort(all(v));
		int fl = 1;
		rep(i, 2, 5)if(v[i] == v[i - 2] && v[i] != 0)fl = 0;
		ans += fl;
	}
	cout << ans << endl;
	return 0;
}
