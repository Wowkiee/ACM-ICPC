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
#define pw(a) (1ll << (a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	string s; cin >> s;
	int n = sz(s);
	int p1 = 0, p2 = n - 1;
	int ans = 0;
	while(p1 < n && s[p1] == 'L')p1++, ans++;
	while(p2 >= 0 && s[p2] == 'R')p2--, ans++;
	if(p2 > p1)ans++;
	cout << ans << endl;
	return 0;
}
