
/*	@hysbz-1146
	树链剖分链上第K大
*/
const int N = 80808 , M = N << 1;
int n,m;
int val[N] , h[N] , ne[M] , to[M] , e;
void link(int u,int v){
	to[e] = v , ne[e] = h[u];
	h[u] = e++;
}
int dep[N] , par[N][17] , lft[N] , rgt[N] , _;
void dfs(int c,int fa){
	par[c][0] = fa , dep[c] = dep[fa] + 1 ;
	lft[c] = ++_;
	for(int k=h[c];~k;k=ne[k])
		if(to[k] != fa)
			dfs(to[k] , c);
	rgt[c] = _;
}
int lca(int a,int b){
	if(dep[a] < dep[b]) swap(a,b);
	for(int i=16;i>=0;--i)
		if(dep[a] - dep[b] >>i&1)
			a = par[a][i];
	if(a == b) return a;
	for(int i=16;i>=0;--i)
		if(par[a][i] != par[b][i])
			a = par[a][i] , b = par[b][i];
	return par[a][0];
}
const int DOWN = -1 , UP = 1e8 + 1 , NODE = 12580000;
inline int get_id(int l,int r){
	return l+r|l!=r;
}
#define get int m=l+r>>1,id=get_id(l,r)
int rt[N<<1];
int lc[NODE] , rc[NODE] , sum[NODE] , L;
void Add(int l,int r,int &p,int x,int d){
	get;
	if(!p) p = ++L;
	if(l == r) sum[p] += d;
	else{
		if(x <= m) Add(l,m,lc[p],x,d);
		else Add(m+1,r,rc[p],x,d);
		sum[p] = sum[lc[p]] + sum[rc[p]];
	}
}
void add(int l,int r,int L,int R,int val,int d){
	get;
	if(L <= l && r <= R) Add(DOWN,UP,rt[id],val,d);
	else{
		if(L <= m) add(l,m,L,R,val,d);
		if(R > m) add(m+1,r,L,R,val,d);
	}
}
vi pl , ml;
void get_rts(int l,int r,int x,int d){
	get;
	if(d == 1) pl.push_back(rt[id]);
	else ml.push_back(rt[id]);
	if(l == r) return;
	else{
		if(x <= m) get_rts(l,m,x,d);
		else get_rts(m+1,r,x,d);
	}
}
int Query_kth(int l,int r,int K){
	get;
	if(l == r) return l;
	int cnt = 0;
	rep(i,0,sz(pl)) cnt += sum[rc[pl[i]]];
	rep(i,0,sz(ml)) cnt -= sum[rc[ml[i]]];
	if(cnt >= K){
		rep(i,0,sz(pl)) pl[i] = rc[pl[i]];
		rep(i,0,sz(ml)) ml[i] = rc[ml[i]];
		return Query_kth(m+1,r,K);
	}
	else{
		rep(i,0,sz(pl)) pl[i] = lc[pl[i]];
		rep(i,0,sz(ml)) ml[i] = lc[ml[i]];
		return Query_kth(l,m,K - cnt);
	}
}
int Query(int a,int b,int K){
	pl.clear();ml.clear();
	int c = lca(a,b);
	get_rts(1,n,lft[a],1);
	get_rts(1,n,lft[b],1);
	get_rts(1,n,lft[c],-1);
	if(par[c][0]) get_rts(1,n,lft[par[c][0]],-1);
	return Query_kth(DOWN,UP,K);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) scanf("%d",val+i);
	e = 0;fill(h+1,h+1+n,-1);
	int u , v;
	rep(i,1,n){
		scanf("%d%d",&u,&v);
		link(u,v);link(v,u);
	}
	_ = 0;dfs(1,0);
	for(int j=1;1<<j<=n;++j)
		for(int i=1;i<=n;++i)
			par[i][j] = par[par[i][j-1]][j-1];
	rep(i,1,n+1) add(1,n,lft[i],rgt[i],val[i],1);
	int k , a , b;
	rep(i,0,m){
		scanf("%d%d%d",&k,&a,&b);
		if(k == 0){
			add(1,n,lft[a],rgt[a],val[a],-1);
			add(1,n,lft[a],rgt[a],val[a] = b,1);
		}
		else{
			int ans = Query(a,b,k);
			if(ans == -1) puts("invalid request!");
			else printf("%d\n",ans);
		}
	}
	return 0;
}
