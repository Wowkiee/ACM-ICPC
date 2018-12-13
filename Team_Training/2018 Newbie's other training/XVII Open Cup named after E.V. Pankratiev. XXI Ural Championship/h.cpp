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
#define pw(x) (1ll << (x))
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
//----
const int N = 1005, SUMN = 50005;
struct Hash_table {
	static const int V = 1000003;
	int fst[V], nxt[V];
	int ctm, ptm[V], T;
	int val[V], tot;
	vector< pair<ll, int> > key;
	void init() {
		T = 0; ctm++; key.clear();
		tot = 0;
	}
	void add(ll s) {
		int S = s % V;
		if(ptm[S] != ctm)ptm[S] = ctm, fst[S] = -1;
		for(int j = fst[S]; j != -1; j = nxt[j])if(key[j].fi == s) {
			return;
		}
		nxt[T] = fst[S], fst[S] = T; key.pb(mp(s, ++tot));
		T++;
	}
	int operator[](ll s) {
		int S = s % V;
		if(ptm[S] != ctm)return 0;
		for(int j = fst[S]; j != -1; j = nxt[j])if(key[j].fi == s)
			return key[j].se;
		return 0;
	}
}V;
string s[SUMN];
int sz[N];
vi Can[1 << 20];
int cnt[N];
int getR(char a) {
	return 1 << (a - 'a');
}
int main() {
	//std::ios::sync_with_stdio(0);
	//std::cin.tie(0);
	V.init();
	int n, m;
	cin >> n;
	int p = 0;
	rep(i, 0, n) {
		cin >> sz[i];
		rep(j, 0, sz[i])cin >> s[++p];
	}
	cin >> m;
	rep(i, 1, m + 1) {
		vi can;
		int sz; cin >> sz;
		rep(j, 0, sz) {
			string a; cin >> a;
			rep(k, 0, 1 << sz(a)) {
				int x = 0;
				rep(l, 0, sz(a))if(k >> l & 1)x ^= getR(a[l]);
				can.pb(x);
			}
		}
		sort(all(can)); can.erase(unique(all(can)), can.end());
		rep(j, 0, sz(can)) {
			V.add(can[j]);
			int x = V[can[j]];
			Can[x].pb(i);
		}
	}
	p = 0;
	rep(i, 0, n) {
		memset(cnt, 0, sizeof cnt);
		rep(j, 0, sz[i]) {
			string a = s[++p];
			int x = 0;
			rep(l, 0, sz(a))x ^= getR(a[l]);
			x = V[x];
			rep(l, 0, sz(Can[x]))cnt[Can[x][l]]++;
		}
		int ans = 1;
		rep(j, 2, m + 1)if(cnt[j] > cnt[ans])ans = j;
		cout << ans << endl;
	}
	return 0;
}
