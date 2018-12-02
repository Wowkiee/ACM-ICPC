#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(x) (int)x.size()
#define de(x) cout<< #x<<" = "<<x<<endl
#define dd(x) cout<< #x<<" = "<<x<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N=333;

int n,m,q;

struct seg {
    ll ma[N<<2];
    void build(int l=1,int r=m,int rt=1) {
        if(l==r) {
            scanf("%lld",ma+rt);
            return ;
        }
        int mid=l+r>>1;
        build(l, mid, rt<<1);
        build(mid+1, r, rt<<1|1);
        ma[rt]=max(ma[rt<<1], ma[rt<<1|1]);
    }
    ll qry(int L,int R,int l=1,int r=m,int rt=1) {
        if(L<=l&&r<=R) return ma[rt];
        int mid=l+r>>1;
        ll ans=0;
        if(L<=mid) ans=max(ans, qry(L, R, l, mid, rt<<1));
        if(R>=mid+1) ans=max(ans, qry(L, R, mid+1, r, rt<<1|1));
        return ans;
    }
};

struct Seg {
    seg ma[N<<2];
    void up(int fa,int L,int R,int l=1,int r=m,int rt=1) {
        ma[fa].ma[rt]=max(ma[L].ma[rt], ma[R].ma[rt]);
        if(l==r) return ;
        int mid=l+r>>1;
        up(fa, L, R, l, mid, rt<<1);
        up(fa, L, R, mid+1, r, rt<<1|1);
    }
    void build(int l=1,int r=n,int rt=1) {
        if(l==r) {
            ma[rt].build();
            return ;
        }
        int mid=l+r>>1;
        build(l, mid, rt<<1);
        build(mid+1, r, rt<<1|1);
        up(rt,rt<<1,rt<<1|1);
    }
    ll qry(int x1,int x2,int y1,int y2,int l=1,int r=n,int rt=1) {
        if(x1<=l&&r<=x2) return ma[rt].qry(y1, y2);
        int mid=l+r>>1;
        ll ans=0;
        if(x1<=mid) ans=max(ans, qry(x1, x2, y1, y2, l, mid, rt<<1));
        if(x2>=mid+1) ans=max(ans, qry(x1, x2, y1, y2, mid+1, r, rt<<1|1));
        return ans;
    }
}T;

int main() {
    while(~scanf("%d%d",&n,&m)) {
        T.build();
        scanf("%d",&q);
        while(q--) {
            int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
            ll ma=T.qry(a, c, b, d);
            ll A=T.qry(a, a, b, b);
            ll B=T.qry(c, c, b, b);
            ll C=T.qry(a, a, d, d);
            ll D=T.qry(c, c, d, d);
            printf("%lld %s\n",ma,(ma==max(max(A, B), max(C, D)))?"yes":"no");
        }
    }
    return 0;
}
