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

const int N = 303030, P = 1e9+7, M = 1010101;

int ans[M], res[M];

inline int mul(int a, int b) {
    return 1ll * a * b % P;
}
inline int add(int a, int b) {
    int r = a + b;
    if(r >= P) r -= P;
    return r;
}
inline int sub(int a, int b) {
    int r = a - b;
    if(r < 0) r += P;
    return r;
}

struct SAM{
    static const int N = ::N << 1 , M = 26;
    int par[N] , l[N] , ne[N][M], sum[N], vis[N], Vis[N];
    int rt , last , L;
    void add(int c){
        int p = last , np = ++L;
        fill(ne[np] , ne[np] + M , 0);
        sum[np] = 1;
        l[np] = l[p] + 1;
        last = np;
        while(p && !ne[p][c]) ne[p][c] = np , p = par[p];
        if(!p) par[np] = rt;
        else{
            int q = ne[p][c];
            if(l[q] == l[p] + 1) par[np] = q;
            else{
                int nq = ++L;
                l[nq] = l[p] + 1;
                sum[nq] = 1;
                copy(ne[q] , ne[q] + M , ne[nq]);
                par[nq] = par[q];
                par[q] = par[np] = nq;
                while(p && ne[p][c] == q) ne[p][c] = nq , p = par[p];
            }
        }
    }
    void ini(){
        rt = last = L = 1;
        fill(ne[rt] , ne[rt] + M , 0);
        l[0] = -1;
    }
    void build(string s, int val, int tim) {
        int p = rt;
        for(auto u : s) {
            int c = u - 'a';
            p = ne[p][c];
            int q = p;
            while(q != rt && vis[q] != tim) {
                vis[q] = tim;
                sum[q] = mul(sum[q], val);
                q = par[q];
            }
        }
    }
    void dfs(int p) {
        int f = par[p];
        ans[l[f]+1] = ::add(ans[l[f]+1], sum[p]);
        ans[l[p]+1] = ::sub(ans[l[p]+1], sum[p]);
        Vis[p] = 1;
        rep(i, 0, 26) if(ne[p][i] && !Vis[ne[p][i]]) {
            dfs(ne[p][i]);
        }
    }
}sam;

int n;
int a[10101];
string s[10101];

inline int kpow(int a, int b) {
    int r = 1;
    while(b) {
        if(b & 1) r = mul(r, a);
        a = mul(a, a);
        b >>= 1;
    }
    return r;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n;
    sam.ini();
    rep(i, 1, n+1) {
        cin >> s[i];
        sam.last = 1;
        for(auto j : s[i]) {
            sam.add(j - 'a');
        }
    }
    rep(i, 1, n+1) {
        cin >> a[i];
        sam.build(s[i], a[i], i);
    }
    ans[1] = 0;
    sam.dfs(1);
    rep(i, 1, M) ans[i] = add(ans[i], ans[i-1]);
    rep(i, 1, M) ans[i] = add(ans[i], ans[i-1]);
    res[0] = 1;
    rep(i, 1, M) res[i] = mul(res[i-1], 26);
    rep(i, 2, M) res[i] = add(res[i], res[i-1]);
    rep(i, 1, M) ans[i] = mul(ans[i], kpow(res[i], P-2));
    int q;
    cin >> q;
    while(q--) {
        int x;
        cin >> x;
        cout << ans[x] << endl;
    }
    return 0;
}
