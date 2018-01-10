#include <cstdio>
#include <algorithm>
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
//------

const int N=101010;
int n,m,cntx;
int a[N],x[N];

int cntn;
int root[N];
int cnt[N*22], ls[N*22], rs[N*22];

void upd(int pre,int &now,int p,int l,int r) {
	now=++cntn;
	cnt[now]=cnt[pre]+1;
	ls[now]=ls[pre];
	rs[now]=rs[pre];
	if(l==r) return ;
	int mid=l+r>>1;
	if(p<=mid) upd(ls[pre], ls[now], p, l, mid);
	else upd(rs[pre], rs[now], p, mid+1, r);
}

int qry(int L,int R,int l,int r,int k) {
	if(l==r) return l;
	int mid=l+r>>1;
	int cl = cnt[ls[R]]-cnt[ls[L]];
	if(k<=cl) return qry(ls[L], ls[R], l, mid, k);
	return qry(rs[L], rs[R], mid+1, r, k-cl);
}

int main() {
	while(~scanf("%d%d",&n,&m)) {
		///init
		cntx=cntn=0;
		///read
		rep(i,1,n+1) {
			scanf("%d",a+i);
			x[++cntx]=a[i];
		}
		///solve
		sort(x+1,x+1+cntx);
		cntx=unique(x+1,x+1+cntx)-x-1;
		rep(i,1,n+1) {
			int p=lower_bound(x+1,x+1+cntx,a[i])-x;
			upd(root[i-1],root[i],p,1,cntx);
		}
		while(m--) {
			int l,r,k;scanf("%d%d%d",&l,&r,&k);
			int p=qry(root[l-1], root[r], 1, cntx, k);
			printf("%d\n",x[p]);
		}
	}
	return 0;
}
