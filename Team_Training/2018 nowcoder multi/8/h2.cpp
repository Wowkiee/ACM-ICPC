#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---
const int N= 1<<19;
void FWT(int *a,int len,int o) {
    for(int k=0;1<<k<len;k++) rep(i,0,len) if(~i>>k&1) {
        int j=i^(1<<k),x,y;
        x=(a[i]+a[j]),y=(a[i]-a[j]);
        if(o==-1)x/=2,y/=2;
        a[i]=x,a[j]=y;
    }
}
int cc[N*4]={0};
int now[N*4]={1};
int main() {
    int n;scanf("%d",&n);
    int ans=0;
    rep(i,0,n) {
        int a;scanf("%d",&a);cc[a]=1;ans^=a;
    }
    int res=0;
    FWT(cc,N,1);
    while(!now[ans]) {
        res++;
        if(res==19)break;
        FWT(now,N,1);
        rep(i,0,N)now[i]=now[i]*cc[i];
        FWT(now,N,-1);
        rep(i,0,N)now[i]=!!now[i];
    }
    cout<<n-res<<endl;
    return 0;
}
