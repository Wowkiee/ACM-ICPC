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
const int N=22;
int a[N],b[N],pre[N];
ll Ans[1<<N];
int main() {
	int n;scanf("%d",&n);
	rep(i,0,n) {
		int s;
		scanf("%d%d%d",a+i,b+i,&s);
		while(s--) {
			int a;scanf("%d",&a);a--;pre[i]|=pw(a);
		}
	}
	ll ans=0;
	rep(i,1,pw(n)) {
		Ans[i]=-1e18;
		ll cc=__builtin_popcount(i);
		rep(j,0,n)if(i&(1<<j)) {
			int z=i^(1<<j);
			if((pre[j]&z)==pre[j])Ans[i]=max(Ans[i],Ans[z]+cc*a[j]+b[j]);
		}
		ans=max(ans,Ans[i]);
	}
	cout<<ans<<endl;
	return 0;
}
