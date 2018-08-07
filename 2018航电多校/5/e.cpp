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
//typedef long double db;
typedef double db;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 111;
const db eps = 1e-8, pi = acos(-1);

int sign(db x) {
	return (x > eps) - (x < -eps);
}

int n;

struct P {
	db x, y;
	P() {}
	P(db _x, db _y) {
		x = _x, y = _y;
	}
	P operator + (const P &c) const {
		return P(x + c.x, y + c.y);
	}
	P operator - (const P &c) const {
		return P(x - c.x, y - c.y);
	}
	P operator * (const db &c) const {
		return P(c * x, c * y);
	}
};
struct C {
	P o;
	db r;
	C() {}
	C(P o, db r) : o(o), r(r) {}
};
db norm(P a) {
	return a.x * a.x + a.y * a.y;
}
db abs(P a) {
	return sqrt(norm(a));
}
db dis(P a, P b) {
	return sqrt(norm(a - b));
}
db cross(P a, P b) {
	return a.x * b.y - b.x * a.y;
}
db dot(P a, P b) {
	return a.x * b.x + a.y * b.y;
}
P rot90(P p) {
	return P(-p.y, p.x);
}
db ang(P a, P b) {
	db res = acos(dot(a, b) / abs(a) / abs(b));
	return res;
}
db ang(P a) {
	return atan2(a.y, a.x);
}
int relCC(C c1, C c2) {
	P p1 = c1.o, p2 = c2.o;
	db r1 = c1.r, r2 = c2.r;
	db d = dis(p1, p2);
	if(sign(d) == 0 && sign(r1 - r2) == 0) return 0;
	int x = sign(d - r1 - r2), y = sign(d - fabs(r1 - r2));
	if(x == 0) return 2;
	if(y == 0) return 4;
	if(x > 0) return 1;
	if(y < 0) return 5;
	if(y > 0 && x < 0) return 3;
	return -1;
}
bool isCC(C c1, C c2, P &p1, P &p2) {
	db x = norm(c1.o - c2.o), y = ((c1.r * c1.r - c2.r * c2.r) / x + 1) / 2;
	db d = c1.r * c1.r / x - y * y;
	if(sign(d) < 0) return 0;
	if(d < 0) d = 0;
	P q1 = (c2.o - c1.o) * y + c1.o, q2 = rot90((c2.o - c1.o) * sqrt(d));
	p1 = q1 - q2;
	p2 = q1 + q2;
	return 1;
}
void print(P p) {
	cout << p.x << " " << p.y << endl;
}

C c0;
C c[N];
P p[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		db r;
		cin >> n >> r;
		c0 = C(P(0, 0), r);
		rep(i, 1, n+1) {
			db x, y, r;
			cin >> x >> y >> r;
			c[i] = C(P(x, y), r);
		}
		db ans = 2 * pi * r;
		rep(i, 1, n+1) {
			int t = relCC(c0, c[i]);
			if(t == 4) {
				ans += 2 * pi * c[i].r;
			} else if(t == 3) {
				P p1, p2;
				isCC(c0, c[i], p1, p2);
				db t = 2 * ang(p1, c[i].o);
				ans -= t * r;
				t = 2 * ang(p1 - c[i].o, P(0, 0) - c[i].o);
				ans += t * c[i].r;
			}
		}
		cout << setiosflags(ios::fixed);
		cout << setprecision(10);
		double res = ans;
		cout << res << endl;
	}
	return 0;
}
