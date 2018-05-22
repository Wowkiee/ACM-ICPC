/*	@hdu-5345 sg+线段树
	sg[x][y] = lowbit(max(x,y))
	矩形并异或和
*/
int n , R , C;
struct event{
	int l,r,v;
	event(int _l=0,int _r=0,int _v=0){l=_l,r=_r,v=_v;}
}e[N<<1]; int ne[N<<1] , h[N] , e_cnt;
vi w;
void add(int x,int l,int r,int v){
	e[e_cnt] = event(l,r,v);
	ne[e_cnt] = h[x];
	h[x] = e_cnt++;
	w.pb(l); w.pb(r+1);
}

int cal(int l,int r){
	if(l > r) return 0;
	int ret = 0;
	for(int i=1;i<=r;i<<=1){
		int u , v;
		u = (r - i) / (2*i) + 1;
		v = l - 1 < i ? 0 : (l - 1 - i) / (2*i) + 1;
		if(u-v&1) ret += i;
	}
	return ret;
}

#define lson get_id(l,m)
#define rson get_id(m+1,r)
int sum[N<<2] , cov[N<<2] , sz[N<<2] , sgs[N<<2];
inline int get_id(int l,int r){
	return l + r | l != r;
}
void Build(int l,int r){
	int x = get_id(l,r);
	int m = l+r>>1;
	cov[x] = sz[x] = sgs[x] = 0; //
	if(l == r){
		sum[x] = cal(w[l] , w[r+1] - 1);
		return;
	}
	Build(l,m); Build(m+1,r);
	sum[x] = sum[lson] ^ sum[rson];
}
void Cover(int l,int r,int L,int R,int v){
	int x = get_id(l,r);
	int m = l+r>>1;
	if(L <= l && r <= R){
		cov[x] += v;
		if(cov[x]){
			sz[x] = w[r+1] - w[l];
			sgs[x] = sum[x];
		}
		else if(l == r) sz[x] = sgs[x] = 0;
		else sz[x] = sz[lson] + sz[rson] , sgs[x] = sgs[lson] ^ sgs[rson];
		return;
	}
	if(L <= m) Cover(l,m,L,R,v);
	if(m < R) Cover(m+1,r,L,R,v);
	if(!cov[x]) sz[x] = sz[lson] + sz[rson] , sgs[x] = sgs[lson] ^ sgs[rson];
}
int sg , szcnt , nowx , covcnt;
void Query_sz2(int l,int r){
	int x = get_id(l,r) , m = l+r>>1;
	if(cov[x]){
		sg ^= cal(nowx,w[r+1] - 1);
		szcnt += min(nowx,w[r+1]) - w[l];
	}
	else if(l < r){
		szcnt += sz[lson];
		Query_sz2(m+1,r);
	}
}
void Query_sz(int l,int r,int L,int R){
	int x = get_id(l,r) , m = l+r>>1;
	covcnt += cov[x];
	if(L <= l && r <= R){
		if(R == r){
			if(covcnt) sg ^= cal(nowx,w[r+1]-1) , szcnt += min(nowx,w[r+1]) - w[l];
			else Query_sz2(l,r);
		}
		else if(covcnt) szcnt += w[r+1] - w[l];
		else szcnt += sz[x];
		return ;
	}
	int cc = covcnt;
	if(L <= m) Query_sz(l,m,L,R); covcnt = cc;
	if(m < R) Query_sz(m+1,r,L,R);
}
void Query_sgs(int l,int r,int L,int R){
	int x = get_id(l,r) , m = l+r>>1;
	covcnt += cov[x];
	if(L <= l && r <= R){
		if(covcnt) sg ^= sum[x];
		else sg ^= sgs[x];
		return;
	}
	int cc = covcnt;
	if(L <= m) Query_sgs(l,m,L,R); covcnt = cc;
	if(m < R) Query_sgs(m+1,r,L,R);
}
int main(){
	while(~scanf("%d%d%d",&n,&R,&C)){
		rep(i,1,R+1) h[i] = -1; e_cnt = 0;
		w.clear();
		rep(i,0,n){
			int x1,x2,y1,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			add(x1,y1,y2,1);
			add(x2+1,y1,y2,-1);
		}
		sort(all(w)); w.erase(unique(all(w)),w.end());
		Build(0,sz(w)-2);
		sg = 0;
		int po = 0;
		rep(i,1,R+1){
			for(int k=h[i];~k;k=ne[k]){
				e[k].l = lower_bound(all(w),e[k].l) - w.begin();
				e[k].r = lower_bound(all(w),e[k].r+1) - w.begin();
				Cover(0,sz(w)-2,e[k].l,e[k].r-1,e[k].v);
			}
			while(po < sz(w)-1 && w[po] < i) ++po;
			szcnt = 0 , nowx = i;
			covcnt = 0; if(po - 1 >= 0) Query_sz(0,sz(w)-2,0,po-1);
			covcnt = 0; if(po <= sz(w)-2) Query_sgs(0,sz(w)-2,po,sz(w)-2);
			if(szcnt&1) sg ^= i&(-i);
		}
		if(sg) puts("GTW wins"); else puts("DSY wins");
	}
	return 0;
}
