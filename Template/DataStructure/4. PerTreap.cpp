// init!!
struct PerTreap {
    #define ls son[u][0]
    #define rs son[u][1]
    static const int N=500005;
    int L, tim;
    int rt[N], w[N*50], siz[N*50], son[N*50][2], r[N*50];
    void init() {
        fill_n(rt, tim+1, 0);
        fill_n(w, L+1, 0);
        fill_n(r, L+1, 0);
        fill_n(siz, L+1, 0);
        fill_n(son[0], L+1, 0);
        fill_n(son[1], L+1, 0);
        L=tim=0;
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
        r[L]=rand();
        return L;
    }
    void copy(int &x, int u) {
        x=++L;
        w[x]=w[u];
        r[x]=r[u];
        siz[x]=siz[u];
        son[x][0]=son[u][0];
        son[x][1]=son[u][1];
    }
    void split(int u, int c, int &x, int &y) {
        if(!u) {
            x=y=0;
        } else {
            if(w[u]<=c) {
                copy(x, u);
                split(rs, c, son[x][1], y);
                up(x);
            } else {
                copy(y, u);
                split(ls, c, x, son[y][0]);
                up(y);
            }
        }
    }
    int merge(int x,int y) {
        if(x&&y) {
            int u;
            if(r[x]<r[y]) {
                copy(u, x);
                son[u][1]=merge(son[x][1], y);
            } else {
                copy(u, y);
                son[u][0]=merge(x, son[y][0]);
            }
            up(u);
            return u;
        } else {
            return x+y;
        }
    }
    void ins(int pre, int &now, int c) {
        int x, y;
        split(pre, c, x, y);
        now=merge(x, merge(newnode(c), y));
    }
    void del(int pre, int &now, int c) {
        int x, y, z;
        split(pre, c-1, x, y);
        split(y, c, y, z);
        if(!y) {
            now=pre;
            return ;
        }
        y=merge(son[y][0], son[y][1]);
        now=merge(x, merge(y, z));
    }
    int rank(int now, int c) {
        int x, y;
        split(now, c-1, x, y);
        int res=siz[x]+1;
        now=merge(x, y);
        return res;
    }
    int mink(int now, int k) {
        int u=now;
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
    int Pre(int now, int c) {
        int x, y;
        split(now, c-1, x, y);
        if(!x) return -2147483647;
        int u=x;
        while(rs) u=rs;
        now=merge(x, y);
        return w[u];
    }
    int Next(int now, int c) {
        int x, y;
        split(now, c, x, y);
        if(!y) return 2147483647;
        int u=y;
        while(ls) u=ls;
        now=merge(x, y);
        return w[u];
    }
}T;
