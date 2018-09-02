// 树状数组套主席树做法
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<assert.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define lb(x) ((x)&(-x))
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef pair<int, int> pii;

const int N = 50005, P = 1e9+7;

int n, m;
int ord[N], v[N], rt[N<<1];

struct IO {
    static const int IO_N = 1<<23;
    int wt,ss[19];
    char fl[IO_N], *A;
    void init() { A=fl; *(fl + fread(fl, 1, IO_N, stdin)) = EOF; }
    void read(int &x){
        char c;
        for(x = 0; '0' > (c = *A++) || c > '9'; );
        for(; '0' <= c && c <= '9'; c = *A++) x = (x << 3) + (x << 1) + c - 48;
    }
    void print(int x){
        if(!x) putchar(48); else {
            for(wt = 0; x; ss[++wt] = x % 10, x /= 10);
            for(; wt; putchar(ss[wt--] + 48));
        }
        putchar('\n');
    }
}io;

inline int add(int a, int b) {
	a+=b;
	if(a>=P) a-=P;
	return a;
}
inline int sub(int a, int b) {
	a-=b;
	if(a<0) a+=P;
	return a;
}
inline int mul(int a, int b) {
	return 1ll*a*b%P;
}
inline pii add(pii a, pii b) {
	return mp(a.fi+b.fi, add(a.se, b.se));
}
inline pii sub(pii a, pii b) {
	return mp(a.fi-b.fi, sub(a.se, b.se));
}

struct Seg {
	static const int N = 30000003;
	int cntn, cnt[N], ls[N], rs[N], sum[N];
	inline void init() {
		fill_n(rt+1, n<<1, cntn = 0);
	}
	inline void upd(int pre, int &now, int p, int c1, int c2, int l, int r) {
		now = ++cntn;
		assert(now<N);
		cnt[now] = cnt[pre] + c1;
		sum[now] = add(sum[pre], c2);
		ls[now] = ls[pre];
		rs[now] = rs[pre];
		if(l==r) return ;
		int mid = l+r>>1;
		if(p<=mid) upd(ls[pre], ls[now], p, c1, c2, l, mid);
		else upd(rs[pre], rs[now], p, c1, c2, mid+1, r);
	}
	inline void qry(pii &ans, int rt, int p, int l, int r) {
		if(p<=l) {
			ans = add(ans, mp(cnt[rt], sum[rt]));
			return ;
		}
		int mid = l+r>>1;
		if(p<=mid) qry(ans, ls[rt], p, l, mid);
		qry(ans, rs[rt], p, mid+1, r);
	}
}seg;

struct FW {
	int a[N];
	inline void init() {
		fill_n(a+1, n, 0);
	}
	inline void upd(int x, int d) {
		for( ; x<=n; x+=lb(x)) a[x] = add(a[x], d);
	}
	inline int qry(int x) {
		int r = 0;
		for( ; x>=1; x^=lb(x)) r = add(r, a[x]);
		return r;
	}
}f;

struct Fenwick {
	inline void upd(int x, int p, int c1, int c2) {
		for(; x<=n; x+=lb(x)) seg.upd(rt[x+n], rt[x+n], p, c1, c2, 1, n);
	}
	inline pii qry(int l, int r, int p) {
		if(p>n || l>r) return mp(0, 0);

		pii r1 = mp(0, 0);
		seg.qry(r1, rt[r], p, 1, n);
		for(int x = r; x; x^=lb(x)) seg.qry(r1, rt[x+n], p, 1, n);

		pii r2 = mp(0, 0);
		seg.qry(r2, rt[l-1], p, 1, n);
		for(int x = l-1; x; x^=lb(x)) seg.qry(r2, rt[x+n], p, 1, n);

		return sub(r1, r2);
	}
}fw;

inline int calc(pii t, int p) {
	int res = 0;
	res = add(res, mul(t.fi, v[p]));
	res = add(res, t.se);
	return res;
}

int main() {
	io.init();
	int T;
	io.read(T);
	while(T--) {
		///
		io.read(n);
		io.read(m);
		///init
		seg.init();
		f.init();
		///read
		rep(i, 1, n+1) io.read(ord[i]), io.read(v[i]);
		///solve
		int ans = 0;
		rep(i, 1, n+1) seg.upd(rt[i-1], rt[i], ord[i], 1, v[i], 1, n), f.upd(i, v[i]);
		rep(i, 1, n+1) ans = add(ans, calc(fw.qry(1, i-1, ord[i]+1), i));
		while(m--) {
			int i, j;
			io.read(i);
			io.read(j);

			if(i==j) {
				io.print(ans);
				continue;
			}

			if(i>j) swap(i, j);

			int t = add(v[i], v[j]);
			if(ord[i]<ord[j]) ans = add(ans, t);
			else ans = sub(ans, t);

			int tt = sub(f.qry(j-1), f.qry(i));
			pii temp = fw.qry(i+1, j-1, ord[i]+1);
			ans = add(ans, calc(temp, i));
			ans = sub(ans, calc(sub(mp(j-i-1, tt), temp), i));

			temp = fw.qry(i+1, j-1, ord[j]+1);
			ans = sub(ans, calc(temp, j));
			ans = add(ans, calc(sub(mp(j-i-1, tt), temp), j));

			io.print(ans);

			if(!m) continue;
			t = sub(v[j], v[i]);
			f.upd(i, t);
			f.upd(j, P - t);

			fw.upd(i, ord[i], -1, P-v[i]);
			fw.upd(j, ord[j], -1, P-v[j]);
			swap(ord[i], ord[j]);
			swap(v[i], v[j]);
			fw.upd(i, ord[i], 1, v[i]);
			fw.upd(j, ord[j], 1, v[j]);
		}
	}
	return 0;
}
