#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---
 
const int N = 202020, P = 1e9+7;
 
int n, d, np;
int A[N], sz[N], dep[N], belong[N], cnt[N], pre[N], cc[N], pp[N], par[N], pw[N], p[N], maxd[N];
bool vis[N], ok[N];
vi g[N];
unordered_map<int, int> B[N];
 
inline int add(int a, int b) {
    if((a += b) >= P) a -= P;
    return a;
}
inline int sub(int a, int b) {
    if((a -= b) < 0) a += P;
    return a;
}
inline int mul(int a, int b) {
    return 1ll * a * b % P;
}
 
void dfssz(int c, int fa, int Sz, int &rt) {
    sz[c] = 1;
    for(auto t : g[c]) if(!vis[t] && t != fa) dfssz(t, c, Sz, rt), sz[c] += sz[t];
    if(!rt && sz[c] * 2 > Sz) rt = c;
}
void dfs2(int u, int fa, int top) {
    p[np++] = u;
    dep[u] = dep[fa] + 1;
    if(u <= n) maxd[top] = max(maxd[top], dep[u]);
    belong[u] = top;
    par[u] = fa;
    for(auto v : g[u]) if(!vis[v] && v != fa) dfs2(v, u, top);
}
void dfs(int c) {
    int rt = 0;
    dfssz(c, 0, 0, rt);
    dfssz(c, 0, sz[c], rt = 0);
    int u = rt;
 
    np = dep[u] = 0;
    p[np++] = u;
    for(auto v : g[u]) if(!vis[v]) {
        maxd[v] = 0;
        dfs2(v, u, v);
        maxd[u] = max(maxd[u], maxd[v]);
    }
    assert(np < N);
    fill_n(cnt, maxd[u]+1, 0);
    rep(i, 0, np) {
        int v = p[i];
        if(v <= n && dep[v] == d) ++B[u][belong[v]];
        if(v <= n) ++cnt[dep[v]];
    }
    pre[0] = cnt[0];
    rep(i, 1, maxd[u]+1) pre[i] = pre[i-1] + cnt[i];
    A[u] += pre[min(d - 1, maxd[u])];
 
    for(int i = 1, j; i < np; i = j + 1) {
        j = i;
        while(j < np-1 && belong[p[j+1]] == belong[p[i]]) ++j;
        int v = belong[p[i]];
        fill_n(cc, maxd[v]+1, 0);
        rep(k, i, j + 1) if(p[k] <= n) ++cc[dep[p[k]]];
        pp[0] = cc[0];
        rep(i, 1, maxd[v]+1) pp[i] = pp[i-1] + cc[i];
        rep(k, i, j + 1) if(ok[p[k]]) {
            int t = p[k], _ = d - dep[t];
            if(_ - 1 >= 0) {
                A[t] += pre[min(_ - 1, maxd[u])];
                A[t] -= pp[min(_ - 1, maxd[v])];
            }
            if(_ >= 0) {
                int c = 0;
                if(_ <= maxd[u]) c += cnt[_];
                if(_ <= maxd[v]) c -= cc[_];
                if(c) B[t][par[t]] += c;
            }
        }
    }
 
    vis[u] = 1;
    for(auto t : g[u]) if(!vis[t]) dfs(t);
}
 
int main() {
    ///init
    pw[0] = 1;
    rep(i, 1, N) pw[i] = mul(2, pw[i-1]);
    ///read
    scanf("%d", &n);
    rep(i, 1, n) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].pb(i + n), g[i + n].pb(u);
        g[v].pb(i + n), g[i + n].pb(v);
    }
    scanf("%d", &d);
    ///solve
    if(d & 1) rep(i, n+1, n<<1) ok[i] = 1;
    else rep(i, 1, n+1) ok[i] = 1;
 
    dfs(1);
 
    int st = (d & 1) ? n + 1 : 1, ed = (d & 1) ? (n << 1) : n + 1;
    ll ans = 0;
    rep(i, st, ed) {
        int b = 0;
        ll res = 0;
        for(auto j : B[i]) {
            (res += pw[j.se] + P - 1) %= P;
            b += j.se;
        }
        res = sub(pw[b], add(res, 1));
        (res *= pw[A[i]]) %= P;
        ans = add(ans, res);
    }
    printf("%lld\n", ans);
    return 0;
}
