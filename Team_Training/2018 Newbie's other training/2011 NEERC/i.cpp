#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll<<(a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 50;
int a[N], b[N], c[N], n, ans[N];

int print(int m, int *a){
	rep(i, 1, n+1) c[i] = ans[i];
	rep(i, 1, m+1) c[i] = a[i];
	rep(i, 1, n+1) cout << c[i] << " ";
	cout << endl;
	fflush(stdout);
	int res;
	cin >> res;
	if (res == n) exit(0);
	return res;
}

void solve(int m) {
	int cnt = print(m, a);
	rep(i, 1, m) {
		int mm = 0;
		rep(j, 1, m+1) if (j != i) b[++mm] = a[j];
		b[++mm] = a[i];
		int t = print(m, b);
		if (t > cnt) {
			rep(i, 1, m+1) a[i] = b[i];
			solve(m);
		}
	}
	per(i, 2, m+1) {
		int mm = 1;
		rep(j, 1, m+1) if (j != i) b[++mm] = a[j];
		b[1] = a[i];
		int t = print(m, b);
		if (t > cnt) {
			rep(j, 1, m+1) a[j] = b[j];
			solve(m);
		}else if (t < cnt){
			ans[m] = a[i];
			rep(j, i, m) a[j] = a[j+1];
			solve(m - 1);
		}
	}
}

int main() {
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	std::ios::sync_with_stdio(0);
//	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n+1) a[i] = i;
	solve(n);
	return 0;
}
