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

int n, m, tot;
int a[N], b[N];

int cntn, rt;
int ls[N*22], rs[N*22], id[N*22], di[N];
vi g[N*22];

int dfn[N*22], low[N*22], sid[N*22], st[N*22], _st, _, cc, out[N*22];
ll val[N*22];

void dfs(int c) {
	dfn[c]=low[c]=++cc;
	st[_st++]=c;
	for(auto t:g[c]) {
		if(!dfn[t]) {
			dfs(t);
			low[c]=min(low[c], low[t]);
		} else if(!sid[t]) {
			low[c]=min(low[c], dfn[t]);
		}
	}
	if(low[c]==dfn[c]) {
		++_;
		do{sid[st[--_st]]=_;}while(st[_st]!=c);
	}
}

void build(int l,int r,int &rt) {
	rt=++cntn;
	if(l==r) {
		id[rt]=l;
		di[l]=rt;
		return ;
	}
	int mid=l+r>>1;
	build(l, mid, ls[rt]);
	build(mid+1, r, rs[rt]);
	g[rt].pb(ls[rt]);
	g[rt].pb(rs[rt]);
}

void upd(int pre, int &now, int p, int c, int l, int r) {
	now=++cntn;
	ls[now]=ls[pre];
	rs[now]=rs[pre];
	id[now]=id[pre];
	if(l==r) {
		id[now]=c;
		di[c]=now;
		return ;
	}
	int mid=l+r>>1;
	if(p<=mid) upd(ls[pre], ls[now], p, c, l, mid);
	else upd(rs[pre], rs[now], p, c, mid+1, r);
	g[now].pb(ls[now]);
	g[now].pb(rs[now]);
}

void gao(int rt,int u,int L,int R,int l,int r) {
	if(L<=l&&r<=R) {
		g[u].pb(rt);
		return ;
	}
	int mid=l+r>>1;
	if(L<=mid) gao(ls[rt], u, L, R, l, mid);
	if(R>=mid+1) gao(rs[rt], u, L, R, mid+1, r);
}

int main() {
	///read
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i), b[i]=i;
	scanf("%d",&m);
	///solve
	build(1, n, rt);
	tot=n;
	while(m--) {
		int t,x;scanf("%d%d",&t,&x);
		if(t==0) {
			int y;scanf("%d",&y);
			a[++tot]=y;
			b[x]=tot;
			upd(rt, rt, x, tot, 1, n);
		} else {
			int l,r;scanf("%d%d",&l,&r);
			x=b[x];
			gao(rt, di[x], l, r, 1, n);
		}
	}
	rep(i,1,cntn+1) if(!dfn[i]) dfs(i);
	rep(i,1,cntn+1) {
		for(auto j:g[i]) if(sid[i]!=sid[j]) {
			++out[sid[i]];
		}
	}
	rep(i,1,tot+1) {
		int j=di[i];
		val[sid[j]]+=a[i];
	}
	ll ans=1e18;
	rep(i,1,_+1) if(!out[i]) ans=min(ans, val[i]);
	printf("%lld\n",ans);
	return 0;
}
