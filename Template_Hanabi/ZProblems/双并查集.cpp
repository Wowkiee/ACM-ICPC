#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
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
const int N = 300003;
int n , m , p , par[N] , sz[N] , wson[N] , top[N] , dep[N] , edgecnt[N];
int A[N] , B[N];
struct Event{
    int w,u,v,id;
}event[N];
vector<pii> fobid[N] , block;
int FA(int x){return A[x]==x?x:A[x]=FA(A[x]);}
int FB(int x){return B[x]==x?(!x||FA(x)!=FA(par[x])?x:B[x]=FB(par[x])):B[x]=FB(B[x]);}
int Lca(int x,int y){
    while(top[x]!=top[y]) dep[top[x]]>dep[top[y]]?x=par[top[x]]:y=par[top[y]];
    return dep[x]<dep[y]?x:y;
}

int main(){
    scanf("%d%d%d",&n,&m,&p);
    rep(i,2,n+1) scanf("%d",par + i),dep[i]=dep[par[i]]+1;
    rep(i,1,n+1) A[i]=B[i]=i;
    for(int i=n;i>=2;--i) sz[par[i]]+=++sz[i],(sz[i]>sz[wson[par[i]]])&&(wson[par[i]]=i);
    rep(i,1,n+1) top[i]=wson[par[i]]==i?top[par[i]]:i;
    rep(i,0,m) scanf("%d%d%d",&event[i].u,&event[i].v,&event[i].w),event[i].id=i;
    int t,a,b;rep(i,0,p) scanf("%d%d%d",&t,&a,&b) , fobid[--t].pb(mp(a,b));
    sort(event,event+m,[&](const Event&a,const Event&b){return a.w<b.w;});
    ll ans = 0;
    rep(i,0,m){
        int u=event[i].u,v=event[i].v,w=event[i].w,id=event[i].id;
        for(auto&e:fobid[id]){
            e.fi = FA(e.fi) , e.se = FA(e.se);
            if(e.fi < e.se) swap(e.fi,e.se);
        }
        sort(all(fobid[id]));
        vector<pii> block , preblock , nxtblock;
        int lca=Lca(u,v);
        for(;FB(u)!=FB(lca);u=par[FB(u)])
            block.pb(mp(FA(u) , dep[u]-dep[FB(u)]+1));
        for(;FB(v)!=FB(lca);v=par[FB(v)])
            block.pb(mp(FA(v) , dep[v]-dep[FB(v)]+1));
        block.pb(mp(FA(lca) , dep[u]+dep[v]-2*dep[lca]+1));
        sort(all(block));
        for(int i=0,j=0,k=0;i<sz(block);i=j){
            pii info = mp(block[j].fi , 0);
            for(j=i;j<sz(block) && block[j].fi==block[i].fi;++j)
                info.se += block[j].se;
            for(;k<sz(fobid[id])&&fobid[id][k].fi == info.fi;++k)
                edgecnt[FA(fobid[id][k].se)]++;
            int Sum = 0;
            for(auto e : preblock){
                if(edgecnt[e.fi] < 1ll * e.se * info.se)
                    A[e.fi] = info.fi , Sum += e.se , ans += w;
                else nxtblock.pb(e);
                edgecnt[e.fi] = 0;
            }
            edgecnt[info.fi] = 0;
            nxtblock.pb(mp(info.fi , info.se + Sum));
            swap(preblock , nxtblock);nxtblock.clear();
        }
    }
    printf("%lld\n",ans);
    return 0;
}
