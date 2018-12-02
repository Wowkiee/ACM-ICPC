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
typedef pair<ll,ll> pll;
//---
int sct[25]={0,0,0,0,0,0,10000,36,720,360,80,252,108,72,54,180,72,180,119,36,360,1080,144,1800,3600};
int dir[8][3]={0,1,2,3,4,5,6,7,8,0,3,6,1,4,7,2,5,8,0,4,8,2,4,6};
char s[10];
int flag[10],tab[10];
vector<int> xing,shu,now;
double res;
ll sumt;
void solve() {
	vector<int> Now=now;
	vector<int> rest,S[4];
	S[0].pb(0);
	rep(i,1,10)if(!flag[i])rest.pb(i);
	if(sz(rest)>=1)rep(i,0,sz(rest)) {
		S[1].pb(rest[i]);
		if(sz(rest)>=2)rep(j,i+1,sz(rest)) {
			S[2].pb(rest[i]+rest[j]);
			if(sz(rest)>=3)rep(k,j+1,sz(rest)) {
				S[3].pb(rest[i]+rest[j]+rest[k]);
			}
		}
	}
	do {
		memset(tab,0,sizeof(tab));
		rep(i,0,9)if(isdigit(s[i]))tab[i]=s[i]-'0';
		assert(sz(Now)==sz(xing));
		rep(i,0,sz(Now))tab[xing[i]]=Now[i];
		pll ans=mp(0,1);
		rep(i,0,8) {
			pll Ans=mp(0,0);
			int sum=0,cnt0=0;
			rep(j,0,3) {
				if(tab[dir[i][j]]==0)cnt0++;
				else sum+=tab[dir[i][j]];
			}
			rep(j,0,sz(S[cnt0])) {
				Ans.se++;
				Ans.fi+=sct[sum+S[cnt0][j]];
			}
			if(ans.fi*Ans.se<Ans.fi*ans.se)swap(ans,Ans);
		}
		res+=1.0*ans.fi/ans.se;
		sumt++;
	}while(next_permutation(all(Now)));
}
void dfs(int pos) {
	if(pos==0)solve();
	else {
		if(sz(now)<sz(xing)) {
			// choose
			now.pb(shu[pos]);flag[shu[pos]]=1;
			dfs(pos-1);
			now.pop_back();flag[shu[pos]]=0;
		}
		if(pos+sz(now)>sz(xing)) {
			// not choose
			dfs(pos-1);
		}
	}
}
int main() {
	int T;scanf("%d",&T);while(T--) {
		memset(flag,0,sizeof(flag));
		shu.clear();xing.clear();
		shu.pb(0);
		sumt=0;res=0;
		rep(i,0,3)scanf("%s",s+i*3);
		rep(i,0,9) {
			if(isdigit(s[i]))flag[s[i]-'0']=1;
			else if(s[i]=='*')xing.pb(i);
		}
		per(i,1,10)if(!flag[i])shu.pb(i);
		dfs(sz(shu)-1);
		printf("%.10lf\n",1.0*res/sumt);
	}
	return 0;
}
