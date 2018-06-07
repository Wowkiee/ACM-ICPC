#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define per(i,l,r) for(int i=(r)-1;i>=(l);i--)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----
const int N = 5e3 + 7;
int n, c[N];
string a, b;
vector<pii> tab;
bool ned[N];
ll gao(string a) {
	ll ret = 0, bas = 0;
	rep(i, 0, n) if (a[i] == '1') bas += c[i];
	rep(i, 0, sz(tab)) {
		int p = tab[i].se;
		if (ned[p] || (a[p] == '1' && b[p] == '0')) {
			a[p] = '0';
			bas -= c[p];
			ret += bas;
		}
	}
	per(i, 0, sz(tab)) {
		int p = tab[i].se;
		if (a[p] == '0' && b[p] == '1') {
			bas += c[p];
			ret += bas;
		}
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	rep(i, 0, n) cin >> c[i];
	cin >> a >> b;
	rep(i, 0, n) tab.pb(mp(c[i], i));
	sort(all(tab)); reverse(all(tab));
	ll ans = gao(a);
	rep(i, 0, sz(tab)) {
		int p = tab[i].se;
		if (a[p] == '1' && b[p] == '1') {
			ned[p] = true;
			ans = min(ans, gao(a));
		}
	}
	cout << ans;
	return 0;
}
