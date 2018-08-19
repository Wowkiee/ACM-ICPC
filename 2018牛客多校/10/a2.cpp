#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

const int N = 101010;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	string s, t;
	rep(i, 1, N) s = 'a' + s;
	t = s;
	rep(i, 1, N) s + t;
	return 0;
}
