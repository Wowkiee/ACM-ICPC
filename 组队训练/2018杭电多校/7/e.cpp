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


const int maxn = 1e6+7;
int mod,N,M,f[maxn],g[maxn],h[maxn],p[maxn]; //f[n]为n的最小质因子，g[n]=f[n]^k，phi[n]为欧拉函数，u[n]为莫比乌斯函数，h[n]为一般积性函数 
ll inv[maxn], w[maxn];


void prime(int N)
{
	M = 0;
	h[1]=1; //1的时候特判
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	for (int i=2; i<=N; i++)
	{
		if (!f[i]) p[++M]=i,f[i]=g[i]=i,h[i]=i * inv[i - 1] % mod; //质数的时候特判 
		for (int j=1,k; j<=M&&p[j]<=f[i]&&i*p[j]<=N; j++)
		{
			f[k=i*p[j]]=p[j];
			if (p[j]<f[i]) g[k]=p[j],h[k]=1ll*h[i]*h[p[j]]%mod;
			else g[k]=g[i]*p[j],h[k]=1ll * h[i/g[i]] * f[i] %mod * inv[f[i] - 1] % mod ; /*质数次幂特判*/
		}
	}
}

void get_inv(int n) {
	inv[1] = 1;
	rep(i, 2, n+1) inv[i] = (mod - mod / i) * inv[mod % i] % mod;	
}

int n, m, ans, S, T;


int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T){
		cin >> n >> m >> mod;
		S = max(n, m);
		get_inv(S);
		prime(S);
		ans = 0;
		/*rep(i, 1, n+1)	
			rep(j,1, m+1) ans +=h[__gcd(i,j)],ans %=mod;
		de(ans);
		ans = 0;*/
		for (int i = S;i >= 1;i--) {
			w[i] = 1ll * (n / i) % mod * (m / i) % mod;
			for (int j = i + i; j <= S; j += i)	w[i] = (w[i] - w[j]) % mod;
			ans = (ans + h[i] * w[i]) % mod;
		}
		if (ans < 0) ans += mod;
		cout << ans << endl;
	}
	return 0;
}
