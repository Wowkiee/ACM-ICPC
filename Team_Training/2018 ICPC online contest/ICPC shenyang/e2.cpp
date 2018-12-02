#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
#define x(a) a.x
#define y(a) a.y
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double db;
//---

const int N = 333;
const db eps = 1e-6;

int sign(db x) {
	return (x > eps) - (x < -eps);
}

struct P {
	db x,y;
	P() {}
	P(db x, db y) {
		this->x = x;
		this->y = y;
	}
	P operator + (const P &c) const {
		return P(x + c.x, y + c.y);
	}
	P operator - (const P &c) const {
		return P(x - c.x, y - c.y);
	}
	P operator * (const db &c) const {
		return P(x * c, y * c);
	}
	P operator / (const db &c) const {
		return P(x / c, y / c);
	}
	bool operator == (const P &c) const {
		return !sign(x - c.x) && !sign(y - c.y);
	}
	bool operator != (const P &c) const {
		return !(*this == c);
	}
	void print() {
		cout << x << " " << y << endl << endl;
	}
};

int n, s, r;
db ans;
P p[N];

db abs(P a) {
	return sqrt(x(a) * x(a) + y(a) * y(a));
}
db norm(P a) {
	return x(a) * x(a) + y(a) * y(a);
}
db dot(P a, P b) {
	return x(a) * x(b) + y(a) * y(b);
}
db cross(P a, P b) {
	return x(a) * y(b) - x(b) * y(a);
}
db cross(P a, P b, P o) {
	a = a - o, b = b - o;
	return cross(a, b);
}

P othroC(P A, P B, P C) {
	P b = B - A, c = C - A;
	db db = norm(b), dc = norm(c), d = 2 * cross(b, c);
	return A - P(y(b) * dc - y(c) * db, x(c) * db - x(b) * dc) / d;
}

db solve(int u, int v) {
	db res = abs(p[u] - p[v]) / 2;
	if(res > ans) return res;

	int cnt = s - 2;
	vector<db> V[2];
	for(int i = 0; i < n && cnt > 0; ++i) if(i != u && i != v) {
		if(sign(cross(p[u], p[v], p[i]))) {
			P x = othroC(p[u], p[v], p[i]);
			db r = abs(p[i] - x);
			db t = sign(cross(x - p[v], p[u] - p[v]));
			if(t > 0) V[0].pb(r);
			else if(t < 0) V[1].pb(r);
			else --cnt;
		} else {
			if(p[u] == p[i] || p[v] == p[i] || (abs(p[i] - p[u]) < abs(p[v] - p[u]) && abs(p[i] - p[v]) < abs(p[u] - p[v]))) --cnt;
		}
	}
	if(cnt <= 0) return res;
	db mi = 1e18;
	if(sz(V[0]) >= cnt) {
		nth_element(V[0].begin(), V[0].begin() + cnt - 1, V[0].end());
		mi = min(mi, V[0][cnt-1]);
	}
	if(sz(V[1]) >= cnt) {
		nth_element(V[1].begin(), V[1].begin() + cnt - 1, V[1].end());
		mi = min(mi, V[1][cnt-1]);
	}
	return max(res, mi);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		map<pii, int> vis;
		cin >> n >> s;
		int ma = 0;
		rep(i, 0, n) {
			int x, y;
			cin >> x >> y;
			++vis[mp(x, y)];
			ma = max(ma, vis[mp(x, y)]);
			p[i] = P(x, y);
		}
		cin >> r;
		if(n < s) {
			cout << "The cake is a lie." << endl;
			continue;
		}
		ans = 1e18;
		if(s <= ma) {
			ans = 0;
		} else {
			rep(i, 0, n) rep(j, i + 1, n) if(p[i] != p[j]) {
				ans = min(ans, solve(i, j));
			}
		}
		cout << setiosflags(ios::fixed);
		cout << setprecision(4);
		double res = ans + r;
		cout << res << endl;
	}
	return 0;
}
