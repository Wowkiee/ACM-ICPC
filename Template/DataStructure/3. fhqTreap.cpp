// init!!
// rt=merge()
struct fhqTreap {
    #define ls son[u][0]
    #define rs son[u][1]
    static const int N=101010;
    int rt, L;
    int w[N], son[N][2], siz[N];
    ll r[N];
    void init() {
        fill_n(w, L+1, 0);
        fill_n(r, L+1, 0);
        fill_n(siz, L+1, 0);
        fill_n(son[0], L+1, 0);
        fill_n(son[1], L+1, 0);
        rt=L=0;
        srand(time(0));
    }
    void up(int u) {
        if(!u) return ;
        siz[u]=1;
        if(ls) siz[u]+=siz[ls];
        if(rs) siz[u]+=siz[rs];
    }
    int newnode(int c) {
        w[++L]=c;
        siz[L]=1;
        r[L]=((1ll*rand()<<30)^rand());
        return L;
    }
    void split(int u, int c, int &x, int &y) {
        if(!u) {
            x=y=0;
        } else {
            if(w[u]<=c) {
                x=u;
                split(rs, c, rs, y);
            } else {
                y=u;
                split(ls, c, x, ls);
            }
            up(u);
        }
    }
    int merge(int x,int y) {
        if(x&&y) {
            if(r[x]<r[y]) {
                son[x][1]=merge(son[x][1], y);
                up(x);
                return x;
            } else {
                son[y][0]=merge(x, son[y][0]);
                up(y);
                return y;
            }
        } else {
            return x+y;
        }
    }
    void ins(int c) {
        int x, y;
        split(rt, c, x, y);
        rt=merge(x, merge(newnode(c), y));
    }
    void del(int c) {
        int x, y, z;
        split(rt, c-1, x, y);
        split(y, c, y, z);
        y=merge(son[y][0], son[y][1]);
        rt=merge(x, merge(y, z));
    }
    int rank(int c) {
        int x, y;
        split(rt, c-1, x, y);
        int res=siz[x]+1;
        rt=merge(x, y);
        return res;
    }
    int mink(int k) {
        int u=rt;
        while(1) {
            if(k<=siz[ls]) {
                u=ls;
            } else {
                k-=siz[ls];
                if(k==1) {
                    return w[u];
                } else {
                    --k;
                    u=rs;
                }
            }
        }
    }
    int Pre(int c) {
        int x, y;
        split(rt, c-1, x, y);
        int u=x;
        while(rs) u=rs;
        rt=merge(x, y);
        return w[u];
    }
    int Next(int c) {
        int x, y;
        split(rt, c, x, y);
        int u=y;
        while(ls) u=ls;
        rt=merge(x, y);
        return w[u];
    }
}T;
