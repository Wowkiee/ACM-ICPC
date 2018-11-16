#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 101010, inf = 1e9;

int n, l1, r1, a[N];
ll ans, f[N];
struct P{
	ll x, y;
	P(){}
	P(ll x, ll y){
		this->x = x;
		this->y = y;
	}
	P operator - (const P & c) {
		return P (x - c.x, y - c.y);
	}
} p[N];

ll cross(P a, P b){
	__int128 x = a.x, y = a.y;
	__int128 xx = b.x, yy = b.y;
	__int128 res = x * yy - y * xx;
	if (res > 0) return 1;
	else return -1;

	//return a.x * b.y - a.y * b.x;
}

struct node {
	ll f, a, i;
	//int a, i;
	node(ll f = 0, ll a = 0, ll i = 0) : f(f), a(a), i(i){}
} v[N];

bool cmp(const node &a, const node &b) {
	if (a.a == b.a) return a.i < b.i;
	return a.a < b.a;
}

bool cmp2(const node &a,const node &b) {
	return a.i < b.i;
}

void solve(int l, int mid, int r){
	l1 = 0;r1 = -1;
	rep(i, mid+1, r+1) {
		while (l <= mid && v[l].i < v[i].i) {
			P tmp = P(v[l].i, v[l].f - (v[l].i * v[l].i + v[l].i) / 2);
			while (r1 - l1 + 1 >= 2 && cross(p[r1] - p[r1-1], tmp - p[r1]) > 0) r1--;
			p[++r1] = tmp;
			l++;
		}
		while (l1 < r1 && p[l1+1].y - p[l1].y > -v[i].i * (p[l1+1].x - p[l1].x)) l1++;
		if (l1 <= r1) {
			v[i].f = max(v[i].f, v[i].a -(v[i].i * v[i].i - v[i].i)/2 + v[i].i * p[l1].x + p[l1].y);	
		}
	}
}


void CDQ(int l, int r) {
	if (l == r) {
		v[l].f = max(v[l].f, v[l].a - v[l].i * (v[l].i-1) / 2);
		return;
	}
	int mid = l + r >> 1;
	CDQ(l, mid);
	sort(v + mid + 1, v + r + 1, cmp2);
	solve(l, mid, r);
	sort(v + mid + 1, v + r + 1, cmp);
	CDQ(mid+1, r);
	sort(v + l, v + r + 1, cmp2);
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	srand(time(0));
	rep(i, 1, n+1) cin >> a[i];
	//rep(tim, 0, 1000) {
	//rep(i, 1, n+1) a[i] = rand() % 10 - rand() % 10;

	rep(i, 1, n+1) {
		v[i] = node(-pw(60), a[i], i);
	}
	sort(v+1, v+n+1, cmp);
	CDQ(1, n);
	ans = -(1ll * n * (n + 1)) / 2;

	/*ll ans2 = ans;
	rep(i, 1, n+1) {
		f[i] = -i * (i - 1) / 2 + a[i];
		rep(j, 1, i) if (a[i] >= a[j]) {
			f[i] = max(f[i], f[j] + a[i] - (i - j) * (i - j - 1)/ 2);
		}	
	}
	rep(i, 1, n+1) ans2 = max(ans2, f[i] - (n - i) * (n - i + 1) / 2);
 */
	rep(i, 1, n+1) ans = max(ans, v[i].f - (n - v[i].i) * (n - v[i].i + 1) / 2);
	cout << ans << endl;
	//cout << ans2 << endl;
	/*if (ans != ans2) {
		rep(i, 1, n+1) cout << a[i] << " ";
		//cout << ans << endl;
		cout << endl;
		de(ans);
		de(ans2);
		return 0;
	}	 
	}*/
	return 0;
}
