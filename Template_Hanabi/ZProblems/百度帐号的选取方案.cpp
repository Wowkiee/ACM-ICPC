#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<b;++i)
#define per(i,a,b) for(int i=b-1;i>=a;--i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define setIO(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);

namespace Doubling{
    static const int N = 101010;
    int t[N] , wa[N] , wb[N] , sa[N] , h[N];
    void sort(int *x,int *y,int n,int m){
        rep(i,0,m) t[i] = 0;
        rep(i,0,n) t[x[y[i]]]++;
        rep(i,1,m) t[i] += t[i-1];
        per(i,0,n) sa[--t[x[y[i]]]] = y[i];
    }
    bool cmp(int *x,int a,int b,int d){
        return x[a] == x[b] && x[a+d] == x[b+d];
    }
    void da(int *s,int n,int m){
        int *x=wa,*y=wb;
        rep(i,0,n) x[i] = s[i] , y[i] = i;
        sort(x , y , n , m);
        for(int j=1,p=1;p<n;m=p,j<<=1){
            p = 0;rep(i,n-j,n) y[p++] = i;
            rep(i,0,n) if(sa[i] >= j) y[p++] = sa[i] - j;
            sort(x , y , n , m);
            std::swap(x , y);p = 1;x[sa[0]] = 0;
            rep(i,1,n) x[sa[i]] = cmp(y,sa[i],sa[i-1],j)?p-1:p++;
        }
    }
    void cal_h(int *s,int n,int *rk){
        int j,k=0;
        for(int i=1;i<=n;++i) rk[sa[i]] = i;
        for(int i=0;i<n;h[rk[i++]] = k)
            for(k&&--k,j=sa[rk[i]-1];s[i+k]==s[j+k];++k);
    }
}
struct DA{
    static const int N = 101010;
    int p[20][N] , rk[N] , in[N] , Log[N] , n;
    void Build(){
        Doubling::da(in,n+1,300);
        Doubling::cal_h(in,n,rk);
        Log[0] = -1;for(int i=1;i<=n;++i) Log[i] = Log[i-1] + (i==(i&(-i)));
        for(int i=1;i<=n;++i) p[0][i] = Doubling::h[i];
        for(int j=1;1<<j<=n;++j){
            int lim = n+1-(1<<j);
            for(int i=1;i<=lim;++i)
                p[j][i] = std::min(p[j-1][i] , p[j-1][i+(1<<j>>1)]);
        }
    }
    int lcp(int a,int b){
        a = rk[a] , b = rk[b];
        if(a > b) std::swap(a , b);++a;
        int t = Log[b-a+1];
        return std::min(p[t][a] , p[t][b-(1<<t)+1]);
    }
}D1,D2;
const int N = 101010;
char s[N];int n;
vector<pair<pii,int> > V[N] , E[N];
pii p[N];

const int M = N<<1;
ll lcnt[N] , rcnt[N];
ll Sum(int l,int r){
    return (ll)(l+r)*(r-l+1)>>1;
}
ll solve(vector<pair<pii,int> > pv){
    vector<pii> v;
    for(auto e : pv){
        int l = e.fi.fi , r = e.fi.se , L = e.se , R = L+r-l;
        lcnt[l]++ , lcnt[L+1]-- , rcnt[r]++ , rcnt[R+1]--;
        v.pb(mp(l-1,1));v.pb(mp(L,2)); // 2 : + , 1 : -
        v.pb(mp(r-1,-2));v.pb(mp(R,-1));
    }
    sort(all(v));
    ll sz = 0 , sum = 0 , f = 0 , pre = -1 , ret = 0;
    for(int i=0;i<sz(v);){
        int nt = v[i].fi;
        sz += (nt - pre) * f;sum += Sum(pre + 1, nt) * f;
        for(;i<sz(v) && v[i].fi == nt;++i){
            if(v[i].se < 0) f += (v[i].se == -2 ? 1 : -1);
            else ret += (v[i].se == 2 ? 1 : -1) * (nt * sz - sum);
        }
        pre = nt;
    }
    return ret;
}

ll solve1(){
    rep(i,1,n) lcnt[i] += lcnt[i-1] , rcnt[i] += rcnt[i-1];
    //rep(i,0,n) printf("%d %d\n",lcnt[i] , rcnt[i]);
    rep(i,1,n) rcnt[i] += rcnt[i-1];
    ll ret = 0;
    rep(i,1,n) ret += (Sum(1,i) - rcnt[i-1]) * (n-i - lcnt[i]);
    return ret;
}
void Upf(int &x,int d){
    if(x < d) x = d;
}
int main(){
    scanf("%s",s);
    n = strlen(s);
    D1.n = n;rep(i,0,n) D1.in[i] = s[i];D1.in[n] = 0;
    D1.Build();
    D2.n = n;rep(i,0,n) D2.in[i] = s[n-i-1];D2.in[n] = 0;
    D2.Build();
    for(int l=1;l<<1<=n;++l)
        for(int c=1;(c+1)*l<=n;++c){
            int left_cnt = D2.lcp(n-(c+1)*l , n-c*l);
            int right_cnt = (c+1)*l<n ? D1.lcp((c+1)*l , c*l) : 0;
            int tot_len = left_cnt + right_cnt + l;
            int repeat = tot_len / l;
            int L = c*l - left_cnt , R = (c+1)*l + right_cnt;
            for(int i=2;i<=repeat;++i){
                V[L].pb(mp(mp(L+i*l-1,R-i*l),i)); // r , R , x
            }
            c += right_cnt / l;
        }
    rep(i,0,n) p[i] = mp(0,0);
    rep(i,0,n){
        for(auto e : V[i]) p[e.fi.fi] = max(p[e.fi.fi] , mp(e.fi.se , e.se));
        for(auto e : V[i]){
            pii&t = p[e.fi.fi];
            if(t != mp(0,0)) E[t.se].pb(mp(mp(i , e.fi.fi) , t.fi)) , t = mp(0,0); // l , r , L
        }
    }
    ll ans = 0;
    rep(i,2,n+1) ans += solve(E[i]);
    ans += solve1();
    printf("%lld\n",ans);
    return 0;
}
