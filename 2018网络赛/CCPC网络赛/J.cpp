#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---
const int N=100005;
vector<int> V;
int s;
struct vil {
	int x,y,val;
	void in() {
		scanf("%d%d%d",&x,&y,&val);
		V.pb(x);
	}
}data[N];
int cmp(vil a,vil b) {
	return a.y<b.y;
}
int tree[N<<2];
void update(int l,int r,int node,int c,int val) {
	if(l==r) {
		tree[node]=max(tree[node],val);
		return;
	}
	int mid=(l+r)>>1;
	if(c<=mid)update(l,mid,node<<1,c,val);
	else update(mid+1,r,node<<1|1,c,val);
	tree[node]=max(tree[node<<1],tree[node<<1|1]);
}
int query(int l,int r,int node,int _l,int _r) {
	int mid=(l+r)>>1;
	if(_l>r||_r<l)return 0;
	else if(_l<=l&&_r>=r)return tree[node];
	else return max(query(l,mid,node<<1,_l,_r),query(mid+1,r,node<<1|1,_l,_r));
}
int main() {
	int T;scanf("%d",&T);while(T--) {
		memset(tree,0,sizeof(tree));
		V.clear();V.pb(0);V.pb(1e9);
		int n;scanf("%d",&n);
		rep(i,0,n)data[i].in();
		sort(all(V));V.erase(unique(all(V)),V.end());
		s=sz(V);
		rep(i,0,n)data[i].x=lower_bound(all(V),data[i].x)-V.begin()+1;
		sort(data,data+n,cmp);
		queue<pii> Q;
		rep(i,0,n) {
			if(i&&data[i].y!=data[i-1].y) {
				while(!Q.empty()) {
					pii f=Q.front();Q.pop();
					update(1,s,1,f.fi,f.se);
				}
			}
			Q.push(mp(data[i].x,query(1,s,1,1,data[i].x-1)+data[i].val));
		}
		while(!Q.empty()) {
			pii f=Q.front();Q.pop();
			update(1,s,1,f.fi,f.se);
		}
		cout<<query(1,s,1,1,s)<<endl;
	}
	return 0;
}
