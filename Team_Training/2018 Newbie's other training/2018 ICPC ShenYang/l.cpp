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
typedef long double db;

const int N = 222;
const db eps = 1e-8, pi = acos(-1);

int sign(db x) {
	return (x > eps) - (x < -eps);
}

struct P {
	db x, y;
	P() {}
	P(db x, db y) : x(x), y(y) {}
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
	db len() {
		return sqrt(x * x + y * y);
	}
	P unit() {
		return *this / len();
	}
	P turn90() {
		return P(-y, x);
	}
	void print() {
		dd(x), de(y);
	}
};
struct C {
	P o;
	db r;
	C() {}
	C(P o, db r) : o(o), r(r) {}
};

int n, cntp;
db r, ans;
C c[N];
P p[N];

bool isCC(C a, C b, P &p1, P &p2) {
	db s1 = (a.o - b.o).len();
	if(sign(s1 - a.r - b.r) > 0 || sign(s1 - abs(a.r - b.r)) < 0) return 0;
	db s2 = (a.r * a.r - b.r * b.r) / s1;
	db aa = (s1 + s2) / 2, bb = (s1 - s2) / 2;
	P o = (b.o - a.o) * (aa / (aa + bb)) + a.o;
	P delta = (b.o - a.o).unit().turn90() * sqrt(a.r * a.r - aa * aa);
	p1 = o + delta, p2 = o - delta;
	return 1;
}

bool check(db x, db y) {
	rep(i, 1, n + 1) if((c[i].o - P(x, y)).len() < c[i].r) return 0;
	return 1;
}

db solve() {
	rep(i, 1, cntp + 1) {
		if(check(-p[i].x, -p[i].y)) return 2 * r;
	}
	rep(i, 1, cntp + 1) rep(j, i + 1, cntp + 1) ans = max(ans, (p[i] - p[j]).len());
	return ans;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T;
	cin >> T;
	int ca = 0;
	cout << setiosflags(ios::fixed);
	cout << setprecision(15);
	while(T--) {
		cout << "Case #" << ++ca << ": ";
		cin >> n >> r;
		c[0] = C(P(0, 0), r);
		cntp = 0;
		ans = 0;
		rep(i, 1, n + 1) {
			db x, y, r;
			cin >> x >> y >> r;
			c[i] = C(P(x, y), r);
			P a, b;
			if(isCC(c[0], c[i], a, b)) p[++cntp] = a, p[++cntp] = b;
		}
		cout << solve() << endl;
	}
	return 0;
}
