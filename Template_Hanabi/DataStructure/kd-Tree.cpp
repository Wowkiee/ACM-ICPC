/*
	
*/
const ll INF=1ll<<62;
const int N=200005;
int Q;
ll now;

int T,n,m,root;

struct node{
	int d[2],id,l,r,mi[2],ma[2],minp,p;
	void add(int x,int y,int z) {d[0]=x;d[1]=y;id=z;}
};

bool cmp(node a,node b){
	return a.d[Q]<b.d[Q];
}

node a[N],tr[N],ans,v;

void update(int x){
	rep(i,0,2) {
		tr[x].mi[i]=tr[x].ma[i]=tr[x].d[i];
		if (tr[x].l) {
			tr[x].mi[i]=min(tr[x].mi[i],tr[tr[x].l].mi[i]);
			tr[x].ma[i]=max(tr[x].ma[i],tr[tr[x].l].ma[i]);
		}
		if (tr[x].r) {
			tr[x].mi[i]=min(tr[x].mi[i],tr[tr[x].r].mi[i]);
			tr[x].ma[i]=max(tr[x].ma[i],tr[tr[x].r].ma[i]);
		}
	}
}

int build(int l,int r,int k) {
	if (l>r) return 0;
	int mid=(l+r)>>1;Q=k;
	nth_element(a+l,a+mid,a+r+1,cmp);
	tr[mid]=a[mid];
	tr[mid].l=build(l,mid-1,k^1);
	tr[mid].r=build(mid+1,r,k^1);
	update(mid);
	return mid;
}

ll sqr(ll x) {return x*x;}

ll get(node v,int x) {//估价函数
	if (!x) return 0;
	ll res=0;
	rep(i,0,2) {
		if (v.d[i]<tr[x].mi[i]) res+=sqr(v.d[i]-tr[x].mi[i]);
		if (v.d[i]>tr[x].ma[i]) res+=sqr(v.d[i]-tr[x].ma[i]);
	}
	return res;
}
 
void check(node v,int x) {
	ll dis=0;
	rep(i,0,2) dis+=sqr(tr[x].d[i]-v.d[i]);
	if (dis<now || (dis==now && tr[x].id<ans.id)) {
		now=dis;
		ans=tr[x];
	}
}
 
void ask(node v,int x) {
	if (!x) return;
	check(v,x);
	ll lm=get(v,tr[x].l),rm=get(v,tr[x].r);
	if (lm<rm) {
		if (lm<=now) ask(v,tr[x].l);
		if (rm<=now) ask(v,tr[x].r);
	}else {
		if (rm<=now) ask(v,tr[x].r);
		if (lm<=now) ask(v,tr[x].l);
	}
}

int main(){
	scanf("%d",&T);
	rep(ii,0,T){
		scanf("%d%d",&n,&m);
		rep(i,1,n+1) {
			scanf("%d%d",&a[i].d[0],&a[i].d[1]);
		}
		root=build(1,n,0);
		rep(i,1,m+1) {
			now=INF;
			scanf("%d%d",&v.d[0],&v.d[1]);
			ask(v,root);
			printf("%d %d\n",ans.d[0],ans.d[1]);
		}
	}	
}
