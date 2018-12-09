#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define endl "\n"
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
typedef long long ll;
typedef pair<int, int> pii;
typedef double db;
typedef vector<int> vi;
string s[5] = {"Typically Otaku", "Eye-opener", "Young Traveller", "Excellent Traveller", "Contemporary Xu Xiake"};
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T; cin >> T; while(T--) {
		int c = 0;
		rep(i, 0, 4) {
			int a; cin >> a;
			c += !!a;
		}
		cout << s[c] << endl;
	}
	return 0;
}
