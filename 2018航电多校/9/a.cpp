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

const int N = 1010;

int _;
int a[N], b[N][N], hang[N], lie[N];

int solve(int n, int m) {
	rep(i, 1, n*m+1) a[i] = i;
	int ans = 0;
	do {
		int p = 0;
		rep(i, 1, n+1) rep(j, 1, m+1) b[i][j] = a[++p];
		int cnt = 0;
		fill_n(hang+1, n, 0);
		fill_n(lie+1, m, 0);
		rep(i, 1, n+1) rep(j, 1, m+1) {
			hang[i] = max(hang[i], b[i][j]);
			lie[j] = max(lie[j], b[i][j]);
		}
		rep(i, 1, n+1) rep(j, 1, m+1) {
			if(b[i][j] == hang[i] && b[i][j] == lie[j]) ++cnt;
		}
		if(cnt == 1) ++ans;
	} while(next_permutation(a+1, a+1+n*m));
	return ans;
}

int jc(int n) {
	int r = 1;
	rep(i, 1, n+1) r *= i;
	return r;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	rep(i, 1, 10) {
		for(int j = 1; i * j < 12; ++j) dd(i), dd(j), de(solve(i, j));
		cout << endl;
	}
	return 0;
}
