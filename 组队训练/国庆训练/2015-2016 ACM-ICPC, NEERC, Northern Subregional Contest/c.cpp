#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(x) (int)x.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll<<(a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll ans;
int cnt[300];
string s1, s2;
int main() {
	freopen("concatenation.in","r",stdin);
	freopen("concatenation.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> s1 >> s2;
	rep(i, 0, sz(s2) - 1) cnt[s2[i]]++;
	rep(i, 1, sz(s1)) ans -= cnt[s1[i]];
	ans += 1ll * sz(s1) * sz(s2);
	cout << ans;
	return 0;
}
