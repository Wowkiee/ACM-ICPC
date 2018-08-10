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
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 1010101;

namespace SA {
	const static int N = ::N << 1;
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
		}
};

string s;
int n, ans;
int cnt[2], pre[N], mpre[N], msuf[N], in[N<<1];

void solve() {
	int add = (cnt[0] < cnt[1]) ? (cnt[1] - cnt[0]) : 0;
	rep(_, 1, n<<1|1) {
		int i = SA::sa[_];
		if(i >= n) continue;
		++i;
		int t = min(msuf[i] - pre[i-1], mpre[i-1] + pre[n] - pre[i-1]) + add;
		if(t >= 0) {
			ans = i;
			return ;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	///read
	cin >> s;
	n = sz(s);
	s = " " + s;
	///get cnt, pre
	rep(i, 1, n+1) {
		++cnt[s[i] == ')'];
		int t = (s[i] == '(') ? 1 : -1;
		pre[i] = pre[i-1] + t;
	}
	mpre[1] = pre[1];
	rep(i, 2, n+1) mpre[i] = min(mpre[i-1], pre[i]);
	msuf[n] = pre[n];
	for(int i = n-1; i; --i) msuf[i] = min(msuf[i+1], pre[i]);
	///get da
	rep(i, 1, n+1) in[i-1] = (s[i] == ')') + 1;
	rep(i, 1, n+1) in[n+i-1] = (s[i] == ')') + 1;
	in[n<<1] = 0;
	SA::suffixArray<int>(n<<1, in);
	///solve
	solve();
	while(cnt[0] < cnt[1]) cout << "(", ++cnt[0];
	rep(i, ans, n+1) cout << s[i];
	rep(i, 1, ans) cout << s[i];
	while(cnt[0] > cnt[1]) cout << ")", ++cnt[1];
	return 0;
}
