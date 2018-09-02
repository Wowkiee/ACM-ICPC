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
map<int,int> M[N];
int data[N<<2];
ll kpow(ll a,ll b) {
	ll ans=1;
	while(b) {
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(int n) {
	rep(i,0,n+1)M[n][i]=kpow(2,n*2-1),M[i][i]=0;
}
int solve(int a,int b) {
	if(a<b)return (mod-solve(b,a))%mod;
	if(M[a].count(b))return M[a][b];
	else return M[a][b]=inv2*(solve(a+1,b)+solve(a,b+1))%mod;
}
int main() {
	srand(time(0));
	int n;n=1000;//scanf("%d",&n);
	init(n);
	int c[2]={0},a,p;
	for(p=0;c[0]<n&&c[1]<n;p++) {
		a=rand()&1;
		c[a]++;data[p]=a;
	}
	vector<int> V;
	per(i,0,p) {
		if(data[i]) {
			int ans=solve(c[0],c[1]-1)-solve(c[0],c[1]);
			if(ans<0)ans+=mod;
			V.pb(ans);
			c[1]--;
		}
		else {
			int ans=solve(c[0],c[1])-solve(c[0]-1,c[1]);
			if(ans<0)ans+=mod;
			V.pb(ans);
			c[0]--;
		}
	}
	per(i,0,sz(V))cout<<V[i]<<endl;
	return 0;
}
