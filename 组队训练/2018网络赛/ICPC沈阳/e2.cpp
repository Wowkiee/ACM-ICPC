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
typedef double db;
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
    bool operator == (const P &c) const {
    	return !sign(x - c.x) && !sign(y - c.y);
		}
};

int n, s, r;
P p[N];
db ans;

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
	P ba = B - A, ca = C - A, bc = B - C;
	db Y = y(ba) * y(ca) * y(bc);
	db a = cross(ca, ba);
	db xx = (Y + x(ca) * y(ba) * x(B) - x(ba) * y(ca) * x(C)) / a;
	db yy = -x(ba) * (xx - x(C)) / y(ba) + y(ca);
	return P(xx, yy);
}

db solve(int u, int v) {
	db res = abs(p[u] - p[v]) / 2;
	if(res > ans) return res;

	int cnt = s - 2;
	vector<db> V[2];
	for(int i = 0; i < n && cnt > 0; ++i) if(i != u && i != v) {
		P x = othroC(p[u], p[v], p[i]);
		int t = sign(cross(x - p[v], p[u] - p[v]));
		if(t) {
			db r = abs(p[i] - x);
			V[t > 0].pb(r);
		} else {
			if(p[u] == p[i] || p[v] == p[i] || sign(abs(p[v]) - abs(p[i])) == sign(abs(p[i]) - abs(p[u]))) --cnt;
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
	return res + mi;
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
		ans = 1e18;
		if(s == 1) {
			ans = 0;
		} else {
			rep(i, 0, n) rep(j, i + 1, n) {
				ans = min(ans, solve(i, j));
			}
		}
		cout << setiosflags(ios::fixed);
		cout << setprecision(5);
		cout << ans + r << endl;
	}
	return 0;
}
