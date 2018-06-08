namespace MaxMatch{
    const int N = 5050;
    int link[N],vis[N];
    int dfs(int c,vi g[]){
        for(auto t : g[c])
            if(!vis[t]){
                vis[t] = true;
                if(link[t]==-1||dfs(link[t],g))
                    return link[t]=c,1;
            }
        return 0;
    }
    int solve(int n,int m,vi g[]){
        fill_n(link,m,-1);
        int ret=0;
        rep(i,0,n){
            memset(vis,0,m*sizeof(int));
            ret += dfs(i,g);
        }
        return ret;
    }
}
