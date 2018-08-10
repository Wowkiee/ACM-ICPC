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

bool reach;
int n, m, t, cnt, l, r;
int a[N], ans[N], que[N];

int main() {
	scanf("%d%d%d", &n, &m, &t);
	rep(i, 1, n+1) {
		int x, y, z;
		scanf("%d:%d:%d", &x, &y, &z);
		a[i] = x * 3600 + y * 60 + z;
	}
	l = 1, r = 0;
	rep(i, 1, n+1) {
		while(l <= r && a[que[l]] < a[i] - t + 1) ++l;
		if(r - l + 1 < m) {
			ans[i] = ++cnt;
			que[++r] = i;
		} else {
			ans[i] = cnt;
			que[r] = i;
		}
		if(r - l + 1 >= m) reach = 1;
	}
	if(reach) {
		printf("%d\n", cnt);
		rep(i, 1, n+1) printf("%d\n", ans[i]);
	} else {
		puts("No solution");
	}
	return 0;
}
