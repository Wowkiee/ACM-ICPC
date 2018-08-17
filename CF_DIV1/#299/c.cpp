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
typedef double db;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 202020;
const db eps = 0;

int sign(db x) {
	return (x > eps) - (x < -eps);
}

struct P {
	db x, y;
	vi index;
	P() {};
	P(db x, db y) : x(x), y(y) {};
	P operator + (const P &c) const {
		return P(x + c.x, y + c.y);
	}
	P operator - (const P &c) const {
		return P(x - c.x, y - c.y);
	}
	bool operator < (const P &c) const {
		int f = sign(x - c.x);
		return f ? f < 0 : sign(y - c.y) < 0;
	}
};

db cross(P a, P b) {
	return a.x * b.y - b.x * a.y;
}

int convexhull(P *p, int n, P *ch) {
	sort(p, p+n);
	int m = 0;
	rep(i, 0, n) {
		while(m > 1 && sign(cross(ch[m-1] - ch[m-2], p[i] - ch[m-2])) < 0) --m;
		ch[m++] = p[i];
	}
	int k = m;
	for(int i = n-2; i>=0; --i) {
		while(m > k && sign(cross(ch[m-1] - ch[m-2], p[i] - ch[m-2])) < 0) --m;
		ch[m++] = p[i];
	}
	if(n > 1) --m;
	return m;
}

int n, cntp, m;
bool ans[N];
pair<pii, int> a[N];
P p[N], ch[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n+1) {
		int x, y;
		cin >> x >> y;
		a[i] = {{x, y}, i};
	}
	sort(a+1, a+1+n);
	rep(i, 1, n+1) {
		if(i == 1 || a[i].fi != a[i-1].fi) {
			++cntp;
			p[cntp].x = 1./a[i].fi.fi;
			p[cntp].y = 1./a[i].fi.se;
		}
		p[cntp].index.pb(a[i].se);
	}
	m = convexhull(p+1, cntp, ch);
	db mix = 1e18, miy = mix;
	int st, ed;
	rep(i, 0, m) {
		int t1 = sign(mix - ch[i].x);
		int t2 = sign(miy - ch[i].y);
		if(t1 > 0) {
			mix = ch[i].x;
			ed = i;
		} else if(t1 == 0) {
			if(ch[ed].y > ch[i].y) ed = i;
		}
		if(t2 > 0) {
			miy = ch[i].y;
			st = i;
		} else if(t2 == 0) {
			if(ch[st].x > ch[i].x) st = i;
		}
	}
	swap(st, ed);
	if(st <= ed) {
		rep(i, st, ed+1) for(auto j : ch[i].index) ans[j] = 1;
	} else {
		rep(i, st, m) for(auto j : ch[i].index) ans[j] = 1;
		rep(i, 0, ed+1) for(auto j : ch[i].index) ans[j] = 1;
	}
	rep(i, 1, n+1) if(ans[i]) cout << i << " ";
	cout << endl;
	return 0;
}
