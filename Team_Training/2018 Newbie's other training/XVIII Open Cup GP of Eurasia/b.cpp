#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(a) cout << #a << " = " << a << " "
#define de(a) cout << #a << " = " << a << endl
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 101010;

int n, ma;
string s[N];

bool solve() {
	rep(i, 1, n + 1) {
		rep(j, 0, sz(s[i])) if(s[i][j] != s[ma][j]) return 0;
	}
	return 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> n;
		ma = 1;
		rep(i, 1, n + 1) {
			cin >> s[i];
			if(sz(s[ma]) < sz(s[i])) ma = i;
		}
		if(solve()) {
			cout << sz(s[ma]) << endl;
		} else {
			cout << "Impossible" << endl;
		}
	}
	return 0;
}
