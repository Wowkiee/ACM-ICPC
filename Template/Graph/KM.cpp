/*
	输入保证左边点数<=右边点数
*/
// init!! , id starts from 0
template<class T>
struct KM {
    static const int N = 505;
    static const T inf = ~0U>>2;
    int n, m, left[N], pre[N], used[N];
    T g[N][N], Lx[N], Ly[N], slack[N];
    void ini(int _n, int _m) {
        n = _n , m = _m;
        rep(i,0,n) rep(j,0,m) g[i][j] = -inf;
    }
    void go(int now) {
        rep(i,0,m+1) used[i]=0,slack[i]=inf;
        left[m] = now;int u,v;
        for(u=m;~left[u];u=v){
            used[u] = 1;
            T d = inf;
            rep(i,0,m) if(!used[i]){
                T tmp = Lx[left[u]] + Ly[i] - g[left[u]][i];
                if(tmp < slack[i]) slack[i] = tmp, pre[i] = u;
                if(slack[i] < d) d = slack[v=i];
            }
            rep(i,0,m+1) if(used[i]) Lx[left[i]] -= d , Ly[i] += d;
                else slack[i] -= d;
        }
        for(;u!=m;left[u]=left[pre[u]],u=pre[u]);
    }
    T run() {
        fill_n(Lx,n,0);fill_n(Ly,m,0);
        fill_n(left,m,-1);
        rep(i,0,n) go(i);
        T ans = 0;
        rep(i,0,n) ans += Lx[i];
        rep(i,0,m) ans += Ly[i];
        return ans;
    }
};
