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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 55, M = 25;

int n, m, k;
int a[N][N];
ll f[N][N][M][M];
vector<ll> sum[N][N];

void upd(ll &a, ll b) {
	if(a < b) a = b;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T; 
	cin >> T;
	while(T--) {
		///
		cin >> n >> m >> k;
		///init
		memset(f, 0, sizeof(f));
		///read
		rep(i, 1, n+1) rep(j, 1, m+1) cin >> a[i][j];
		///get sum
		rep(i, 1, n) rep(j, 1, m+1) {
			sum[i][j].clear();
			rep(t, j+1, m+1) sum[i][j].pb(a[i][t]);
			rep(t, 1, j) sum[i][j].pb(a[i+1][t]);
			sort(all(sum[i][j]));
			reverse(all(sum[i][j]));
			rep(t, 1, sz(sum[i][j])) sum[i][j][t] += sum[i][j][t-1];
		}
		///solve
		f[1][1][0][0] = a[1][1];
		rep(i, 1, n+1) {
			rep(j, 1, m+1) {
				int tx = min(k, i+j-1);
				rep(x, 0, tx+1) {
					int ty = min(k, (i-1)*(m-1)+j-1);
					rep(y, 0, ty+1) {
			//			dd(i);dd(j);dd(x);dd(y);de(f[i][j][x][y]);
						if(j < m) {
							upd(f[i][j+1][x][y], f[i][j][x][y] + a[i][j+1]);
							upd(f[i][j+1][x+1][y], f[i][j][x][y]);
						}
						if(i < n) {
							int to = min(m-1, k-y) + 1;
							rep(c, 0, to) {
								upd(f[i+1][j][x][y+c], f[i][j][x][y] + a[i+1][j] + (c?sum[i][j][c-1]:0));
								upd(f[i+1][j][x+1][y+c], f[i][j][x][y] + (c?sum[i][j][c-1]:0));
							}
						}
					}
				}
			}
		}
		ll ans = 0;
		rep(i, 0, k+1) upd(ans, f[n][m][i][i]);
		cout << ans << endl;
	}
	return 0;
}
