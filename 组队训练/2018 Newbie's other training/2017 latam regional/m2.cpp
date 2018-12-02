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

int n, tot;
int a[N * 5];
vi v[N];

namespace SA2 {
	const static int N = ::N * 5;
	int sa[N], rk[N], ht[N], s[N<<1], t[N<<1], p[N], cnt[N], cur[N];
#define pushS(x) sa[cur[s[x]]--] = x
#define pushL(x) sa[cur[s[x]]++] = x
#define inducedSort(v) std::fill_n(sa, n, -1); std::fill_n(cnt, m, 0);      \
	for (int i = 0; i < n; i++) cnt[s[i]]++;                                  \
	for (int i = 1; i < m; i++) cnt[i] += cnt[i-1];                           \
	for (int i = 0; i < m; i++) cur[i] = cnt[i]-1;                            \
	for (int i = n1-1; ~i; i--) pushS(v[i]);                                  \
	for (int i = 1; i < m; i++) cur[i] = cnt[i-1];                            \
	for (int i = 0; i < n; i++) if (sa[i] > 0 &&  t[sa[i]-1]) pushL(sa[i]-1); \
	for (int i = 0; i < m; i++) cur[i] = cnt[i]-1;                            \
	for (int i = n-1;  ~i; i--) if (sa[i] > 0 && !t[sa[i]-1]) pushS(sa[i]-1)
	void sais(int n, int m, int *s, int *t, int *p) {
		int n1 = t[n-1] = 0, ch = rk[0] = -1, *s1 = s+n;
		for (int i = n-2; ~i; i--) t[i] = s[i] == s[i+1] ? t[i+1] : s[i] > s[i+1];
		for (int i = 1; i < n; i++) rk[i] = t[i-1] && !t[i] ? (p[n1] = i, n1++) : -1;
		inducedSort(p);
		for (int i = 0, x, y; i < n; i++) if (~(x = rk[sa[i]])) {
			if (ch < 1 || p[x+1] - p[x] != p[y+1] - p[y]) ch++;
			else for (int j = p[x], k = p[y]; j <= p[x+1]; j++, k++)
				if ((s[j]<<1|t[j]) != (s[k]<<1|t[k])) {ch++; break;}
			s1[y = x] = ch;
		}
		if (ch+1 < n1) sais(n1, ch+1, s1, t+n, p+n1);
		else for (int i = 0; i < n1; i++) sa[s1[i]] = i;
		for (int i = 0; i < n1; i++) s1[i] = p[sa[i]];
		inducedSort(s1);
	}
	template<typename T>
		int mapCharToInt(int n, const T *str) {
			int m = *max_element(str, str+n);
			std::fill_n(rk, m+1, 0);
			for (int i = 0; i < n; i++) rk[str[i]] = 1;
			for (int i = 0; i < m; i++) rk[i+1] += rk[i];
			for (int i = 0; i < n; i++) s[i] = rk[str[i]] - 1;
			return rk[m];
		}
	template<typename T>
		void suffixArray(int n, const T *str) {
			int m = mapCharToInt(++n, str);
			sais(n, m, s, t, p);
			for (int i = 0; i < n; i++) rk[sa[i]] = i;
			for (int i = 0, h = ht[0] = 0; i < n-1; i++) {
				int j = sa[rk[i]-1];
				while (i+h < n && j+h < n && s[i+h] == s[j+h]) h++;
				if (ht[rk[i]] = h) h--;
			}

			rep(i, 0, n+1) {
				dd(i), dd(sa[i]);
				rep(j, sa[i], n) cout << str[j] << " ";
				cout << endl;
			}
			cout << endl;
		}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n+1) {
		int m;
		cin >> m;
		rep(j, 0, m) {
			int x;
			cin >> x;
			v[i].pb(x);
		}
		for(int j = m - 1; ~j; --j) a[tot++] = v[i][j] + 1;
		a[tot++] = 1;
	}
	a[tot] = 0;
	rep(i, 0, tot+1) cout << a[i] << " ";
	cout << endl << endl;
	a[tot] = 1;
	SA2::suffixArray<int>(tot, a);
	return 0;
}
