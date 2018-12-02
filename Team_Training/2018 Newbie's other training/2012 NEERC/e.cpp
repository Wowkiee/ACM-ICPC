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
#define pw(a) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
//----
typedef pair<ll,int> pli;
typedef unsigned long long ull;
ull Pow10[20] = {1};
ll x;
int n;
vector<pli> V[20];
vector<int> ans;
int main() {
	freopen("exact.in", "r", stdin);
	freopen("exact.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	rep(i, 1, 20)Pow10[i] = Pow10[i - 1] * 10;
	cin >> x >> n;
	rep(i, 1, n + 1) {
		int k; ll q;
		cin >> k >> q;
		q *= Pow10[k];
		V[k].pb(mp(q, i));
	}
	ll now = 0;
	rep(i, 0, 19) {
		sort(all(V[i]));
		while(now < x % Pow10[i + 1]) {
			if(!sz(V[i])) {
				cout << -1 <<endl;
				return 0;
			}
			ans.pb(V[i].back().se);
			now += V[i].back().fi;
			V[i].pop_back();
		}
		while(sz(V[i]))V[i + 1].pb(V[i].back()), V[i].pop_back();
	}
	cout << sz(ans) << endl;
	rep(i, 0, sz(ans))cout << ans[i] << " \n"[i == sz(ans) - 1];
	return 0;
}
