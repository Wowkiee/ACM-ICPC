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

const int N=505;

int n;
int deg[100][N];
char s[N][N];
bool vis[100][N];
vector<pair<char, int> > g[100][N];

int main() {
	int T;scanf("%d",&T);
	while(T--) {
		///
		scanf("%d",&n);
		///init
		fill_n(vis['C'], n+1, 0);
		fill_n(vis['R'], n+1, 0);
		fill_n(deg['C'], n+1, 0);
		fill_n(deg['R'], n+1, 0);
		fill_n(g['C'], n+1, vector<pair<char, int> >());
		fill_n(g['R'], n+1, vector<pair<char, int> >());
		///read
		rep(i,1,n+1) scanf("%s",s[i]+1);
		///solve
		rep(i,1,n+1) rep(j,1,n+1) {
			if(s[i][j]=='O') {
				vis['C'][j]=1;
			} else {
				vis['R'][i]=1;
			}
		}
		int cnt=0;
		rep(i,1,n+1) cnt+=vis['C'][i]+vis['R'][i];
		rep(i,1,n+1) rep(j,1,n+1) if(vis['C'][j]&&vis['R'][i]) {
			if(s[i][j]=='O') {
				g['R'][i].pb(mp('C', j));
				++deg['C'][j];
			} else {
				g['C'][j].pb(mp('R', i));
				++deg['R'][i];
			}
		}
		vector<pair<char, int> > ans;
		priority_queue<pair<char, int> > q;
		rep(i,1,n+1) {
			if(vis['C'][i]&&deg['C'][i]==0) q.push(mp(-'C', -i));
			if(vis['R'][i]&&deg['R'][i]==0) q.push(mp(-'R', -i));
		}
		while(!q.empty()) {
			char ch=-q.top().fi; int x=-q.top().se;
			ans.pb(mp(ch, x));q.pop();
			rep(i,0,sz(g[ch][x])) {
				pair<char, int> t=g[ch][x][i];
				--deg[t.fi][t.se];
				if(deg[t.fi][t.se]==0) q.push(mp(-t.fi, -t.se));
			}
		}
		if(sz(ans)==cnt) {
			rep(i,0,sz(ans)) printf("%c%d%c",ans[i].fi,ans[i].se," \n"[i==sz(ans)-1]);
		} else {
			puts("No solution");
		}
	}
	return 0;
}

