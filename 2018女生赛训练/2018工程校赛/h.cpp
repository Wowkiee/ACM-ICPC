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
#define dd(x) cout<<#x<<" = "<<x<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const double PI = acos(-1.0);
struct Complex{
    double x,y;
    Complex(double _x = 0.0,double _y = 0.0){
        x = _x,y = _y;
    }
    Complex operator+(const Complex &p) {
        return Complex(x+p.x,y + p.y);
    }
    Complex operator-(const Complex &p) {
        return Complex(x-p.x,y - p.x);
    }
    Complex operator*(const Complex &p) {
        return Complex(x*p.x-y*p.y,x*p.y+y*p.x);
    }
};

void fft(Complex x[],int len,int on){
    for(int i=1,j=len/2;i<len-1;++i){
        if(i < j) swap(x[i],x[j]);
        int k = len >> 1;
        while(j >= k){
            j-=k;
            k >>= 1;
        }
        if(j < k) j+=k;
    }
    for(int h=2;h<=len;h<<=1){
        Complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j=0;j<len;j+=h){
            Complex w(1,0);
            for(int k=j;k<j+h/2;++k){
                Complex u=x[k];
                Complex t=w*x[k+h/2];
                x[k]=u+t;
                x[k+h/2]=u-t;
                w=w*wn;
            }
        }
    }
    if(on==-1) {
        for(int i=0;i<len;++i) x[i].x/=len;
    }
}
const int N = (1 << 19);
Complex x1[N],x2[N];
ll ans = 0,tt;

//int a[N], b[N];

int main(){
    de(N);
    int n,t;scanf("%d",&n);
    rep(i,0,n){
        scanf("%d",&t);
        x1[i] = x1[i + n] = Complex(t,0);
    //    a[i]=a[i+n]=t;
    }
    rep(i,0,n){
        scanf("%d",&t);
        x2[n - i - 1] = Complex(t,0);
      //  b[n-i-1]=t;
    }
    int len = 1;
    while(len < n * 4) len <<= 1;
   // for(int i = n * 2;i < len;++i) x1[i] = Complex(0,0);
   // for(int i = n;i < len;++i) x2[i] = Complex(0,0);

 //  de(len);
    fft(x1,len,1);
    fft(x2,len,1);
   // fft(x1,len,-1);
    cout<<"-----------------"<<endl;

    for(int i = 0;i < len;++i) printf("%.lf %.lf\n",x1[i].x,x1[i].y);
    cout<<"-----------------"<<endl;
   // for(int i = 0;i < len;++i) printf("%.lf %.lf\n",x2[i].x,x2[i].y);
   // cout<<"========================"<<endl;

    for(int i = 0;i < len;++i) x1[i] = x1[i] * x2[i];

    fft(x1,len,-1);

    for(int i = n-1;i < 2*n-1;++i){
        tt = x1[i].x + 0.5;
        dd(i);de(tt);
        ans = max(ans,tt);
    }
    printf("%lld\n",ans);
    return 0;
}
