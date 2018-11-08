#include<bits/stdc++.h>
using namespace std;
#define fi fitst
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll<<(a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
//----
const int N = 20;
int n, m;
vi v[N];
int main() {
	freopen("easy.in", "r", stdin);
	freopen("easy.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 0, n) {
		int s;
		cin >> s;
		while(s--) {
			int a;
			cin >> a;
			v[i].pb(a);
		}
	}
	int ans = 0;
	for(int i = 0;;i++) {
		for(int j = 0; j < n;j++) {
			if(i < sz(v[j])) {
				if(ans <= v[j][i]) {
					ans += v[j][i];
					m--;
					if(m == 0) {
						cout << ans << endl;
						return 0;
					}
				}
			}
			else {
				ans += 50;
				m--;
				if(m == 0) {
					cout << ans << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
