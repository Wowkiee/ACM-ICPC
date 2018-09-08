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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;
//---

const int N = 333;
const db eps = 1e-8;

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
	P operator - (const P &c) const {
		return P(x - c.x, y - c.y);
	}
};

db cross(P a, P b) {
	return a.x * b.y - a.y * b.x;
}
db norm(P p) {
	return p.x * p.x + p.y * p.y;
}
db abs(P p) {
	return sqrt(norm(p));
}
db distoL(P p, P a, P b) {
	return fabs(cross(b - a, p - a)) / abs(b - a);
}

P othroC(P A, P B, P C) {
	P ba = B - A, ca = C - A, bc = B - C;
	db Y = ba.y * ca.y * bc.y;
	db a = cross(ca, ba);
	db xx = (Y + ca.x * ba.y * B.x - ba.x * ca.y * C.x) / a;
	db yy = -ba.x * (xx - C.x) / ba.y + ca.y;
	return P(xx, yy);
}

int n,s,r;
P p[N];

db solve(int i, int j) {
	db l = abs(p[i] - p[j]), r = 20000;
	rep(_, 0, 20) {
		db mid = (l + r) / 2;

	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> n >> s;
		rep(i, 0, n) cin >> p[i].x >> p[i].y;
		cin >> r;
		if(n < s) {
			cout << "The cake is a lie." << endl;
			continue;
		}
		db ans = 1e18;
		rep(i, 1, n+1) rep(j, i+1, n+1) {
			ans = min(ans, solve(i, j));
		}
		cout << ans << endl;
	}
	return 0;
}
