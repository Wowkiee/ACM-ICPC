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
typedef vector<int> vi;
typedef pair<int, int> pii;
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
		return 0 <= cmp(c, a) && cmp(c, b) < 0;
	}
	pii operator + (const pii &a, const pii &b) {
		return mp(a.fi + b.fi, a.se + b.se);
	}
	pii operator * (const pii &a, int x) {
		return mp(a.fi * x, a.se * x);
	}
	void search(V v, int MAXB, pii &lo, pii &hi, int f) {
		V x;
		int l = 0, r = f > 0 ? (hi.se ? (MAXB - lo.se) / hi.se : INF) : (lo.se ? (MAXB - hi.se) / lo.se : INF);
		while(l + 1 < r) {
			int z = (l + r) >> 1;
			x = f > 0 ? lo + hi * z : lo * z + hi;
			f * cmp(x, v) <= 0 ? l = z : r = z;
		}
		x = f > 0 ? lo + hi * r : lo * r + hi;
		r = f * cmp(x, v) <= 0 ? r : l;
		f > 0 ? lo = lo + hi * r : hi = lo * r + hi;
	}
	pii solve(V v, int MAXB) {
		V L = mp(v.fi * 10 - 5, v.se * 10);
		V R = mp(v.fi * 10 + 5, v.se * 10);
		pii lo(0, 1), hi(1, 0);
		while(1) {
			V m = mp(lo.fi + hi.fi, lo.se + hi.se);
			if(in(L, R, m)) return mp(m.fi, m.se);
			search(v, MAXB, lo, hi, 1);
			search(v, MAXB, lo, hi, -1);
			if(in(L, R, lo)) return lo;
			if(in(L, R, hi)) return hi;
		}
		return mp(-1, -1);
	}
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n;
	cin >> n;
	while(n--) {
		db x;
		cin >> x;
		__int128 a = x * 1e9, b = 1e9;
		pii ans = SBT::solve(mp(a, b), 1e9);
		cout << ans.fi << " " << ans.se << endl;
	}
	return 0;
}
