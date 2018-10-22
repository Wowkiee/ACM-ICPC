struct Splay {
	#define ls son[u][0]
	#define rs son[u][1]
	static const int N = ::N;
	int rt, L, w[N], fa[N], son[N][2], cnt[N], siz[N];
	bool rev[N];
	void init() {
		fill_n(w, L+1, 0);
		fill_n(fa, L+1, 0);
		fill_n(son[0], L+1, 0);
		fill_n(son[1], L+1, 0);
		fill_n(cnt, L+1, 0);
		fill_n(siz, L+1, 0);
		fill_n(rev, L+1, 0);
		L=rt=0;
	}
	void up(int u) {
		if(!u) return ;
		siz[u] = cnt[u];
		if(ls) siz[u] += siz[ls];
		if(rs) siz[u] += siz[rs]; 
	}
	int build(int l, int r, int pre) {
		if(l > r) return 0;
		int mid = l + r >> 1, u = ++L;
		w[u] = ::w[mid];
		fa[u] = pre;
		cnt[u] = 1;
		ls = build(l, mid - 1, u);
		rs = build(mid + 1, r, u);
		up(u);
		return u;
	}
	void gao(int u) {
		if(!u) return ;
		rev[u] ^= 1;
		swap(ls, rs);
	}
	void down(int u) {
		if(!rev[u]) return ;
		gao(ls), gao(rs);
		rev[u] = 0;
	}
	int id(int u) {
		return son[fa[u]][1]==u;
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
	void splay(int x, int g = 0) {
		while(fa[x]!=g) {
			int y=fa[x], z=fa[y];
			if(z!=g) (id(x)^id(y))?rot(x):rot(y);
			rot(x);
		}
		if(!g) rt=x;
	}
	void ins(int c) {
		if(!rt) {
			w[++L]=c;
			cnt[L]=siz[L]=1;
			rt=L;
			return ;
		}
		int u=rt, f=0;
		while(1) {
			if(c==w[u]) {
				++cnt[u];
				up(u); up(f);
				splay(u);
				return ;
			}
			f=u;
			u=son[u][w[u]<c];
			if(!u) {
				w[++L]=c;
				fa[L]=f;
				if(f) son[f][w[f]<c]=L;
				cnt[L]=siz[L]=1;
				up(f);
				splay(L);
				return ;
			}
		}
	}
	// c in splay
	// splay(u)
	int rank(int c) {
		int u=rt, ans=0;
		while(1) {
			if(c<w[u]) {
				u=ls;
			} else if(c==w[u]) {
				if(ls) ans+=siz[ls];
				splay(u);
				return ans+1;
			} else {
				ans+=cnt[u];
				if(ls) ans+=siz[ls];
				u=rs;
			}
		}
	}
	// return w[u]
	int mink(int k) {
		int u=rt;
		while(1) {
			if(siz[ls]>=k) {
				u=ls;
			} else {
				k-=siz[ls];
				if(cnt[u]>=k) {
					splay(u);
					return w[u];
				} else {
					k-=cnt[u];
					u=rs;
				}
			}
		}
	}
	// Next of rt
	// 0 pre 1 next
	// return u
	int Next(int t) {
		int u=son[rt][t];
		while(son[u][t^1]) u=son[u][t^1];
		return u;
	}
	void del(int c) {
		rank(c);
		int u=rt;
		if(cnt[rt]>1) {
			--cnt[rt];
			up(rt);
			return ;
		}
		if(ls&&rs) {
			int pre=Next(0);
			int ne=Next(1);
			splay(pre);
			splay(ne, pre);
			son[ne][0]=0;
			up(ne);
			up(pre);
		} else if(ls) {
			rt=ls;
			fa[ls]=0;
		} else if(rs) {
			rt=rs;
			fa[rs]=0;
		} else {
			rt=0;
		}
	}
};
