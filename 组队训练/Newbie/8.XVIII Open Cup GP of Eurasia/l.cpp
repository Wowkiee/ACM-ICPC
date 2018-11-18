
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(a) cout << #a << " = " << a << " "
#define de(a) cout << #a << " = " << a << endl
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 3e5 + 7;
int x, n, ok, p;
string s, a[N];
vi tmp;
vector<string> ans;

string t[] = {"0", "110", "1110", "11110", "111110", "1111110","10"};

bool check(string a, string b) {
	rep(i, 0, sz(b)) if (a[i] != b[i]) return 0;
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	while (cin >> s) {
		++n;
		rep(i, 0, 2) {
			if (s[i] <= '9') x = s[i] - '0';else x = s[i] - 'A' + 10;
			per(j, 0, 4) if (pw(j) & x) a[n] += '1';else a[n] += '0';
		}
	}
	rep(i, 1, n+1) {
		ok = 0;
		rep(j, 0, 6) {
			if (check(a[i], t[j])) {
				p = j;
				ok = 1;
				break;
			}
		}
		//de(p);
		if (ok) rep(j, i+1, i+p+1) ok &= check(a[j], t[6]);
		if (!ok) {
			if (sz(ans) >= 3) {
				rep(i, 0, sz(ans)) {
					cout << ans[i];
					if (i == sz(ans) - 1) cout << endl;else cout << " ";
				}
			}
			ans.clear();
		}else {
			tmp.clear();
			rep(j, p+1, 8) tmp.pb(a[i][j] - '0');
			rep(j, i+1, i+p+1) {
				rep(k, 2, 8) tmp.pb(a[j][k] - '0');
			}
			reverse(all(tmp));
			while (sz(tmp) % 4 != 0) tmp.pb(0);
			vector<int> an;
			for (int j = 0; j < sz(tmp); j += 4) {
				x = 0;
				rep(k, 0, 4) x += pw(k) * tmp[j + k];
				if (x <= 9) an.pb(x + '0'); else an.pb(x - 10 + 'A');
			}
			while (sz(an) > 1 && an[sz(an)-1] == '0') an.pop_back();
			string tt;
			rep(j, 0, sz(an)) tt += an[j];
			reverse(all(tt));
			ans.pb(tt);
			i += p;
		}
	}
	if (sz(ans) >= 3) {
		rep(i, 0, sz(ans)) {
			cout << ans[i];
			if (i == sz(ans) - 1) cout << endl;else cout << " ";
		}
	}
	ans.clear();
	return 0;
}
