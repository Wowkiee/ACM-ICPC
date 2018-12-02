#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b-1);i>=a; i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 101010;

int n, m;
int a[N];

struct Seg {
#define ls rt<<1
#define rs ls|1
	static const int N = ::N << 2;
	int ma[N];
	void build(int l, int r, int rt) {
		if(l == r) {
			ma[rt] = a[l];
			return ;
		}
		int mid = l + r >> 1;
		build(l, mid, ls);
		build(mid+1, r, rs);
		ma[rt] = max(ma[ls], ma[rs]);
	}
	int qry(int L, int R, int c, int l, int r, int rt) {
		if(L <= l && r <= R && (ma[rt] <= c || l == r)) {
			if(ma[rt] <= c) return 0;
			return l;
		}
		int mid = l + r >> 1;
		if(L <= mid) {
			int t = qry(L, R, c, l, mid, ls);
			if(t) return t;
		}
		if(R >= mid+1) {
			int t = qry(L, R, c, mid+1, r, rs);
			if(t) return t;
		}
		return 0;
	}
}seg;
int nxt[N],ans[N]={0};
vector<int> V1,V2;
int main() {
	int T;scanf("%d",&T);while(T--) {
		V1.clear();V2.clear();
		int n,q;scanf("%d%d",&n,&q);
		rep(i,1,n+1)scanf("%d",&a[i]);
		a[0]=0,a[n+1]=1e9+7;V1.pb(0),V2.pb(0);
		seg.build(0,n+1,1);
		priority_queue<pii> Q;Q.push(mp(0,0));
		rep(i,1,n+2) {
			while(!Q.empty()&&-Q.top().fi<a[i])nxt[Q.top().se]=i,Q.pop();
			if(Q.empty())V1.pb(i),V2.pb(a[i]);
			Q.push(mp(-a[i],i));
		}
		ans[n+1]=1;
		per(i,0,n+1)ans[i]=ans[nxt[i]]+1;
		//rep(i,0,n+2)de(nxt[i]);
		//rep(i,0,n+2)de(ans[i]);
		//rep(i,0,sz(V))de(V[i]);
		int Ans=sz(V1)-2;
		while(q--) {
			int aa,b;scanf("%d%d",&aa,&b);
			if(a[aa]==b) {
				printf("%d\n",Ans);
				continue;
			}
			int p=lower_bound(all(V1),aa)-V1.begin();
			if(V1[p]==aa) {
				if(a[aa]<b) {
					int pnxt=upper_bound(all(V2),b)-V2.begin();
		//			de(Ans);de(pnxt);de(p);
					printf("%d\n",Ans-(pnxt-p)+1);
				}
				else {
					if(b<=V2[p-1]) {
						int pos=seg.qry(V1[p]+1,V1[p+1],V2[p-1],0,n+1,1);
						printf("%d\n",p+ans[pos]-2);
					}
					else {
						int pos=seg.qry(V1[p]+1,V1[p+1],b,0,n+1,1);
						printf("%d\n",p+ans[pos]-1);
					}
				}
			}
			else {
				if(a[aa]>b)printf("%d\n",Ans);
				else {
					if(b<=V2[p-1])printf("%d\n",Ans);
					else {
						int pnxt=upper_bound(all(V2),b)-V2.begin();
						printf("%d\n",Ans+1-(pnxt-p));
					}
				}
			}
		}
	}
	return 0;
}
