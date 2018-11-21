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
const int N = 150;
int a[N], b[N];
int n;
int main() {
	freopen("chickens.in", "r", stdin);
	freopen("chickens.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(i, 0, n)cin >> a[i];
	rep(i, 0, n) {
		int s;
		cin >> s;
		b[s]++;
	}
	ll ans = 1, cnt = 0;
	int p = 100;
	sort(a, a + n);
	per(i, 0, n) {
		while(p >= a[i])cnt += b[p--];
		ans *= cnt--;
	}
	cout << ans << endl;
	return 0;
}
