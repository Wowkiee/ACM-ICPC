#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----
const int N=100005;
const ll mod=1e9+7;
ll kpow(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
int n;
char str[N];
int main() {
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	while(scanf("%d%s",&n,str)!=EOF)
	{
		ll ans=1;
		int cnt=0;
		int nn=strlen(str);
		rep(i,0,nn)
		{
			if(str[i]=='1')
			{
				ans=ans*(kpow(2,i+n-nn-cnt)%mod+mod-1)%mod*kpow(2,nn-i-1)%mod;
				cnt++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
