#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----

const int N=101010;

int n,q,cntn;
int rt[N], cnt[N*20], ls[N*20], rs[N*20];

void upd(int pre, int &now, int p, int l=1,int r=n) {
	now=++cntn;
	cnt[now]=cnt[pre]+1;
	ls[now]=ls[pre];
	rs[now]=rs[pre];
	if(l==r) return ;
	int mid=l+r>>1;
	if(p<=mid) upd(ls[pre], ls[now], p, l, mid);
	else upd(rs[pre], rs[now], p, mid+1, r);
}

int qry(int lt,int rt,int L,int R,int l=1,int r=n) {
	if(L<=l&&r<=R) return cnt[rt]-cnt[lt];
	int mid=l+r>>1;
	int ans=0;
	if(L<=mid) ans+=qry(ls[lt], ls[rt], L, R, l, mid);
	if(R>=mid+1) ans+=qry(rs[lt], rs[rt], L, R, mid+1, r);
	return ans;
}

bool check(int h,int l,int r) {
	return qry(rt[l-1], rt[r], h, n)>=h;
}

int main() {
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	while(~scanf("%d%d",&n,&q)) {
		///init
		cntn=0;
		///read
		rep(i,1,n+1) {
			int x;scanf("%d",&x);
			upd(rt[i-1], rt[i], x);
		}
		///solve
		while(q--) {
			int l,r;scanf("%d%d",&l,&r);
			int st=0, ed=r-l+1, ans=0;
			while(st<=ed) {
				int mid=st+ed>>1;
				if(check(mid,l,r)) {
					ans=mid;
					st=mid+1;
				} else {
					ed=mid-1;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
