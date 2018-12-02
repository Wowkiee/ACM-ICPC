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
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double db;
//----
const int N = 505;
int a[N], tmp[N];
int cmp(int a, int b) {
	printf("? %d %d\n", a, b);
	fflush(stdout);
	int x; scanf("%d", &x); return x;
}
void Mysort(int l, int r) {
	if(l == r)return;
	int mid = (l + r) >> 1;
	Mysort(l, mid);
	Mysort(mid + 1, r);
	int p = l, p1 = l, p2 = mid + 1;
	while(p1 <= mid && p2 <= r) {
		if(cmp(a[p1], a[p2]))tmp[p++] = a[p1++];
		else tmp[p++] = a[p2++];
	}
	while(p1 <= mid)tmp[p++] = a[p1++];
	while(p2 <= r)tmp[p++] = a[p2++];
	assert(p == r + 1);
	per(i, l, r)if(cmp(tmp[r], tmp[i])) {
		assert(i != r - 1);
		puts("! NO");
		printf("3 %d %d %d\n", tmp[i], tmp[i + 1], tmp[r]);
		exit(0);
	}
	rep(i, l, r + 1)a[i] = tmp[i];
}
int main() {
	int n; scanf("%d",&n);
	rep(i, 1, n + 1)a[i] = i;
	Mysort(1, n);
	puts("! YES");
	rep(i, 1, n + 1)printf("%d%c", a[i], " \n"[i == n]);
	return 0;
}
