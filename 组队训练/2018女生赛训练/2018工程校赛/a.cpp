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
#define dd(x) cout<<#x<<" = "<<x<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    int n;
    scanf("%d",&n);
    int ans[10] ={0,10,102,1020,10200,102000,1020005,10200056,102000564,1020005640};
    cout<<ans[n - 1]<<endl;
    return 0;
}
