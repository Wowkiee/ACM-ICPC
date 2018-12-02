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

string s;

int main() {
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> s;
	for(int i = 0; i < sz(s); ) {
		if(s[i] == '-') {
			cout << s[i] << s[i + 1];
			int j = i + 2;
			while(j < sz(s) && '0' <= s[j] && s[j] <= '9') ++j;
			rep(k, i + 2, j) {
				cout << '+';
				if(s[k] == '0') {
					cout << 0;
				} else {
					rep(c, k, j) cout << s[c];
					break;
				}
			}
			i = j;
		} else {
			cout << s[i];
			++i;
		}
	}
	return 0;
}
