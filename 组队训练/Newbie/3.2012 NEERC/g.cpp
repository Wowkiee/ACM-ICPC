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
#define pw(a) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 101010;

ll n;
int k, p;
int dig[N];

int main() {
	freopen("great.in", "r", stdin);
	freopen("great.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> k;
	while(n) {
		dig[p++] = n % (k * k);
		n /= (k * k);
	}
	reverse(dig, dig + p);
	rep(i, 0, p) if(dig[i] >= k) {
		rep(j, i, p) dig[j] = k - 1;
		break;
	}
	ll ans = 0;
	rep(i, 0, p) ans = ans * k + dig[i];
	cout << ans + 1 << endl;
	return 0;
}
