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
#define pw(a) (1ll << (a))
typedef long long ll;
typedef pair<int, int> pii;
typedef double db;
typedef vector<int> vi;
//----
const int N = 100005, MAX = 100000;
ll x[N], t, L, R, l, r;
char ans[N];

string s1, s2;

ll cal(int l, int r) {
	if (r < l) return 0;
	return 1ll * (r + l) * (r - l + 1) / 2;
}

bool check(ll l, ll r, ll L, ll R) {
	if (L <= 0 && 0 <= R) return 1;
	if (l > r) return L <= 0 && 0 <= R;
	if (R < l) return 0;
	ll x = R / (l - 1);
	if (R % (l - 1) == 0) x--;
	x = min(x, r - l + 1);
	return L - x * (l - 1) <= cal(r - (l-1) - x + 1, r - (l-1));
}

void solve1(ll a, ll b, ll ar, ll r) {
	b -= cal(ar + 1, r);
	t = cal(1, ar);
	rep(i, 1, ar+1) ans[i] = 'A';
	rep(i, ar+1, r+1) ans[i] = 'B';
	if (b > 0) per(i, 1, ar+1) {
		if (i >= b && t - i >= a) {
			ans[i] = 'B';
			break;
		}
	}
	rep(i, 1, r+1) s1 += ans[i];
}

void solve2(ll a, ll b, ll br, ll r) {
	a -= cal(br +1, r);
	t = cal(1, br);
	rep(i, br+1, r+1) ans[i] = 'A';
	L = a; R = t - b;
	//dd(L);de(R);
	rep(i, 1, br+1) {
		if (check(i+1, br, L - i, R - i)) {
			ans[i] = 'A';
			L -= i; R -= i;
		}else ans[i] = 'B';
	}
	rep(i, 1, r+1) s2 += ans[i];
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	rep(i, 1, MAX + 1)x[i] = 1ll * i * (i + 1) / 2;
	int T; cin >> T; while(T--) {
		ll a, b, c, d; cin >> a >> b >> c >> d;
		ll r = lower_bound(x + 1, x + MAX + 1, a + b) - x;
		ll ar = lower_bound(x + 1, x + MAX + 1, a) - x;
		ll br = lower_bound(x + 1, x + MAX + 1, b) - x;

		ll dma = c * ar + d * r, dmb = c * r + d * br;
		s1 = s2 = "";
		solve1(a, b, ar, r);
		solve2(a, b, br, r);
		cout << min(dma, dmb) << " ";
		//de(s1),de(s2);
		//dd(r);dd(ar);de(br);
		if (dma < dmb) cout << s1 << endl;
		else if (dma > dmb) cout << s2 << endl;
		else cout << min(s1, s2) << endl;
		/*if(c * ar + d * r <= c * r + d * br) {
			cout << c * ar + d * r << " ";
			per(i, 1, ar + 1) {
			if(a >= i)ans[i] = 'A', a -= i;
			else ans[i] = 'B';
			}
			rep(i, ar + 1, r + 1)ans[i] = 'B';
			}
			else {
			cout << c * r + d * br << " ";
			per(i, 1, br + 1) {
			if(b >= i)ans[i] = 'B', b -= i;
			else ans[i] = 'A';
			}
			rep(i, br + 1, r + 1)ans[i] = 'A';
			}*/
	}
	return 0;

}
