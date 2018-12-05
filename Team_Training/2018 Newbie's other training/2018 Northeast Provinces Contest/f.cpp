#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define endl "\n"
#define pw(a) (1ll << (a))
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;

const int N = 101010, inf = 1e9 + 7;

int n, res;
int pre[N];
vector<pair<pii, pii> > v[2], line, S;
vector<pair<int, pii> > tmp;
vi V;

int F(int x) {
	return lower_bound(all(V), x) - V.begin() + 1;
}

int find(int x) {
	return x == pre[x] ? x : pre[x] = find(pre[x]);
}
void join(int x, int y) {
//	dd(x), dd(y), de(sz(line));
	x = find(x);
	y = find(y);
	pre[x] = y;
}

void gao1() {
	for(auto u : v[0]) tmp.pb(mp(u.fi.fi, mp(u.fi.se, u.se.se)));
	sort(all(tmp));
	for(int i = 0, j; i < sz(tmp); i = j) {
		j = i;
		while(j < sz(tmp) && tmp[j].fi == tmp[i].fi) ++j;
		int l = -inf, r = -inf - 1;
		rep(t, i, j) {
			if(r < tmp[t].se.fi) {
				if(l <= r) line.pb(mp(mp(tmp[i].fi, l), mp(tmp[i].fi, r)));
				l = tmp[t].se.fi, r = tmp[t].se.se;
			} else {
				r = max(r, tmp[t].se.se);
			}
		}
		if(l <= r) line.pb(mp(mp(tmp[i].fi, l), mp(tmp[i].fi, r)));
	}
}

void gao2() {
	tmp.clear();
	for(auto u : v[1]) tmp.pb(mp(u.fi.se, mp(u.fi.fi, u.se.fi)));
	sort(all(tmp));
	for(int i = 0, j; i < sz(tmp); i = j) {
		j = i;
		while(j < sz(tmp) && tmp[j].fi == tmp[i].fi) ++j;
		int l = -inf, r = -inf - 1;
		rep(t, i, j) {
			if(r < tmp[t].se.fi) {
				if(l <= r) line.pb(mp(mp(l, tmp[i].fi), mp(r, tmp[i].fi)));
				l = tmp[t].se.fi, r = tmp[t].se.se;
			} else {
				r = max(r, tmp[t].se.se);
			}
		}
		if(l <= r) line.pb(mp(mp(l, tmp[i].fi), mp(r, tmp[i].fi)));
	}
}

struct Seg {
#define ls rt << 1
#define rs ls | 1
	static const int N = ::N << 3;
	int cnt[N], id[N];
	void up(int rt) {
		cnt[rt] = cnt[ls] + cnt[rs];
	}
	void upd(int p, int c, int l, int r, int rt) {
	//	if(rt == 1) dd(p), de(c);
		if(l == r) {
			cnt[rt] += c / abs(c);
			id[rt] += c;
			return ;
		}
		int mid = l + r >> 1; 
		if(p <= mid) upd(p, c, l, mid, ls);
		else upd(p, c, mid + 1, r, rs);
		up(rt);
	}
	void qry(int L, int R, int c, int l, int r, int rt) {
	//	if(rt == 1) dd(L), dd(R), de(c);
		if(res > sz(line) - 1) return ;
		if(L <= l && r <= R && (l == r || cnt[rt] == 0)) {
			if(cnt[rt] == 0) return ;
			join(c, id[rt]);
	//		dd(c), de(id[rt]);
			++res;
		}
		int mid = l + r >> 1;
		if(L <= mid) qry(L, R, c, l, mid, ls);
		if(R > mid) qry(L, R, c, mid + 1, r, rs);
	}
}seg;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n + 1) {
		int a1, b1, a2, b2;
		cin >> a1 >> b1 >> a2 >> b2;
		if(a1 > a2) swap(a1, a2);
		if(b1 > b2) swap(b1, b2);
		v[b1 == b2].pb(mp(mp(a1, b1), mp(a2, b2)));
	}
	gao1();
	gao2();
//	for(auto u : line) dd(u.fi.fi), dd(u.fi.se), dd(u.se.fi), de(u.se.se);
	rep(i, 0, sz(line)) {
		pre[i + 1] = i + 1;
		V.pb(line[i].fi.fi);
		V.pb(line[i].se.fi);
	}
	sort(all(V));
	V.erase(unique(all(V)), V.end());
	rep(i, 0, sz(line)) {
		auto u = line[i];
		int a1 = u.fi.fi, b1 = u.fi.se, a2 = u.se.fi, b2 = u.se.se;
		if(a1 == a2) {
			int t = F(a1);
			S.pb(mp(mp(b1, -inf), mp(t, i + 1)));
			S.pb(mp(mp(b2, inf), mp(t, i + 1)));
		} else {
			S.pb(mp(mp(b1, i + 1), mp(F(a1), F(a2))));
		}
	}
	sort(all(S));
	for(auto u : S) {
		if(u.fi.se == -inf) {
			seg.upd(u.se.fi, u.se.se, 1, n, 1);
		} else if(u.fi.se == inf) {
			seg.upd(u.se.fi, -u.se.se, 1, n, 1);
		} else {
			seg.qry(u.se.fi, u.se.se, u.fi.se, 1, n, 1);
			if(res > sz(line) - 1) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	if(res != sz(line) - 1) {
		cout << "No" << endl;
		return 0;
	}
	rep(i, 1, sz(line) + 1) if(find(i) != find(1)) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	return 0;
}
