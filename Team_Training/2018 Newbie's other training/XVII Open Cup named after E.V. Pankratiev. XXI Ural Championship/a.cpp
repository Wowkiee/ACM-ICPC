#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(x) cout << #x << " = " << x << endl 
#define dd(x) cout << #x << " = " << x << " "
#define endl "\n"
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;
//----
const int N = 105;
int id[N], fa[N];
int findf(int x) {
	return x == fa[x] ? x : (fa[x] = findf(fa[x]));
}
void noans() {
	cout << "No" << endl;
	exit(0);
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n, m; cin >> n >> m;
	rep(i, 1, n + 1)fa[i] = i;
	rep(i, 0, m) {
		int a, b; cin >> a >> b;
		id[a]++, id[b]++;
		int aa = findf(a), bb = findf(b);
		if(aa != bb)fa[aa] = bb;
	}
	rep(i, 2, n + 1)if(findf(i) != findf(1))noans();
	int id1 = 0, id3 = 0;
	rep(i, 1, n + 1) {
		switch(id[i]) {
			case 1 : {
				if(id1)noans();
				else id1 = i;
				break;
			}
			case 2 : {
				break;
			}
			case 3 : {
				if(id3)noans();
				else id3 = i;
				break;
			}
			default : {
				noans();
				break;
			}
		}
	}
	if(id1 && id3)cout << "Yes" << endl;
	else noans();
	return 0;
}
