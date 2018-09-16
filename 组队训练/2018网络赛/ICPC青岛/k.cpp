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
int cc[40];
int solve(int a) {
	int ans=0;
	while(a)a>>=1,ans++;
	return ans;
}
int main() {
	int T;scanf("%d",&T);while(T--) {
		memset(cc,0,sizeof(cc));
		int n;scanf("%d",&n);
		rep(i,0,n) {
			int a;scanf("%d",&a);
			cc[solve(a)]++;
		}
		int ans=0;
		rep(i,0,40)ans=max(ans,cc[i]);
		cout<<ans<<endl;
	}
	return 0;
}
