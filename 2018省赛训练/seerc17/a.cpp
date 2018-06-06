#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define per(i,l,r) for(int i=(r)-1;i>=(l);i--)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----

const int N = 1e5+5, K = 3e2 + 7;
const int mod = 1e9+7;
int n, k, f[N][K], w[N];
char a[N], b[N];


void upd(int &x,int y){ if ((x += y) >= mod) x -= mod; }

int main() {
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	scanf("%d%d", &k, &n);
	rep(i, 0, 26) scanf("%d", &w['A' + i]);
	if (k) scanf(" %s", a + 1);
	if (n) scanf(" %s", b + 1);
	rep(i, 0, n + 1) f[i][0] = 1;
	rep(i, 1, n + 1) rep(j, 1, k + 1) {
		f[i][j] = f[i - 1][j];
		if (b[i] == a[j] && i - w[a[j - 1]] - 1 >= 0) 
			upd(f[i][j], f[i - w[a[j - 1]] - 1][j - 1]);	
	}
	printf("%d", f[n][k]);
	return 0;
}
