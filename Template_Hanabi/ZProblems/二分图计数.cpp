
/*	@Gym-100524B
    带标号2染色二分图种类数 2-->x
    */
const int N = 101 , M = N<<1;
int n;
ll a[N] , b[N] , c[N] , C[N][N] , e3[N*N];
inline void pp(ll &x,ll d){
    x += d; if(x >= mod) x -= mod;
}
int main(){
    rep(i,0,N) rep(j,0,i+1)
        C[i][j] = j ? (C[i-1][j-1] + C[i-1][j]) % mod : 1;
    e3[0] = 1;
    rep(i,1,N*N) e3[i] = e3[i-1] * 3 % mod;
    a[0] = 1;
    rep(i,1,N) rep(j,1,i+1)
        pp(a[i] , e3[j*(i-j)] * C[i-1][j-1] % mod);
    rep(i,0,N){
        b[i] = a[i];
        rep(j,1,i) pp(b[i] , mod - C[i-1][j-1] * b[j] % mod
                * a[i-j] % mod * 2 % mod);
    }
    c[0] = 1;
    rep(i,1,N) rep(j,1,i+1)
        pp(c[i] , C[i-1][j-1] * b[j] % mod * c[i-j] % mod);
    while(~scanf("%d",&n),n) printf("%I64d\n",c[n]);
    return 0;
}
