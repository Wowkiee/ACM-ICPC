#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e6 +7;
int n, cnt[N], a[N],p;
vector<string> ans;
string s, tmp;
bool ok1, ok2;
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	while (getline(cin, tmp)) {
		n++;
		if (n > 1) {
			ok1 = (s[sz(s)-1] >= '0' && s[sz(s)-1] <= '9');
			ok2 = (tmp[0] >= '0' && tmp[0] <= '9');
			if (!(ok1 && ok2)) s += ' '; 
		}
		rep(i, 0, sz(tmp)) s += tmp[i], a[sz(s)-1] = n;
	}
	//de(s);
	rep(i, 0, sz(s)) if (s[i] != ' '){
		p = sz(s);
		rep(j, i, sz(s)) if (s[j] == ' ') {p = j;break;}
		string t;
		bool ok = (s[i] != '0');
		rep(j, i, p) {
			t += s[j];
			if (s[j] < '0' || s[j] > '9') {ok = 0;break;}
		}
		if (i == p-1 && s[i] == '0') {t = "0"; ok = 1;}
		if (ok) ans.pb(t), cnt[a[i]]++;
		i = p;
	}
	rep(i, 0, sz(ans)) {
		cout << ans[i];
		if (i == sz(ans)-1) cout << endl;else cout << " ";
	}
	rep(i, 1, n+1) cout << cnt[i] << endl;
	return 0;
}
