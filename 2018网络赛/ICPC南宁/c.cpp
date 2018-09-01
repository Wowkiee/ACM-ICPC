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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---

const int N = 202, M = 20202;

int n, m, pi, pv;
int a[M], p;
int cnt[N][14], ne[14], dis[N][N], tot[N];
set<int> v[14];

void in(int i, int val) {
	++tot[i];
	cnt[i][val]++;
	v[val].insert(i);
}
bool out(int i, int val) {
	if(i > n) i = 1;
	if(val) {
		tot[i]--;
		cnt[i][val]--;
		if(cnt[i][val] == 0) v[val].erase(i);
		pi = i, pv = val;
		return tot[i] == 0;
	} else {
		rep(j, 3, 14) if(cnt[i][j]) {
			return out(i, j);
		}
		rep(j, 1, 3) if(cnt[i][j]) {
			return out(i, j);
		}
	}
}

int find(int val) {
	if(sz(v[val]) == 0) return 0;
	if(pv == 2 && val == 2) return 0;
	auto u = v[val].upper_bound(pi);
	int ans;
	if(u == v[val].end()) {
		ans = *v[val].begin();
	} else {
		ans = *u;
	}
	if(ans == pi) return 0;
	return ans;
}

void solve() {
	///
	cin >> n >> m;
	rep(i, 1, n+1) rep(j, 1, n+1) {
		if(i == j) dis[i][j] = n;
		if(i < j) dis[i][j] = j - i;
		if(i > j) dis[i][j] = j + n - i;
	}
	///read
	p = 1;
	rep(i, 1, m+1) cin >> a[i];
	///solve
	rep(i, 1, n+1) {
		for(int j = 0; j < 5 && p <= m; ++j) {
			in(i, a[p++]);
		}
	}
	out(1, 0);
	while(1) {
		int t1 = find(ne[pv]);
		int t2 = find(2);
		if(t1 && t2) {
			if(dis[pi][t1] <= dis[pi][t2]) {
				if(out(t1, ne[pv])) break;
			} else {
				if(out(t2, 2)) break;
			}
		} else if(t1) {
			if(out(t1, ne[pv])) break;
		} else if(t2) {
			if(out(t2, 2)) break;
		} else {
			for(int i = pi; i <= n && p <= m; ++i) in(i, a[p++]);
			for(int i = 1; i < pi && p <= m; ++i) in(i, a[p++]);
			if(out(pi, 0)) break;
		}
	}
	rep(i, 1, n+1) {
		if(tot[i]) {
			ll ans = 0;
			rep(j, 1, 14) ans += 1ll * j * cnt[i][j], cnt[i][j] = 0;
			cout << ans << endl;
		} else {
			cout << "Winner" << endl;
		}
	}
	rep(i, 1, 14) v[i].clear();
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	rep(i, 3, 13) ne[i] = i + 1;
	ne[13] = 1;
	ne[1] = 2;
	int T;
	cin >> T;
	rep(ca, 1, T+1) {
		cout << "Case #" << ca << ":" << endl;
		solve();
	}
	return 0;
}
