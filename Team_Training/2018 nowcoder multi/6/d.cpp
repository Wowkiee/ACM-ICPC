#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 101010;

int n, m, k;
int ma[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	rep(ca, 1, T+1) {
		cin >> n >> m >> k;
		memset(ma, 0, sizeof(ma));
		rep(i, 1, k+1) {
			int u, v, w;
			cin >> u >> v >> w;
			ma[v] = max(ma[v], w);
		}
		ll ans = 0;
		rep(i, 1, m+1) ans += ma[i];
		cout << "Case #" << ca << ": " << ans << endl;
	}
	return 0;
}
