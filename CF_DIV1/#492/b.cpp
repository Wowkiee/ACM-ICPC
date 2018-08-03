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

const int N = 222;

int n;
int a[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	n <<= 1;
	rep(i, 1, n+1) cin >> a[i];
	int ans = 0;
	rep(i, 1, n+1) if(a[i]) {
		rep(j, i+1, n+1) if(a[j]) {
			if(a[i] == a[j]) {
				a[j] = 0;
				break;
			}
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
