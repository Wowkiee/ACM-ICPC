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

const int N = 20;

int f[N][N];

int main() {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
	rep(i, 1, N) rep(j, 1, N) {
		if(j == 1) f[i][j] = 1;
		else if(i < j) f[i][j] = 0;
		else f[i][j] = f[i-1][j] + f[i-1][j-1] + f[i][j-1];
	}
	rep(i, 1, N) {
		rep(j, 1, i+1) printf("%7d ", f[i][j]);
		cout << endl;
	}
	return 0;
}
