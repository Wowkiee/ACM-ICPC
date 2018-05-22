const int N=3;
const int mod=1e9+7;
struct Mat {
    ll r[N][N];
    Mat() {memset(r,0,sizeof(r));}
    Mat operator * (Mat b) {
        Mat c;
        rep(i,0,N) rep(j,0,N) rep(k,0,N) c.r[i][j]=(c.r[i][j]+r[i][k]*b.r[k][j])%mod;
        return c;
    }
};
Mat kpow(Mat a,ll k) {
    Mat b;
    rep(i,0,N) b.r[i][i]=1;
    for(;k;k>>=1,a=a*a) if(k&1) b=b*a;
    return b;
}
