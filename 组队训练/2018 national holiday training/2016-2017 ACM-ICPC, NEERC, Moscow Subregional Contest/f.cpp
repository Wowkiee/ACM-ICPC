#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 205;
string s, ans, ans1, ans2;
int num, pos;
bool use[N];

bool check(char x) {
	return (x >= '0' && x <= '9') || (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z') || x == ' ';
}

string solve() {
	string s;
	vi tmp;num = 0;
	rep(i, 32, 'z' + 2) if (use[i] && i <= 'z'){
		tmp.pb(i);
		if (check(i)) num++, pos = i;
	}else {
		if (num <= 2) {
			rep(j, 0, sz(tmp)) if (check(tmp[j])) s += char(tmp[j]);
		}else {
			s += char(tmp[0]);
			s += '-';
			s += char(pos);
		}
		tmp.clear();
		num = 0;
	}
	return s;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	getline(cin, s);
	//de(s);
	rep(i, 0, sz(s)) {
		use[s[i]] = 1;
	}
	rep(i, 32, 'z'+1) if (!check(i)) use[i] = 1;
	ans1 = solve();
	rep(i, 32, 'z'+1) if (check(i)) use[i] ^= 1;
	ans2 = "^" + solve();
	if (ans2 == "^") ans2 += '!'; 
	if (sz(ans1) < sz(ans2)) ans = ans1;
	else if (sz(ans1) > sz(ans2)) ans = ans2;
	else ans = min(ans1, ans2);
	ans = "%[" + ans;
	ans += ']';
	cout << ans;
	return 0;
}
