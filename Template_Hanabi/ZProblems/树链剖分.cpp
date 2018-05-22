
/*	@hdu-5405
	单点修改，去链后子树sum^2和
*/
const int N = 101010 , M = N << 1;
int n , m;
#define lb(x) ((x)&(-x))
struct BIT{
	ll a[N];
	void ini(){
		fill(a+1,a+1+n,0);
	}
	void Pre(){
		for(int i=1,j=i+lb(i);i<=n;++i,j=i+lb(i)) if(j<=n) a[j] += a[i];
	}
	void add(int x,ll d){
		for(;x<=n;x+=lb(x)) a[x] += d;
	}
	ll sum(int x){
		ll r=0; for(;x>=1;x-=lb(x)) r += a[x]; return r;
	}
};
BIT bi,bj;
int to[M] , ne[M] , h[N] , e;
void link(int u,int v){
	to[e] = v , ne[e] = h[u];
	h[u] = e++;
}
int par[N] , dep[N] , sz[N] , wson[N];
int lft[N] , rht[N] , tp[N] , _;
ll s[N];
int w[N];ll wsum;
void dfs(int c,int fa){
	par[c] = fa , dep[c] = dep[fa] + 1 , sz[c] = 1 , wson[c] = 0;
	for(int k=h[c];~k;k=ne[k]){
		int t = to[k];
		if(t == fa) continue;
		dfs(t , c);
		sz[c] += sz[t];
		if(sz[t] > sz[wson[c]]) wson[c] = t;
	}
}
inline ll sqr(ll x){
	x %= mod;
	return x*x%mod;
}
void dds(int c,int pa){
	lft[c] = ++_;
	tp[c] = pa;
	bi.a[_] = w[c]; // bi
	s[c] = w[c];
	ll tmp = 0;
	if(wson[c]){
		dds(wson[c],pa);
		s[c] += s[wson[c]];
	}
	for(int k=h[c];~k;k=ne[k]){
		int t = to[k];
		if(t == par[c] || t == wson[c]) continue;
		dds(t,t);
		s[c] += s[t];
		(tmp += sqr(s[t])) %= mod;
	}
	rht[c] = _;
	bj.a[lft[c]] = tmp;
}
ll Query_s(int x){
	return bi.sum(rht[x]) - bi.sum(lft[x]-1);
}
void Change(int a,int b){
	ll del = b - w[a];
	w[a] = b;wsum += del;
	bi.add(lft[a],del); // bi
	int fa = tp[a];
	while(a = par[fa]){
		ll gt = Query_s(fa);
		bj.add(lft[a],sqr(gt) - sqr(gt-del));
		fa = tp[a];
	}
}
int Query(int a,int b){
	ll ret = 0;
	int fa = tp[a] , fb = tp[b];
	while(fa != fb){
		if(dep[fa] < dep[fb]) swap(a,b) , swap(fa,fb);
		ret += bj.sum(lft[a]) - bj.sum(lft[fa]-1);
		if(wson[a]) ret += sqr(Query_s(wson[a]));
		ret -= sqr(Query_s(fa));
		a = par[fa] , fa = tp[a];
	}
	if(dep[a] < dep[b]) swap(a,b);
	if(wson[a]) ret += sqr(Query_s(wson[a]));
	ret += bj.sum(lft[a]) - bj.sum(lft[b]-1);
	ret += sqr(wsum - Query_s(b));
	ret = sqr(wsum) - ret;
	ret %= mod , (ret += mod) %= mod;
	return (int)ret;
}
void work(){
	wsum = 0;
	rep(i,1,n+1) scanf("%d",w+i) , wsum += w[i];
	int u , v;
	e = 0;fill(h+1,h+1+n,-1);
	rep(i,1,n){
		scanf("%d%d",&u,&v);
		link(u,v);
		link(v,u);
	}
	bi.ini();bj.ini();
	dfs(1,0);_=0;dds(1,1);
	bi.Pre();bj.Pre();
	int op , a , b;
	rep(i,0,m){
		scanf("%d%d%d",&op,&a,&b);
		if(op == 1) Change(a,b);
		else printf("%d\n",Query(a,b));
	}
}
int main(){
	while(~scanf("%d%d",&n,&m)) work();
	return 0;
}
