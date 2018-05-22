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

int n;
int a[N<<1], b[N<<1];

int main() {
    while(~scanf("%d",&n)) {
        rep(i,1,n+1) scanf("%d",a+i), a[i+n]=a[i];
        rep(i,1,n+1) scanf("%d",b+i), b[i+n]=b[i];
        rep(i,1,2*n+1) a[i]+=a[i-1], b[i]+=b[i-1];
        rep(i,1,2*n+1) a[i]-=b[i];
        int mi=2e9;
        rep(i,1,2*n+1) mi=min(mi, a[i]);
        int ans=-1;
        rep(i,0,n) if(a[i]<=mi) {
            ans=i;
            break;
        }
        printf("%d\n",ans);
    }
    return 0;
}

