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

int n, m;
int c[1<<18];
ll sum;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 0, 1<<n) cin >> c[i], sum += c[i];
	cout << setiosflags(ios::fixed);
	cout << setprecision(6);
	cout << sum * 1. / (1 << n) << endl;
	while(m--) {
		int x, y;
		cin >> x >> y;
		sum -= c[x];
		sum += y;
		c[x] = y;
		cout << sum * 1. / (1 << n) << endl;
	}
	return 0;
}
