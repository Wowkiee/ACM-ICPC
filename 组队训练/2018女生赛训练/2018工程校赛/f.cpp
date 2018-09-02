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
const int N = 100000 + 10;
const ll mod = 1e9 + 7;
ll q[N],h[N];
int a[N];
ll mul(ll a, ll b) {

  return (a * b) % mod;
}
int  main() {
    int n;
    while(scanf("%d", &n) != EOF ){

        rep(i, 1, n + 1) scanf("%d" ,&a[i]);
        q[1] = a[1]; h[n] = a[n];
        rep(i, 2, n + 1) q[i] = mul(q[i - 1], (ll)a[i]);
        per(i, 1, n) h[i] = mul(h[i + 1], (ll)a[i]);
        printf("%lld ",h[2]);
        rep(i, 2 ,n) printf("%lld ", mul(q[i - 1], h[i + 1]));
        printf("%lld\n",q[n - 1]);

    }
    return 0;
}
