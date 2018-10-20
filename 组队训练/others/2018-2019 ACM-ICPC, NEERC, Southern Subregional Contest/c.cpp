#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(c) cout << #c << " = " << c << endl
#define dd(c) cout << #c << " = " << c << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1010100;

struct Seg {
#define ls rt << 1
#define rs ls | 1
	static const int N = ::N << 2;
	ll sum[N], cnt[N];
	void up(int rt) {
		cnt[rt] = cnt[ls] + cnt[rs];
		sum[rt] = sum[ls] + sum[rs];
	}
	void upd(int p, ll c, int l, int r, int rt) {
		if(l == r) {
			cnt[rt] += c;
			sum[rt] = cnt[rt] * l;
			return ;
		}
		int mid = l + r >> 1;
		if(p <= mid) upd(p, c, l, mid, ls);
		else upd(p, c, mid + 1, r, rs);
		up(rt);
	}
	ll qry(ll k, int l, int r, int rt) {
		if(cnt[rt] <= k) return sum[rt];
		if(l == r) return k * l;
		int mid = l + r >> 1;
		if(cnt[ls] >= k) return qry(k, l, mid, ls);
		return sum[ls] + qry(k - cnt[ls], mid + 1, r, rs);
	}
}seg;

vector<pii> V[N];
int main() {
	int n,m,k;scanf("%d%d%d",&n,&m,&k);
	rep(i,0,k) {
		int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
		V[a].pb(mp(c,d));V[b+1].pb(mp(-c,d));
	}
	ll ans=0;
	rep(i,1,n+1) {
		rep(j,0,sz(V[i])) {
			pii nxt=V[i][j];
			seg.upd(nxt.se,nxt.fi,1,1000000,1);
		}
		ans+=seg.qry(m,1,1000000,1);
	}
	cout<<ans<<endl;
	return 0;
}
