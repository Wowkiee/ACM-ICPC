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

int n, m, k;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> n >> m >> k;
		int ans = n * m + (n % 2 && m % 2);
		rep(i, 0, k) {
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			if(a == c && b == d) continue;
			if(n % 2 == 0 || m % 2 == 0) continue;
			int x = a+b, y = c+d;
			if(x%2==0 && y%2==0) ans = n * m;
		}
		cout << ans << endl;
	}
	return 0;
}