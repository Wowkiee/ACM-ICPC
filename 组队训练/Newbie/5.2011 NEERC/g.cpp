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

const int N = 1e5 + 7;
int ans, n, l, r, m, p[N];
bool f[N];

int main() {
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	rep(i, 2, n+1) {
		if (!f[i]) p[++m] = i;
		for (int j = i + i; j <= n; j += i) f[j] = 1;
	}
	l = 1; r = m;
	while (r >= l) {
		if (l == r) {ans++; break;}
		if (p[r] * p[l] <= n) ans++, l++, r--;
		else ans++, r--;
	}
	cout << ans;
	return 0;
}
