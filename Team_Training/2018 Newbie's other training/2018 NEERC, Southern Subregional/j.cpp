#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(c) cout << #c << " = " << c << endl
#define dd(c) cout << #c << " = " << c << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = pw(30);
const int N = 3e4 + 7;

int T, n, m, kk, cnt[30], ans, mi;
bool f[N];
string s;

int solve(int n, int m, int x) {
	if (x < n + m) return inf;
	return n * m;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n >> m >> kk >> s;
		rep(i, 0, 26) cnt[i] = 0;
		rep(i, 0, sz(s)) cnt[s[i] - 'A']++;
		ans = inf;
		rep(i, 0, 26) {
			//de(cnt[i]);
			memset(f, 0, sizeof(f));
			f[0] = 1;mi = inf;
			rep(j, 0, 26) if (j != i){
				rep(k, max(0, n - cnt[j]), n+1) if (f[k]){
					mi = min(mi, k + cnt[j]);
					break;
				}
				per(k, 1, n+1) if (k - cnt[j] >= 0 && f[k - cnt[j]]) f[k] = 1;
			}
			//rep(i, 0, n+1) dd(f[i]);
			rep(k, 0, n+1) if (f[k]) ans = min(ans, solve(n - k, max(0, m - (kk - cnt[i] - k)), cnt[i]));
			if (mi != inf) ans = min(ans, solve(0, max(0, m - (kk - cnt[i] - mi)), cnt[i])); 
		}
		cout << ans << endl;
	}
	return 0;
}
