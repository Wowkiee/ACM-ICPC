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
const int N = 100005;
int s[N];int l[N<<1] , n , m;

struct FastIO {
    static const int S = 1310720;
    int wpos; char wbuf[S];
    FastIO() : wpos(0) {}
    inline int xchar() {
        static char buf[S];
        static int len = 0, pos = 0;
        if (pos == len)
            pos = 0, len = fread(buf, 1, S, stdin);
        if (pos == len) return -1;
        return buf[pos ++];
    }
    inline int xuint() {
        int c = xchar(), x = 0;
        while (c <= 32 && ~c) c = xchar();
        if (c == -1) return -1;
        for (;'0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x;
    }
    inline int xint() {
        int s = 1, c = xchar(), x = 0;
        while (c <= 32) c = xchar();
        if (c == '-') s = -1, c = xchar();
        for (; '0' <= c && c <= '9'; c = xchar()) x = x * 10 + c - '0';
        return x * s;
    }
    inline void xstring(char *s) {
        int c = xchar();
        while (c <= 32) c = xchar();
        for(; c > 32; c = xchar()) *s++ = c;
        *s = 0;
    }
    inline void wchar(int x) {
        if (wpos == S) fwrite(wbuf, 1, S, stdout), wpos = 0;
        wbuf[wpos ++] = x;
    }
    inline void wint(ll x) {
        if (x < 0) wchar('-'), x = -x;

        char s[24];
        int n = 0;
        while (x || !n) s[n ++] = '0' + x % 10, x /= 10;
        while (n--) wchar(s[n]);
    }
    inline void wstring(const char *s) {
        while (*s) wchar(*s++);
    }
    ~FastIO() {
        if (wpos) fwrite(wbuf, 1, wpos, stdout), wpos = 0;
    }
} io;
void manacher(int *s,int n,int *l){
    l[0]=1;
    for(int i=1,j=0;i<(n<<1)-1;++i){
        int p=i>>1,q=i-p,r=((j+1)>>1)+l[j]-1;
        l[i]=r<q?0:min(r-q+1,l[(j<<1)-i]);
        while(p-l[i]!=-1&&q+l[i]!=n&&s[p-l[i]]==s[q+l[i]]) l[i]++;
        if(q+l[i]-1>r) j=i;
    }
}

vector<pair<pii,int> > ql,qr;
ll sum[N],ans[N];
struct Tree{
#define lson c<<1,l,m
#define rson c<<1|1,m+1,r
#define pos int c,int l,int r
    ll sum[N<<2],f[N<<2],g[N<<2],ans[N<<2],len[N<<2];
    void up(int c){ans[c]=ans[c<<1]+ans[c<<1|1];}
    void F(int c,ll t){f[c]+=t,ans[c]+=t*sum[c];}
    void G(int c,ll t){g[c]+=t,ans[c]+=t*len[c];}
    void down(int c){
        if(f[c]) F(c<<1,f[c]) , F(c<<1|1,f[c]) , f[c]=0;
        if(g[c]) G(c<<1,g[c]) , G(c<<1|1,g[c]) , g[c]=0;
    }
    void Build(pos){
        sum[c]=f[c]=g[c]=ans[c]=0;len[c]=r-l+1;
        if(l==r) sum[c]=(l?::sum[l-1]:0);
        else {
            int m=(l+r)>>1;
            Build(lson);Build(rson);
            sum[c]=sum[c<<1]+sum[c<<1|1];
        }
    }
    ll Ans(pos,int L,int R){
        if(L <= l && r <= R) return ans[c];
        else {
            int m=(l+r)>>1;ll s=0;
            down(c);
            if(L<=m) s+=Ans(lson,L,R);
            if(R>m) s+=Ans(rson,L,R);
            return s;
        }
    }
    void Mod(pos,int L,int R,ll x,int type){
        if(L <= l && r <= R) type?G(c,x):F(c,x);
        else {
            int m=(l+r)>>1;
            down(c);
            if(L<=m) Mod(lson,L,R,x,type);
            if(R>m) Mod(rson,L,R,x,type);
            up(c);
        }
    }
}tree;

void solve(int *s,vector<pair<pii,int> >&v){
    manacher(s,n,l);
    sort(all(v));
    rep(i,0,n) sum[i]=(i?sum[i-1]:0)+s[i];
#define rt 1,0,n-1
    tree.Build(rt);
    for(int i=0,j=0;i<(n<<1)-1;++i){
        int p=i>>1;
        if(l[i]){
            tree.Mod(rt,p-l[i]+1,p,-2,0); // *
            tree.Mod(rt,p-l[i]+1,p,sum[p]+(i&1?sum[p]:(i?sum[p-1]:0)),1); // +
        }
        for(;j<sz(v)&&v[j].fi.fi==i;++j)
            ans[v[j].se]+=tree.Ans(rt,v[j].fi.se,p);
    }
}

int main(){
    n = io.xint();
    m = io.xint();
    rep(i,0,n) s[i] = io.xint();
    rep(i,0,m){
        int u , v;
        u = io.xint() , v = io.xint();
        --u;--v;
        if(u > v) swap(u,v);
        ql.pb(mp(mp(u+v,u),i));
        if(u==v) continue;
        u=n-1-u,v=n-1-v;swap(u,v);
        qr.pb(mp(mp(u+v-1,u),i));
    }
    solve(s,ql);
    reverse(s,s+n);
    solve(s,qr);
    rep(i,0,m) io.wint(ans[i]) , io.wchar('\n');
    return 0;
}
