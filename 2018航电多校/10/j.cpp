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
ll ma1[50], ma2[50], a[N][10], b[N][10], ans, k, n, m, u[N], v[N], tmp, s, w, T;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T) {
		//memset(ma2, 0, sizeof(ma2));
		//memset(ma1, 0, sizeof(ma1));
		cin >> n >> m >> k;
		s = pw(k);
		rep(i, 0, s) {
			ma2[i] = ma1[i] = -pw(60);
		}
		rep(i, 1, n+1) {
			cin >> u[i];
			rep(j, 0, k) cin >> a[i][j]; 
		}		
		rep(i, 1, m+1) {
			cin >> v[i];
			rep(j, 0, k) cin >> b[i][j]; 
		}
		rep(i, 1, n+1) {
			rep(j, 0, s) {
				tmp = 0;
				rep(l, 0, k) if (pw(l) & j) tmp += a[i][l];else tmp -= a[i][l];
				ma1[j] = max(ma1[j], tmp + u[i]);
			}
		}		
		rep(i, 1, m+1) {
			rep(j, 0, s) {
				tmp = 0;
				rep(l, 0, k) if (pw(l) & j) tmp += b[i][l];else tmp -= b[i][l];
				ma2[j] = max(ma2[j], tmp + v[i]);
			}
		}
		ans  = -pw(60);
		rep(j, 0, s) {
			ans =  max(ans,ma1[j] + ma2[(s-1)^j]);
		}
		cout << ans << endl;
	}
	return 0;
}
