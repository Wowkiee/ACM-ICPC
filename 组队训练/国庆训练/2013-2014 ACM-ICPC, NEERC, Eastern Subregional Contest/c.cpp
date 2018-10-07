#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double db;

const int N = 1e6 + 7;
int h1[N], h2[N], ne1[N], ne2[N], root1[N], root2[N], n, m, now1, now2, x, c, k;
string s;

void add1(int c, int x) {
	now1++;
	ne1[now1] = root1[c];
	h1[now1] = x;
	root1[c] = now1;
}

void add2(int c, int x) {
	now2++;
	ne2[now2] = root2[c];
	h2[now2] = x;
	root2[c] = now2;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m;
	root1[1] = 0;
	root2[1] = 0;
	k = 1;
	rep(i, 1, n+1) {
		cin >> s >> c;
		if (s[0] == 'l') {
			cin >> x;
			add1(c, x);
			root2[c] = 0;
		}else if (s == "rollback") {
			add2(c, h1[root1[c]]);
			root1[c] = ne1[root1[c]];
		}else if (s == "relearn") {
			add1(c, h2[root2[c]]);
			root2[c] = ne2[root2[c]];
		}else if (s == "clone"){
			root1[++k] = root1[c];
			root2[k] = root2[c];
		}else {
			if (h1[root1[c]] == 0) cout << "basic" << endl;
			else cout << h1[root1[c]] << endl;
		}
	} 
	return 0;
}
