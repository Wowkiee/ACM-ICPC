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
#define endl "\n"
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;

unordered_map<int, int> cnt;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	rep(i, 0, 6000) rep(j, 0, 6000) cnt[i * i + j * j]++;
	int ma = 0;
	for(auto u : cnt) ma = max(ma, u.se);
	de(ma);
	return 0;
}
