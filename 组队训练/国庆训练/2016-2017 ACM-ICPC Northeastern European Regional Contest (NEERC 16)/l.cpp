#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(x) (int)x.size()
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 111;

bool vis[MAXN];
vi p;

void init() {
	rep(i, 2, MAXN) if(!vis[i]) {
		p.pb(i);
		for(int j = i + i; j < MAXN; j += i) vis[j] = 1;
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	init();
	return 0;
}
