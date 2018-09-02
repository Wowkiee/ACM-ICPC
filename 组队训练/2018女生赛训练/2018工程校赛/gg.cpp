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

int get(int a[]) {
    int t=1;
    rep(i,1,n+1) if(a[i]>a[t]) t=i;
    return t;
}

int main() {
    while(~scanf("%d%d",&n,&k)) {
        ///init
        rep(i,1,n+1) rep(j,1,n+1) a[i][j]=0;
        fill_n(col, n+1, 0);
        fill_n(row, n+1, 0);
        ///read
        rep(i,1,k+1) {
            int x,y;scanf("%d%d",&x,&y);
            a[x][y]=1;
            ++row[x];
            ++col[y];
        }
        ///solve
        int ans=0;
        while(k) {
            ++ans;
            int i=get(row);
            int j=get(col);
            if(row[i]>=col[j]) {
                k-=row[i];
                row[i]=0;
                rep(j,1,n+1) if(a[i][j]) {
                    a[i][j]=0;
                    --col[j];
                }
            } else {
                k-=col[j];
                col[j]=0;
                rep(i,1,n+1) if(a[i][j]) {
                    a[i][j]=0;
                    --row[i];
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
