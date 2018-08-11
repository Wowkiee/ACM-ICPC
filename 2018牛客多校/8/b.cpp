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

const int N = 101010;

int a[N], pre[N], mi[N], ma[N], ans[N], res[N];

int find(int x) {
	if(x == pre[x]) return x;
	return pre[x] = find(pre[x]);
}
void join(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return ;
	mi[y] = min(mi[x], mi[y]);
	ma[y] = max(ma[x], ma[y]);
	pre[x] = y;
}

void solve(int n) {
	rep(i, 1, n+1) a[i] = i;
	int cnt = 0;
	do {
		rep(i, 1, n+1) pre[i] = i, mi[i] = ma[i] = a[i];
		vi q;
		rep(i, 2, n+1) q.pb(i);
		int f = 0;
		rep(t, 0, sz(q)) {
			int i = q[t];
			int x = find(i), y = find(i-1);
			if(abs(ma[x] - mi[y]) == 1 || abs(ma[y] - mi[x]) == 1) join(i, i-1), f = 0;
			else q.pb(i), ++f;
			if(f == n) break;
		}
		int t = find(1);
		if(mi[t] != 1 || ma[t] != n) {
	//		rep(i, 1, n+1) cout << a[i] << " ";
	//		cout << endl;
		} else ++cnt;
	} while(next_permutation(a+1, a+1+n));
	ans[n] = cnt;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	rep(i, 1, 11) {
		solve(i);
		res[i] = 1;
		rep(j, 1, i+1) res[i] *= j;
	}
	rep(i, 1, 11) {
		dd(i);
		dd(ans[i]);
		de(ans[i-1]);
	}
	return 0;
}
