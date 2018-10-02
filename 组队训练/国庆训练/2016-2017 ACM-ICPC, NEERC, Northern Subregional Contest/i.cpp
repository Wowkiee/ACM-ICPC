#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(x) cout << #x << " = " << x << " "
#define de(x) cout << #x << " = " << x << endl
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 404040, P = 2;

int n;
int x[N], y[N], val[N], pre[N], pp[N][2][2][2];

int cross(pii a, pii b) {
	return ((1ll * a.fi * b.se - 1ll * a.se * b.fi) & 1);
}

int main() {
	freopen("integral.in","r",stdin);
	freopen("integral.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n + 1) {
		cin >> x[i] >> y[i];
		x[i] &= 1;
		y[i] &= 1;
		x[i + n] = x[i];
		y[i + n] = y[i];
	}
	rep(i, 2, n << 1 | 1) val[i] = cross(mp(x[i - 1], y[i - 1]), mp(x[i], y[i])), pre[i] = pre[i - 1] + val[i];
	if(pre[n + 1] & 1) {
		cout << 0 << endl;
		return 0;
	}
	rep(i, 1, n << 1 | 1) rep(a, 0, 2) rep(b, 0, 2) rep(c, 0, 2) {
		bool t = 1;
		t &= (x[i] == a);
		t &= (y[i] == b);
		t &= ((pre[i] & 1) == c);
		pp[i][a][b][c] = pp[i - 1][a][b][c] + t;
	}
	ll ans = 0;
	rep(i, 1, n + 1) {
		int l = i + 2, r = n + i - 2;
		rep(a, 0, 2) rep(b, 0, 2) rep(c, 0, 2) {
			int t = ((x[i] * b - y[i] * a + c - pre[i]) & 1);
			if(t == 0) ans += pp[r][a][b][c] - pp[l-1][a][b][c];
		}
	}
	cout << ans / 2 << endl;
	return 0;
}
