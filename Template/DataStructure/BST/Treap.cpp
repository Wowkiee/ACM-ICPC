// init!!
struct Treap {
    #define ls son[u][0]
    #define rs son[u][1]
    static const int N=101010;
    static const int inf=1e9+7;
    int rt, L;
    int son[N][2], w[N], cnt[N], siz[N];
    ll r[N];
    void init() {
        fill_n(son[0], L+1, 0);
        fill_n(son[1], L+1, 0);
        fill_n(w, L+1, 0);
        fill_n(r, L+1, 0);
        fill_n(cnt, L+1, 0);
        fill_n(siz, L+1, 0);
        rt=L=0;
        srand(time(0));
    }
    void up(int u) {
        if(!u) return ;
        siz[u]=cnt[u];
        if(ls) siz[u]+=siz[ls];
        if(rs) siz[u]+=siz[rs];
    }
    // 1 left 0 right
    void rot(int &u, int t) {
        int v=son[u][t];
        son[u][t]=son[v][t^1];
        son[v][t^1]=u;
        up(u); up(v);
        u=v;
    }
    // return u w[u]=c
    int ins(int &u, int c) {
        int po;
        if(!u) {
            u=++L;
            w[u]=c;
            r[u]=((1ll*rand()<<30)^(rand()));
            cnt[u]=siz[u]=1;
            po=u;
        } else if(w[u]==c) {
            ++cnt[u];
            po=u;
        } else {
            int &s=son[u][w[u]<c];
            po=ins(s, c);
            if(r[s]<r[u]) rot(u, w[u]<c);
        }
        up(u);
        return po;
    }
    void del(int &u, int c) {
        if(w[u]==c) {
            if(cnt[u]>1) {
                --cnt[u];
            } else {
                if(ls&&rs) {
                    int t=r[ls]>r[rs];
                    rot(u, t);
                    del(son[u][t^1], c);
                } else {
                    u=ls+rs;
                }
            }
        } else {
            del(son[u][w[u]<c], c);
        }
        up(u);
    }
    // c in treap
    int rank(int c) {
        int u=rt, ans=0;
        while(1) {
            if(c<w[u]) {
                u=ls;
            } else if(c==w[u]) {
                if(ls) ans+=siz[ls];
                return ans+1;
            } else {
                if(ls) ans+=siz[ls];
                ans+=cnt[u];
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
                    return w[u];
                } else {
                    k-=cnt[u];
                    u=rs;
                }
            }
        }
    }
    int Pre(int u, int c) {
        if(!u) return -inf;
        if(w[u]>=c) return Pre(ls, c);
        return max(w[u], Pre(rs, c));
    }
    int Next(int u, int c) {
        if(!u) return inf;
        if(w[u]<=c) return Next(rs, c);
        return min(w[u], Next(ls, c));
    }
}T;

int main() {
    T.init();
    int n;scanf("%d",&n);
    while(n--) {
        int t, x;scanf("%d%d",&t,&x);
        switch(t) {
            case 1:
                T.ins(T.rt, x);
                break;
            case 2:
                T.del(T.rt, x);
                break;
            case 3:
                printf("%d\n",T.rank(x)); 
                break;
            case 4:
                printf("%d\n",T.mink(x)); 
                break;
            case 5:
                printf("%d\n",T.Pre(T.rt, x)); 
                break;
            case 6:
                printf("%d\n",T.Next(T.rt, x)); 
                break;
        }
    }
    return 0;
}

