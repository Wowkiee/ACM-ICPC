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

int tmp, s, x, y, n, b[100], cnt, t, ans2;
vi ans, w;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n+1) {
		cin >> x; y = x;
		//de(y);
		for (int j = 19;j >= 0;j--) {
			//de(y);
			if (y == 0) {ans.pb(x);break;}
			else {
				if ((1 << j) & y) {
					if (b[j] == 0) {b[j] = y, w.pb(x);break;}
					else y ^= b[j];
				}	
			}
			if (y == 0) {ans.pb(x);break;}
		}
	}
	//de(sz(w));
	//de(sz(ans));
	rep(i, 0, sz(ans)) {
		tmp ^= ans[i];
	}
	s = sz(w);
	rep(i, 0, 1 << s){
		cnt = 0, t = 0;
		rep(j, 0 , s) {
			if ((1 << j) & i) {
				cnt++;
				t ^= w[j];
			}
		}
		if (t == tmp) {
			ans2 = max(ans2, cnt);	
		}
	}
	cout <<  ans2 + sz(ans);
	return 0;
}
