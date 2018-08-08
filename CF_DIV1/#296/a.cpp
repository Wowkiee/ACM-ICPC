#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

int w, h, n;

inline void ins(set<int> &S, multiset<int> &ss, int x) {
	auto l = S.upper_bound(x), r = l;
	--l;
	S.insert(x);
	ss.erase(ss.find(*r - *l));
	ss.insert(*r - x);
	ss.insert(x - *l);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	while(cin >> w >> h >> n) {
		set<int> H, V;
		multiset<int> hh, vv;
		H.insert(0);
		H.insert(h);
		hh.insert(h);
		V.insert(0);
		V.insert(w);
		vv.insert(w);
		while(n--) {
			string s;
			int t;
			cin >> s >> t;
			if(s[0] == 'H') {
				ins(H, hh, t);
			} else {
				ins(V, vv, t);
			}
			auto x = hh.end(), y = vv.end();
			--x, --y;
			cout << 1ll * (*x) * (*y) << endl;
		}
	}
	return 0;
}
