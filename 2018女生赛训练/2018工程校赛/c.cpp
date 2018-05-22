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

int main() {
    int T;scanf("%d",&T);
    while(T--) {
        int a,b;scanf("%d%d",&a,&b);
        if(a>b) swap(a, b);
        printf("%d.00\n",b-a);
    }
    return 0;
}

