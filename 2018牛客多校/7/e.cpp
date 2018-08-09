#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 1e6+1;

int n, k;
int in[N];
bool g[77][77];

int C(int n, int m) {
	if(n < m) return 0;
	int r = 1;
	rep(i, 0, m) r *= n-i;
	rep(i, 2, m+1) r /= i;
	return r;
}

void init() {
	memset(in, -1, sizeof(in));
	for(int i = 3; ; ++i) {
		int t = C(i, 3);
		if(t >= N) break;
		in[t] = i;
	}
}

bool solve(int k) {
	for(int i = 70; i >= 4; --i) if(C(i, 4) <= k) {
		n = i;
		k -= C(i, 4);
		break;
	}
	if(!k) return 1;
	rep(i, 1, n+1) rep(j, 1, n+1) if(i != j) g[i][j] = 1;
	rep(a, 0, n+1) rep(b, a, n+1) rep(c, b, n+1) rep(d, c, n+1) {
		int t = k - C(a, 3) - C(b, 3) - C(c, 3) - C(d, 3);
		if(t < 0 || in[t] == -1 || in[t] > n) continue;
		int e = in[t];
		if(a>=3) {++n;rep(i, 1, a+1) g[i][n] = g[n][i] = 1;}
		if(b>=3) {++n;rep(i, 1, b+1) g[i][n] = g[n][i] = 1;}
		if(c>=3) {++n;rep(i, 1, c+1) g[i][n] = g[n][i] = 1;}
		if(d>=3) {++n;rep(i, 1, d+1) g[i][n] = g[n][i] = 1;}
		if(e>=3) {++n;rep(i, 1, e+1) g[i][n] = g[n][i] = 1;}
		return 1;
	}
	return 0;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	init();
	rep(i, 1, N) if(!solve(i)) de(i);
	return 0;
}
