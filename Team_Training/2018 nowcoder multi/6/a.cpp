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

const int N = (1 << 15);

int n;
int a[N];
set<int> v[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	rep(ca, 1, T+1) {
		///
		cin >> n;
		///init
		rep(i, 0, 1<<n) v[i].clear();
		///read
		rep(i, 0, 1<<n) {
			int x;
			rep(j, 0, n) {
				cin >> x;
				v[i].insert(x);
			}
		}
		///solve
		rep(i, 0, 1<<n) a[i] = i;
		for(int m = (1<<n); m>1; m >>= 1) {
			for(int i = 1; i < m; i+=2) {
				auto x = v[a[i-1]].end(); --x;
				auto y = v[a[i]].end(); --y;
				if(*x > *y) {
					v[a[i-1]].erase(v[a[i-1]].lower_bound(*y));
					a[i>>1] = a[i-1];
				} else {
					v[a[i]].erase(v[a[i]].lower_bound(*x));
					a[i>>1] = a[i];
				}
			}
		}
		cout << "Case #" << ca << ": " << a[0]+1 << endl;
	}
	return 0;
}
