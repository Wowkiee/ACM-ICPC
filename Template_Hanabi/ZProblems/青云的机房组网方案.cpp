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
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define setIO(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
const int N = 101000;
vi G[N] , fac[N];
int mu[N] , p[N] , dep[N] , lg[N<<1] , lft[N<<1] , n;
ll ans;
struct RMQ{
    int a[20][N<<1] , L;
    int rmin(int x,int y){return dep[x] < dep[y] ? x : y;}
    void Build(){
        rep(i,1,20){
            int lim = L + 1 - (1<<i);
            rep(j,0,lim) a[i][j] = rmin(a[i-1][j] , a[i-1][j+(1<<i>>1)]);
        }
    }
    int lca(int x,int y){
        if(x == y) return x;
        x = lft[x] , y = lft[y];
        if(x > y) swap(x , y);
        int j = lg[y-x+1];
        return rmin(a[j][x] , a[j][y+1-(1<<j)]);
    }
    void add(int x){
        a[0][L++] = x;
    }
}R;
vi V[N];
void dfs(int c,int fa){
    dep[c] = dep[fa] + 1;
    lft[c] = R.L;R.add(c);
    for(int t : fac[p[c]]) V[t].pb(c);
    for(int t : G[c]) if(t != fa){
        dfs(t , c);
        R.add(c);
    }
}
vi g[N];int tp[N] , _ , w;
ll dn[N] , up[N] , sz[N] , rt;
void DFS1(int c,int fa){
    dn[c] = 0;sz[c] = p[c] % w == 0;
    for(int t : g[c]) if(t != fa){
        DFS1(t , c);
        dn[c] += sz[t] * (dep[t] - dep[c]) + dn[t];
        sz[c] += sz[t];
    }
}
void DFS2(int c,int fa){
    if(fa == 0) up[c] = 0;
    for(int t : g[c]) if(t != fa){
        up[t] = (sz[rt] - 2 * sz[t]) * (dep[t] - dep[c]) + up[c] + dn[c] - dn[t];
        DFS2(t , c);
    }
}
ll solve(vi&v){
    if(sz(v) <= 1) return 0;
    _ = 0;
    vi del;del.pb(tp[_++] = v[0]);
    rep(i,1,sz(v)){
        int lca = R.lca(tp[_-1] , v[i]);
        vi l;while(_ > 0 && dep[lca] < dep[tp[_-1]]) l.pb(tp[--_]);
        if(_ == 0 || lca != tp[_-1]) del.pb(tp[_++] = lca);
        l.pb(tp[_-1]);del.pb(tp[_++] = v[i]);
        rep(i,1,sz(l)) g[l[i]].pb(l[i-1]);
    }
    rep(i,0,_-1) g[tp[i]].pb(tp[i+1]);
    DFS1(rt = tp[0] , 0);
    DFS2(rt , 0);
    ll ret = 0;
    for(int t : del) {
        if(p[t] % w == 0) ret += dn[t] + up[t];
        g[t].clear();
    }
    return ret / 2;
}

int main(){
    rep(i,2,N+N)  lg[i] = lg[i-1] + (i == (i&-i));
    mu[1] = 1;rep(i,1,N) for(int j=i+i;j<N;j+=i) mu[j] -= mu[i] , fac[j].pb(i);
    rep(i,1,N) fac[i].pb(i);
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",p + i);
    rep(i,1,n){
        int u , v;
        scanf("%d%d",&u,&v);
        G[u].pb(v);
        G[v].pb(u);
    }
    dfs(1 , 0);
    R.Build();
    rep(i,1,N) if(mu[i]) ans += mu[i] * solve(V[w = i]);
    printf("%lld\n",ans);
    return 0;
}
