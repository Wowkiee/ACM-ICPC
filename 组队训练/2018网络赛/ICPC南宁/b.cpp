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

const int N = 1e5 + 6;
ll ans, sum;
int p, cnt[N], l[N], r[N], n, m, k, x, y, T;
vi g[105];

ll cal(int x) {return 1ll * x * (x + 1) / 2;}

void init(){
	rep(i, 1, m+1) g[i].clear();
	ans = 0;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n >> m >> k;
		init();
		rep(i, 0, k) {
			cin >> x >> y;
			g[y].pb(x);
		}
		rep(i, 1, m+1) {
			rep(j, i, m+1) 
				rep(k, 0, sz(g[j])) cnt[g[j][k]]++;
			cnt[0] = 1;
			cnt[n+1] = 1;
			rep(j, 1, n+2) if (cnt[j-1]) l[j] = j - 1; else l[j] = l[j-1];
			per(j, 0, n+1) if (cnt[j+1]) r[j] = j + 1; else r[j] = r[j+1];
			sum = 0;
			rep(j, 1, n+2) if (cnt[j]){
				//dd(j);de(l[j]);
				sum += cal(j - l[j] - 1);
			}
			//de(sum);
			per(j, i, m+1) {
				ans += sum;
				rep(k, 0, sz(g[j])) {
					p = g[j][k];
					cnt[p]--;
					if (!cnt[p]) {
						sum -= cal(p - l[p] - 1) + cal(r[p] - p - 1);
						sum += cal(r[p] - l[p] - 1);
						l[r[p]] = l[p];
						r[l[p]] = r[p];
					}
				} 
			}
			cnt[0] = cnt[n+1] = 0;
			//rep(j, 1, n+1) assert(cnt[i] == 0);
		}
		cout << "Case #" << cas+1 << ": " << ans << endl;
	}
	return 0;
}
