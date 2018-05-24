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

const int N=200004, se1=53;//, se2=131;
const int p1=1e9+9;//, p2=1e9+7;
char s[3][N];
int cnt, n, c[2];
ll ba1[N], ha1[3][N];//, ba2[N], ha2[3][N];
ll vis[2][N*26];
pii ans;

inline bool Find(int i,ll h1) {
	int p=lower_bound(vis[i], vis[i]+c[i], h1)-vis[i];
	return vis[i][p]==h1;
}

inline void upd(ll &a, ll b, int p) {
	a+=b;
	if(a>=p) a-=p;
	if(a<0) a+=p;
}

inline void solve() {
	rep(j,1,n+1) rep(k,0,26) {
		ll h1=ha1[2][n];   
		upd(h1, ('a'-s[2][j]+k)*ba1[n-j]%p1, p1);
	//	ll h2=ha2[2][n];   
	//	upd(h2, ('a'-s[2][j]+k)*ba2[n-j]%p2, p2);
		if(Find(0, h1)&&Find(1, h1)) {
			++cnt;
			if(cnt>1) return ;
			ans=mp(j, k); 
		} 
	}
}

int main() {
	rep(i,0,3) scanf("%s",s[i]+1);
	n=strlen(s[0]+1);
	ba1[0]=1;//=ba2[0]=1;
	rep(i,1,N) {
		ba1[i]=ba1[i-1]*se1%p1;
	//	ba2[i]=ba2[i-1]*se2%p2;
	}
	rep(i,0,3) {
		rep(j,1,n+1) {
			ha1[i][j]=ha1[i][j-1]*se1%p1;
			upd(ha1[i][j], s[i][j]-'a', p1);
		//	ha2[i][j]=ha2[i][j-1]*se2%p2;
		//	upd(ha2[i][j], s[i][j]-'a', p2);
		}
	}
	rep(i,0,2) {
		rep(j,1,n+1) {
			rep(k,0,26) {
				ll h1=ha1[i][n];   
				upd(h1, ('a'-s[i][j]+k)*ba1[n-j]%p1, p1);
			//	ll h2=ha2[i][n];   
			//	upd(h2, ('a'-s[i][j]+k)*ba2[n-j]%p2, p2);
				vis[i][c[i]++]=h1;
			}
		}
	}
	sort(vis[0], vis[0]+c[0]);
	sort(vis[1], vis[1]+c[1]);
	solve();
	if(cnt==0) {
		puts("Impossible");
	} else if(cnt==1) {
		s[2][ans.fi]=ans.se+'a';
		printf("%s\n",s[2]+1);
	} else {
		puts("Ambiguous");
	}
	return 0;
}

