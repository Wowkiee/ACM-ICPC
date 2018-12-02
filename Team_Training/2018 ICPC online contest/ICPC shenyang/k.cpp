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
int dig[10]={0,1,1,2,3,5,7};
int pe[10]={0,1,2,3,4,5,6};
int Pow10[10]={1};
vector<int> V;
char s[105];
int OK[1100000],ok[1100000];
bool isprime(int n) {
	if(OK[n]==1)return true;
	else if(OK[n]==-1)return false;
	for(int i=2;i*i<=n;i++)if(n%i==0) {
		OK[n]=-1;
		return false;
	}
	OK[n]=1;
	return true;
}
bool isok(int n,int len) {
	if(ok[n]==1)return true;
	if(ok[n]==-1)return false;
	rep(i,1,1<<len) {
		int ans=0,_n=n;
		int p=0;
		rep(j,0,len) {
			if((i>>j)&1) {
				ans+=Pow10[p++]*(_n%10);
			}
			_n/=10;
		}
		if(!isprime(ans)) {
			ok[n]=-1;
			return false;
		}
	}
	ok[n]=1;
	return true;
}
int main() {
	rep(i,1,8)Pow10[i]=Pow10[i-1]*10;
	do {
		int ans=0;
		rep(i,1,7) {
			ans=ans*10+dig[pe[i]];
			if(isok(ans,i))V.pb(ans);
		}
	}while(next_permutation(pe+1,pe+7));
	sort(all(V));V.erase(unique(all(V)),V.end());
	int T;scanf("%d",&T);rep(cas,0,T) {
		scanf("%s",s);int now=0;
		if(strlen(s)>6)now=1000000;
		else for(int i=0;s[i];i++)now=now*10+s[i]-'0';
		int pos=upper_bound(all(V),now)-V.begin()-1;
		printf("Case #%d: %d\n",cas+1,V[pos]);
	}
	return 0;
}
