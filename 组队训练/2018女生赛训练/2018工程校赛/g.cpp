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

const int N=111;
int n,k;
int a[N][N], col[N], row[N];

void gao() {
    int t=1;
    rep(i,2,n+1) if(row[i]>row[t]) {
        t=i;
    }
    row[t]=0;
    rep(i,1,n+1) if(a[t][i]) {
        --col[i];
    }
}

int calc() {
    int res=0;
    rep(i,1,n+1) res+=col[i]>0;
    return res;
}

int solve() {
    int ans=calc();
    rep(i,1,n+1) {
        gao();
        ans=min(ans, i+calc());
    }
    return ans;
}

int main() {
    while(~scanf("%d%d",&n,&k)) {
        ///
        rep(i,1,n+1) rep(j,1,n+1) a[i][j]=0;
        fill_n(row, n+1, 0);
        fill_n(col, n+1, 0);
        rep(i,1,k+1) {
            int x,y;scanf("%d%d",&x,&y);
            a[x][y]=1;
            ++row[x];
            ++col[y];
        }
        int ans=solve();
        ///
        fill_n(row, n+1, 0);
        fill_n(col, n+1, 0);
        rep(i,1,n+1) rep(j,i+1,n+1) swap(a[i][j], a[j][i]);
        rep(x,1,n+1) rep(y,1,n+1) if(a[x][y]) {
            ++row[x];
            ++col[y];
        }
        ans=min(ans, solve());
        printf("%d\n",ans);
    }
    return 0;
}
