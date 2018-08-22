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
typedef unsigned int uint;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < P) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---

const int N = 1e7 + 7;
uint n, M, f[N], phi[N], p[N], T, g[N]; 
short ok2[N], ok3[N];
uint A, B, C, ch2[N], ch3[N], w2[N], w3[N], u[N];
uint fang[N], ff[N];
uint tmp, ans;


void prime(int n) {
	u[1] = phi[1] = 1;
	rep(i, 2, n+1) {
		if (!f[i]) {
			p[++M] = i;
			f[i] = g[i] = i;
			//ok2[i] = 0;
			//ok3[i] = 0;
			ch2[i] = i;
			ch3[i] = i;
			u[i] = -1;
			phi[i] = i - 1;
		}
		for (int j = 1, k; j <= M && p[j] <= f[i] && i * p[j] <= N; j++){
			f[k = i * p[j]] = p[j];
			if (p[j] < f[i]) {
				g[k] = p[j];
				//ok2[k] = 0;
				//ok3[k] = 0;
				ch2[k] = p[j];
				ch3[k] = p[j];
				u[k] = u[i] * u[p[j]];
				phi[k] = phi[i] * phi[p[j]];	
			}else {
				g[k] = g[i] * p[j];
				ok2[k] = ok2[i] ^ 1;
				ok3[k] = ok3[i] + 1;
				if (ok3[k] == 3) ok3[k] = 0;
				ch2[k] = ch2[i] * (ok2[k] == 0 ? f[k] : 1);
				ch3[k] = ch3[i] * (ok3[k] == 0 ? f[k] : 1);
				u[k] = 0;
				phi[k] = phi[i] * p[j];
			}
		}
	}
	w2[1] = w3[1] = 1;
	rep(i, 2, n+1) {
		w2[i] = w2[i / g[i]] * ch2[g[i]];	
		w3[i] = w3[i / g[i]] * ch3[g[i]];
	}
}


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	n = 1e7;
	prime(n);
	cin >> T;
	rep(cas, 0, T) {
		cin >> A >> B >> C;
		//return 0;
		for (uint i = A; i >= 1; i--) {
			fang[i] =  (A / i) * (B / w2[i]) * (C / w3[i]);
			de(B / w2[i]);
			tmp = 0;
			for (uint j = i, z = 1; j <= A; j += i, z++) if (u[z]) tmp += u[z] * fang[j];
			//tmp = 0;
			ans += phi[i] * tmp;
		}
		ans %= pw(30);
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}
