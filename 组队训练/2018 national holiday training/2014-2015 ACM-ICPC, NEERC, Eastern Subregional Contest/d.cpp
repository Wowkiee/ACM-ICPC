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
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 333;

int n, m, k, t[3];
pii a[N];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> t[1] >> t[2];
	cin >> m;
	rep(i, 1, m + 1) cin >> a[i].fi >> a[i].se;
	cin >> k;
	int r1 = 0, r2 = 0, ma = -1, ty = 0;
	rep(i, 1, k + 1) {
		int o, x, y;
		cin >> o >> x >> y;
		if(n >= x && t[o] + y > ma) {
			r1 = i, r2 = 0, ma = t[o] + y, ty = o;
		}
		if(o == 2) {
			if(n >= (x + 1) / 2) rep(j, 1, m + 1) {
				if(a[j].fi >= (x + 1) / 2 && ma < a[j].se + y) {
					r1 = i, r2 = j, ma = a[j].se + y, ty = o;
				}
			}
		}
	}
	if(ma == -1) {
		cout << "Forget about apartments. Live in the dormitory." << endl;
	} else if(r2) {
		cout << "You should rent the apartment #" << r1 << " with the friend #" << r2 << ".";
	} else {
		cout << "You should rent the apartment #" << r1 << " alone.";
	}
	return 0;
}
