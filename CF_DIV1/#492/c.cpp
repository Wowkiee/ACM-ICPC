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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 201010, inf = 1e6;

struct P {
	int x, y;
	P() {}
	P(int _x, int _y) {
		x = _x, y = _y;
	}
	P operator + (const P &c) const {
		return P(x + c.x, y + c.y);
	}
	P operator - (const P &c) const {
		return P(x - c.x, y - c.y);
	}
};

double dis(P a) {
	return sqrt(1. * a.x * a.x + 1. * a.y * a.y);
}

int n, m, top;
int ls[N], rs[N], tag[N], sta[N], pre[N];
P p[N];

inline int newnode(P point) {
	p[++m] = point;
	tag[m] = 1;
	return m;
}

inline void gao() {
	rep(i, 0, 3) rep(j, i+1, 3) {
		double t;
		if((t = dis(p[sta[top-i]] + p[sta[top-j]])) <= inf) {
			int u = newnode(p[sta[top-i]] + p[sta[top-j]]);
			ls[u] = sta[top-i];
			rs[u] = sta[top-j];
			sta[top-2] = sta[top-3+i+j];
			sta[top-1] = m;
			--top;
			return ;
		}
		if((t = dis(p[sta[top-i]] - p[sta[top-j]])) <= inf) {
			int u = newnode(p[sta[top-i]] - p[sta[top-j]]);
			ls[u] = sta[top-i];
			rs[u] = sta[top-j];
			tag[rs[u]] = -tag[rs[u]];
			sta[top-2] = sta[top-3+i+j];
			sta[top-1] = m;
			--top;
			return ;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	///
	cin >> n;
	///read
	rep(i, 1, n+1) {
		int x, y;
		cin >> x >> y;
		p[i] = P(x, y);
		tag[i] = 1;
		sta[++top] = i;
	}
	///
	if(n == 1) {
		cout << 1 << endl;
		return 0;
	}
	///solve
	m = n;
	while(top >= 3) {
		gao();
	}
	int u;
	if(dis(p[sta[1]] + p[sta[2]]) < dis(p[sta[1]] - p[sta[2]])) {
		u = newnode(p[sta[1]] + p[sta[2]]);
		ls[u] = sta[1];
		rs[u] = sta[2];
	} else {
		u = newnode(p[sta[1]] - p[sta[2]]);
		ls[u] = sta[1];
		rs[u] = sta[2];
		tag[rs[u]] = -tag[rs[u]];
	}
	///print
	rep(i, n+1, m+1) {
		pre[ls[i]] = pre[rs[i]] = i;
	}
	for(int i = m-1; i; --i) {
		tag[i] *= tag[pre[i]];
	}
	rep(i, 1, n+1) {
		cout << tag[i] << " ";
	}
	cout << endl;
	return 0;
}
