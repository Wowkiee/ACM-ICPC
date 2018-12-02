#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(a) cout << #a << " = " << a << " "
#define de(a) cout << #a << " = " << a << endl
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
//----
vector<pii> v;
const int MAXV = 1000000;
int query(int x, int y) {
	printf("? %d %d\n", x, y);
	fflush(stdout);
	int s; scanf("%d", &s);
	rep(i, 0, sz(v))if(v[i].fi <= x && v[i].se <= y)s--;
	return s;
}
int main() {
	int n; scanf("%d" ,&n);
	int l = -MAXV, r = MAXV;
	while(sz(v) < n) {
		while(l < r) {
			int mid = l + r >> 1;
			int c = query(mid, MAXV);
			if(c == 0)l = mid + 1;
			else r = mid;
		}
		int s = query(l, MAXV);
		while(s--) {
			int ll = -MAXV, rr = MAXV;
			while(ll < rr) {
				int mmid = ll + rr >> 1;
				int c = query(l, mmid);
				if(c == 0)ll = mmid + 1;
				else rr = mmid;
			}
			v.pb(mp(l, ll));
			ll = ll + 1, rr = MAXV;
		}
		l = l + 1, r = MAXV;
	}
	printf("!");
	rep(i, 0, sz(v))printf(" %d %d", v[i].fi, v[i].se);
	puts("");
	return 0;
}
