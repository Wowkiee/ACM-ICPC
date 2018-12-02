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

const int N = 101010;

namespace Doubling {
	static const int N = ::N;
	int t[N], wa[N], wb[N], sa[N], h[N];
	void sort(int *x, int *y, int n, int m) {
		rep(i, 0, m) t[i] = 0;
		rep(i, 0, n) t[x[y[i]]]++;
		rep(i, 1, m) t[i] += t[i-1];
		per(i, 0, n) sa[--t[x[y[i]]]] = y[i];
	}
	bool cmp(int *x, int a, int b, int d) {
		return x[a] == x[b] && x[a+d] == x[b+d];
	}
	void da(int *s, int n, int m) {
		int *x = wa, *y = wb;
		rep(i, 0, n) x[i] = s[i], y[i] = i;
		sort(x, y, n, m);
		for(int j = 1, p = 1; p < n; m = p, j <<= 1) {
			p = 0; rep(i, n-j, n) y[p++] = i;
			rep(i, 0, n) if(sa[i] >= j) y[p++] = sa[i] - j;
			sort(x, y, n, m);
			swap(x, y); p = 1; x[sa[0]] = 0;
			rep(i, 1, n) x[sa[i]] = cmp(y, sa[i], sa[i-1], j) ? p-1 : p++;
		}
	}
	void cal_h(int *s, int n, int *rk) {
		int j, k = 0;
		for(int i = 1; i <= n; ++i) rk[sa[i]] = i;
		for(int i = 0; i < n; h[rk[i++]] = k) {
			for(k && --k, j = sa[rk[i] - 1]; s[i + k] == s[j + k]; ++k) ;
		}
	}
}
struct DA{
	static const int N = ::N;
	int p[22][N], rk[N], in[N], Log[N], n;
	void Build() {
		Doubling::da(in, n + 1, 300);
		Doubling::cal_h(in, n, rk);
		Log[0] = -1; for(int i = 1; i <= n; ++i) Log[i] = Log[i - 1] + (i == (i & (-i)));
		for(int i = 1; i <= n; ++i) p[0][i] = Doubling::h[i];
		for(int j = 1; 1<<j <= n; ++j) {
			int lim  = n + 1 - (1 << j);
			for(int i = 1; i <= lim; ++i) {
				p[j][i] = min(p[j-1][i], p[j-1][i+(1<<j>>1)]);
			}
		}
	}
	int lcp(int a, int b) {
		if(a > b) swap(a, b);
		if(a == b) return n - Doubling::sa[a];
		if(b > n) return 0;
		++a;
		int t = Log[b - a + 1];
		return min(p[t][a], p[t][b - (1<<t) + 1]);
	}
	ll solve(int l, int r) {
		ll ans = 0;
		rep(i, 1, n + 1) {
			int st = Doubling::h[i] + 1, ed = n - Doubling::sa[i];
			st = max(st, lcp(i, i + r) + 1);
			ed = min(ed, lcp(i, i + l - 1));
			if(st <= ed) ans += ed - st + 1;
		}
		return ans;
	}
}da;

string s;
int l, r;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	while(cin >> s >> l >> r) {
		rep(i, 0, sz(s)) da.in[i] = s[i] - 'A' + 1;
		da.in[sz(s)] = 0;
		da.n = sz(s);
		da.Build();
		cout << da.solve(l, r) << endl;
	}
	return 0;
}
