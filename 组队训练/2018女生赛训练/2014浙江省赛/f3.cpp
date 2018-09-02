#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b-1);i>=(a);i--)
#define sz(x) (int)x.szie()
#define de(x) cout<<#x<<" = "<<x<<endl
#define dd(x) cout<<#x<<" = "<<x<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N=44;

int n,m;
int pre[N*N], deg[N*N], a[N][N];
int dx[]={0, 1, 0, -1};
int dy[]={1, 0, -1, 0};
char s[N][N];

inline bool che(int i,int j) {
	return 0<=i&&i<n&&0<=j&&j<m;
}

int find(int x) {
	if(x==pre[x]) return x;
	return pre[x]=find(pre[x]);
}
void join(int x,int y) {
	int fx=find(x);
	int fy=find(y);
	pre[fx]=fy;
}

bool gao() {
	rep(u,0,n*m) {
		int x=u/m, y=u%m;
		rep(j,0,4) {
			int nx=x+dx[j];
			int ny=y+dy[j];
			if(!che(nx, ny)) continue;
			int v=nx*m+ny;
			if(a[x][y]==a[nx][ny]) join(u, v);
		}
	}
	fill_n(deg, n*m, 0);
	int ma=0;
	rep(u,0,n*m) {
		int x=u/m, y=u%m;
		rep(j,0,4) {
			int nx=x+dx[j];
			int ny=y+dy[j];
			if(!che(nx, ny)) continue;
			int v=nx*m+ny;
			int fu=find(u), fv=find(v);
			if(fu!=fv) {
				++deg[fu], ++deg[fv];
				if(deg[fu]>deg[ma]) ma=fu;
				if(deg[fv]>deg[ma]) ma=fv;
			}
		}
	}
	if(deg[ma]==0) return 0;
	rep(i,0,n) rep(j,0,m) {
		int u=i*m+j;
		if(find(u)==ma) a[i][j]^=1;
	}
	return 1;
}

int main() {
	int T;scanf("%d",&T);
	while(T--) {
		///
		scanf("%d%d",&n,&m);
		///init
		rep(i,0,n*m) pre[i]=i;
		///read
		rep(i,0,n) scanf("%s",s[i]);
		rep(i,0,n) rep(j,0,m) a[i][j]=s[i][j]=='X';
		///solve
		int ans=0;
		while(gao()) ++ans;
		printf("%d\n",ans);
	}
	return 0;
}

