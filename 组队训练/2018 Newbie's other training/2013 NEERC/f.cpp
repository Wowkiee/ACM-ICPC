#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(a) cout << #a << " = " << a << " "
#define de(a) cout << #a << " = " << a << endl
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double db;
string s,ss;
int n;
vector<string> ans;
int main() {
	freopen("fraud.in", "r", stdin);
	freopen("fraud.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> ss >> n;
	rep(i, 0, n) {
		cin >> s;
		int flag = 1;
		rep(j, 0, 9)if(ss[j] != '*' && ss[j] != s[j])flag = 0;
		if(flag)ans.pb(s);
	}
	cout << sz(ans) << endl;
	rep(i, 0, sz(ans))cout << ans[i] << endl;
	return 0;
}
