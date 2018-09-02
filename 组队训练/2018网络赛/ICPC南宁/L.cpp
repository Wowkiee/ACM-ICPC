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
typedef pair<int,pii> pip;
const int N=100005;
int n,m,k;
vector<pii> V[N];
ll dis[N][20];
void spfa() {
	rep(i,1,n+1)rep(j,0,k+1)dis[i][j]=1e18;
	priority_queue<pip> Q;Q.push(mp(0,mp(1,0)));
	while(!Q.empty()) {
		pip f=Q.top();Q.pop();
		if(dis[f.se.fi][f.se.se]!=1e18)continue;
		dis[f.se.fi][f.se.se]=-f.fi;
		rep(i,0,sz(V[f.se.fi])) {
			pii nxt=V[f.se.fi][i];
			if(f.se.se<k) {
				if(dis[nxt.fi][f.se.se+1]==1e18) {
					Q.push(mp(-dis[f.se.fi][f.se.se],mp(nxt.fi,f.se.se+1)));
				}
			}
			if(dis[nxt.fi][f.se.se]==1e18) {
				Q.push(mp(-dis[f.se.fi][f.se.se]-nxt.se,mp(nxt.fi,f.se.se)));
			}
		}
	}
}
int main() {
	int T;scanf("%d",&T);while(T--) {
		scanf("%d%d%d",&n,&m,&k);
		rep(i,1,n+1)V[i].clear();
		rep(i,0,m) {
			int a,b,c;scanf("%d%d%d",&a,&b,&c);
			V[a].pb(mp(b,c));
		}
		spfa();
		ll ans=1e18;
		rep(i,0,k+1)ans=min(ans,dis[n][i]);
		cout<<ans<<endl;
	}
	return 0;
}
