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

int tab[63][63];

void add(ll x) {
	int pos = 0, cnt = 0;
	while(x) {
		++pos;
		cnt += (x & 1);
		x >>= 1;
	}
	++tab[pos][cnt];
}

int main() {
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	rep(i, 1, 1e9 + 1) add(i * 1ll * i);
	rep(i, 0, 63) {
		cout << "{";
		rep(j, 0, 63) cout << tab[i][j] << ",}"[j == 62] << " ";
		cout << "," << endl;
	}
	return 0;
}
