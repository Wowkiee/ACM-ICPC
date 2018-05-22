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
const int N = 202020 , P = 1e9 + 7;
int n;
struct ele{
    int l,r;
    bool operator < (const ele&b) const{
        if(r!=b.r) return r<b.r;
        return l<b.l;
    }
}e[N];
int L[N] , R[N];
vi V;
#define lb(x) (x&(-x))
struct Fenwick{
    int a[N<<1],l;
    int Max(int d){
        int r=0;
        for(int i=d;i>=1;i-=lb(i)) r=max(r,a[i]);
        return r;
    }
    void ins(int d,int x){
        for(int i=d;i<=l;i+=lb(i)) a[i]=max(a[i],x);
    }
}f,g;
void pp(int &a,int d){a+=d;if(a>=P)a-=P;}
int sum[N<<1] , lazy[N<<1];
#define id(l,r) (l+r)|(l!=r)
#define pr int c=id(l,r),mid=(l+r)>>1
void Down(int l,int r){pr;
    if(lazy[c] != 1){
        int lc=id(l,mid),rc=id(mid+1,r);
        lazy[lc] = (ll)lazy[lc]*lazy[c]%P;
        lazy[rc] = (ll)lazy[rc]*lazy[c]%P;
        sum[lc] = (ll)sum[lc]*lazy[c]%P;
        sum[rc] = (ll)sum[rc]*lazy[c]%P;
        lazy[c] = 1;
    }
}
void Up(int l,int r){pr;
    int lc=id(l,mid),rc=id(mid+1,r);
    sum[c] = (sum[lc]+sum[rc])%P;
}
void Ins(int l,int r,int x,int d){ pr;
    if(l == r){
        pp(sum[c] , d);
    } else{
        Down(l,r);
        if(x<=mid) Ins(l,mid,x,d);
        else Ins(mid+1,r,x,d);
        Up(l,r);
    }
}
void Mul2(int l,int r,int L,int R){pr;
    if(L <= l && r <= R){
        pp(lazy[c],lazy[c]);
        pp(sum[c],sum[c]);
    } else {
        Down(l,r);
        if(L<=mid) Mul2(l,mid,L,R);
        if(R>mid) Mul2(mid+1,r,L,R);
        Up(l,r);
    }
}
int Sum(int l,int r,int L,int R){pr;
    if(L <= l && r <= R){
        return sum[c];
    } else {
        Down(l,r);
        int ret=0;
        if(L<=mid) pp(ret,Sum(l,mid,L,R));
        if(R>mid) pp(ret,Sum(mid+1,r,L,R));
        Up(l,r);
        return ret;
    }
}


int main(){
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d%d",&e[i].l,&e[i].r) , V.pb(e[i].l) , V.pb(e[i].r);
    sort(all(V));V.erase(unique(all(V)) , V.end());
    sort(e + 1, e + n + 1);
#define Rk(x) lower_bound(all(V) , x) - V.begin() + 1
    rep(i,1,n+1) e[i].l = Rk(e[i].l) , e[i].r = Rk(e[i].r);
    f.l = g.l = sz(V) + 1;
    rep(i,1,n+1){
        L[i] = f.Max(e[i].l - 1);
        f.ins(e[i].r,i);
    }
    for(int i=n;i>=1;--i){
        R[i] = n + 1 - g.Max(f.l - e[i].r);
        g.ins(f.l - e[i].l + 1 ,n + 1 - i);
    }
    fill(lazy,lazy+(N<<1),1);
    Ins(0,n+1,1,1);Ins(0,n+1,R[1],1);
    rep(i,2,n+1){
        Ins(0,n+1,R[i],Sum(0,n+1,L[i]+1,R[i]));
        Mul2(0,n+1,0,L[i]);
    }
    printf("%d\n",Sum(0,n+1,n+1,n+1));
    return 0;
}
