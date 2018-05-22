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

const int N=44, inf=1e9;

int n, m;
int dis[N*N][N*N], q[N*N*N*N], vis[N*N];
int dx[]={0, 1, 0, -1};
int dy[]={1, 0, -1, 0};
char s[N][N];

inline bool che(int i,int j) {
	return 0<=i&&i<n&&0<=j&&j<m;
}

inline void spfa(int st) {
	int i=0, r=0;q[r++]=st;
	vis[st]=st;
	dis[st][st]=0;
	while(i<r) {
		int u=q[i++];vis[u]=-1;
		int x=u/m, y=u%m;
		rep(j,0,4) {
			int nx=x+dx[j];
			int ny=y+dy[j];
			if(!che(nx, ny)) continue;
			int v=nx*m+ny;
			if(dis[st][v]>dis[st][u]+(s[x][y]!=s[nx][ny])) {
				dis[st][v]=dis[st][u]+(s[x][y]!=s[nx][ny]);
				if(vis[v]!=st) {
					vis[v]=st;
					q[r++]=v;
				}
			}
		}
	}
}

int main() {
	int T;scanf("%d",&T);
	while(T--) {
		///
		scanf("%d%d",&n,&m);
		///init
		rep(i,0,n*m) rep(j,0,n*m) dis[i][j]=inf;
		fill_n(vis, n*m, -1);
		///read
		rep(i,0,n) scanf("%s",s[i]);
		///solve
		rep(i,0,n*m) spfa(i);
		int ans=0;
		rep(i,0,n*m) rep(j,i+1,n*m) ans=max(ans, dis[i][j]);
//		de(ans);
		printf("%d\n",(ans+1)/2);
	} 
	return 0;
}
/*
3
2 2
OX
OX
3 3
XOX
OXO
XOX
4 4
OXOX
XOXO
OXOX
XOXO
*/

