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

const int N = 1e5 + 7;
int cnt[N], d[N], ans1, ans2, n, m, u, v, sum, T;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n >> m;
		if (m == 0) {
			cout << n << " " << 1 << endl;
			continue;
		}
		rep(i, 1, n+1) d[i] = 0;
		rep(i, 0, n+1) cnt[i] = 0;
		rep(i, 0, m) {
			cin >> u >> v;
			d[u]++;d[v]++;
		}
		rep(i, 1, n+1) cnt[d[i]]++;
		sum = cnt[n];
		for (int x = n; x >= 1; x--) {
			sum += cnt[x-1];
			if (sum >= x) {
				ans1 = sum - x + 1;
				if (cnt[x-1] - (sum - x)> 0) ans2 = cnt[x-1] - (sum - x);
				else ans2 = 1 + cnt[x];
				break;
			}
		}
		cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}
