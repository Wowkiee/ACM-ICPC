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
//------

const int N=101010;
int n,m;
int a[N];

int cntn;
int root[N];
int ls[N*88], rs[N*88];
ll sum[N*88], add[N*88];

void build(int &now,int l,int r) {
    now=cntn++;
    add[now]=0;
    if(l==r) {
        sum[now]=a[l];
        return ;
    }
    int mid=l+r>>1;
    build(ls[now], l, mid);
    build(rs[now], mid+1, r);
    sum[now]=sum[ls[now]]+sum[rs[now]];
}

void upd(int pre,int &now,int L,int R,ll c,int l,int r) {
    now=cntn++;
    ls[now]=ls[pre];
    rs[now]=rs[pre];
    sum[now]=sum[pre]+c*(min(r,R)-max(l,L)+1);;
    add[now]=add[pre];
    if(L<=l&&r<=R) {
        add[now]+=c;
        return ;
    }
    int mid=l+r>>1;
    if(L<=mid) upd(ls[pre], ls[now], L, R, c, l, mid);
    if(R>=mid+1) upd(rs[pre], rs[now], L, R, c, mid+1, r);
}

ll qry(int rt, int L, int R, int l, int r) {
    if(L<=l&&r<=R) return sum[rt];
    int mid=l+r>>1;
    ll ans=add[rt]*(min(r,R)-max(l,L)+1);
    if(L<=mid) ans+=qry(ls[rt], L, R, l, mid);
    if(R>=mid+1) ans+=qry(rs[rt], L, R, mid+1, r);
    return ans;
}

int main() {
    while(~scanf("%d%d",&n,&m)) {
        ///init
        cntn=0;
        ///read
        rep(i,1,n+1) scanf("%d",a+i);
        ///solve
        int tim=0;
        build(root[tim],1,n);
        while(m--) {
            char s[11];scanf("%s",s);
            char ch = s[0];
            if(ch=='C') {
                int l,r,d;scanf("%d%d%d",&l,&r,&d);
                ++tim;
                upd(root[tim-1],root[tim],l,r,d,1,n);
            } else if(ch=='Q') {
                int l,r;scanf("%d%d",&l,&r);
                printf("%lld\n",qry(root[tim], l, r, 1, n));
            } else if(ch=='H') {
                int l,r,t;scanf("%d%d%d",&l,&r,&t);
                printf("%lld\n",qry(root[t], l, r, 1, n));
            } else {
                int t;scanf("%d",&t);
                tim = t;
            }
        }
    }
    return 0;
}
