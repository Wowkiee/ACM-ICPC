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

const int N = 55;

int n, k;
int a[5][N];
pii pre[5][N], ne[5][N];
vector<pair<int, pii> > ans;

pii find() {
	rep(i, 2, 4) rep(j, 1, n+1) if(a[i][j] && !a[ne[i][j].fi][ne[i][j].se]) {
		return mp(i, j);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	///read
	cin >> n >> k;
	rep(i, 1, 5) rep(j, 1, n+1) cin >> a[i][j];
	rep(j, 1, n) pre[2][j] = mp(2, j+1);pre[2][n] = mp(3, n);
	///get pre ne
	rep(j, 2, n+1) pre[3][j] = mp(3, j-1);pre[3][1] = mp(2, 1);
	rep(i, 2, 4) rep(j, 1, n+1) ne[pre[i][j].fi][pre[i][j].se] = mp(i, j);
	///
	rep(j, 1, n+1) {
		if(a[2][j] && a[2][j] == a[1][j]) {
			ans.pb(mp(a[2][j], mp(1, j)));
			a[2][j] = 0;
			--k;
		}
		if(a[3][j] && a[3][j] == a[4][j]) {
			ans.pb(mp(a[3][j], mp(4, j)));
			a[3][j] = 0;
			--k;
		}
	}
	///
	if(k == 2 * n) {
		cout << "-1" << endl;
		return 0;
	}
	///solve
	pii st = find();
	while(k) {
		int x = st.fi, y = st.se;
		st = ne[x][y];
		int nx = st.fi, ny = st.se;
		a[nx][ny] = a[x][y];
		ans.pb(mp(a[x][y], mp(nx, ny)));
		a[x][y] = 0;
		int t = nx==2 ? 1 : 4;
		if(a[nx][ny] == a[t][ny]) {
			a[nx][ny] = 0;
			ans.pb(mp(a[t][ny], mp(t, ny)));
			--k;
		}
		if(!k) break;
		while(1) {
			st = pre[nx][ny];
			nx = st.fi, ny = st.se;
			if(a[nx][ny]) break;
		}
	}
	cout << sz(ans) << endl;
	for(auto u : ans) {
		cout << u.fi << " " << u.se.fi << " " << u.se.se << endl;
	}
	return 0;
}
