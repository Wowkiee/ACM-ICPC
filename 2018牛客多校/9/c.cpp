#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b-1);i>=a; i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---
const int N = 1e5 + 7;
const int mod = 1e9 + 7;
const ll inv2 = 500000004;
int data[N<<2];
ll jc[N],njc[N];
ll kpow(ll a,ll b) {
	ll ans=1;
	while(b) {
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
ll C(ll a,ll b) {
	return jc[a]*njc[b]%mod*njc[a-b]%mod;
}
int line;
int Ans,now,pos;
int n;
int solve(int k) {
	de(k);de(pos);
	Ans=Ans*2%mod;
	now=(now*2+1)%mod;
	line++;
	if(k==1)now=now-C(line,pos);
	else pos++;
	de(now);de(Ans);
	return 1LL*(Ans-now+mod)*kpow(Ans,mod-2)%mod;
}
int main() {
	jc[0]=1;
	rep(i,0,N)jc[i]=jc[i-1]*i%mod;
	njc[N-1]=kpow(jc[N-1],mod-2);
	per(i,0,N-1)njc[i]=njc[i]*(i+1)%mod;
	scanf("%d",&n);
	int c[2]={0},a,p;
	for(p=0;c[0]<n&&c[1]<n;p++) {
		scanf("%d",&a);
		c[a]++;data[p]=a;
	}
	vector<int> V;
	line=n+n-c[0]-c[1]-1;
	Ans=kpow(2,line-2+mod),now=0,pos=0;
	//dd(Ans);dd(now);de(pos);
	per(i,0,p) {
		if(data[i]) {
			int ans=Ans;
			ans=ans-solve(c[0]+c[1]-1-c[0]-c[1]);
			if(ans<0)ans+=mod;
			de(ans);
			V.pb(ans);
			c[1]--;
		}
		else {
			int ans=solve(c[0]+c[1]-(c[0]-1)-c[1]);
			if(ans<0)ans+=mod;
			V.pb(ans);
			c[0]--;
		}
	}
	per(i,0,sz(V))cout<<V[i]*kpow(2,2*n-1)%mod<<endl;
	return 0;
}
