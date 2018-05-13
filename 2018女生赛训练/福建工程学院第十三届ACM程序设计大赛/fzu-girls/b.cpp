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

const int N=505050;

int n;
ll a[N];

int main() {
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%lld",a+i);
    ll ans=0;
    rep(i,1,n+1) {
        ll t=1ll*i*(n-i+1);
        if(t&1) ans^=a[i];
    }
    printf("%lld\n",ans);
    return 0;
}
