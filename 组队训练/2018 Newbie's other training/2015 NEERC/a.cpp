#include<bits/stdc++.h>
using namespace std;
#define fi fitst
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll<<(a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e6 + 7;
ll n, q, sum1, sum2, cnt1, cnt2, p;
bool vis[N], vis2[N];
string s;
int main() {
	freopen("adjustment.in", "r", stdin);
	freopen("adjustment.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> q;
	rep(cas, 0, q) {
		cin >> s >> p;
		if (s[0] == 'R') {
			if (vis[p] == 1) cout << 0 << endl;
			else {
				vis[p] = 1;
				sum1 += p;
				cnt1 ++;
				cout << n * (n + 1) / 2 - sum2 + (n - cnt2) * p << endl;
			}
		}
		else {
			if (vis2[p] == 1) cout << 0 << endl;
			else {
				vis2[p] = 1;
				sum2 += p;
				cnt2 ++;
				cout << n * (n + 1) / 2 - sum1 + (n - cnt1) * p << endl;
			}
		}
	}
	return 0;
}
