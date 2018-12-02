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

const int N = 120001;

int n;
int X[N];
bool vis[5];

struct Q {
	int o, v, t;
}q[N];

struct Seg {
#define ls rt<<1
#define rs ls|1
	static const int N = ::N << 4;
	int ma[N], la[N];
	void build(int n) {
		fill_n(ma+1, n<<2, 0);
		fill_n(la+1, n<<2, 0);
	}
	void down(int rt) {
		if(!la[rt]) return ;
		ma[ls] += la[rt];
		ma[rs] += la[rt];
		la[ls] += la[rt];
		la[rs] += la[rt];
		la[rt] = 0;
	}
	void upd(int L, int R, int c, int l, int r, int rt) {
		if(L <= l && r <= R) {
			ma[rt] += c;
			la[rt] += c;
			return ;
		}
		int mid = l + r >> 1;
		down(rt);
		if(L <= mid) upd(L, R, c, l, mid, ls);
		if(R >= mid+1) upd(L, R, c, mid+1, r, rs);
		ma[rt] = max(ma[ls], ma[rs]);
	}
	int qry(int p, int l, int r, int rt) {
		if(l == r) return ma[rt];
		int mid = l + r >> 1;
		down(rt);
		if(p <= mid) return qry(p, l, mid, ls);
		else return qry(p, mid+1, r, rs);
	}
	int qry(int L, int R, int c, int l, int r, int rt) {
		if(L <= l && r <= R && (ma[rt] < c || l == r)) {
			if(ma[rt] < c) return 0;
			return l;
		}
		int mid = l + r >> 1;
		down(rt);
		if(R >= mid+1) {
			int t = qry(L, R, c, mid+1, r, rs);
			if(t) return t;
		}
		if(L <= mid) {
			int t = qry(L, R, c, l, mid, ls);
			if(t) return t;
		}
		return 0;
	}
}seg[5];

// val, tim
// val: empty -2, else val
pii qry(int t) {
	int val = -2, tim = 0;
	rep(i, 0, 5) if(vis[i]) {
		int c = seg[i].qry(t, 1, n, 1);
		int k = seg[i].qry(1, t, c+1, 1, n, 1);
		if(tim < k) val = i, tim = k;
	}
	return mp(val, tim);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> n;
		rep(i, 0, 5) vis[i] = 0;
		rep(i, 1, n+1) {
			string s;
			int v, t;
			cin >> s;
			if(s[0] == 'p' && s[1] == 'u') {
				cin >> v >> t;
				q[i].o = 0;
			} else if(s[0] == 'd') {
				cin >> v >> t;
				q[i].o = 1;
			} else if(s[0] == 'p') {
				cin >> t;
				q[i].o = 2;
			} else {
				cin >> t;
				q[i].o = 3;
			}
			vis[v-1] = 1;
			q[i].v = v - 1;
			q[i].t = t;
			X[i] = t;
		}
		sort(X+1, X+1+n);
		rep(i, 0, 5) if(vis[i]) seg[i].build(n);
		set<int> s;
		rep(i, 1, n+1) {
			int o = q[i].o, t = lower_bound(X+1, X+1+n, q[i].t) - X;
			if(o == 0) {
				seg[q[i].v].upd(1, t, 1, 1, n, 1);
			} else if(o == 1) {
				seg[q[i].v].upd(1, t, -1, 1, n, 1);
			} else if(o == 2) {
				s.insert(t);
			} else {
				vector<pii> r;
				for(auto u : s) {
					if(u > t) break;
					pii v = qry(u);
					r.pb(v);
					seg[v.fi].upd(1, v.se, -1, 1, n, 1);
				}
				pii v = qry(t);
				cout << v.fi + 1 << endl;
				for(auto v : r) seg[v.fi].upd(1, v.se, 1, 1, n, 1);
			}
		}
	}
	return 0;
}
