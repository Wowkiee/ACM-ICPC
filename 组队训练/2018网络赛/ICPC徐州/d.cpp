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

unordered_map<ll, int> u, S;
map<pair<int, ll> , int> F;
const int N = 1e7+ 7;
int M, f[N], U[N], p[N];
vector<ll> D, tmp;
ll m, n;

void prime(int n){
	U[1] = 1;
	rep(i, 2 , n+1) {
		if (!f[i]) {
			p[++M] = i;
			f[i] = i;U[i] = -1;
		}
		for(int j = 1, k; j <= M && p[j] <= f[i] && i * p[j] <= n; j++) {
			f[k = i * p[j]] = p[j];
			if (p[j] < f[i]) {
				U[k] = U[i] * U[p[j]];
			}
			else {
				U[k] = 0;
			}
		}
	}
	rep(i, 1, n+1) U[i] += U[i-1];
}
 
int _u(ll n) {
	if (n <= 1e7) return U[n];
	if (S.count(n)) return S[n];
	ll res = 1;
	for (ll l = 2, r; l <= n; l = r + 1) {
		r = n / (n / l);
		res -= _u(n / l) * (r - l + 1);
	}
	return S[n] = res;
}

int init(ll n) {
	ll nn = n, cnt;
	for (ll i = 2; i * i <= n; i++) {
		cnt = 0;
		while (n % i == 0) {
			n /= i;
			cnt++;
		}
		if (cnt > 1) return -1;
		if (cnt == 1) tmp.pb(i);
	}
	if (n > 1) tmp.pb(n);
	rep(i, 0, pw(sz(tmp))) {
		ll d = 1;cnt = 0;
		rep(j, 0, sz(tmp)) if (pw(j) & i) d *= tmp[j], cnt++;
		if (cnt & 1) u[d] = -1;else u[d] = 1;
	}
	n = nn;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			D.pb(i);
			if (i * i != n) D.pb(n / i);
		}
	}
	sort(all(D));
	return 1;
}

ll solve(int m, ll n) {
	if (m == 0) return 0;
	if (F.count(mp(m, n))) return F[mp(m, n)];
	ll res = 0;
	rep(i, 0, sz(D)) if(n % D[i] == 0){
		if (D[i] == 1) res += u[D[i]] * _u(m);
		else res += solve(m / D[i], D[i]) * u[D[i]];
	}
	res *= u[n];
	return F[mp(m, n)] = res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> m >> n;
	int ok = init(n);
	prime(1e7);
	if (ok == -1) cout << 0;
	else cout << solve(m, n) << endl;
	/*rep(i, 0, sz(D)) {
		dd(D[i]);de(u[D[i]]);
	}*/
	//ll ans2 = 0;
	//rep(i, 1, m+1) ans2 += U[i * n] - U[i * n - 1];
	//de(ans2);
	return 0;
}
