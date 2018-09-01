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

const int N = 2e7 + 7;
int n, T, M, f[N], g[N], p[N];
char cnt[N];
int h[N];

void prime(int n) {
	rep(i, 2, n+1) {
		if (!f[i]) {
			p[++M] = i;
			f[i] = g[i] = i;
			cnt[i] = 1;
		}
		for (int j = 1, k; j <= M && p[j] <= f[i] && i * p[j] <= n; j++) {
			f[k = i * p[j]] = p[j];
			if(p[j] < f[i]) {
				g[k] = p[j];
				cnt[k] = 1;
			}else {
				g[k] = g[i] * p[j];
				cnt[k] =  cnt[i] + 1;
			}
		}
	}
	h[1] = 1;
	rep(i, 2, n+1) {
		if (g[i] == i) {
			if (cnt[i] >= 3) h[i] = 0;
			else if (cnt[i] == 2) h[i] = 1;
			else h[i] = 2;
		}else{
			h[i] = h[i / g[i]] * h[g[i]];
		}
	}
	rep(i, 1, n+1) h[i] += h[i-1];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	prime(2e7);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n;
		cout << h[n] << endl;
	}
	return 0;
}
