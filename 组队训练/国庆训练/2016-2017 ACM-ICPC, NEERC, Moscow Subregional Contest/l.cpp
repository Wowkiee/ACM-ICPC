#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
//---
const int N=100005<<2;
typedef pair<db,db> pdd;
pdd tree[N],lazy[N];
int tim[N];
char co[N][2];
//---
pdd operator +(pdd a,pdd b) {
	return mp(a.fi+b.fi,a.se+b.se);
}
void up(int node) {
	tree[node]=tree[node<<1]+tree[node<<1|1];
}
void buildtree(int l,int r,int node) {
	lazy[node]=mp(0.0,1.0);
	if(l==r)tree[node]=mp(0.0,1.0);
	else {
		int mid=(l+r)>>1;
		buildtree(l,mid,node<<1);
		buildtree(mid+1,r,node<<1|1);
		up(node);
	}
}
void down(int node) {
	if(lazy[node].se!=1.0){
		lazy[node<<1].fi/=lazy[node].se;
		lazy[node<<1|1].fi/=lazy[node].se;
		lazy[node<<1].se*=lazy[node].se;
		lazy[node<<1|1].se*=lazy[node].se;
		tree[node<<1].se*=lazy[node].se;
		tree[node<<1|1].se*=lazy[node].se;
		lazy[node].se=1.0;
	}
	if(lazy[node].fi!=0.0) {
		lazy[node<<1].fi+=lazy[node].fi;
		lazy[node<<1|1].fi+=lazy[node].fi;
		tree[node<<1].fi+=lazy[node].fi*tree[node<<1].se;
		tree[node<<1|1].fi+=lazy[node].fi*tree[node<<1|1].se;
		lazy[node].fi=0.0;
	}
}
void update(int l,int r,int node,int _l,int _r,int zt,db val) {
	if(l==_l&&r==_r) {
		if(zt==1) {
			lazy[node].fi+=val;
			tree[node].fi+=val*tree[node].se;
		}
		else {
			lazy[node].fi/=val;
			lazy[node].se*=val;
			tree[node].se*=val;
		}
		return;
	}
	else if(l==r)return;
	int mid=(l+r)>>1;
	down(node);
	if(_r<=mid)update(l,mid,node<<1,_l,_r,zt,val);
	else if(_l>mid)update(mid+1,r,node<<1|1,_l,_r,zt,val);
	else {
		update(l,mid,node<<1,_l,mid,zt,val);
		update(mid+1,r,node<<1|1,mid+1,_r,zt,val);
	}
	up(node);
}
db query(int l,int r,int node,int c) {
	if(l==r)return tree[node].fi;
	else {
		down(node);
		int mid=(l+r)>>1;
		if(c<=mid)return query(l,mid,node<<1,c);
		else return query(mid+1,r,node<<1|1,c);
	}
}

//---
int main() {
	int n;while(scanf("%d",&n)!=EOF) {
		rep(i,0,n<<1)scanf("%s%d",co[i],&tim[i]);
		int p=0;
		buildtree(1,n,1);
		int nowl=1,nown=0,cc=0;
		rep(i,0,n<<1) {
			if(cc)update(1,n,1,nowl,nown,1,tim[i]-tim[i-1]);
			if(co[i][0]=='+')nown++,cc++;
			else {
				cc--;
				if(cc)update(1,n,1,nowl,nown,2,1-1.0/(cc+1));
				else {
					rep(i,nowl,nown+1)printf("%.12lf\n",query(1,n,1,i));
					nowl=nown+1;
				}
			}
		}
	}
	return 0;
}
