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

const int N = 202;

int n, top;
int a[N][N], pre[N*N], vis[N*N], sta[N*N];

void push(int x) {
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
	int cnt[N][2], id[N][::N<<1];
	void init(int rt, int l) {
		cnt[rt][0] = cnt[rt][1] = 0;
		rep(i, 0, n) {
			if(i == 0 || a[i][l] != a[i-1][l]) {
				id[rt][i] = i * n + l;
				++cnt[rt][a[i][l]];
			} else {
				id[rt][i] = id[rt][i-1];
			}
			id[rt][i+n] = id[rt][i];
		}
	}
	void up(int rt, int l, int r, int mid) {
		rep(i, 0, 2) cnt[rt][i] = cnt[ls][i] + cnt[rs][i];
		rep(i, 0, n) if(a[i][mid] == a[i][mid+1]) {
			int x = find(id[ls][i+n]), y = find(id[rs][i]);
			if(x != y) {
				--cnt[rt][a[i][mid]];
				pre[x] = y;
				if(!vis[x]) push(x);
			}
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
	void upd(int p, int l, int r, int rt) {
		if(l == r) {
			init(rt, p);
			return ;
		}
		int mid = l + r >> 1;
		if(p <= mid) upd(p, l, mid, ls);
		else upd(p, mid+1, r, rs);
		up(rt, l, r, mid);
	}
}seg;

void init() {
	rep(i, 1, top+1) vis[sta[i]] = 0, pre[sta[i]] = sta[i];
	top = 0;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> n;
		rep(i, 0, n) rep(j, 0, n) cin >> a[i][j];
		rep(i, 0, n*n) pre[i] = i;
		init();
		seg.build(0, n-1, 1);
		int m;
		cin >> m;
		while(m--) {
			int o, x, y;
			cin >> o;
			if(o == 1) {
				cin >> y;
				--y;
				rep(x, 0, n) a[x][y] ^= 1;
			} else {
				cin >> x >> y;
				--x, --y;
				a[x][y] ^= 1;
			}
			init();
			seg.upd(y, 0, n-1, 1);
			init();
			int r[] = {seg.cnt[1][0], seg.cnt[1][1]};
			rep(i, 0, n) if(a[i][0] == a[i][n-1]) {
				int x = find(seg.id[1][i]), y = find(seg.id[1][i+n]);
				if(x != y) {
					--r[a[i][0]];
					pre[x] = y;
					if(!vis[x]) push(x);
				}
			}
			cout << r[0] << " " << r[1] << endl;
		}
	}
	return 0;
}
