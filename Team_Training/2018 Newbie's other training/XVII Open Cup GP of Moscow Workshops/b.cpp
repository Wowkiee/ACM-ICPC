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
#define pw(a) (1ll << (a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 1e6 + 7;
int ma, f[N], a[N], s[N], M, n, p[N], w[N], mi, u[N];
int d[] = {-1,-1,1,1,-1,-1,1,-1,1,-1,1,1,-1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,-1,-1,-1,1,1,1,1,1,1,1,-1,-1,-1,-1,1,-1,-1,1,1,-1,1,-1,-1,1,-1,-1,1,1,-1,1,-1,-1,1,-1,-1,1,-1,1,1,1,1,-1,-1,-1,1,-1,-1,1,-1,-1,1,1,1,-1,1,1,1,-1,-1,-1,1,1,1,1,1,1,1,1,1,-1,1,1,1,1,-1,1,1,1,-1,1,1,1,1,1,-1,1,-1,1,1,-1,1,-1,-1,1,-1,-1,-1,1,1,-1,1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,1,1,1,-1,-1,-1,1,-1,-1,-1,1,-1,1,-1,-1,-1,1,1,1,-1,-1,-1,1,-1,-1,-1,1,-1,1,-1,-1,1,-1,1,-1,-1,-1,1,-1,-1,1,-1,-1,1,1,1,1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,1,1,-1,1,-1,-1,1,-1,1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,1,-1,-1,1,1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,1,1,-1,1,1,1,1,1,1,1,-1,1,1,-1,1,-1,-1,-1,-1,1,-1,-1,1,1,-1,-1,-1,1,1,-1,1,1,1,1,1,-1,1,-1,-1,1,1,1,-1,-1,1,1,1,1,-1,-1,-1,-1,1,1,-1,1,-1,-1,1,1,-1,-1,-1,-1,-1,1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,1,1,1,-1,1,1,-1,1,1,1,1,1,1,1,-1,1,1,1,1,-1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,-1,-1,-1,-1,1,1,-1,-1,1,1,-1,1,1,-1,1,-1,-1,1,1,-1,-1,1,-1,-1,-1,-1,1,1,1,-1,1,1,1,1,1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,1,-1,1,-1,1,-1,-1,1,1,1,-1,-1,-1,1,1,-1,-1,-1,-1,1,-1,1,1,-1,1,1,-1,-1,-1,-1,1,1,-1,1,1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,1,1,-1,-1,-1,-1,1,-1,1,1,1,1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,1,-1,1,1,-1,1,1,1,1,1,1,-1,1,1,1,-1,1,-1,-1,1,-1,1,1,-1,1,-1,1,1,1,-1,1,1,-1,1,-1,-1,1,1,-1,1,-1,1,1,1,1,-1,1,1,1,1,1,-1,-1,-1,-1,1,-1,-1,1,1,-1,1,1,-1,1,1,-1,-1,-1,1,-1,-1,-1,-1,-1,1,1,1,-1,-1,1,-1,1,1,-1,1,1,-1,1,1,-1,-1,-1,-1,1,1,1,1,-1,-1,1,1,1,-1,1,1,1,1,1,1,1,-1,-1,-1,1,-1,1,1,1,-1,1,1,1,-1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,1,-1,1,-1,-1,-1,-1,1,1,-1,1,-1,-1,-1,1,-1,1,-1,-1,1,-1,1,1,-1,1,-1,-1,-1,-1,1,1,-1,-1,1,-1,1,-1,-1,-1,1,1,1,-1,1,-1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,1,1,1,-1,1,1,-1,1,1,-1,-1,-1,-1,1,-1,-1,1,1,1,1,1,1,1,1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,1,1,-1,1,1,1,-1,-1,1,1,-1,1,-1,-1,-1,-1,-1,-1,1,1,1,1,1,1,-1,1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,1,-1,-1,1,-1,-1,-1,-1,1,-1,1,1,1,1,1,-1,-1,-1,-1,1,1,-1,1,-1,1,1,-1,1,1,-1,1,1,1,1,1,1,-1,1,1,-1,-1,-1,1,-1,1,1,1,-1,1,1,-1,-1,1,1,1,-1,-1,1,1,1,-1,-1,-1,1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,1,1,-1,1,1,-1,-1,1,-1,1,-1,-1,-1,-1,1,1,1,-1,1,1,-1,1,-1,-1,1,-1,1,-1,1,1,1,1,-1,1,1,-1,-1,1,-1,1,-1,1,1,-1,-1,1,-1,1,1,-1,-1,-1,-1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,1,1,-1,1,-1,1,1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,1,-1,-1,-1,1,-1,1,-1,-1,1,1,-1,1,-1,1,1,1,-1,-1,1,1,1,-1,-1,1,-1,1,-1,-1,1,-1,-1,1,-1,-1,-1,1,1,-1,-1,-1,-1,1,1,1,-1,-1,1,-1,1,1,1,1,1,1,1,-1,1,1,1,1,1,1,1,-1,1,1,1,1,1,1,1,1,1,1,-1,1,1,1,-1,1,1,-1,1,-1,1,1,1,-1,1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,1,1,-1,1,-1,-1,-1,-1,1,-1,-1,-1,1,1,1,1,-1,1,-1,1,-1,1,1,1,1,-1,1,-1,1,-1,1,1,-1,1,-1,1,-1,1,1,-1,-1,-1,-1,1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,-1,1,-1,1,-1,-1,1,1,1,-1,-1,1,1,1,1,1,-1,-1,1,-1,1,-1,1,1,-1,1,1,1,1,1,1,1,-1,-1,1,-1,-1,1,-1,-1,1,-1,1,1,-1,1,1,-1,1,-1,1,-1,1,-1,-1,-1,1,1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,1,-1,1,1,1,-1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,1,-1,1,1,-1,1,-1,-1,1,-1,-1,1,1,1,-1,-1,-1,1,-1,1,1,-1,-1,1,-1,1,-1,-1,-1,1,1,1,-1,1,-1,-1,-1,-1,1,1,-1,1,1,1,-1,-1,-1,1,-1,-1,-1,-1,1,1,-1,1,1,-1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,1,-1,-1,1,-1,1,-1,1,-1,1,-1,-1,-1,1,-1,-1,-1,1,1,-1,1,-1,1,-1,1,-1,-1,1,-1,-1,-1,1,-1,-1,-1,1,1,1,1,1,-1,1,1,1,1,-1,1,1,-1,-1,-1,1,1,1,-1,-1,-1,1,-1,1,1,1,1,-1,1,-1,1,1,1,1,1,1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,-1,-1,-1,-1,1,-1,-1,1,-1,1,-1,-1,-1,-1,1,1,-1,1,1,1,1,1,1,1,-1,-1,-1,1,-1,1,-1,1,-1,-1,1,1,1,1,-1,1,-1,-1,-1,-1,1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,1,-1,-1,-1,-1,1,1,-1,1,1,1,1,1,-1,-1,-1,1,-1,1,1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,1,1,-1,1,1,1,-1,1,1,-1,-1,-1,1,-1,1,1,-1,1,-1,-1,-1,-1,-1,1,1,1,-1,1,-1,-1,1,-1,1,1,1,-1,-1,1,-1,1,1,1,1,1,1,-1,-1,1,1,1,-1,-1,1,1,1,1,1,-1,1,1,1,1,1,-1,1,1,1,1,1,-1,1,-1,1,1,1,-1,1,-1,1,1,1,-1,-1,-1,1,-1,-1,1,1,-1,-1,-1,1,-1,1,-1,1,1,1,1,1,-1,1,1,1,1,1,-1,1,1,-1,1,1,1,-1,-1,1,-1,-1,-1,-1,1,1,-1,1,-1,-1,-1,-1,-1,1,-1,1,-1,1,1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,-1,-1,1,-1,1,-1,-1,-1,1,1,1,1,-1,-1,1,-1,-1,-1,1,-1,1,1,1,-1,1,-1,-1,-1,1,-1,1,-1,1,-1,1,-1,-1,1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,1,-1,-1,1,1,-1,-1,1,-1,-1,-1,1,-1,-1,1,-1,-1,1,1,1,-1,-1,1,-1,-1,1,-1,1,1,-1,1,1,1,1,-1,-1,1,-1,-1,1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,1,1,1,1,1,1,-1,-1,-1,1,1,1,1,1,1,1,-1,-1,-1,1,1,1,-1,-1,-1,1,1,-1,1,-1,1,-1,1,1,-1,1,1,1,1,-1,-1,-1,-1,1,1,1,-1,1,1,1,-1,-1,-1,-1,1,1,1,1,1,-1,1,-1,-1,-1,-1,-1,-1,1,1,1,-1,-1,1,1,1,1,1,1,1,-1,-1,1,-1,1,-1,1,-1,1,-1,-1,1,1,1,1,-1,-1,-1,1,-1,-1,1,1,1,1,-1,-1,-1,-1,-1,1,1,1,1,1,1,-1,1,-1,1,-1,1,1,1,1,-1,-1,-1,1,1,-1,-1,1,-1,1,1,-1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,-1,1,1,1,1,1,1,1,-1,1,-1,1,1,-1,-1,-1,1,-1,1,1,-1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,1,1,-1,-1,-1,1,1,-1,-1,-1,-1,1,-1,1,-1,-1,1,1,-1,-1,1,1,1,1,1,1,1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,-1,-1,1,1,-1,-1,1,-1,-1,-1,-1,1,-1,1,-1,1,1,1,-1,1,-1,-1,1,-1,-1,1,1,-1,1,-1,-1,1,1,1,1,-1,-1,-1,-1,-1,-1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,1,-1,-1,-1,1,-1,1,-1,-1,1,1,-1,1,1,-1,-1,-1,-1,-1,1,1,1,-1,-1,1,1,1,1,1,1,-1,1,1,1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,1,-1,1,-1,1,1,-1,1,1,1,1,-1,-1,-1,1,1,-1,1,1,-1,-1,-1,1,-1,1,1,-1,1,1,-1,-1,-1,1,-1,1,-1,1,1,1,1,1,1,1,1,-1,-1,1,-1,1,1,1,-1,1,-1,1,-1,-1,-1,-1,1,1,-1,-1,1,1,1,1,-1,1,-1,1,1,-1,-1,-1,1,1,1,-1,1,1,1,1,1,-1,-1,-1,1,-1,1,-1,1,1,-1,1,-1,-1,1,1,1,-1,1,-1,-1,1,1,1,1,1,1,-1,-1,-1,1,1,-1,1,-1,-1,1,-1,1,1,-1,-1,-1,-1,-1,-1,1,1,-1,1,1,-1,-1,-1,1,1,1,1,1,1,-1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,1,-1,-1,-1,1,-1,1,-1,-1,1,1,-1,-1,1,-1,-1,-1,1,1,1,1,1,-1,1,-1,-1,-1,-1,1,-1,1,1,-1,1,1,1,1,1,1,1,1,1,1,-1,1,1,1,1,1,1,1,-1,-1,1,-1,-1,1,-1,-1,1,1,-1,1,-1,-1,1,-1,1,-1,-1,-1,1,1,-1,1,1,-1,-1,-1,1,1,1,-1,-1,-1,1,1,1,1,1,1,-1,1,-1,1,-1,1,1,-1,-1,1,1,-1,1,1,-1,1,1,1,1,-1,-1,1,1,-1,-1,1,-1,-1,1,-1,1,-1,1,-1,-1,-1,-1,1,-1,-1,1,-1,1,-1,-1,1,-1,-1,1,1,1,-1,-1,1,-1,-1,1,-1,-1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,1,1,1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,-1,1,1,1,-1,-1,-1,1,-1,1,-1,-1,1,-1,1,-1,-1,1,1,1,-1,-1,1,1,1,1,-1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,1,1,1,-1,-1,1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,-1,1,-1,1,1,-1,1,-1,-1,-1,1,1,-1,-1,-1,-1,1,-1,1,-1,1,1,1,1,1,1,-1,1,1,1,-1,1,1,1,1,1,1,-1,1,-1,1,1,1,1,1,1,1,1,1,1,1,-1,-1,-1,1,1,1,1,-1,-1,-1,-1,-1,-1,1,1,-1,-1,1,1,1,1,-1,1,1,1,1,1,1,1,1,-1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,-1,1,1,-1,1,1,1,1,1,1,-1,1,1,-1,1,1,-1,1,1,1,1,-1,-1,1,1,-1,1,-1,-1,-1,1,1,1,-1,-1,-1,1,-1,1,-1,1,1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,-1,1,1,1,1,1,1,1,-1,-1,1,-1,1,-1,1,1,-1,-1,1,1,-1,-1,-1,1,-1,1,1,-1,-1,1,1,1,-1,1,1,1,1,1,1,1,-1,-1,1,1,1,1,1,1,-1,1,-1,-1,1,-1,-1,1,-1,-1,1,-1,-1,-1,1,-1,1,-1,1,1,1,1,1,-1,1,1,1,1,1,1,1,1,1,1,1,-1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,1,1,1,1,1,-1,-1,1,1,1,1,1,1,1,-1,1,1,1,1,1,1,1,1,-1,-1,1,-1,1,-1,-1,1,1,-1,1,-1,-1,1,1,-1,1,1,1,1,1,1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,-1,-1,1,-1,1,-1,1,-1,-1,1,1,-1,1,1,-1,1,-1,1,1,1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,-1,1,-1,1,1,-1,1,-1,-1,1,-1,-1,1,1,-1,1,1,1,1,-1,1,1,1,1,1,1,1,1,1,1,1,-1,1,-1,1,-1,-1,-1,-1,1,-1,1,-1,1,-1,-1,-1,1,1,1,1,-1,-1,1,1,1,-1,-1,1,1,-1,1,1,-1,-1,1,-1,-1,1,-1,-1,-1,-1,-1,-1,1,-1,1,1,1,1,-1,1,1,-1,-1,1,1,-1,1,-1,-1,1,1,-1,-1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1,1,1,1,1,1,-1,1,1,-1,-1,-1,1,1,1,-1,-1,1,-1,1,-1,-1,1,-1,-1,1,1,-1,1,1,-1,-1,1,-1,-1,1,1,1,1,1,1,1,-1,1,-1,1,1,-1,-1,1,1,1,1,1,-1,-1,1,1,1,-1,-1,-1,1,-1,1,1,-1,1,1,1,-1,1,1,-1,-1,1,-1,-1,1,-1,1,1,-1,-1,1,1,-1,1,-1,-1,1,-1,-1,1,1,1,-1,-1,1,-1,1,1,1,1,-1,-1,1,-1,1,1,-1,-1,-1,1,-1,1,-1,-1,-1,-1,-1,-1,1,1,-1,1,1,-1,1,1,1,1,-1,1,1,1,1,1,1,-1,1,-1,1,-1,1,1,-1,-1,1,-1,1,-1,-1,1,1,-1,1,-1,-1,-1,1,1,1,-1,1,-1,1,1,1,1,1,-1,1,-1,-1,-1,1,1,-1,1,-1,1,-1,-1,1,1,-1,-1,-1,1,-1,-1,-1,1,1,1,-1,-1,-1,1,1,1,-1,-1,-1,1,1,-1,-1,1,-1,-1,1,1,-1,-1,-1,-1,-1,1,-1,1,1,-1,1,1,1,1,1,1,-1,-1,1,-1,1,1,1,1,-1,-1,1,1,-1,-1,1,-1,-1,1,-1,-1,1,-1,1,-1,-1,1,1,1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,1,1,1,1,-1,-1,-1,1,1,1,1,1,-1};
void prime(int n) {
	u[1] = 1;
	rep(i, 2, n+1) {
		if (!f[i]) {
			p[++M] = i;
			f[i] = i;
			u[i] = -1;
		}
		for (int j = 1, k; j <= M && p[j] <= f[i] && i * p[j] <= n; j++) {
			
			f[k = i * p[j]] = p[j];
			if (p[j] < f[i]) u[k] = u[i] * u[p[j]];
			else u[k] = 0;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	n = 1000000;
	prime(n);
	s[1] = a[1] = 1;
	int cnt = 0, t = 30000;
//de(u[10]);
	rep(i, 1, 19)de(u[i]);
	rep(i, 1, t+1) if (p[i] <= t && i <= M) a[p[i]] = d[i-1];else break;
	rep(i, 2, n+1) {
		if (i == f[i]) {
			if (i <= t) continue;
			//if (s[i-1] >= 0) {
			//	a[i]= -1;
			//}else a[i] = 1;
			//if (s[i-1] >= 15) a[i] = -1;else 
			//if (i <= 40000) a[i] = -1;else
			//if (cnt % 3 == 0 || cnt % 11 == 0 || cnt % 23 == 0) a[i] = -1;else 
			int w = s[i-1], ww = 0;
			for (int j = i + i; j <= n; j += i) { 
				w += a[j / i];
				ww = max(w, ww);
			}
			if (ww > 1) a[i] = - 1;else a[i] = 1;
		}
		else {
			/*int tmp = i;
			while (tmp != f[tmp]) tmp /= f[tmp];
			if (tmp > 1000) a[i] = a[i / tmp];else
			*/
			a[i] = a[f[i]] * a[i / f[i]];
		}
		//s[i] = s[i-1] + a[i];
		s[i] = s[i-1] + u[i];
		ma = max(s[i], ma);
		mi = min(s[i], mi);
	}
	rep(i, 1, M+1) if (p[i] > t){
		int w = 0, ww;
		for (int j = p[i]; j <= n; j += p[i]) {
			w += a[j];
			ww = -w;
			
		}
	}
/*	rep(i, 1, M+1) {
		for (int j = p[i]; j <= n; j += p[i]) w[i] += a[j];
		de(w[i]);
	} */

	de(s[n]);
	de(ma);
	de(mi);
	return 0;
}