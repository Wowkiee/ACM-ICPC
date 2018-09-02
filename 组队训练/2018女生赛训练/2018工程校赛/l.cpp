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
int a[N], b[N], suf[N];

int main() {
    scanf("%d",&n);
    rep(i,0,n) scanf("%d",a+i);
    rep(i,0,n) scanf("%d",b+i), b[i]-=i;
    suf[n-1]=b[n-1];
    for(int i=n-2;~i;--i) suf[i]=max(suf[i+1], b[i]);
    ll ans=0;
    rep(i,0,n) {
        ll t=suf[i]+i;
        ans+=a[i]*t;
    }
    printf("%lld\n",ans);
    return 0;
}
