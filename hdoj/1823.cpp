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

const int N=111, M=1010;

int ma[N<<2][M<<2];

void updy(int fa,int p,int c,int l=0,int r=1000,int rt=1) {
    ma[fa][rt]=max(ma[fa][rt], c);
    if(l==r) return ;
    int mid=l+r>>1;
    if(p<=mid) updy(fa, p, c, l, mid, rt<<1);
    else updy(fa, p, c, mid+1, r, rt<<1|1);
}

void updx(int x,int y,int c,int l=0,int r=100,int rt=1) {
    updy(rt, y, c);
    if(l==r) return ;
    int mid=l+r>>1;
    if(x<=mid) updx(x, y, c, l, mid, rt<<1);
    else updx(x, y, c, mid+1, r, rt<<1|1);
}

int qryy(int fa,int L,int R,int l=0,int r=1000,int rt=1) {
    if(L<=l&&r<=R) return ma[fa][rt];
    int mid=l+r>>1, ans=-1;
    if(L<=mid) ans=max(ans, qryy(fa, L, R, l, mid, rt<<1));
    if(R>=mid+1) ans=max(ans, qryy(fa, L, R, mid+1, r, rt<<1|1));
    return ans;
}

int qryx(int x1,int x2,int y1,int y2,int l=0,int r=100,int rt=1) {
    if(x1<=l&&r<=x2) return qryy(rt, y1, y2);
    int mid=l+r>>1, ans=-1;
    if(x1<=mid) ans=max(ans, qryx(x1, x2, y1, y2, l, mid, rt<<1));
    if(x2>=mid+1) ans=max(ans, qryx(x1, x2, y1, y2, mid+1, r, rt<<1|1));
    return ans;
}

int main() {
    int n;
    while(~scanf("%d",&n)) {
        if(n==0) break;
        memset(ma, -1, sizeof(ma));
        char s[11];int h1, h2;double a, l;
        while(n--) {
            scanf("%s%d",s,&h1);
            h1-=100;
            if(s[0]=='I') {
                scanf("%lf%lf",&a,&l);
                int A=a*10, L=l*10;
                updx(h1, A, L);
            } else {
                scanf("%d%lf%lf",&h2,&a,&l);
                int A=a*10, L=l*10;h2-=100;
                if(h1>h2) swap(h1, h2);
                if(A>L) swap(A, L);
                int t=qryx(h1, h2, A, L);
                if(~t) printf("%.1f\n",t/10.0);
                else puts("-1");
            }
        }
    }
    return 0;
}
