#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(x) (int)x.size()
#define de(x) cout<< #x<<" = "<<x<<endl
#define dd(x) cout<< #x<<" = "<<x<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N=22, M=55;

int n, m;
int a[N], b[N], to[N];

bool check(int sta) {
	rep(i,1,n+1) if(sta>>i&1) {
		if((sta&to[i])!=to[i]) return 0;
	}
	return 1;
}

int main() {
	///read
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i), b[i]=i;
	scanf("%d",&m);
	///solve
	while(m--) {
		int t, x;scanf("%d%d",&t,&x);
		if(t==0) {
			int y;scanf("%d",&y);
			b[x]=++n;
			a[n]=y;
		} else {
			int l,r;scanf("%d%d",&l,&r);
			rep(i,l,r+1) {
				to[b[x]]|=(1<<b[i]);
			}
		}
	} 
	ll ans=1e18;
	rep(i,1,(1<<n)) if(check(i<<1)) {
		ll res=0;
		int sta=(i<<1);
		rep(j,1,n+1) if(sta>>j&1) dd(j);puts("");
		rep(j,1,n+1) if(sta>>j&1) res+=a[j];
		ans=min(ans, res);
	}
	printf("%lld\n",ans);
	return 0;
}

