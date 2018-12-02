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
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll L, R, Q;
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	while(cin >> L >> R >> Q) {	
		int ans = 0;
		for(ll i = 1; i * i <= Q; i++)if(Q % i == 0) {
			ans++;
			if(i * i != Q)ans++;
		}
		if(Q > R)cout << "infinity" << endl;
		else {
			L = L - L % Q;
			if(R - L + 1 <= Q) {
				ans = 0;
				for(ll i = 1; i * i <= L; i++)if(L % i == 0) {
					ll A1 = i, A2 = L / i;
					if(A1)ans++;
					if(A2 != A1)ans++;
				}
				cout << ans << endl;
			}
			else cout << ans << endl;
		}
	}
	return 0;
}
