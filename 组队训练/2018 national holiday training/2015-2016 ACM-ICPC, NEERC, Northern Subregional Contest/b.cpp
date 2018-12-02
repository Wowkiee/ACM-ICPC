#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(x) (int)x.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll<<(a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

int a, b, s, t;
char c[3][10000];

int main() {
	freopen("black.in","r",stdin);
	freopen("black.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> a >> b;
	s = max(a, b);
	rep(i, 1, s*2 + 1) 
		if (i & 1) c[1][i] = c[2][i] = '@';
		else c[1][i] = c[2][i] = '.';
	if (a < s) {
		t = s - a + 1;
		rep(i, 1, 2 * t) c[2][i] = '@';
	}else {
		t = s - b + 1;
		rep(i, 2, 2 * t + 1) c[2][i] = '.';
	}
	cout << 2 << " " << 2 * s << endl;
	rep(i, 1, 2 * s + 1) cout << c[1][i];
	cout << endl;
	rep(i, 1, 2 * s + 1) cout << c[2][i];
	return 0;
}
