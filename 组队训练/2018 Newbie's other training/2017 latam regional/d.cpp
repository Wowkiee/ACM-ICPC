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
const int P = 1e8 + 1;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---

const int N = 100001, M = 128, CN = N / M + 7;

int l, c, n;
short B[N], sz[CN];
int la[CN], a[N], ST[CN], ED[CN], cnt[N];
//unordered_map<int, short> s[CN];
short s[CN][N];

inline void upd(int blo, int st, int ed, int x) {
	st = max(st, ST[blo]);
	ed = min(ed, ED[blo]);
	if(la[blo]) {
		rep(i, ST[blo], ED[blo]+1) {
			if(st <= i && i <= ed) {
				if(a[i] == x) continue;
				--s[blo][a[i]];
				a[i] = x;
				++s[blo][x];
			} else if(la[blo]) {
				if(a[i] == la[blo]) continue;
				--s[blo][a[i]];
				a[i] = la[blo];
				++s[blo][la[blo]];
			}
		}
		la[blo] = 0;
	} else {
		rep(i, st, ed+1) if(a[i] != x) {
			--s[blo][a[i]];
			a[i] = x;
			++s[blo][x];
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> l >> c >> n;
	rep(i, 0, l) a[i] = 1, B[i] = i >> 7, ++sz[B[i]], ED[B[i]] = i;
	for(int i = l - 1; ~i; --i) ST[B[i]] = i;
	rep(i, 0, B[l-1]+1) s[i][1] = sz[i];
	while(n--) {
		int p, x, A, b;
		cin >> p >> x >> A >> b;
		int S = 0;
		rep(i, 0, B[l-1]+1) {
			if(la[i]) {
				if(la[i] == p) S += sz[i];
			} else {
				S += s[i][p];
			}
		}
		int st = (A + 1ll * S * S) % l;
		int ed = (A + 1ll * (S + b) * (S + b)) % l;
		if(st > ed) swap(st, ed);
		rep(i, B[st] + 1, B[ed]) la[i] = x;
		upd(B[st], st, ed, x);
		if(B[st] != B[ed]) upd(B[ed], st, ed, x);
	}
	rep(i, 0, B[l-1]+1) {
		if(la[i]) {
			cnt[la[i]] += sz[i];
		} else {
			rep(j, ST[i], ED[i]+1) cnt[a[j]]++;
		}
	}
	int ans = 1;
	rep(i, 2, c+1) if(cnt[i] > cnt[ans]) ans = i;
	cout << cnt[ans] << endl;
	return 0;
}
