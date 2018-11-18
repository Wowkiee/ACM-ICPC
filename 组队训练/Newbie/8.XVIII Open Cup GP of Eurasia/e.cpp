#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(a) cout << #a << " = " << a << " "
#define de(a) cout << #a << " = " << a << endl
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;


const int N = 2e5 + 7;

int n, f[N], m, mm, ans, x, s[N], a[N], b[N], pp, pos[N], a1[N], b1[N], id[N];
struct node {
	int l, r, f, a, pre;
}v[N], p[N];

bool cmp(const node &a, const node &b) {
	return a.a < b.a;
}

bool cmp2(const node &a, const node &b) {
	return a.l < b.l;
}

struct Fenwick{
	static const int N = 2e5 + 7;
	int n; int a[N];
	void ini(int _n) {
		fill_n(a+1, n = _n, 0);	
	}

	int rmax(int a, int b) {
		return f[a] > f[b] ? a : b;
	}
	void add(int p, int x) {
		for (; p <=n; p += p & -p) a[p] = rmax(a[p], x);
	}
	void del(int p) {	
		for (; p <=n; p += p & -p) a[p] = 0;
	}
	int qry(int p) {
		int res = 0;
		for (; p >=1; p -= p & -p) res = rmax(a[p], res);
		return res;
	}
} fen;

void solve(int l, int mid, int r) {
	rep(i, mid+1, r+1) {
		while (l <= mid && p[l].r < p[i].l) {
			fen.add(p[l].r + 1 - s[p[l].a], p[l].a);
			l++;
		}
		int x = fen.qry(p[i].l - s[p[i].a-1]);
		if(f[x] + p[i].r - p[i].l + 1 > p[i].f) {
			p[i].f = f[x] + p[i].r - p[i].l + 1;
			p[i].pre = x;
			f[p[i].a] = p[i].f;
		}
	}
	rep(i, l, mid+1) fen.del(p[i].r + 1 - s[p[i].a]);
}

void CDQ(int l, int r) {
	if (l == r) {
		int i = l;
		if (p[i].f < p[i].r - p[i].l + 1) {
			p[i].f = p[i].r - p[i].l + 1;
			p[i].pre = 0;
			f[p[i].a] = p[i].f;
		}
		return;
	}
	int mid = l + r >> 1;
	CDQ(l, mid);

	sort(p+mid+1, p+r+1, cmp2);
	solve(l, mid, r);
	sort(p+mid+1, p+r+1, cmp);

	CDQ(mid+1, r);
	sort(p+l, p+r+1, cmp2);
}

bool use[N];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m;
	//n = 10;
	//m = 10;

	fen.ini(n + 5);
	rep(i, 1, n+1) {
		cin >> a[i] >> b[i];
		//if (i == 1) a[i] = n;else a[i] = i-1;
		//b[i] = 1;
		if (a[i] != -1 && a[i] != a[i-1]) {
			v[a[i]].l = v[a[i]].r = i;
			v[a[i]].a = a[i];
		}else if (a[i] != -1) v[a[i]].r = i;
	}
	//rep(i, 1, n+1) cout << a[i] << " " << b[i] << endl;;
	//return 0;
	rep(i, 1, m+1) s[i] = s[i-1] + v[i].r - v[i].l + 1;
	mm = 0;
	rep(i, 1, m+1) if (v[i].r + s[m] - s[v[i].a] <= n && s[v[i].a-1] < v[i].l) p[++mm] = v[i]; 
	sort(p+1, p+mm+1, cmp);
	/*rep(i, 1, mm+1) {
		dd(p[i].a); dd(p[i].l); dd(p[i].r);
	}*/
	//return 0;
	rep(i, 1, mm+1) p[i].f = -1;
	f[0] = -pw(30);
	rep(i, 1, m+1) f[i] = -1;
	//de(mm);
	//return 0;
	if (mm >= 1) CDQ(1, mm);
	//return 0;
	ans = 0;
	rep(i, 1, mm+1) {
		if (ans < p[i].f) {
			ans = p[i].f;
			pp = i;
		}
	}
	//return 0;
	vi tmp;
	rep(i, 1, mm+1) pos[p[i].a] = i;
	while (pp != 0) {
		tmp.pb(p[pp].a);
		pp = pos[p[pp].pre];
		assert(sz(tmp) <= N);
	}
	reverse(all(tmp));
	
	rep(i, 0, sz(tmp)) use[tmp[i]] = 1;
	rep(i, 1, n+1) a1[i] = b1[i] = -1;
	int pre = 0;
	rep(i, 1, m+1) if (!use[i]) {
		rep(j, v[i].l, v[i].r+1)  a1[pre + j - v[i].l + 1] = v[i].a, b1[pre + j - v[i].l + 1] = j - v[i].l + 1;
		pre += v[i].r - v[i].l + 1;
	}else {
		rep(j, v[i].l, v[i].r+1) a1[j] = v[i].a, b1[j] = j - v[i].l + 1;
		pre = v[i].r;
	}
	//rep(i, 1, n+1) cout << a1[i] <<" " << b1[i] <<endl;	
	rep(i, 1, n + 1) if(a1[i] != -1) {
		int t = s[a1[i] - 1] + b1[i];
		id[t] = i;
	}
	int _ = 0;
	vector<vi> res;
	rep(i, 1, n + 1) if(a[i] != -1) {
		int t = s[a[i] - 1] + b[i];
		if(id[t] != i) {
			vi v;
			v.pb(i);
			int x = a[i], y = b[i];
			a[i] = b[i] = -1;
			while(1) {
				int c = id[s[x - 1] + y];
				v.pb(c);
				swap(x, a[c]), swap(y, b[c]);
				if(x == -1 && y == -1) break;
				++_;
				assert(_ <= N);
			}
			res.pb(v);
		}
	}
	cout << s[m] - ans << " " << sz(res) << endl;
	rep(i, 0, sz(res)) {
		vi v = res[i];
		cout << sz(v);
		rep(j, 0, sz(v)) cout << " " << v[j];
		cout << endl;
	}
	return 0;
}
