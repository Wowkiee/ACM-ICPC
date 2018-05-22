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
const int inf = 1e9 + 10;
typedef db T;
typedef complex<T> P;
T dot(P a,P b){return (conj(a)*b).real();}
T cross(P a,P b){return (conj(a)*b).imag();}
T angle(P a,P b){return arg(b-a);}
T angle(P a,P o,P b){return abs(remainder(arg(a-o)-arg(b-o),2.*M_PI));}
P in(){
    db x,y;scanf("%lf%lf",&x,&y);
    return P(x,y);
}
const int N = 10100 * 2;
P a[N],b[N];
vi g[N],cir[N];db area[N];int id[N] , ccnt;
struct L{
    int s,t,c,v,nxt;
    L(int _s=0,int _t=0,int _c=0,int _v=0){s=_s,t=_t,c=_c,v=_v;}
}l[N];int lcnt;
bool Cmp(int x,int y){
    return angle(b[l[x].s],b[l[x].t]) < angle(b[l[y].s],b[l[y].t]);
}
void ins(int u,int v,int c){
    l[lcnt] = L(u,v,c,0);
    g[u].pb(lcnt++);
}
int cnta,n,m,u,v,c;
bool in(P a,vi&cir){
    db ag = 0.;
    rep(i,0,sz(cir)){
        P u = b[l[cir[i]].s] , v = b[l[cir[i]].t];
        db del = angle(u , a , v);
        if(cross(u - a , v - a) >= 1e-8) ag += del;
        else ag -= del;
    }
    return fabs(ag) > 1;
}
bool in(vi&cira,vi&cir){
    rep(j,0,sz(cira)) if(!in(b[l[cira[j]].s] , cir)) return false;
    return true;
}

template<class T>
struct Dinic{ // [0,n) init!!
    const static int N = 200 , M = 1000;
    int s , t , n , h[N] , cur[N] , level[N] , q[N] , e , ne[M] , to[M];
    T cap[M] , flow;
    void liu(int u,int v,T w){ to[e] = v;ne[e] = h[u];cap[e] = w;h[u] = e++;};
    void link(int u,int v,T w){ liu(u , v , w);liu(v , u , 0);}
    void ini(int _n = N) { fill(h , h + (n=_n) , -1);e = 0;}
    bool bfs(){
        int L = 0 , R = 0;
        fill(level , level + n , -1);
        level[q[R++] = s] = 0;
        while(L < R && level[t] == -1){
            int c = q[L++];
            for(int k=h[c];~k;k=ne[k])
                if(cap[k] > 0 && level[to[k]] == -1)
                    level[q[R++] = to[k]] = level[c] + 1;
        }
        return ~level[t];
    }
    T dfs(int c,T mx){
        if(c == t) return mx;
        T ret = 0;
        for(int &k = cur[c];~k;k = ne[k]){
            if(level[to[k]] == level[c] + 1 && cap[k] > 0){
                T flow = dfs(to[k] , min(mx , cap[k]));
                ret += flow;cap[k] -= flow , cap[k^1] += flow;mx -= flow;
                if(!mx) return ret;
            }
        }
        level[c] = -1;
        return ret;
    }
    T run(int _s,int _t){
        s = _s , t = _t;
        while(bfs()){
            copy(h , h + n , cur);
            flow += dfs(s,~0U>>1);
        }
        return flow;
    }
};
Dinic<int> flow[11];
int ans[100] , belong[100];
int SS , TT;
void dfs(int dep,int mask){
    flow[dep].run(SS,TT);
    if(dep == cnta){
        int c1 = __builtin_popcount(mask);
        ans[c1] = min(ans[c1] , flow[dep].flow);
    }
    else{
        flow[dep+1] = flow[dep];
        dfs(dep + 1 , mask << 1);
        flow[dep+1].link(SS , belong[dep] , inf);
        dfs(dep + 1 , mask << 1 | 1);
    }
}

int main(){
    fill(ans , ans + 100 , inf);
    scanf("%d%d%d",&cnta,&n,&m);
    rep(i,0,cnta) a[i] = in();
    rep(i,0,n) b[i] = in();
    b[n] = P(-inf,-inf) , b[n + 1] = P(inf,-inf);
    b[n + 2] = P(inf,inf) , b[n + 3] = P(-inf,inf);
    rep(i,0,m){
        scanf("%d%d%d",&u,&v,&c);
        --u;--v;
        ins(u , v , c);
        ins(v , u , c);
    }
    rep(i,0,4) ins(n + i , n + (i+1)%4 , inf) , ins(n + (i+1)%4 , n + i , inf);
    rep(i,0,n+4){
        sort(all(g[i]) , Cmp);
        rep(j,0,sz(g[i])){
            int u = g[i][j]^1 , v = g[i][(j+1)%sz(g[i])];
            l[u].nxt = v;
        }
    }
    rep(i,0,lcnt) if(!l[i].v){
        ++ccnt;int c = i , s = l[i].s;
        area[ccnt] = 0.;
        do {l[c].v = ccnt , cir[ccnt].pb(c) , area[ccnt] += cross(b[l[c].s],b[l[c].t]) , c = l[c].nxt;}while(l[c].s != s);
        //rep(i,0,sz(cir[ccnt])) cout << cir[ccnt][i] << " " << b[l[cir[ccnt][i]].s] << " \n"[i == sz(cir[ccnt]) - 1];
        //cout << area[ccnt] << endl;
    }
    // area < 0 : in
    db Min = 0;
    SS = 0 , TT = 0;
    rep(i,1,ccnt+1) if(area[i] < Min) Min = area[i] , TT = i;
    rep(i,1,ccnt+1)
        if(area[i] >= 0){
            rep(j,1,ccnt+1) if(area[j] < 0 && (fabs(area[j]) > fabs(area[i])))
                if(in(cir[i], cir[j]))
                    if(!id[i] || (area[j] > area[id[i]]))
                        id[i] = j;
        }
    rep(i,1,ccnt+1) if(!id[i]) id[i] = i;
    rep(i,0,cnta) rep(j,1,ccnt+1) if(area[j] < 0 && in(a[i] , cir[j]))
        if(!belong[i] || area[j] > area[belong[i]]) belong[i] = j;
    flow[0].ini(ccnt + 1);
    rep(i,0,lcnt) flow[0].liu(id[l[i].v] , id[l[i^1].v] , l[i].c);
    dfs(0,0);
    rep(i,1,cnta+1) printf("%d\n",ans[i]);
    return 0;
}
