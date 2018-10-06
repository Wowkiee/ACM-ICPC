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
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 50505, P = 1e9 + 7;

int n, a[2];
int f[N][2];

int add(int a, int b) {
	if((a += b) >= P) a -= P;
	return a;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> a[0] >> a[1];
	f[0][0] = f[0][1] = 1;
	rep(i, 1, n + 1) rep(o, 0, 2) {
		for(int j = i - 1; i - j <= a[o] && j >= 0; --j) {
			f[i][o] = add(f[i][o], f[j][o ^ 1]);
		}
	}
	cout << add(f[n][0], f[n][1]) << endl;
	return 0;
}
