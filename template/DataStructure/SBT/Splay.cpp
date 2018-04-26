// init 
// 0 is virtual 
// fa[rt] = 0
struct Splay{
	static const int N=101010;
	int rt, L;
    int w[N], siz[N], cnt[N], son[N][2], fa[N];
    void ini() {
    	rt=L=0;
	}
	void newnode(int c, int f=0) {
		w[++L]=c;
		siz[L]=cnt[L]=1;
		son[L][0]=son[L][1]=0;
		fa[L]=f;
		if(f) son[f][w[f]<c]=L;
	}
    void up(int x) {
        siz[x] = siz[son[x][1]] + siz[son[x][0]] + cnt[x];
    }
    int id(int x) {
        return son[fa[x]][1]==x;
    }
    void rot(int x) {
        int y=fa[x], z=fa[y];
        int l=(son[y][1]==x), r=(l^1);
        son[y][l]=son[x][r];
        if(son[y][l]) fa[son[y][l]]=y;
        fa[y]=x; son[x][r]=y;
        fa[x]=z;
        if(z) son[z][son[z][1]==y]=x;
        up(y); up(x);
    }
    void splay(int x, int g=0) {
    	while(fa[x]!=g) {
    		int y=fa[x], z=fa[y];
    		if(z!=g) (id(y)^id(x))?rot(x):rot(y);
    		rot(x);
		}
        if(!g) rt=x;
    }
    void find(int c) {
    	if(!rt) return ;
    	int u;
    	for(u=rt; w[u]!=c && son[u][w[u]<c]; ) u=son[u][w[u]<c];
    	splay(u);
	}
    void ins(int c) {
    	int u, f;
    	for(u=rt, f=0; u && w[u]!=c; f=u, u=son[u][w[u]<c]) ;
    	if(u) ++cnt[u]; else newnode(u, f);
    	up(u); splay(u);
    }
    int Next(int c, int t) { // pre 0, ne 1
    	find(c);
    	int u=rt;
    	if(w[u] > c && t) return u;
    	if(w[u] < c && !t) return u;
    	u = son[u][t];
    	while(son[u][!t]) u = son[u][!t];
    	return u;
	}
	void del(int c) {
		int pre = Next(c, 0);
		int ne = Next(c, 1);
		splay(pre, 0);
		splay(ne, pre);
		int u=son[ne][0];
		if(cnt[u]>1) {
			--cnt[u];
			up(u); splay(u);
		} else {
			son[ne][0]=0;
			up(ne); up(pre);
		}
	}
    int mink(int k) {
    	for(int u=rt;;) {
    		if(k<=siz[son[u][0]]) {
    			u=son[u][0];
			} else {
				k-=siz[son[u][0]];
				if(k<=cnt[u]) {
					splay(u);
					return w[u];
				}
				x-=cnt[u];
				u=son[u][1];
			}
		}
    }
    int rank(int c) {
    	find(c);
    	if(!rt) return 1;
    	if(c<=w[rt]) return siz[son[rt][0]]+1;
    	else return siz[son[rt][0]]+cnt[rt]+1;
    }
};
