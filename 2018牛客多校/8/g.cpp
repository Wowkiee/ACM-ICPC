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
const ll mod=1e9+7;
ll kpow(ll a,ll b) {
	ll ans=1;
	while(b) {
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
ll solve(ll n)
{
	ll s1=n*n%mod*(n+1)%mod*kpow(2,mod-2)%mod;
	ll s2=n*(n+1)%mod*(2*n+1)%mod*kpow(6,mod-2)%mod;
	return (s1-s2+mod)%mod;
}
int main() {
	ll n;scanf("%lld",&n);
	ll s1=solve(n-2)*n%mod*kpow(4,mod-2)%mod+n*(n-3)%mod*kpow(2,mod-2)%mod+1;
	cout<<s1%mod<<endl;
	return 0;
}
