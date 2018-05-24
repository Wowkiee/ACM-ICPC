#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int N=200004, p1=1e9+7, p2=1e9+9, se1=131, se2=107;
char s[3][N], str[N];
int cnt, n;
int to[N];
bool ok[N];
ll ba1[N], ba2[N], ha1[3][N], ha2[3][N];
map<pll, bool> vis[2];
pii ans;

inline void upd(ll &a, ll b, int p) {
	a+=b;
	if(a>=p) a-=p;
	if(a<0) a+=p;
}

inline void solve() {
	rep(j,1,n+1) rep(k,0,26) {
		ll h1=ha1[2][n];   
		upd(h1, ('a'-s[2][j]+k)*ba1[n-j]%p1, p1);
		ll h2=ha2[2][n];   
		upd(h2, ('a'-s[2][j]+k)*ba2[n-j]%p2, p2);
		if(vis[0].count(mp(h1, h2))&&vis[1].count(mp(h1, h2))) {
			++cnt;
			if(cnt>1) return ;
			ans=mp(j, k); 
		} 
	}
}

int main() {
	rep(i,0,3) scanf("%s",s[i]+1);
	n=strlen(s[0]+1);
	rep(i,0,3) rep(j,i+1,3) {
		int _=0;
		rep(k,1,n+1) _+=s[i][k]!=s[j][k];
		if(_>2) {
			puts("Impossible");
			return 0;
		}
	}
	int __=0;
	rep(i,1,n+1) {
		str[i]=s[2][i];
		int _=0;
		rep(j,1,3) _+=s[j][i]!=s[0][i];
		if(_||__==0) {
			++__;
			ok[i]=1;
		}
	}
	n=0;
	for(int i=1;s[0][i];++i) if(ok[i]) {
		s[0][++n]=s[0][i];
		s[1][n]=s[1][i];
		s[2][n]=s[2][i];
		to[n]=i;
	}
	ba1[0]=ba2[0]=1;
	rep(i,1,n+1) {
		ba1[i]=ba1[i-1]*se1%p1;
		ba2[i]=ba2[i-1]*se2%p2;
	}
	rep(i,0,3) {
		rep(j,1,n+1) {
			ha1[i][j]=ha1[i][j-1]*se1%p1;
			upd(ha1[i][j], s[i][j]-'a', p1);
			ha2[i][j]=ha2[i][j-1]*se2%p2;
			upd(ha2[i][j], s[i][j]-'a', p2);
		}
	}
	rep(i,0,2) {
		rep(j,1,n+1) {
			rep(k,0,26) {
				ll h1=ha1[i][n];   
				upd(h1, ('a'-s[i][j]+k)*ba1[n-j]%p1, p1);
				ll h2=ha2[i][n];   
				upd(h2, ('a'-s[i][j]+k)*ba2[n-j]%p2, p2);
				vis[i][mp(h1, h2)]=1;
			}
		}
	}
	solve();
	if(cnt==0) {
		puts("Impossible");
	} else if(cnt==1) {
		str[to[ans.fi]]=ans.se+'a';
		printf("%s\n",str+1);
	} else {
		puts("Ambiguous");
	}
	return 0;
}
/*
aabaaa
acaaaa
daaaaa
*/
