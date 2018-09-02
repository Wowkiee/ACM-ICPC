#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a);i<(b);++i)
#define per(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define sz(a) (int)a.size();
#define de(x) cout<<#x<<" = "<<x<<endl
#define de(x) cout<<#x<<" = "<<x<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N=101010;

int n,q;
int cnt[N<<2], len[N<<2], llen[N<<2], rlen[N<<2];

void build(int l=1, int r=n, int rt=1) {
    cnt[rt]=len[rt]=llen[rt]=rlen[rt]=0;
    if(l==r) return ;
    int mid=l+r>>1;
    build(l, mid, rt<<1);
    build(mid+1, r, rt<<1|1);
}

void upd(int p,int l=1,int r=n,int rt=1) {
    if(l==r) {
        cnt[rt]^=1;
        len[rt]^=1;
        llen[rt]^=1;
        rlen[rt]^=1;
        return ;
    }
    int mid=l+r>>1;
    if(p<=mid) upd(p, l, mid, rt<<1);
    else upd(p, mid+1, r, rt<<1|1);

    cnt[rt]=cnt[rt<<1]+cnt[rt<<1|1];
    if(rlen[rt<<1]&&llen[rt<<1|1]) --cnt[rt];
    len[rt]=max(rlen[rt<<1]+llen[rt<<1|1], max(len[rt<<1], len[rt<<1|1]));
    llen[rt]=llen[rt<<1];
    if(llen[rt<<1]==mid-l+1) llen[rt]+=llen[rt<<1|1];
    rlen[rt]=rlen[rt<<1|1];
    if(rlen[rt<<1|1]==r-mid) rlen[rt]+=rlen[rt<<1];
}

int main() {
    scanf("%d%d",&n,&q);
    build();
    while(q--) {
        int x;scanf("%d",&x);
        upd(x);
        printf("%d %d\n",cnt[1],len[1]);
    }
    return 0;
}
