#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(x) (int)x.size()
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 101010;

int R = 32767, L = - R - 1, ADD = R + 2;
int cnt[N];
vector<pii> res;

int calc(const string &s) {
	int r = 0;
	rep(i, 0, sz(s)) if(s[i] != '-') {
		r = r * 10 + s[i] - '0';
		if(r > R) break;
	}
	if(s[0] == '-') r = -r;
	if(r < L) r = L;
	if(r > R) r = R;
	return r;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	freopen("hard.in", "r", stdin);
	freopen("hard.out", "w", stdout);
	string s, t;
	while(cin >> s) {
		int l = L, r = R;
		cin >> s >> t;
		if(s == ">=") l = calc(t);  else r = calc(t);
		if(!(cin >> s) || s == "||") {
		} else {
			cin >> s >> s >> t;
			if(s == ">=") l = calc(t); else r = calc(t);
			cin >> s;
		}
		if(l > r) continue;
		l += ADD, r += ADD;
		cnt[l]++, cnt[r+1]--;
	}
	int now = 0, l, r;
	rep(i, L + ADD, R + ADD + 2) {
		int pre = now;
		now += cnt[i];
		if(!pre && now) l = i - ADD;
		if(pre && !now) {
			r = i - ADD - 1;
			res.pb(mp(l, r));
		}
	}
	if(sz(res)) {
		if(sz(res) == 1 && res[0].fi == L && res[0].se == R) {
			cout << "true" << endl;
		} else {
			rep(i, 0, sz(res)) {
				auto u = res[i];
				if(u.fi > L) {
					cout << "x >= " << u.fi << " ";
					if(u.se < R) cout << "&& ";
				}
				if(u.se < R) {
					cout << "x <= " << u.se;
					if(i != sz(res) - 1) cout << " ||";
				}
				cout << endl;
			}
		}
	} else {
		cout << "false" << endl;
	}
	return 0;
}
