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
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double db;

const int N = 505050;

int ta[] = {1, -1, 0, 2};
int tb[] = {0, 1, -2, 2};
int a[N], b[N], ans[N];
string s, t;

void add(const string &s) {
	rep(i, 0, sz(s)) if(s[i] == '1') {
		a[i / 4] += ta[i % 4];
		b[i / 4] += tb[i % 4];
	}
}

int main() {
	freopen("base-i-1.in", "r", stdin);
	freopen("base-i-1.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> s >> t;
	reverse(all(s));
	reverse(all(t));
	add(s);
	add(t);
	rep(i, 0, N) {
		rep(sta, 0, 16) {
			int x = 0, y = 0;
			rep(j, 0, 4) if(sta >> j & 1) {
				x += ta[j];
				y += tb[j];
			}
			if((a[i] - x) % 4 == 0 && (b[i] - y) % 4 == 0) {
				ans[i] = sta;
				a[i + 1] += (a[i] - x) / (-4);
				b[i + 1] += (b[i] - y) / (-4);
				break;
			}
		}
	}
	int p = 0;
	for(int i = N - 1; ~i; --i) {
		if(i == 0 || ans[i]) {
			p = i;
			break;
		}
	}
	vi v;
	int x = ans[p];
	while(x) {
		v.pb(x & 1);
		x >>= 1;
	}
	if(!sz(v)) v.pb(0);
	reverse(all(v));
	rep(i, 0, sz(v)) cout << v[i];
	for(int i = p - 1; ~i; --i) for(int j = 3; ~j; --j) cout << (ans[i] >> j & 1);
	cout << endl;
	return 0;
}
