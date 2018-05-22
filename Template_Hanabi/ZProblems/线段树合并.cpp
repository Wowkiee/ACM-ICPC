/*	@hiho-1193 线段树合并
    有根带权树各子树删除最少点变为树堆
    树堆->父节点权值大于儿子
    */
struct Index:vector<int>{
    void Pre(){
        sort(begin(),end());
        erase(unique(begin(),end()),end());
    }
    int rk(int x){
        return lower_bound(begin(),end(),x) - begin() + 1;
    }
}R;
int to[M] , ne[M] , h[N] , e;
void link(int u,int v){
    to[e] = v , ne[e] = h[u];
    h[u] = e++;
}
int n;
int val[N] , ans[N];
const int NODE = N * 60;
int lc[NODE] , rc[NODE] , sum[NODE] , L , rt[N] , up;
int newnode(){
    ++L; lc[L] = rc[L] = sum[L] = 0;
    return L;
}
int merge(int a,int b){
    if(a == 0) return b;
    if(b == 0) return a;
    int p = newnode();
    lc[p] = merge(lc[a],lc[b]);
    rc[p] = merge(rc[a],rc[b]);
    sum[p] = sum[a] + sum[b];
    return p;
}
int Query(int l,int r,int &p,int L,int R){
    if(L <= l && r <= R) return sum[p];
    if(p == 0) return 0;
    int m = l+r>>1;
    int ret = 0;
    if(L <= m ) ret += Query(l,m,lc[p],L,R);
    if(R > m ) ret += Query(m+1,r,rc[p],L,R);
    return ret;
}
void Update(int l,int r,int &p,int x,int d){
    if(p == 0) p = newnode();
    sum[p] += d;
    if(l == r) return;
    int m = l+r>>1;
    if(x <= m) Update(l,m,lc[p],x,d);
    else Update(m+1,r,rc[p],x,d);
}
int Query_R(int l,int r,int p,int x){
    if(p == 0 || sum[p] == 0) return 0;
    if(l == r) return l;
    int m = l+r>>1 , ret = 0;
    if(x <= m) ret = Query_R(l,m,lc[p],x);
    if(ret) return ret;
    return Query_R(m+1,r,rc[p],x);
}
void dfs(int c,int fa){
    rt[c] = newnode();
    for(int k=h[c];~k;k=ne[k]){
        if(to[k] == fa) continue;
        dfs(to[k] , c);
        rt[c] = merge(rt[c],rt[to[k]]);
    }
    ans[c] = Query(1,up,rt[c],1,val[c]) + 1;
    int l = val[c];
    Update(1,up,rt[c],val[c],1);
    int r = val[c] != up ? Query_R(1,up,rt[c],val[c]+1) : 0;
    if(r) Update(1,up,rt[c],r,-1);
}
int main(){
    while(~scanf("%d",&n)){
        R.clear();
        rep(i,0,n) scanf("%d",val+i) , R.push_back(val[i]);
        R.Pre(); rep(i,0,n) val[i] = R.rk(val[i]);
        up = R.size();
        fill(h,h+n,-1);e = 0;
        int u,v;
        rep(i,1,n){
            scanf("%d%d",&u,&v);
            link(u,v);link(v,u);
        }
        L = 0;dfs(0,-1);
        rep(i,0,n) printf("%d%c",ans[i]," \n"[i==n-1]);
    }
    return 0;
}
