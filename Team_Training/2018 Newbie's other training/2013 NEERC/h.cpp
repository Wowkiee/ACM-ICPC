#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse2")
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

const int N = 1e5 +7;
int n, x, y, a[N], s[N], tid;
ll ans;
map<int , int> M; 
vi vv[N], v[40];

int cal(int l, int r, int x) {
	int p1, p2, p;
	if (M.count(x) == 0) return 0;
	p = M[x];
	p1 = lower_bound(all(vv[p]), l) - vv[p].begin();
	p2 = upper_bound(all(vv[p]), r) - vv[p].begin();
	return p2 - p1;
}

void solve(int l) {
	int p = l, pos, pp;
	int x = a[p];
	while (1) {
		if (x == 0) {
			ans += cal(p, n, x ^ s[l-1]);
			return;
		}else {
			pos = n;
			rep(i, 0, 32) if (pw(i) & x) {
				pp = upper_bound(all(v[i]), p) - v[i].begin();
				if (pp != sz(v[i])) pos = min(pos, v[i][pp] - 1);
			}	
			ans += cal(p, pos, x ^ s[l-1]);
			p = pos + 1;
			if (p > n) return;
			x &= a[p];
		}
	}
}

int main() {
	freopen("hack.in", "r", stdin);
	freopen("hack.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	
	//n = 100000;srand(time(0));
	
	rep(i, 1, n+1) {
		cin >> a[i];	
		//a[i] = rand();
		s[i] = s[i-1] ^ a[i];
		rep(j, 0, 32) if ((pw(j) & a[i]) == 0) v[j].pb(i);
	}
	rep(i, 1, n+1) {
		if (M.count(s[i]) == 0) M[s[i]] = ++ tid;
		vv[M[s[i]]].pb(i);
	}
	rep(i, 1, n+1) {
		solve(i);
	}
	cout << ans << endl;
	/*ll ans2 = 0, x , y;
	rep(i, 1, n+1){
		x = a[i]; y = a[i];
		rep(j, i+1, n+1) {
			x ^= a[j];
			y &= a[j];
			if (x == y) ans2++; 
		}
	}
	assert(ans2 + n == ans);
	*/
	return 0;
}
