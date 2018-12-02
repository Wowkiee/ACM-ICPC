#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(a) cout << #a << " = " << a << " "
#define de(a) cout << #a << " = " << a << endl
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double db;
//----
const int N = 1e6 + 7;
int n, m, col, win, ma;
int a[N], b[N], c[N], cnt[4];

void upd(int p, int c) {
	rep(i, 0, 4) if(p == ma - i + 1) cnt[i] += c;
}

bool check() {
	int Max = ma - 3;
	rep(i, 0, 4) if(cnt[i] > 0) {
		Max = ma - i + 1;
		break;
	}
	if(cnt[ma - Max + 1] == 1 && Max == c[win]) return 1;
	return 0;
}

int main() {
	freopen("kabaleo.in", "r", stdin);
	freopen("kabaleo.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m >> col >> win;
	rep(i, 1, n + 1) {
		cin >> a[i];
		c[a[i]]++;
	}
	rep(i, 0, m)cin >> b[i];
	if(n == 1) {
		if(b[m - 1] == win) {
			cout << 1 << endl << 1 << endl;
		} else {
			cout << 0 << endl;
		}
		return 0;
	}
	rep(i, 1, m) {
		if(c[win] == 0) {
			if(n == 1 && b[m - 1] == win) {
				cout << 1 << endl << 1 <<endl;
			}
			else cout << 0 <<endl;
			return 0;
		}
		else c[win]--, c[b[i]]++;
	}
	rep(i, 1, col + 1) {
		ma = max(ma, c[i]);
	}
	rep(i, 1, col + 1) {
		if(c[i] == ma) ++cnt[1];
		if(c[i] == ma - 1) ++cnt[2];
		if(c[i] == ma - 2) ++cnt[3];
	}
	vi ans;
	rep(i, 1, n + 1) {
		int x = b[0], y = a[i];
		int cc[4];
		rep(t, 0, 4) cc[t] = cnt[t];
		upd(c[x], -1);
		upd(c[y], -1);
		++c[x], --c[y];
		upd(c[x], 1);
		upd(c[y], 1);
		if(check()) ans.pb(i);
		--c[x], ++c[y];
		rep(t, 0, 4) cnt[t] = cc[t];
	}
	cout << sz(ans) << endl;
	rep(i, 0, sz(ans)) cout << ans[i] << " \n"[i == sz(ans) - 1];
	return 0;
}
