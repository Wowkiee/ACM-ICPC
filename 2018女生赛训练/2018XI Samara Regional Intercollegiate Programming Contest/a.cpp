#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
	int s, g;
	while(~scanf("%d%d",&s,&g)) {
		int k=s/g;
		if(s%g||k==1) {
			puts("-1");
			continue;
		}
		printf("%d %d\n",g,g*(k-1));
	}
	return 0;
}

