#pragma GCC optimize(Ofast)
#pragma GCC optimize(unroll-loops)
#pragma GCC target(sse2)
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

unsigned int ans[10];
int cnt, p[100], n[10], len, T, A, B, C, ss;
bool ok;
int main() {
	//std::ios::sync_with_stdio(0);
	//std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T) cin >> n[cas];	
		for (int s = 3; s * s + 1 <= 1e9 * 2; s += 2) {
			len = 0;
			ss = s;
			for (int x = 3; x * x <= ss; x ++) {
				if (ss % x == 0) p[++len] = x;
				while (ss % x == 0) ss /= x;
			}
			if (ss > 1) p[++len] = s;
			for (int t = 1; t < s && s * s + t * t <= 1e9 * 2; t += 2) {
				ok = 1;
				rep(i, 1, len + 1) if (t % p[i] == 0) {ok = 0; break;}
				if (!ok) continue;
				//A = s * t;
				//B = (s * s - t * t) / 2;
				//C = (s * s + t * t) / 2;
				//if (n / C == 1) cnt++;
				//ans[0] += n[0] / C;
				/*if (C > 1e9 / 2) {
					rep(i, 0, T) ans[i] += n[i] >= C;
				}else {
					rep(i, 0, T) ans[i] += n[i] / C;
				}*/
				//de(C);
				//if (C < 1e8) rep(i, 0, T) ans[i]++;
			}
		}
	rep(i, 0, T) cout << ans[i] << endl;
	return 0;
}
