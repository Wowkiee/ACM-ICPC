// id starts with 1
struct HeavyChain{
    static const int N = 100005 , inf = ~0U>>1;
    int sz[N] , wson[N] , top[N] , dep[N] , id[N] , _ , par[N] , who[N];
    void dfs(int c,int fa,vi g[]){
        sz[c]=1;dep[c]=dep[par[c]=fa]+1;int &s=wson[c]=top[c]=0;
        for(auto t:g[c]) if(t!=fa)
            dfs(t,c,g),sz[c]+=sz[t],(sz[t]>=sz[s])&&(s=t);
    }
    void dfs2(int c,int fa,vi g[]){
        who[id[c]=++_]=c;int s=wson[c];
        if(!top[c]) top[c]=c;
        if(s) top[s]=top[c],dfs2(s,c,g);
        for(auto t:g[c]) if(t!=fa&&t!=s) dfs2(t,c,g);
    }
    void Query(int a,int b){// info in points
        int fa=top[a],fb=top[b];
        while(fa!=fb){
            if(dep[fa]<dep[fb]) swap(a,b) , swap(fa,fb);
            // Cal id[fa] .. id[a]
            a = par[fa];fa = top[a];
        }
        if(dep[a]<dep[b]) swap(a,b);
        // Cal id[b] .. id[a]
    }
    void Build(vi g[]){
        dfs(1,0,g);_=0;dfs2(1,0,g);
    }
}hc;
