#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(x) (int)x.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll<<(a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll n;
int T;
vector<ll> ans;

vector<ll> solve(ll n) {
	vector<ll> res;
	if (n <= 3) {
		if (n > 0) res.pb(n);
		return res;
	}
	ll x = 1;
	if (n % 2 == 0) {
		res = solve(n / 2);
		rep(i, 0, sz(res)) res[i] <<= 1;
	}else{
		rep(i, 1, 70) if (x * 3 <= n) x *= 3;else break;
		res = solve((n - x) / 2);
		rep(i, 0, sz(res)) res[i] <<= 1;
		res.pb(x);
	}
	return res;
} 
int main() {
	freopen("distribution.in","r",stdin);
	freopen("distribution.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n;
		ans = solve(n);
		cout << sz(ans) << endl;
		rep(i, 0, sz(ans)) cout << ans[i] << (i == sz(ans) - 1 ? "\n" : " ");
	}
	return 0; 
}
