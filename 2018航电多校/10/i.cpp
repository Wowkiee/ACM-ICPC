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
int sub(int a, int b) {if((a -= b) < P) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---

const int N = 2e7 + 7;
int n, M, f[N], phi[N], p[N], T;
ll s[N];

void prime(int n) {
	phi[1] = 1;
	rep(i, 2, n+1) {
		if (!f[i]) {
			p[++M] = i;
			f[i] = i;
			phi[i] = i - 1;
		}
		for (int j = 1, k; j <= M && p[j] <= f[i] && i * p[j] <= N; j++){
			f[k = i * p[j]] = p[j];
			if (p[j] < f[i]) {
				phi[k] = phi[i] * phi[p[j]];	
			}else {
				phi[k] = phi[i] * p[j];
			}
		}
	}
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	n = 2e7;
	prime(n);
	rep(i, 2, n+1) {
		if (i % 2 == 0) s[i] = s[i-1] + phi[i];
		else s[i] = s[i-1] + phi[i] / 2;
	}
	cin >> T;
	rep(cas, 0, T) {
		cin >> n;
		cout << s[n] << endl;
	}
	return 0;
}
