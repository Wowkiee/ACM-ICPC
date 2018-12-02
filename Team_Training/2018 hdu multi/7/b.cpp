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

const int N = 10101, inf = 1e9;

int m, x, y, z, na, nb, nc;
int a[3][N], pre[3][N], ne[3][N];

void gao(int l) {
	int mi[] = {l, l, l};
	int ma[] = {-1, -1, -1};
	for(int i = 0; i < N; i += l) {
		int j = i + l - 1;
		if(j >= N) j = N;
		if(i > j) continue;
		rep(t, 0, 3) {
			if(ne[t][i] <= j) mi[t] = min(mi[t], ne[t][i] - i);
			if(pre[t][j] >= i) ma[t] = max(ma[t], pre[t][j] - i);
		}
	}
	rep(i, 0, 3) {
		if(mi[i] == l) {
			if(i) {
				mi[i] = ma[i] = ma[i-1] + 1;
			} else {
				mi[i] = ma[i] = 0;
			}
		}
	}
	if(ma[0] >= mi[1]) return ;
	if(ma[0] >= mi[2]) return ;
	if(ma[1] >= mi[2]) return ;
	if(ma[2] >= l) return ;
	na = ma[0] + 1;
	nb = ma[1] + 1;
	nc = l;
	nc -= nb, nb -= na;
	if(na < x) {
		x = na, y = nb, z = nc;
	} else if(na == x) {
		if(nb < y) {
			y = nb, z = nc;
		} else if(nb == y) {
			if(nc < z) {
				z = nc;
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		///init
		memset(a, 0, sizeof(a));
		memset(pre, -1, sizeof(pre));
		memset(ne, -1, sizeof(ne));
		///read
		cin >> m;
		rep(i, 1, m+1) {
			int x; string s;
			cin >> x >> s;
			++a[s[0] - 'A'][x-1];
		}
		///get pre ne
		rep(t, 0, 3) {
			int p = -inf;
			rep(i, 0, N) {
				if(a[t][i]) p = i;
				pre[t][i] = p;
			}
			p = inf;
			for(int i = N-1; ~i; --i) {
				if(a[t][i]) p = i;
				ne[t][i] = p;
			}
		}
		///solve
		x = y = z = N;
		rep(l, 3, N) {
			na = nb = nc = N;
			gao(l);
		}
		///print
		if(x == N) {
			cout << "NO" << endl;
		} else {
			cout << x << " " << y << " " << z << endl;
		}
	}
	return 0;
}
