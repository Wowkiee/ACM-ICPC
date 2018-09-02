#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define per(i,l,r) for(int i=(r)-1;i>=(l);i--)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----
const int N = 1e5 + 7;
int n, a[N];
bool ck0() {
	int mor = 0;
	rep(i, 0, n) mor += a[i] > 1;
	if (mor > 1) return false;
	if (mor == 0) return (n - 1) % 3 == 0;
	return n % 3 == 0 || (n - 1) % 3 == 0;
}
bool ck1() {
	int mor = 0;
	rep(i, 0, n) mor += a[i] > 1;
	if (mor > 1) return false;
	if (mor == 0) return (n - 1) % 3 == 1;
	return n % 3 == 1 || (n - 1) % 3 == 1;
}
bool ck2() {
	int one = 0, two = -1;
	rep(i, 0, n) one += a[i] == 1;
	rep(i, 0, n) if (a[i] == 2) { two = i; break; }
	if (one % 3 == 0) {
		return one == n - 1 && ~two;
	}
	else if (one % 3 == 1) {
		if (n - one != 2) return false;
		return ~two;
	}
	else {
		if (~two) return n - one == 2;
		return n - one == 1;
	}
}
int main() {
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	cin >> n;
	rep(i, 0, n) cin >> a[i];
	if (ck0() || ck1() || ck2()) {
		cout << "Win";
	}
	else {
		cout << "Lose";
	}

	return 0;
}
