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

int main() {
	//freopen("input.txt", "r", stdin);
	freopen("dgen.in", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cout << "3000 50 30000 10000" << endl;
	rep(i, 0, 3000)cout << "1000" << " \n"[i == 2999];
	rep(i, 0, 30000)cout << i / 50 + 1 << " " << i % 50 + 1 << " " << rand() % 10000 + 1 << endl;
	rep(i, 0, 10000)rep(j, 0, 50)cout << "0.0001" << " \n"[j == 49];
	return 0;
}
