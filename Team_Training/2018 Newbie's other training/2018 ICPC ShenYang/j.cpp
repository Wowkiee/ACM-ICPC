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
#define endl "\n"
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;

int n;
ll ans;

void gao() {
	string s;
	cin >> s;
	int t = 0;
	if(s[0] == 'b') {
		t = 1;
	} else if(s[0] == 'c') {
		t = 1;
	} else if(s[0] == 'i') {
		t = 4;
	} else if(s[0] == 'l') {
		cin >> s;
		if(s[0] == 'l') {
			t = 8;
		} else if(s[0] == 'd') {
			t = 16;
		}
	} else if(s[0] == '_') {
		t = 16;
	} else if(s[0] == 'f') {
		t = 4;
	} else if(s[0] == 'd') {
		t = 8;
	}
	cin >> s;
	int o = 0;
	if(s[sz(s) - 2] == ']') {
		int p = 0;
		rep(i, 0, sz(s)) if(s[i] == '[') {
			p = i + 1;
			break;
		}
		rep(i, p, sz(s)) {
			if(s[i] == ']') break;
			o = o * 10 + s[i] - '0';
		}
	} else {
		o = 1;
	}
	ans += 1ll * o * t;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T;
	cin >> T;
	int ca = 0;
	while(T--) {
		cout << "Case #" << ++ca << ": ";
		cin >> n;
		ans = 0;
		rep(i, 1, n + 1) gao();
		cout << (ans + 1023) / 1024 << endl;
	}
	return 0;
}
