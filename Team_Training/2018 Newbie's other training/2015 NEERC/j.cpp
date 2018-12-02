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
#define pw(a) (1ll<<(a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 7;
int a[N], b[N], n, x, cnt, c[N];

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//std::ios::sync_with_stdio(0);
	//std::cin.tie(0);
	/*int n = 1000;
	db p = pow(2, n);
	rep(i, 1, n / 2+1) {
		p *= n - i + 1;
		p /= i;
	}
	cout << p << endl;*/
	cin >> n;
	srand(time(0));
	while (1) {
		rep(i, 1, n+1) b[i] = rand() % 2, cout << b[i];
		cout << endl;
		fflush(stdout);
		rep(i, 1, n+1) if (a[i] == b[i]) x++;
		cin >> x;
		if (x == n) return 0;
		if (x == n / 2) break;
	}
	rep(i, 1, n) {
		rep(j, 1, n+1) c[j] = b[j];
		c[i] ^= 1;
		c[i+1] ^= 1;
		rep(j, 1, n+1) cout << c[j];
		cout << endl;
		fflush(stdout);
		cin >> x;
		if (x == n) return 0;
		if (x == n / 2) a[i+1] = b[i] ^ b[i+1] ^ 1;
		else a[i+1] = b[i] ^ b[i+1];
	}
	a[1] = 0;
	rep(i, 2, n+1) a[i] ^= a[i-1];
	rep(i, 1, n+1) cout << a[i];
	cout << endl;
	fflush(stdout);
	cin >> x;
	if (x == n) return 0;
	rep(i, 1, n+1) cout << (a[i] ^ 1);
	cout << endl;
	fflush(stdout);
	cin >> x;
	assert(x == n);
	return 0;
}
