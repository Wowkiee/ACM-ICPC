#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b-1);i>=(a);i--)
#define sz(x) (int)x.size()
#define de(x) cout<<#x<<" = "<<x<<endl
#define dd(x) cout<<#x<<" = "<<x<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n,m;
int a[22][22], cdig[1<<12], ini[13];
vi f[1<<12], g[1<<12];

int calc(int x) {
	int res=0;
	while(x) {
		if(x&1) ++res;
		x>>=1;
	}
	return res;
}

void gao1(int sta) {
	vi p;
	rep(i,0,n) if(sta>>i&1) p.pb(i+1);// i+1 在 p[i]位置 
	do {
		int res=0;
		rep(i,0,sz(p)) res+=a[i+1][p[i]];
		f[sta].pb(res);
	} while(next_permutation(p.begin(), p.end()));
	sort(f[sta].begin(), f[sta].end());
}
void gao2(int sta) {
	vi p;
	rep(i,0,n) if(sta>>i&1) p.pb(i+1);// i+1+n/2 在 p[i]位置 
	do {
		int res=0;
		rep(i,0,sz(p)) res+=a[i+1+n/2][p[i]];
		g[sta].pb(res);
	} while(next_permutation(p.begin(), p.end()));
	sort(g[sta].begin(), g[sta].end());
}
int gcd(int a, int b) {
	if(b==0) return a;
	return gcd(b, a%b);
}

int main() {
	int T;scanf("%d",&T);
	rep(i,0,1<<12) cdig[i]=calc(i);
	ini[1]=1;
	rep(i,2,13) ini[i]=ini[i-1]*i;
	while(T--) {
		///
		scanf("%d%d",&n,&m);
		///init
		fill_n(f, 1<<n, vi());
		fill_n(g, 1<<n, vi());
		///read
		rep(i,1,n+1) rep(j,1,n+1) scanf("%d",&a[i][j]);
		///solve
		rep(i,0,1<<n) if(cdig[i]==n/2) gao1(i);
		rep(i,0,1<<n) if(cdig[i]==n-n/2) gao2(i);
		int fz=ini[n];
		int fm=0;
		rep(i,0,1<<n) if(cdig[i]==n/2) {
			int j=((1<<n)-1)^i;
			int y=sz(g[j])-1;
			rep(x, 0, sz(f[i])) {
				while(y>=0&&f[i][x]+g[j][y]>=m) --y;
				fm+=sz(g[j])-y-1;
			}
		}
		if(fm==0) {
			puts("No solution");
		} else {
			int d=gcd(fz, fm);
			fz/=d;fm/=d;
			printf("%d/%d\n",fz,fm);
		}
	}
	return 0;
}

