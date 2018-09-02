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

const int N=101010;

int n,m;
char s[N];

struct Trie {
	static const int M=26, N=101010;
	int ne[N][M], fail[N], fa[N], rt, L, ed[N];
	int dfn[N], low[N], id[N], st[N], _st, _, cc, cntn[N], cnte[N];
	vi ng[N];
	void ini() {
		fill_n(ne[fail[0]=N-1], M, 0);
		fill_n(ed, L, 0);
		L=0;
		rt=newnode();
	}
	int newnode() {
		fill_n(ne[L], M, 0);
		return L++;
	}
	void add(char *s) {
		int p=rt;
		for(int i=0;s[i];++i) {
			int c=s[i]-'a';
			if(!ne[p][c]) ne[p][c]=newnode(), fa[L-1]=p;
			p=ne[p][c];
		}
		ed[p]=1;
	}
	void Build() {
		vi v;v.pb(rt);
		rep(i,0,sz(v)) {
			int c=v[i];
			rep(i,0,m) ne[c][i]?
				v.pb(ne[c][i]), fail[ne[c][i]]=ne[fail[c]][i], ed[ne[c][i]]|=ed[ne[fail[c]][i]]:
				ne[c][i]=ne[fail[c]][i];
		}
	}
	void dfs(int c) {
		dfn[c]=low[c]=++cc;
		st[_st++]=c;
		rep(i,0,m) {
			int t=ne[c][i];
			if(ed[t]) continue;
			if(!dfn[t]) {
				dfs(t);
				low[c]=min(low[c], low[t]);
			} else if(!id[t]) {
				low[c]=min(low[c], dfn[t]);
			}
		}
		if(low[c]==dfn[c]) {
			++_;
			do{
				id[st[--_st]]=_;
			} while (st[_st]!=c);
		}
	}
	void scc() {
		fill_n(dfn, L, cc=0);
		fill_n(low, L, _st=0);
		fill_n(id, L, _=0);
		fill_n(cntn, L, 0);
		fill_n(cnte, L, 0);
		rep(i,0,L) if(!ed[i]&&!dfn[i]) dfs(i);
		fill_n(ng, _, vi());
		rep(i,0,L) if(!ed[i]) {
			++cntn[id[i]];
			rep(t,0,m) {
				int j=ne[i][t];
				if(ed[j]) continue;
				if(id[i]==id[j]) {
					++cnte[id[i]];
				} else {
					ng[id[i]].pb(id[j]);
				}
			}
		} 
	}
	bool Dfs(int u) {
		if(cnte[u]>cntn[u]) return 1;
		rep(i,0,sz(ng[u])) {
			int v=ng[u][i];
			if(Dfs(v)) return 1;
		}
		return 0;
	}
}ac;

int main() {
	int T;scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&m);
		ac.ini();
		rep(i,0,n) {
			scanf("%s",s);
			ac.add(s);
		}
		ac.Build();
		ac.scc();
		printf("%s\n",ac.Dfs(ac.id[ac.rt])?"Yes":"No");
	}
	return 0;
}

