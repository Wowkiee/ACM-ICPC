#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(x) (int)x.size()
#define de(x) cout<< #x<<" = "<<x<<endl
#define dd(x) cout<< #x<<" = "<<x<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Splay {
	static const int N=101010;
	int rt, L;
	int w[N], fa[N], son[N][2], cnt[N], siz[N];
	int newnode(int c,int f) {
		w[++L]=c;
		cnt[L]=siz[L]=1;
		son[L][0]=son[L][1]=0;
		fa[L]=f;
		if(f) son[f][w[f]<c]=L;
		return L;
	}
	void up(int x) {
		siz[x]=siz[son[x][0]]+siz[son[x][1]]+cnt[x];
	}
	int id(int x) {
		return x==son[fa[x]][1];
	}
	void rot(int x) {
		int y=fa[x], z=fa[y];
		int l=id(x), r=(l^1);
		fa[x]=z;
		if(z) son[z][id(y)]=x;
		son[y][l]=son[x][r];
		if(son[y][l]) fa[son[y][l]]=y;
		son[x][r]=y;
		fa[y]=x;
		up(y); up(x);
	}
	// u	
	void splay(int x, int g=0) {
		while(fa[x]!=g) {
			int y=fa[x], z=fa[y];
			if(z!=g) (id(x)^id(y))?rot(x):rot(y);
			rot(x);
		}
		if(!g) rt=x;
	}
	// u
	int find(int c) {
		if(!rt) return 0;
		int u;
		for(u=rt; w[u]!=c && son[u][w[u]<c]; u=son[u][w[u]<c]) ;
		return u;
	}
	void ins(int c) {
		int u, f;
		for(u=rt, f=0; u && w[u]!=c; f=u, u=son[u][w[u]<c]) ;
		if(u) {
			++cnt[u];
		} else {
			u=newnode(c, f);
		}
		up(u); splay(u);
	}
	// u
	int Next(int c, int t) {
		int u=find(c);
		splay(u);
		if(w[u]<c && !t) return u;
		if(w[u]>c && t) return u;
		u=son[u][t];
		while(son[u][!t]) u=son[u][!t];
		return u;
	}
	void del(int c) {
		int pre=Next(c, 0);
		int ne=Next(c, 1);
		splay(pre);
		splay(ne, pre);
		int u=son[ne][0];
		if(cnt[u]>1) {
			--cnt[u];
			up(u);
			splay(u);
		} else {
			son[ne][0]=0;
			up(ne); up(pre);
		}
	}
	// u
	int mink(int k) {
		for(int u=rt;;) {
			if(siz[son[u][0]]>=k) {
				u=son[u][0];
			} else {
				k-=siz[son[u][0]];
				if(k<=cnt[u]) {
					splay(u);
					return u;
				}
				k-=cnt[u];
				u=son[u][1];
			}
		}
	}
	int rank(int c) {
		int u=find(c);
		if(!u) return 1;
		splay(u);
		if(w[u]<c) {
			return siz[son[u][0]]+cnt[u]+1;
		} else {
			return siz[son[u][0]]+1;
		}
	}
}T;

int main() {
	int n;scanf("%d",&n);
	while(n--) {
		int t, x; scanf("%d%d",&t,&x);
		switch (t) {
			case 1:
				T.ins(x);
				break;
			case 2:
				T.del(x);
				break;
			case 3:
				printf("%d\n",T.rank(x));
				break;
			case 4:
				printf("%d\n",T.w[T.mink(x)]);
				break;
			case 5:
				printf("%d\n",T.w[T.Next(x, 0)]);
				break;
			case 6:
				printf("%d\n",T.w[T.Next(x, 1)]);
				break;
		}
	}
	return 0;
}

