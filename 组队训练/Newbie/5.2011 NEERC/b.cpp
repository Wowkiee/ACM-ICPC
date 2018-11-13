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
int m, n = 0;
void print(int x, int y) {
	vi v;
	rep(i, 0, n) {
		v.pb(x & 1);
		x >>= 1;
	}
	reverse(all(v));
	rep(i, 0, sz(v))cout << v[i];
	if(y == -1)cout << endl;
	else cout << y << endl;
}
int main() {
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> m;
	while(m > (1 << n))n++; n--;
	int ex = (m - (1 << n)) << 1;
	rep(i, 0, m - ex) {
		print(i,-1);
	}
	rep(i, m - ex, m) {
		print((i - (m - ex)) / 2 + (m - ex), (i - (m - ex)) % 2);
	}
	return 0;
}
