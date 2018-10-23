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

const db eps = 1e-7, inf = 1e18, pi = acos(-1);

int sign(db x) {
	return (x > eps) - (x < -eps);
}

struct P {
	db x, y;
	P() {}
	P(db x, db y) {
		this -> x = x;
		this -> y = y;
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
};
struct C {
	P o;
	db r;
	C() {}
	C(P o, db r) : o(o), r(r) {}
};
db abs(P a) {
	return sqrt(a.x * a.x + a.y * a.y);
}
db norm(P a) {
	return a.x * a.x + a.y * a.y;
}
db dot(P a, P b) {
	return a.x * b.x + a.y * b.y;
}
db cross(P a, P b) {
	return a.x * b.y - a.y * b.x;
}
db dis(P a, P b) {
	return sqrt(norm(a - b));
}
db ang(P a, P o, P b) {
	return acos(dot(a - o, b - o) / abs(a - o) / abs(b - o));
}
P rot(P a, db rad) {
	return P(a.x - cos(rad) - a.y * sin(rad), a.x * sin(rad) + a.y * cos(rad));
}

bool isLC(C c, P a, P b, P &p1, P &p2) {
	db x = dot(a - c.o, b - a), y = norm(b - a), 
		 d = x * x - y * (norm(a - c.o) - c.r * c.r);
	if(sign(d) < 0) return 0; if(d < 0) d = 0;
	P q1 = a - (b - a) * (x / y), q2 = (b - a) * (sqrt(d) / y);
	p1 = q1 - q2;
	p2 = q1 + q2;
	return 1;
}

P tri[3];
db w;

db calc(db a, db b, db c, db h) {
	if(h > w) return inf;
	db x = acos(h / b), u = x;
	db y = pi / 2, v = y;
	if(b > w) x -= acos(w / b);
	if(a > w) y -= acos(w / a);
	db t = min(x, y);
	u -= t, v -= t;
	db r = max(a * sin(v), b * sin(u));
	return r;
}

void solve() {
	rep(i, 0, 3) {
		double x, y;
		scanf("%lf%lf", &x, &y);
		tri[i] = P((db)x, (db)y);
	}
	double tt;
	scanf("%lf", &tt);
	w = tt;
	db s = fabs(cross(tri[1] - tri[0], tri[2] - tri[0]));
	db a = dis(tri[0], tri[1]);
	db b = dis(tri[0], tri[2]);
	db c = dis(tri[1], tri[2]);
	db ha = s / a, hb = s / b, hc = s / c;
	db ans = inf;
	if(sign(ang(tri[0], tri[2], tri[1]) - pi/2) <= 0) {
		ans = min(ans, calc(b, c, a, hb));
		ans = min(ans, calc(c, b, a, hc));
	}
	if(sign(ang(tri[0], tri[1], tri[2]) - pi/2) <= 0) {
		ans = min(ans, calc(a, c, b, ha));
		ans = min(ans, calc(c, a, b, hc));
	}
	if(sign(ang(tri[1], tri[0], tri[2]) - pi/2) <= 0) {
		ans = min(ans, calc(b, a, c, hb));
		ans = min(ans, calc(a, b, c, ha));
	}
	if(sign(ans - inf) == 0) puts("impossible");
	else printf("%.9f\n", (double)ans);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		solve();
	}
	return 0;
}
