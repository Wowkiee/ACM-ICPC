#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <complex>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define setIO(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
const int N = 50001 * 3;
typedef complex<ll> P;
typedef map<ll,P> hull;
#define X real()
#define Y imag()
P a[N] , b[N] , O;int _;
int A(const P&a){ return (a.X >= 0) ^ ((a.Y < 0) + 1);}
ll cross(const P&a,const P&b){return (conj(a)*b).Y;}
bool Cmp(const P&a,const P&b){
    int x = A(a) , y = A(b);
    if(x != y) return x < y;
    return cross(a,b) > 0;
}
hull h1,h2;
bool in(hull&h,ll x,ll y){
    if(!sz(h)) return false;
    if(x < h.begin()->se.X || x > h.rbegin()->se.X) return false;
    auto l = h.lower_bound(x);
    if(x == l->se.X) return y <= l->se.Y;
    auto r = l--;
    return cross(r->se - l->se , P(x,y) - l->se) <= 0;
}

void ins(hull&h,ll x,ll y){
    if(in(h , x , y)) return;
    P p(x,y);h[x] = p;
    auto LL = h.find(x) , RR = LL , L = LL , R = L;
    if(LL != h.begin()) --LL;
    if(*RR != *h.rbegin()) ++RR;
    if(L != h.begin()) while((L = LL) != h.begin()){
        --(LL = L);
        if(cross(p - LL->se , L->se - LL->se) <= 0) h.erase(L);
        else break;
    }
    if(*R != *h.rbegin()) while(*(R = RR) != *h.rbegin()){
        ++(RR = R);
        if(cross(p - RR->se , R->se - RR->se) >= 0) h.erase(R);
        else break;
    }
}
int main(){
    _ = 0;O = P(0,0);
    rep(re,0,3){
        int n;scanf("%d",&n);
        int id = 0;
        rep(i,0,n){
            int x,y;scanf("%d%d",&x,&y);
            a[i] = P(x,y);
            if(a[i].Y < a[id].Y || (a[i].Y == a[id].Y && a[i].X < a[id].X)) id = i;
        }
        O += a[id];a[n] = a[0];
        int __ = _;
        rep(i,id,n) b[__++] = a[i+1] - a[i];
        rep(i,0,id) b[__++] = a[i+1] - a[i];
        inplace_merge(b,b+_,b+__,Cmp);
        _ = __;
    }
    a[0] = O;rep(i,0,_) a[i+1] = a[i] + b[i];
    rep(i,0,_) ins(h1 , a[i].X , a[i].Y) , ins(h2 , a[i].X , -a[i].Y);
    int m;scanf("%d",&m);
    rep(i,0,m){
        int x , y;scanf("%d%d",&x,&y);x*=3;y*=3;
        puts(in(h1,x,y) && in(h2,x,-y) ? "YES" : "NO");
    }
    return 0;
}
