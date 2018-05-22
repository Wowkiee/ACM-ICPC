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
const int N = 110;
typedef unsigned int ui;
int n , m;
map<vi,ui> Mp;
int vis[N],fa[N];
ui Pow[N],sum[N];
int F(int x){return fa[x]==x?x:fa[x]=F(fa[x]);}
vi gt(vi v,int c,int all){
    rep(i,0,all) fa[i] = i;
    rep(i,0,c) fa[F(v[i+c])] = F(v[i]);
    int cc = 0;
    rep(i,0,c+c) {
        if(!vis[F(v[i])]) vis[F(v[i])] = ++cc;
        v[i] = vis[F(v[i])] - 1;
    }
    rep(i,0,all) vis[i] = 0;
    return v;
}
ui dfs(int c,vi&v){
    if(Mp.find(v) != Mp.end()) return Mp[v];
    int cc = 0;
    for(int e : v) if(!vis[e]) vis[e] = true , ++cc;
    for(int e : v) vis[e] = false;
    ui ret = Pow[cc] * sum[n - c];
    if(c + 2 <= n){
        vi nv = v;
        for(int d=c+2;d<=n;d+=2){
            nv.pb(cc++);nv.pb(cc++);
            vi nvv = gt(nv,d/2,cc);
            ret -= dfs(d,nvv);
        }
    }
    return Mp[v] = ret;
}

int main(){
    cin >> n >> m;
    Mp.clear();
    Pow[0] = 1;rep(i,1,N) Pow[i] = Pow[i-1] * m;
    sum[0] = 1;rep(i,1,N) sum[i] = Pow[i] + sum[i-1];
    vi v;
    dfs(0,v);
    cout << Mp[v] - 1 << endl;
    return 0;
}
