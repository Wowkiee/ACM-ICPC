#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
const int Q = 1e4 + 7 , P = Q * Q , N = 100001;
int n , m;
int pri[N] , phi[N] , vis[N];
void Phi(){
    phi[1] = 1;
    for(int i=2,p=0;i<N;++i){
        if(!vis[i]) pri[p++] = i , phi[i] = i-1;
        for(int j=0,o;j<p&&(o=pri[j]*i)<N;++j){
            vis[o] = true;
            phi[o] = phi[i] * (pri[j] - 1);
            if(i % pri[j] == 0){
                phi[o] = phi[i] * pri[j];
                break;
            }
        }
    }
}
void pp(int&a,int b){
    a += b;
    if(a >= P) a -= P;
}
int Pow(int a,int b){ll r=1;for(;b;b>>=1,a=(ll)a*a%P)if(b&1)r=(ll)r*a%P;return r;}
typedef map<int,int> Poly;
ll a[100] , b[100] , _;int cnt[4];char s[200];
void out(Poly a){
    cout << "~~~~~~~~~~~~~" << endl;
    for(Poly::iterator i = a.begin();i != a.end();++i)
        cout << i->first << " " << i->second <<endl;
}
Poly operator * (Poly a,Poly b){
    Poly r;
    for(Poly::iterator i = a.begin();i != a.end();++i)
        for(Poly::iterator j = b.begin();j != b.end();++j)
            pp(r[(i->first + j->first) % P] , (ll)i->second * j->second % P);
    return r;
}
ll solve(int x){
    if(n / x % 2 == 0 && cnt[0]) return 0;
    if(cnt[0] + cnt[2] > x) return 0;
    int ret = 0;
    for(int i=0;i<_;++i) pp(ret , (ll)Pow(a[i] , x) * b[i] % P);
    return ret;
}
int main(){
    Phi();
    while(~scanf("%d%d",&m,&n)&&(n||m)){
        scanf("%s",s);fill(cnt , cnt + 4 , 0);int Magic = 1;
        for(int i=0;i<m;++i) cnt[s[i] - 'A']++ , (s[i] - 'A' <= 1 && (Magic<<=1));
        Poly Po , p[4];Po[0] = 1;p[0][1] = p[1][P-1] = p[1][1] = 1;p[0][P-1] = P-1;
        p[2][1] = p[3][1] = 1;p[2][0] = P-1;
        for(int i=0;i<m;++i) Po = Po * p[s[i] - 'A'];
        _ = 0;
        for(Poly::iterator i = Po.begin();i != Po.end();++i) if(i->second) a[_] = i->first , b[_++] = i->second;
        int ans = 0;
        for(int i=1;i*i<=n;++i) if(n % i == 0){
            pp(ans , (ll)solve(i) * phi[n/i] % P);
            if(i * i != n) pp(ans , (ll)solve(n/i) * phi[i] % P);
        }
        ans = (ll)ans * Pow(Magic , P-2) % P;
        if(n % Q == 0) ans = (ll)ans * Pow(n / Q , P - 2) % P / Q;
        else ans = (ll)ans * Pow(n , P - 2) % Q;
        printf("%d\n",(int)ans);
    }
    return 0;
}
