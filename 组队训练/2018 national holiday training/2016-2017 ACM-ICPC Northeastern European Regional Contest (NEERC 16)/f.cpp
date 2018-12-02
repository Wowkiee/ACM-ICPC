#include<bits/stdc++.h>
using namespace std;
#define fi firse
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(x) (int)x.size()
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

double sum, ans;
ll sc, sw;
string s;

int main() {
	//std::ios::sync_with_stdio(0);
	//std::cin.tie(0);
	freopen("foreign.in", "r", stdin);
	freopen("foreign.out", "w", stdout);
	cin >> s;
	reverse(all(s));
	rep(i, 1, sz(s)+1) {
		if (s[i-1] == 'C') {
			sc += i;
			ans = (sum + sw) / i;
			sum += ans;
		}
		else {
			sw += i; 
			ans = (sum + sc) / i;
			sum += ans;
		}
	}
	printf("%.10f", ans);
	return 0;
}
