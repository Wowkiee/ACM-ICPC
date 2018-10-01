#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(x) (int)x.size()
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N=10010;
ll data1[N],data2[N],cc[N],p1[N],p2[N];
int exi[N>>1][N];
int L[N],R[N];
int n,w,m,q;
int getw(int id) {
	return id*w+w/2;
}
int main() {
	freopen("jenga.in", "r", stdin);
	freopen("jenga.out", "w", stdout);
	scanf("%d%d%d%d",&n,&w,&m,&q);w<<=1;
	L[0]=1,R[0]=n;
	rep(i,1,m+1) {
		data1[i]=data2[i]=1ll*n*(w/2*n);
		cc[i]=n;
		L[i]=1,R[i]=n;
	}
	per(i,1,m+1)p1[i]=p1[i+1]+data1[i],p2[i]=p2[i+1]+data2[i],cc[i]+=cc[i+1];
	rep(cas,1,q+1) {
		int a,b;scanf("%d%d",&a,&b);
		exi[a][b]=1;
		int now=getw(b-1);
		per(i,1,a+1) {
				p1[i]-=(a&1)?now:w/2*n;
				p2[i]-=(a&1)?w/2*n:now;
				cc[i]--;
		}
		while(L[a]<=n&&exi[a][L[a]])L[a]++;
		while(R[a]>0&&exi[a][R[a]])R[a]--;
		if(R[a]==0)R[a]=n+1;
		per(i,1,a+1) {
			if(i&1) {
				if(cc[i+1]&&((L[i]-1)*w>=1.0*p1[i+1]/cc[i+1]||1.0*p1[i+1]/cc[i+1]>=R[i]*w)) {
					puts("yes");
					printf("%d\n",cas);
					return 0;
				}
			}
			else {
				if(cc[i+1]&&((L[i]-1)*w>=1.0*p2[i+1]/cc[i+1]||1.0*p2[i+1]/cc[i+1]>=R[i]*w)) {
					puts("yes");
					printf("%d\n",cas);
					return 0;
				}
			}
		}
	}
	puts("no");
	return 0;
}
