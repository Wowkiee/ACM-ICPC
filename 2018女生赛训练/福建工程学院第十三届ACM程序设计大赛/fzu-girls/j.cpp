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
ll a[N], pre[N], sum[N];

int main() {
    scanf("%d%d",&n,&q);
    rep(i,1,n+1) scanf("%lld",a+i);
    rep(i,1,n+1) pre[i]=pre[i-1]+a[i];
    rep(i,1,n+1) sum[i]=sum[i-1]+a[i]*a[i];
    while(q--) {
        int l, r;scanf("%d%d",&l,&r);
        ll ans=(r-l+1)*(sum[r]-sum[l-1])-(pre[r]-pre[l-1])*(pre[r]-pre[l-1]);
        printf("%lld\n",ans);
    }
    return 0;
}

