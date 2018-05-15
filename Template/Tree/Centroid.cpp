// id starts from 1
namespace Centriod {
    const int N = 101010;
    int vis[N],sz[N];
    void dfssz(int c,int fa,int Sz,int &rt){
        sz[c] = 1;
        for(auto t : g[c]) if(!vis[t]&&t!=fa) dfssz(t,c,Sz,rt) , sz[c]+=sz[t];
        if(!rt && sz[c]*2>Sz) rt=c;
    }
    void dfs(int c){
        int rt=0;dfssz(c,0,0,rt);dfssz(c,0,sz[c],rt=0);
        // cal something
        vis[rt] = true;
        for(auto t : g[rt]) if(!vis[t]) dfs(t);
    }
};
