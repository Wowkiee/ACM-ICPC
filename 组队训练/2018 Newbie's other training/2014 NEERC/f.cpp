#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1005;
int get(char x) {
	if (x >= '0' && x <= '9') return x - '0';
	else return x - 'a' + 10;
}

int n, m, p, q, f, len, b[N];
ll x, a[N];
bitset<N> A[N], C, B[N];
string s;
vi ans;
int main() {
	freopen("filter.in", "r", stdin);
	freopen("filter.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> m >> f;
	rep(i, 1, f+1) cin >> a[i];
	cin >> n;
	rep(i, 0, n) {
		cin >> s;
		len = 0;
		rep(j, 0, sz(s)) {
			x = get(s[j]);
			rep(k, 0, 4) if (pw(k) & x) b[len++] = 1;else b[len++] = 0;
		}  
		rep(j, 0, m) A[i][j] = b[j];
	}
	cin >> q;
	rep(i, 0, q) {
		cin >> x;
		rep(j, 1, f+1) {
			p = x * a[j] % m;
			B[i][p] = 1;
		}
	}
	rep(i, 0, n) 
		rep(j, 0, q) {
			C = A[i] & B[j];
			if (C == B[j]) {
				ans.pb(i);
				break;
			}
		}
	cout << sz(ans) << " ";
	rep(i, 0, sz(ans)) {
		cout << ans[i];
		if (i != sz(ans) - 1) cout << " ";
	}
	return 0;
}
