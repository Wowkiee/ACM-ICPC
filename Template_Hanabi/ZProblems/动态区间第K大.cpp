/*	@zoj-2112
    动态区间第K大
    */
struct Index:vector<int>{
    void Pre(){
        sort(begin(),end());
        erase(unique(begin(),end()),end());
    }
    int rk(int x){
        return lower_bound(begin(),end(),x) - begin() + 1;
    }
}V;
struct Request{
    char op;
    int a , b , kth;
}R[M];
int T , n , m , a[N];
struct node{
    int l,r,w;
}po[2500005];
#define l(x) po[x].l
#define r(x) po[x].r
#define w(x) po[x].w
#define pos int l,int r,int &c
#define lson l,m,l(c)
#define rson m+1,r,r(c)
#define getm int m=l+r>>1
#define lb(x) (x)&(-x)
struct Ztree{
    int L , len , rt[N<<1];
    void ini(){
        L = 0;
        Set(rt,0);
    }
    void ins(int x,pos){
        po[++L] = po[c]; po[c = L].w++;
        if(l == r)return;
        getm;if(x <= m) ins(x,lson);
        else ins(x,rson);
    }
    void add(int x,int d,pos){
        if(c == 0) po[++L] = po[c] , c = L;
        w(c) += d;
        if(l == r) return;
        getm;if(x <= m) add(x,d,lson);
        else add(x,d,rson);
    }
    void Add(int x,int d,int i){
        for(;i<=n;i+=lb(i))
            add(x,d,1,len,rt[i]);
    }vi pl , ml;
    int query_kth(int l,int r,int kth){
        if(l == r) return l;getm;
        int cnt = 0;
        rep(i,0,sz(pl)) cnt += w(l(pl[i]));
        rep(i,0,sz(ml)) cnt -= w(l(ml[i]));
        rep(i,0,sz(pl)) pl[i] = cnt >= kth ? l(pl[i]) : r(pl[i]);
        rep(i,0,sz(ml)) ml[i] = cnt >= kth ? l(ml[i]) : r(ml[i]);
        if(cnt >= kth) return query_kth(l,m,kth);
        else return query_kth(m+1,r,kth - cnt);
    }
    int Query_kth(int l,int r,int kth){
        pl.clear();ml.clear();
        ml.push_back(rt[l == 1 ? 0 : n+l-1]);
        pl.push_back(rt[n + r]);
        for(int i=l-1;i>=1;i-=lb(i)) ml.push_back(rt[i]);
        for(int i=r;i>=1;i-=lb(i)) pl.push_back(rt[i]);
        return query_kth(1,len,kth);
    }
}Z;
void work(){
    scanf("%d%d",&n,&m);
    V.clear();
    rep(i,1,n+1) scanf("%d",a + i) , V.pb(a[i]);
    char op[10];
    rep(i,0,m){
        scanf("%s%d%d",op,&R[i].a,&R[i].b);
        R[i].op = op[0];
        if(op[0] == 'Q') scanf("%d",&R[i].kth);
        else V.pb(R[i].b);
    }
    V.Pre();Z.len = sz(V);Z.ini();
    rep(i,1,n+1) Z.ins(V.rk(a[i]),1,Z.len,Z.rt[i+n] = Z.rt[i+n-1]);
    rep(i,0,m){
        if(R[i].op == 'Q') printf("%d\n",V[Z.Query_kth(R[i].a,R[i].b,R[i].kth) - 1]);
        else{
            Z.Add(V.rk(a[R[i].a]) ,			-1 , R[i].a);
            Z.Add(V.rk(a[R[i].a] = R[i].b) , 1 , R[i].a);
        }
    }
}
