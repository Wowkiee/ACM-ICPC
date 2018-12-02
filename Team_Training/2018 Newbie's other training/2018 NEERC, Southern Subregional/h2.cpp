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

int n, m;
string s;
map<string, int> vis, cnt;
map<string, string> ans;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(t, 1, n + 1) {
		cin >> s;
		rep(i, 0, sz(s)) {
			rep(len, 1, sz(s) + 1 - i) {
				auto str = s.substr(i, len);
				if(vis[str] != t) {
					vis[str] = t;
					cnt[str]++;
					ans[str] = s;
				}
			}
		}
	}
	cin >> m;
	rep(i, 1, m + 1) {
		cin >> s;
		int t = cnt[s];
		cout << t << " ";
		if(t) cout << ans[s] << endl;
		else cout << "-" << endl;
	}
	return 0;
}
