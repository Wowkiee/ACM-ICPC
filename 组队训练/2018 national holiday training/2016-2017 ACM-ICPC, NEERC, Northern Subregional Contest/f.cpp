#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(x) cout << #x << " = " << x << " "
#define de(x) cout << #x << " = " << x << endl
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9 + 7;

int solve(int n, int m, int x, int y) {
	if(n < x || m < y) return inf;
	int ans = 0;
	while(n > x) {
		if((n + 1) / 2 >= x) n = (n + 1) / 2;
		else n = x;
		++ans;
	}
	while(m > y) {
		if((m + 1) / 2 >= y) m = (m + 1) / 2;
		else m = y;
		++ans;
	}
	return ans;
}

int main() {
	freopen("folding.in","r",stdin);
	freopen("folding.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	int ans = min(solve(n, m, x, y), solve(m, n, x, y));
	if(ans == inf) ans = -1;
	cout << ans << endl;
	return 0;
}
