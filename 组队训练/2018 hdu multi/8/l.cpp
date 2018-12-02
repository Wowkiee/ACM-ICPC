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
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---
const int N = 3e5 + 7;
int c[N],d[N],m[N],p[N];
int rom,vmar,vcom;
map<int,int> M;
ll solve(int n) {
	ll ans=0;
	priority_queue<int> qmax,qmin;
	int sz=0;
	int nowval=1e9;
	rep(i,0,n) {
		nowval=min(nowval+vmar,c[i]);
		int nowdo=nowval+m[i]-i*vcom;
		sz+=p[i];
		if(M[nowdo])M[nowdo]+=p[i];
		else {
			M[nowdo]=p[i];
			qmax.push( nowdo);
			qmin.push(-nowdo);
		}
		if(sz<d[i])return -1;
		sz-=d[i];
		while(d[i]) {
			int f=-qmin.top();
			if(M[f]<=d[i]) {
				d[i]-=M[f];qmin.pop();
				ans+=1LL*M[f]*(f+i*vcom);
				M[f]=0;
			}
			else {
				M[f]-=d[i];
				ans+=1LL*d[i]*(f+i*vcom);
				d[i]=0;
			}
		}
		while(sz>rom) {
			int res=sz-rom;
			int f=qmax.top();
			if(M[f]<=res) {
				sz-=M[f];
				M[f]=0;
				qmax.pop();
			}
			else {
				sz-=res;
				M[f]-=res;
			}
		}
	}
	return ans;
}
int main() {
	int T;/*scanf("%d",&T);*/T=1;while(T--) {
		M.clear();
		int n;/*scanf("%d",&n);*/n=300000;
		rep(i,0,n)
		{
			/*scanf("%d%d%d%d",c+i,d+i,m+i,p+i),*/
			c[i]=d[i]=m[i]=p[i]=10000;
		}
		/*scanf("%d%d%d",&rom,&vmar,&vcom);*/rom=1e8,vmar=vcom=10000;
		printf("%lld\n",solve(n));
	}
	return 0;
}
