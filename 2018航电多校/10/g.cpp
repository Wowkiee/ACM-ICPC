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

const int N = 12;

int f[N], g[N];

int solve(int n) {
	int p[20];
	rep(i,0,n)p[i]=i;
	int ans=0;
	do {
		int flag=1;
		rep(i,1,n)if(p[i]==(p[i-1]+1)%n)flag=0;
		if(p[0]==(p[n-1]+1)%n)flag=0;
		ans+=flag;
	}while(next_permutation(p,p+n));
	return ans / n;
}
int main() {
	rep(i, 1, N) dd(i), de(solve(i));
	return 0;
}
