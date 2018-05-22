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

const int N=1e7+7;

int n, A, B, C;
int a[N];

void gao(){
    unsigned x = A, y = B, z = C;
    unsigned t;
    for(int i=0;i<n;++i){
        x ^= x << 16;
        x ^= x >> 5;
        x ^= x << 1;
        t = x;
        x = y;
        y = z;
        z = t ^ x ^ y;
        a[i] = z;
    }
    for(int i=0;i<n;++i){
        if(a[i] < 0)
            a[i] = -a[i];
    }
}

int main() {
    int T;scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d%d",&n,&A,&B,&C);
        gao();
        sort(a, a+n);
        int ans=0;
      //  rep(i,0,n) printf("%d ",a[i]);puts("");
        rep(i,0,n-1) ans=max(ans, a[i+1]-a[i]);
        printf("%d\n",ans);
    }
    return 0;
}
/*
2
2 1 1 1
50 2 3 3
*/
