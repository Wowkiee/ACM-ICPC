
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
typedef __int128 ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double db;

namespace SBT {
	const int INF = 1e9 + 7;
	typedef __int128 T;
	typedef pair<T, T> V;
	inline int cmp(const V &a, const V &b) {
		T x = a.fi * b.se - a.se * b.fi;
		return (x > 0) - (x < 0);
	}
	inline bool in(const V &a, const V &b, const V &c) {
		return 0 <= cmp(c, a) && cmp(c, b) <= 0;
	}
	pll operator + (const pll &a, const pll &b) {
		return mp(a.fi + b.fi, a.se + b.se);
	}
	pll operator * (const pll &a, ll x) {
		return mp(a.fi * x, a.se * x);
	}
	void search(V v, ll MAXB, pll &lo, pll &hi, ll f) {
		V x;
		ll l = 0, r = f > 0 ? (hi.se ? (MAXB - lo.se) / hi.se : INF) : (lo.se ? (MAXB - hi.se) / lo.se : INF);
		while(l + 1 < r) {
			ll z = (l + r) >> 1;
			x = f > 0 ? lo + hi * z : lo * z + hi;
			f * cmp(x, v) <= 0 ? l = z : r = z;
		}
		x = f > 0 ? lo + hi * r : lo * r + hi;
		r = f * cmp(x, v) <= 0 ? r : l;
		f > 0 ? lo = lo + hi * r : hi = lo * r + hi;
	}
	pll solve(V v, ll MAXB) {
		for (int x = 1; x <= 100; x += 1) {
			V L = mp(v.fi * 10 - x + 1, v.se * 10);
			V R = mp(v.fi * 10 + x, v.se * 10);
			pll lo(0, 1), hi(1, 0);
			int cnt = 0;
			while(1) {
				cnt ++;
				if (cnt > 1000) break;
				V m = mp(lo.fi + hi.fi, lo.se + hi.se);
				if(in(L, R, m)) return mp(m.fi, m.se);
				search(v, MAXB, lo, hi, 1);
				search(v, MAXB, lo, hi, -1);
				if(in(L, R, lo)) return lo;
				if(in(L, R, hi)) return hi;
			}
		}
		return mp(-1, -1);
	}
}

int main() {
//	freopen("decimal-form.in", "r", stdin);
//	freopen("decimal-form.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	cin >> n;
	srand(time(0));
	n = 100;		cout << setiosflags(ios::fixed);
		cout << setprecision(18);
	int mod = 1e9;
	while(n--) {
		long double x;
		int aa = 1ll * rand() * rand() % mod;
		int bb = 1ll * rand() * rand() % mod;
		int g = __gcd(aa, bb);
		aa /= g; bb /= g;
		if (aa > bb) swap(aa, bb); 
		//cin >> x;
		x = ((long double)1.0) * aa / bb;
		__int128 c = 1e18, a = x * c + 1, b = c;
		pair<long long, long long> ans = SBT::solve(mp(a, b), 1e9);
		if (aa != ans.fi || bb != ans.se) {
			de((long long) a);
			de((long double)ans.fi / ans.se);
		//	dd(aa);de(bb);
		//	dd(ans.fi);de(ans.se);
		}
		//assert(aa == ans.fi && bb == ans.se);
		/*

		de(x);
		de((long double)ans.fi / ans.se);
		*/
	}
	return 0;
}
