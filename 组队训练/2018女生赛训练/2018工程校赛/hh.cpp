#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a);i<(b);++i)
#define per(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define sz(a) (int)a.size();
#define de(x) cout<<#x<<" = "<<x<<endl
#define de(x) cout<<#x<<" = "<<x<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN=(1<<20);
const double pi=acos(-1);

int N,na,nb,rev[MAXN];

struct com {
    double re, im;
    com(double r=0, double i=0) {
        re=r;
        im=i;
    }
    com operator + (const com &A) const {
        return com(re+A.re, im+A.im);
    }
    com operator - (const com &A) const {
        return com(re-A.re, im-A.im);
    }
    com operator * (const com &A) const {
        return com(re*A.re-im*A.im, re*A.im+im*A.re);
    }
}a[MAXN], b[MAXN], w[2][MAXN];

void FFT(com *a, int f) {
    com x, y;
    for(int i=0; i<N; i++) if(i<rev[i]) swap(a[i], a[rev[i]]);
    for(int i=1; i<N; i<<=1) {
        for(int j=0, t=N/(i<<1); j<N; j+=i<<1) {
            for(int k=0, l=0; k<i; k++, l+=t) x=w[f][l]*a[j+k+i], y=a[j+k], a[j+k]=y+x, a[j+k+i]=y-x;
        }
    }
    if(f) for(int i=0;i<N;i++) a[i].re/=N;
}

void work() {
    for(int i=0;i<N;i++) {
        int x=i, y=0;
        for(int k=1;k<N;x>>=1, k<<=1) (y<<=1)|=x&1;
        rev[i]=y;
    }
    for(int i=0;i<N;++i) w[0][i]=w[1][i]=com(cos(2*pi*i/N), sin(2*pi*i/N)), w[1][i].im=-w[0][i].im;
}

int aa[MAXN], bb[MAXN];

int main() {
    int n;scanf("%d",&n);
    na=2*n;nb=n;
    rep(i,0,n) {
        int x;scanf("%d",&x);
        aa[i]=x;
        a[i].re=a[i+n].re=x;
    }
    rep(i,0,n) {
        int x;scanf("%d",&x);
        bb[i]=x;
        b[n-1-i].re=x;
    }
    for(N=1; N<na||N<nb; N<<=1); N<<=1;
  //  de(N);
    work();
    FFT(a, 0);
    FFT(b, 0);
    rep(i,0,N) a[i]=a[i]*b[i];
    FFT(a, 1);
    ll ans=0;
    int ind=0;
    rep(i,n-1,2*n-1) {
        ll t=a[i].re+0.5;
        if(t>ans) {
            ans=t;
            ind=i-(n-1);
        }
    }
    ans=0;
    rep(i,0,n) ans+=1ll*aa[(i+ind)%n]*bb[i];
    printf("%lld\n",ans);
    return 0;
}
