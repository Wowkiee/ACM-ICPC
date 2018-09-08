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
const int N=5005,M=200005,LINF=0x3fffffff;
struct MaxFlow {
	int n,et,dis[N],que[N],cur[N],head[N];
	struct Edge {
		int s,t,v,nxt;
		Edge() {
		}
		Edge(int _s,int _t,int _v,int _nxt) {
			s=_s,t=_t,v=_v,nxt=_nxt;
		}
	}e[M*2],b[M*2];
	void undo() {
		for(int i=0;i<et;i++)e[i]=b[i];
	}
	void backup() {
		for(int i=0;i<et;i++)b[i]=e[i];
	}
	void init(int _n) {
		n=_n,et=0;
		memset(head,-1,sizeof(head[0])*n);
	}
	void addEdge(int s,int t,int v) {
		e[et]=Edge(s,t,v,head[s]),head[s]=et++;
		e[et]=Edge(t,s,0,head[t]),head[t]=et++;
	}
	bool bfs(int S,int T) {
		int qh=0,qt=0;
		memset(dis,-1,sizeof(dis[0])*n);
		dis[S]=0,que[qt++]=S;
		while(qh<qt)
			for(int i=head[que[qh++]];~i;i=e[i].nxt)
				if(e[i].v&&!~dis[e[i].t]) {
					dis[que[qt++]=e[i].t]=1+dis[e[i].s];
					if(e[i].t==T)return true;
				}
		return false;
	}
	ll dinic(int S,int T) {
		int u,qt;
		ll maxflow=0;
		while(bfs(S,T)) {
			memcpy(cur,head,sizeof(cur[0])*n);
			u=S,qt=0;
			while(~cur[S]) {
				if(u==T) {
					ll flow=LINF;
					for(int i=qt-1;i>=0;i--)
						flow=min(flow,(ll)e[que[i]].v);
					for(int i=qt-1;i>=0;i--) {
						e[que[i]].v-=flow,e[que[i]^1].v+=flow;
						if(!e[que[i]].v)qt=i;
					}
					u=e[que[qt]].s,maxflow+=flow;
				} else if(~cur[u]&&e[cur[u]].v
						&&dis[u]+1==dis[e[cur[u]].t]) {
					que[qt++]=cur[u];
					u=e[cur[u]].t;
				} else {
					while(u!=S&&!~cur[u])
						u=e[que[--qt]].s;
					cur[u]=e[cur[u]].nxt;
				}
			}
		}
		return maxflow;
	}
}G;
			
int main() {
	int n,m,k,cas=0;;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF) {
		int l,r;scanf("%d%d",&l,&r);
		ll Max=0;
		G.init(N);
		G.addEdge(4002,4004,n*l);G.addEdge(4003,4001,n*l);Max+=n*l;
		rep(i,1,n+1)G.addEdge(4001,i,r-l);
		rep(i,1,m+1)G.addEdge(2000+i,4002,r-l);
		rep(i,1,n+1)G.addEdge(4003,i,l),G.addEdge(i,4004,0),Max+=l;
		rep(i,1,m+1)G.addEdge(4003,i+2000,0),G.addEdge(i+2000,4004,l);
		while(k--) {
			int a,b;scanf("%d%d",&a,&b);
			G.addEdge(a,b+2000,1);
		}
		G.addEdge(4001,4002,LINF);G.addEdge(4002,4001,LINF);
		ll flow=G.dinic(4003,4004);
		printf("Case %d: ",++cas);
		if(flow==Max)puts("Yes");
		else puts("No");
	}
	return 0;
}
