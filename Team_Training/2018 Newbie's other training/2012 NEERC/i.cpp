#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
//----
const int N = 1e5 + 7;
const ll P = 9705276, Q = 12805858;
int n;
db a[N];
int M[405][405];
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	ll Max = 0;
	rep(i, 0, n) {
		cin >> a[i]; a[i] *= 100000;
		Max = max((ll)a[i], Max);
	}
	int len = 0, x = 0, y = 0;
	for(int i = 0,i <= 400; i++)if((Max - i * P) % Q == 0) {
		len = i + (Max - i * P) / Q;
		x = i; y = len - i;
	}
	rep(i, 0, n) {
		rep(j, 0, x + 1)if((ll)a[i] >= j * P  && ((ll)a[i] - j * P) % Q == 0) {
			int k = ((ll)a[i] - j * P) / Q;
			if(k <= y) 
	return 0;
}
