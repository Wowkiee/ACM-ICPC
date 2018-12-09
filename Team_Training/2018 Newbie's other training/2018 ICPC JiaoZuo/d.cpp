#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define endl "\n"
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
typedef long long ll;
typedef pair<int, int> pii;
typedef double db;
typedef vector<int> vi;


const db pi = acos(-1);
int sqr(int x) {return x * x;}
int a, b, r, d, T;
db ang1, ang2, l;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cout << setiosflags(ios::fixed);
	cout << setprecision(10);
	cin >> T;
	rep(cas, 0, T) {
		cin >> a >> b >> r >> d;
		l = sqrt(sqr(a + r) + sqr(b));
		ang1 = acos((a + r) / l);
		ang2 = d / 180.0 * pi;
		//cout << ang1 << " " << ang2 << endl;
		if (ang1 < ang2) cout << l - r << endl;
		else cout << l * cos(ang1 - ang2) - r << endl;
	}
	return 0;
}
