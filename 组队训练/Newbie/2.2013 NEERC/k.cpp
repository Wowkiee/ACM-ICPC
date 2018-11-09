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
int n, m, col, win;
int a[N], b[N], c[N];
set<int> S;
int main() {
	freopen("kabaleo.in", "r", stdin);
	freopen("kabaleo.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m >> col >> win;
	rep(i, 1, n + 1) {
		cin >> a[i];
		c[a[i]]++;
		S.insert(a[i]);
	}
	rep(i, 0, m)cin >> b[i];
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
	//de(233);
	int Max = win, Min = win, cc = 0, cc2 = 0;
	rep(i, 1, col + 1) {
		if(c[i] == c[win] + 1) Max = i, cc++;
		else if(c[i] == c[win] && win != i) Min = i, cc2++;
		else if(c[i] > c[win]) {
			cout << 0 << endl;
			return 0;
		}
	}
	assert(cc2 >= 0);
	if(cc > 1) cout << 0 << endl;
	else if(cc == 1) {
		if(b[0] != win) {
			cout << 0 << endl;
			return 0;
		}
		if(S.find(Max) != S.end()) {
			vector<int> V;
			rep(i, 1, n + 1)if(a[i] == Max)V.pb(i);
			cout << sz(V) << endl;
			rep(i, 0, sz(V))cout << V[i] << " \n" [i == sz(V) - 1];
		}
		else cout << 0 << endl;
	}
	else if(cc2) {
		if(b[0] != win) {
			if(cc2 == 1 && S.find(Min) != S.end() && c[b[0]] + 1 != c[win] && b[0] != Min) {
				vector<int> V;
				rep(i, 1, n + 1)if(a[i] == Min)V.pb(i);
				cout << sz(V) << endl;
				rep(i, 0, sz(V))cout << V[i] << " \n" [i == sz(V) - 1];
			}
			else cout << 0 << endl;
			return 0;
		}
		vector<int> V;
		rep(i, 1, n + 1)if(a[i] != win)V.pb(i);
		cout << sz(V) << endl;
		rep(i, 0, sz(V))cout << V[i] << " \n" [i == sz(V) - 1];
	}
	else {
		if(b[0] == win) {
			cout << n << endl;
			rep(i, 1, n + 1)cout << i << " \n"[i == n];
		}
		else {
			vector<int> V;
			rep(i, 1, n + 1) {
				c[b[0]]++, c[a[i]]--;
				if(c[win] > c[b[0]])V.pb(i);
				c[b[0]]--, c[a[i]]++;
			}
			cout << sz(V) << endl;
			rep(i, 0, sz(V))cout << V[i] << " \n" [i == sz(V) - 1];
		}
	}
	return 0;
}
