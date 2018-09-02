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
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---

const int N = 600006, M = 2;

int n, m, L;
int a[N], pre[N], rt[N], ne[N * 30][M], cnt[N * 30];

void add(int x, int p) {
	++cnt[p];
	rep(i, 0, 31) {
		int c = (x >> i & 1);
		p = ne[p][c] = ++L;
		++cnt[p];
	}
}

int merge(int p, int q) {
	if(p && q) {
		cnt[p] += cnt[q];
		rep(i, 0, 2) ne[p][i] = merge(ne[p][i], ne[q][i]);
		return p;
	} else {
		return p + q;
	}
}

void dfs(int p) {
	while(p) {
		swap(ne[p][0], ne[p][1]);
		p = ne[p][0];
	}
}

int solve(int p, int k, int x) {
	rep(i, 0, k) {
		int c = (x & 1);
		x >>= 1;
		p = ne[p][c];
	}
	return cnt[p];
}

int find(int x) {
	if(x == pre[x]) return x;
	return pre[x] = find(pre[x]);
}
void join(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return ;
	pre[x] = y;
	rt[y] = merge(rt[x], rt[y]);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	///
	cin >> n >> m;
	///init
	rep(i, 1, n+1) pre[i] = i, rt[i] = ++L;
	///read
	rep(i, 1, n+1) cin >> a[i], add(a[i], rt[i]);
	///solve
	while(m--) {
		int t, u;
		cin >> t >> u;
		if(t == 1) {
			int v;
			cin >> v;
			join(u, v);
		} else if(t == 2) {
			u = find(u);
			dfs(rt[u]);
		} else {
			int k, x;
			cin >> k >> x;
			u = find(u);
			cout << solve(rt[u], k, x) << endl;
		}
	}
	return 0;
}
