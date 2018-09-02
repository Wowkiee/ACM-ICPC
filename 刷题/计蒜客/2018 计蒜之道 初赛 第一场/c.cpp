#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(x) (int)x.size()
#define de(x) cout<< #x<<" = "<<x<<endl
#define dd(x) cout<< #x<<" = "<<x<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N=101010;

int n,m;
int a[N], b[N];
ll val[N];
vi g[N];

int dfn[N],low[N],id[N],st[N],_st,_,cc;
void dfs(int c){
    dfn[c]=low[c]=++cc;
    st[_st++]=c;
    rep(i,0,sz(g[c])) {
    	int t=g[c][i];
        if(!dfn[t])
            dfs(t),low[c]=min(low[c],low[t]);
        else if(!id[t])
            low[c]=min(low[c],dfn[t]);
	}
    if(low[c]==dfn[c]){
        ++_;
        do{id[st[--_st]]=_;}while(st[_st]!=c);
    }
}
vi ng[N];
void solve(){
    fill_n(dfn,n,cc=0);
    fill_n(low,n,_st=0);
    fill_n(id,n,_=0);
    rep(i,0,n) if(!dfn[i]) dfs(i);
    rep(i,0,n) --id[i];
    rep(i,0,n) val[id[i]]+=a[i];
    fill_n(ng,_,vi());
    rep(i,0,n) {
    	rep(k,0,sz(g[i])) {
    		int j=g[i][k];
    		if(id[i]!=id[j]) ng[id[i]].pb(id[j]);
		}
	}
}

int main() {
	///read
	scanf("%d",&n);
	rep(i,0,n) scanf("%d",a+i), b[i]=i;
	scanf("%d",&m);
	///solve
	while(m--) {
		int t,x;scanf("%d%d",&t,&x);
		--x;
		if(t==0) {
			int y;scanf("%d",&y);
			b[x]=n;
			a[n]=y;
			n++;
		} else {
			int l,r;scanf("%d%d",&l,&r);
			rep(i,l-1,r) if(b[x]!=b[i]) g[b[x]].pb(b[i]);
		}
	}
	solve();
	ll ans=1e18;
	rep(i,0,_) if(sz(ng[i])==0) ans=min(ans, val[i]);
	printf("%lld\n",ans);
	return 0;
}

