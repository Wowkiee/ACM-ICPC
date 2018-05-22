 // [0,n)
struct ST{
    static const int N = 101010;
    int a[20][N] , lg[N] , (*f)(int,int);
    void Build(int *v,int n,int (*_f)(int,int)){
        f = _f;rep(i,0,n) a[0][i] = v[i];
        rep(i,2,n+1) lg[i] = lg[i>>1]+1;
        rep(i,1,lg[n]+1) rep(j,0,n-(1<<i)+1) a[i][j]=f(a[i-1][j],a[i-1][j+(1<<i>>1)]);
    }
    int rmq(int x,int y){
        if(x>y) swap(x,y);
        int i=lg[y-x+1];
        return f(a[i][x] , a[i][y+1-(1<<i)]);
    }
};
