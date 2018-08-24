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

const int N = 202020;

int n, m;
int ans[N];
ll l[N], r[N], a[N];
pair<pair<ll, ll>, int> s[N << 1];

bool solve() {
	sort(s + 1, s + n + m);
	set<pair<ll, int> > st;
	rep(i, 1, n + m) {
		if(s[i].fi.se == -1) {
			st.insert(mp(s[i].fi.fi, s[i].se));
		} else {
			int j = s[i].se;
			ll L = l[j+1] - r[j];
			auto t = st.lower_bound(mp(L, -1));
			if(t == st.end()) return 0;
			ans[j] = t -> se + 1;
			st.erase(t);
		}
	}
	return 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 1, n+1) cin >> l[i] >> r[i];
	rep(i, 1, n) s[i] = mp(mp(r[i+1] - l[i], 1), i);
	rep(i, 0, m) {
		cin >> a[i];
		s[i + n] = mp(mp(a[i], -1), i);
	}
	if(solve()) {
		cout << "Yes" << endl;
		rep(i, 1, n) cout << ans[i] << " ";
		cout << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}
