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

const int N=202020, inf=1e9;

int n,m,d;
int dis[N];
int dx[]={0, 1, 0, -1};
int dy[]={1, 0, -1, 0};
bool ok[N];
char s[N];

bool che(int i,int j) {
	return 0<=i&&i<n&&0<=j&&j<m; 
}

int main() {
	while(~scanf("%d%d%d",&n,&m,&d)) {
		///init
		fill_n(dis, n*m, inf);
		fill_n(ok, n*m, 1);
		///read
		rep(i,0,n) scanf("%s",s+i*m);
		///solve
		vi q;
		rep(i,0,n*m) if(s[i]=='M') {
			q.pb(i);
			ok[i]=0;
			dis[i]=0;
		}
		rep(i,0,sz(q)) {
			int u=q[i];
			if(dis[u]==d) continue;
			int x=u/m, y=u%m;
			rep(j,0,4) {
				int nx=x+dx[j], ny=y+dy[j];
				if(che(nx, ny)) {
					int v=nx*m+ny;
					if(dis[v]>dis[u]+1) {
						dis[v]=dis[u]+1;
						ok[v]=0;
						q.pb(v);
					}
				}
			}
		}
		fill_n(dis, n*m, inf);
		q.clear();
		int st, ed;
		rep(i,0,n*m) {
			if(s[i]=='S') st=i;
			if(s[i]=='F') ed=i;
		}
		if(ok[st]) {
			q.pb(st);
			dis[st]=0;
		}
		rep(i,0,sz(q)) {
			int u=q[i];
			int x=u/m, y=u%m;
			rep(j,0,4) {
				int nx=x+dx[j], ny=y+dy[j];
				if(che(nx, ny)) {
					int v=nx*m+ny;
					if(ok[v]&&dis[v]>dis[u]+1) {
						dis[v]=dis[u]+1;
						q.pb(v);
					}
				}
			}
		}
		if(dis[ed]==inf) dis[ed]=-1;
		printf("%d\n",dis[ed]);
	}
	return 0;
}

