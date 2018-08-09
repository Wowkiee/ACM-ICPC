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

const int N = 200002;

int n, m, k;
int pre[N];
string s, t;
bitset<N> good[4];
char ch[] = "ACGT";

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	n = 2e5, m = 1e5, k = 22;
	rep(i, 0, n) s += 'A';
	rep(i, 0, m) t += 'A';
//	cin >> n >> m >> k >> s >> t;
	rep(i, 0, 4) {
		memset(pre, 0, sizeof(pre));
		rep(j, 0, n) if(s[j] == ch[i]) {
			int l = max(0, j-k), r = min(n-1, j+k);
			++pre[l], --pre[r+1];
		}
		rep(j, 1, n) pre[j] += pre[j-1];
		rep(j, 0, n) if(pre[j]) good[i][j] = 1;
	}
	bitset<N> res;
	res.set();
	rep(i, 0, m) {
		if(t[i] == 'A') res &= (good[0] >> i);
		if(t[i] == 'C') res &= (good[1] >> i);
		if(t[i] == 'G') res &= (good[2] >> i);
		if(t[i] == 'T') res &= (good[3] >> i);
	}
	cout << res.count() << endl;
	return 0;
}
