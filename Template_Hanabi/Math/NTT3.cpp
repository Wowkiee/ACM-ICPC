// init!! , G is root , B is base , len = 3^x
namespace NTT3 {
    const int H = 17 , N = 531441 , P = 258280327 , G = 5 , B = 3;
    int w[2][N] , rev[N];
    void ini(){
        ll t = Pow(G,(P-1)/N);
        w[0][0] = w[1][0] = 1;
        rep(i,1,N) w[0][i] = w[0][i-1]*t%P;
        rep(i,1,N) w[1][i] = w[0][N-i];
        rep(i,0,N) for(int j=1;j<N;j*=B) (rev[i]*=B)+=i/j%B;
    }
    void ntt(int *a,int n,int o){ // N -> max array size
        int tt = N/n , d = N/B;
        rep(i,0,n){
            int j = rev[i]/tt;
            if(i<j) swap(a[i],a[j]);
        }
        for(int i=1;i<n;i*=B)
            for(int j=0,t=N/(i*B);j<n;j+=i*B)
                for(int k=0,l=0;k<i;++k,l+=t){
                    int x = a[j+k] , y = a[j+k+i] , z = a[j+k+i+i];
                    a[j+k] = (x + (ll)y*w[o][l] + (ll)z*w[o][l+l])%P;
                    a[j+k+i] = (x + (ll)y*w[o][l+d] + (ll)z*w[o][(l+l+d+d)%N])%P;
                    a[j+k+i+i] = (x + (ll)y*w[o][l+d+d] + (ll)z*w[o][(l+d+d)*2-N])%P;
                }
        if(o == 1){
            ll inv = Pow(n,P-2);
            rep(i,0,n) a[i] = a[i]*inv%P;
        }
    }
    void mult(int *a,int *b,int len){
        ntt(a,len,0);ntt(b,len,0);
        rep(i,0,len) a[i] = (ll)a[i]*b[i]%P;
        ntt(a,len,1);
    }
}
