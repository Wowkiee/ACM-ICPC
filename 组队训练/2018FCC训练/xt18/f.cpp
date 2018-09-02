#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----
const int N = 1e3 + 7;
struct P {
	int id;
	__int128 a, b, c;
	void read() { int _a, _b, _c; cin >> _a >> _b >> _c; a = _a; b = _b; c = _c; }
}	p[N];
bool cmp(const P &p1, const P &p2) {
	__int128 v1 = (p1.a + p1.b) * (p2.a + p2.b + p2.c);
	__int128 v2 = (p2.a + p2.b) * (p1.a + p1.b + p1.c);
	return v1 == v2 ? p1.id < p2.id : v1 < v2;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int n;
	while (cin >> n) {
		rep(i, 0, n) p[i].read(), p[i].id = i;
		sort(p, p + n, cmp);
		rep(i, 0, n) cout << p[i].id + 1 << " \n"[i == n - 1];
	}
	
	return 0;
}
