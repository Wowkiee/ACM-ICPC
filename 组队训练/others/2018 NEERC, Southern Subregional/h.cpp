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
char s[22];
map<string, int> vis, cnt;
map<string, string> ans;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(t, 1, n + 1) {
		cin >> s + 1;
		de(s + 1);
		int len = strlen(s + 1);
		rep(r, 1, len + 1) {
			auto c = s[r + 1];
			s[r + 1] = '\0';
			rep(l, 1, r + 1) {
				de(s + l);
				/*
				if(vis[s + l] != t) {
					dd(l), de(s + l);
					vis[s + l] = t;
					cnt[s + l]++;
					s[r + l] = c;
					ans[s + l] = s + 1;
					s[r + l] = '\0';
				}
				*/
			}
			cout << endl;
			s[r + 1] = c;
		}
	}
	cin >> m;
	rep(i, 1, m + 1) {
		cin >> s + 1;
		int t = cnt[s];
		cout << t << " ";
		if(t) cout << ans[s] << endl;
		else cout << "-" << endl;
	}
	return 0;
}
