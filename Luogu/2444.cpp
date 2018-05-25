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

const int N=30303;

int n;
char s[N];

struct Trie {
	static const int N=30303, M=2;
	int ne[N][M], fail[N], fa[N], rt, L, vis[N];
	bool ed[N];
	void ini() {
		fill_n(ne[fail[0]=N-1], M, 0);
		fill_n(ed, L, 0);
		fill_n(vis, L, 0);
		L=0;
		rt=newnode();
	}
	int newnode() {
		fill_n(ne[L], M, 0);
		return L++;
	}
	void add(char *s) {
		int p=rt;
		for(int i=0; s[i]; ++i) {
			int c=s[i]-'0';
			if(!ne[p][c]) ne[p][c]=newnode(), fa[L-1]=p;
			p=ne[p][c];
		}
		ed[p]=1;
	}
	void Build() {
		vi v;v.pb(rt);
		rep(i,0,sz(v)) {
			int c=v[i];
			rep(i,0,M) ne[c][i] ? 
				v.pb(ne[c][i]), fail[ne[c][i]] = ne[fail[c]][i], ed[ne[c][i]] |= ed[ne[fail[c]][i]] :
				ne[c][i] = ne[fail[c]][i];
		}
	}
	bool dfs(int u) {
		vis[u]=1;
		rep(i,0,M) {
			int v=ne[u][i];
			if(ed[v]||vis[v]==2) continue;
			if(vis[v]||dfs(v)) return 1;
		}
		vis[u]=2;
		return 0;
	}
}ac;

int main() {
	scanf("%d",&n);
	ac.ini();
	rep(i,0,n) {
		scanf("%s",s);
		ac.add(s);
	}
	ac.Build();
	printf("%s\n",ac.dfs(ac.rt)?"TAK":"NIE");
	return 0;
}
/*
3
011 
11 
00000
*/
