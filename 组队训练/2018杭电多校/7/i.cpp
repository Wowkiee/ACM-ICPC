#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b-1) ;i>=a;i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---
const int N=100005;
struct LCT {
	bool rt[N],rev[N];
	int n,fa[N],que[N],ch[N][2];
	int sz[N];
	void init(int _n) {
		n=_n;
		rep(i,0,n) {
			rt[i]=true,rev[i]=false;
			fa[i]=ch[i][0]=ch[i][1]=0;
		}
	}
	void reverse(int x) {
		rev[x]=!rev[x],swap(ch[x][0],ch[x][1]);
	}
	void up(int x) {
		sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
	}
	void down(int x) {
		if(rev[x])
			rev[x]=0,reverse(ch[x][0]),reverse(ch[x][1]);
	}
	void rotate(int x) {
		int y=fa[x],k=(ch[y][0]==x);
		ch[y][!k]=ch[x][k];
		fa[ch[x][k]]=y,fa[x]=fa[y];
		fa[ch[x][k]=y]=x;
		if(rt[y])
			rt[y]=false,rt[x]=true;
		else
			ch[fa[x]][ch[fa[x]][1]==y]=x;
		up(y);
	}
	void update(int x) {
		int top=0;
		que[top++]=x;
		while(!rt[x])x=fa[x],que[top++]=x;
		while(top)down(que[--top]);
	}
	void splay(int x) {
		update(x);
		while(!rt[x]) {
			int y=fa[x],z=fa[y];
			if(!rt[y])
				(ch[z][1]==y)==(ch[y][1]==x)?rotate(y):rotate(x);
			rotate(x);
		}
		up(x);
	}
	void access(int x) {
		for(int y=0;x;y=x,x=fa[x]) {
			splay(x);
			rt[ch[x][1]]=true;
			rt[ch[x][1]=y]=false;
			up(x);
		}
	}
	int getRoot(int x) {
		access(x),splay(x);
		while(ch[x][0])x=ch[x][0];
		return x;
	}
	void makeRoot(int x) {
		access(x),splay(x),reverse(x);
	}
	void addEdge(int x,int y) {
		makeRoot(x),fa[x]=y;
	}
	void cut(int x) {
		access(x),splay(x);
		if(ch[x][0])
			fa[ch[x][0]]=fa[x],rt[ch[x][0]]=true;
		fa[x]=ch[x][0]=0;
	}
	void delEdge(int x,int y) {
		makeRoot(y),cut(x);
	}
	void delNode(int x) {
		splay(x);
		rep(i,0,2) {
			if(!ch[x][i])continue;
			fa[ch[x][i]]=fa[x],rt[ch[x][i]]=true;
			fa[x]=ch[x][i]=0;
		}
	}
}lct;
vector<int> V[N];
int Fa[20][N];
void dfs(int a,int fa) {
	Fa[0][a]=fa;
	rep(i,0,sz(V[a]))dfs(V[a][i],a);
}
int main() {
	int T;scanf("%d",&T);while(T--) {
		lct.init(N);
		int n;scanf("%d",&n);
		rep(i,1,n+1)V[i].clear();
		rep(i,2,n+1) {
			int a;scanf("%d",&a);
			V[a].pb(i);
		}
		dfs(1,0);
		rep(i,1,20)rep(j,1,n+1)Fa[i][j]=Fa[i-1][Fa[i-1][j]];
		rep(po,1,n+1) {
			int b;scanf("%d",&b);
			int nxt=po;
			per(i,0,20)if(b>=(1<<i))nxt=Fa[i][nxt],b-=(1<<i);
			if(nxt==0)nxt=n+1;
			lct.addEdge(po,nxt);
		}
		int m;scanf("%d",&m);while(m--) {
			int co;scanf("%d",&co);
			if(co==1) {
				int a;scanf("%d",&a);
				lct.access(a);lct.splay(a);
				printf("%d\n",lct.sz[a]-1);
			}
			else {
				int a,b;scanf("%d%d",&a,&b);
				int nxt=a;
				per(i,0,20)if(b>=(1<<i))nxt=Fa[i][nxt],b-=(1<<i);
				if(nxt==0)nxt=n+1;
				lct.cut(a);
				lct.addEdge(a,nxt);
			}
		}
	}
	return 0;
}
