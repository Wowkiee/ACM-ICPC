#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
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

int n, m, q, top, ans, sz;
int a[11][N], pre[11*N], sta[11*N];
bool vis[11*N];
pii res[N];

inline void init() {
	rep(i, 1, top+1) vis[sta[i]] = 0, pre[sta[i]] = sta[i];
	top = ans = 0;
	sz = 0;
}

inline void push(int x) {
	vis[x] = 1;
	sta[++top] = x;
}

int find(int x) {
	if(x == pre[x]) return x;
	if(!vis[x]) push(x);
	return pre[x] = find(pre[x]);
}

struct Seg {
#define ls rt<<1
#define rs ls|1
	static const int N = ::N << 2;
	int cnt[N], id[N][22];
	inline void init(int rt, int l) {
		cnt[rt] = 0;
		rep(i, 0, n) {
			if(i == 0 || a[i][l] != a[i-1][l]) {
				++cnt[rt];
				id[rt][i] = i * m + l; 
			} else {
				id[rt][i] = id[rt][i-1];
			}
			id[rt][i+n] = id[rt][i];
		}
	}
	inline void up(int rt, int l, int r, int mid) {
		cnt[rt] = cnt[ls] + cnt[rs];
		rep(i, 0, n) if(a[i][mid] == a[i][mid+1]) {
			int x = find(id[ls][i+n]), y = find(id[rs][i]);
			if(x == y) continue;
			pre[x] = y;
			if(!vis[x]) push(x);
			--cnt[rt];
		}
		rep(i, 0, n) {
			id[rt][i] = find(id[ls][i]);
			id[rt][i+n] = find(id[rs][i+n]);
		}
	}
	void build(int l, int r, int rt) {
		if(l == r) {
			init(rt, l);
			return ;
		}
		int mid = l + r >> 1;
		build(l, mid, ls);
		build(mid+1, r, rs);
		up(rt, l, r, mid);
	}
	void qry(int L, int R, int l, int r, int rt) {
		if(L <= l && r <= R) {
			ans += cnt[rt];
			res[sz++] = mp(l, rt);
			res[sz++] = mp(r, rt);
			return ;
		}
		int mid = l + r >> 1;
		if(L <= mid) qry(L, R, l, mid, ls);
		if(R >= mid+1) qry(L, R, mid+1, r, rs);
	}
}seg;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> m >> q;
	rep(i, 0, n) rep(j, 0, m) cin >> a[i][j];
	rep(i, 0, n*m) pre[i] = i;
	seg.build(0, m-1, 1);
	while(q--) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		init();
		seg.qry(l, r, 0, m-1, 1);
		for(int t = 1; t < sz - 1; t += 2) {
			int ll = res[t].se, rr = res[t+1].se, mid = res[t].fi;	
			rep(i, 0, n) if(a[i][mid] == a[i][mid+1]) {
				int x = find(seg.id[ll][i+n]), y = find(seg.id[rr][i]);
				if(x == y) continue;
				pre[x] = y;
				--ans;
				if(!vis[x]) push(x);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
