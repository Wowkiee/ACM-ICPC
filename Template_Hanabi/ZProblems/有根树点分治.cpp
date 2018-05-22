const int N = 201010;
int vis[N] , n , p[N] , par[N];
ll q[N] , lim[N] , dis[N] , ans[N];
vector<pair<int,ll> > g[N];
ll getans(int x,int y){return ans[y]+q[x]-p[x]*dis[y];}
void Update(int x,int y){if(dis[y] >= lim[x]) ans[x]=min(ans[x],getans(x,y));}

int getrt(int c){
    static int par[N] , sz[N] , q[N];
    int _ = 0;par[q[_++] = c] = -1;
    rep(i,0,_){
        int c = q[i];sz[c] = 1;
        for(auto e : g[c]) if(!vis[e.fi] && e.fi != par[c]) par[q[_++] = e.fi] = c;
    }
    for(int i=_-1;i>=0;--i){
        int c = q[i];
        if(sz[c]*2>_) return c;
        sz[par[c]] += sz[c];
    }return -1;
}
void dfs(int c,int rt){
    Update(c , rt);
    for(auto e : g[c]) if(!vis[e.fi] && e.fi != par[c]) dfs(e.fi , rt);
}
int e[N],_;
typedef complex<db> PP;
PP po[N];int f[N],tf;
db cross(PP a,PP b,PP c){return (conj(b-a)*(c-a)).imag();}
void Push(int c){
    e[_++] = c;
    for(auto e : g[c]) if(!vis[e.fi] && e.fi != par[c]) Push(e.fi);
}
void add(int x){
    PP tp = PP(-dis[x],ans[x]);
    while(tf > 1 && cross(po[tf-2],po[tf-1],tp) <= 0) --tf;
    f[tf] = x , po[tf++] = tp;
}
void Query(int x){
    if(tf == 0) return;
    int l=0,r=tf;
    while(l+1<r){
        int m=(l+r)>>1;
        if(getans(x,f[m]) <= getans(x,f[m-1])) l=m;
        else r=m;
    }
    Update(x,f[l]);
}

void solve(int c){
    int rt = getrt(c);
    vis[rt] = true;
    if(c != rt){
        solve(c);_ = tf = 0;
        for(auto e : g[rt]) if(!vis[e.fi]) Push(e.fi);
        sort(e , e + _ , [&](int a,int b){return lim[a] < lim[b];});
        for(int i=par[rt];i!=par[c];i=par[i]) Update(rt , i);
        for(int i=rt,j=_-1;j>=0;Query(e[j--]))
            for(;i!=par[c]&&dis[i] >= lim[e[j]];i = par[i])
                add(i);
    } else for(auto e : g[rt]) if(!vis[e.fi]) dfs(e.fi,rt);
    for(auto e : g[rt]) if(!vis[e.fi]) solve(e.fi);
}

void dfs_ini(int c){
    q[c] += dis[c] * p[c] , lim[c] = dis[c] - lim[c];
    for(auto e : g[c]) if(e.fi != par[c])
        par[e.fi] = c , dis[e.fi] = dis[c] + e.se , dfs_ini(e.fi);
}

int main(){
    int u;ll w;
    scanf("%d%*d",&n);
    rep(i,2,n+1) scanf("%d%lld%d%lld%lld",&u,&w,p + i,q + i,lim + i) , g[i].pb(mp(u,w)) , g[u].pb(mp(i,w));
    fill_n(ans+2,n-1,1ll<<62);
    dfs_ini(1);solve(1);
    rep(i,2,n+1) printf("%lld\n",ans[i]);
    return 0;
}
