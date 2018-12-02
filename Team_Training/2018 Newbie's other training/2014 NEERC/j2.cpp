#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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
typedef pair<int, int> pii;
typedef vector<int> vi;

int n = 50;
int a[55];

int main() {
	//freopen(".in", "r", stdin);
	freopen("j.in", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	srand(time(0));
	rep(i, 1, n + 1) a[i] = i;
	random_shuffle(a + 1, a + 1 + n);
	rep(i, 1, n + 1) cout << a[i];
	return 0;
}
