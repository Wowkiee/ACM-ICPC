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
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> iii;
typedef vector<int> vi;

const int N = 101010;

int n;
set<pair<iii, int> > s;
priority_queue<pair<iii, int> > q[2];

int main() {
	scanf("%d", &n);
	int o = 0;
	ll sum = 0;
	rep(i, 1, n + 1) {
		int x, m, d, hh, mm;
		scanf("%d%d.%d %d:%d", &x, &d, &m, &hh, &mm);
		auto u = mp(mp(m, d), mp(hh, mm));
		if(x > 0) {
			q[o].push(mp(u, x));
		} else {
			s.insert(mp(u, -x));
			sum -= x;
		}
		while(!q[o].empty()) {
			auto v = q[o].top(); q[o].pop();
			while(1) {
				auto t = s.lower_bound(v);
				if(t == s.end()) break;
				auto u = *t;
				s.erase(t);
				int c = min(u.se, v.se);
				u.se -= c, v.se -= c;
				sum -= c;
				if(u.se) s.insert(u);
				if(!v.se) break;
			}
			if(v.se) q[o ^ 1].push(v);
		}
		o ^= 1;
		cout << -sum << endl;
	}
	return 0;
}
