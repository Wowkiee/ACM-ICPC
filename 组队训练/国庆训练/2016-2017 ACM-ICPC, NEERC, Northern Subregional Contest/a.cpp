#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(x) cout << #x << " = " << x << " "
#define de(x) cout << #x << " = " << x << endl
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, m, a1, b1, a2, b2;

int main() {
	freopen("anniversary.in","r",stdin);
	freopen("anniversary.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m >> a1 >> b1 >> a2 >> b2;
	if (b1 != b2) cout << 0 << " " << b1 << " " << n << " " << b2;
	else cout << a1 << " " << 0 << " " << a2 << " " << m;
	return 0;
}
