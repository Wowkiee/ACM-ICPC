#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll<<(a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n, m, ans, ans2;
string s;
bool ok;

int main() {
	freopen("ascii.in","r",stdin);
	freopen("ascii.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 1, n+1) {
		cin >> s;
		ok = 0;
		rep(j, 0, m) {
			if (s[j] == '.') {
				if (ok) ans++;
			}else {
				ans2++;
				ok ^= 1;
			}
		}
	}
	cout << ans + ans2 / 2;
	return 0;
}
