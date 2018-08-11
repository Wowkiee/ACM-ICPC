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

const int N= 100;
int n,k;
int f[N][N][2], ans[N],s[N][N][2];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> k;
	f[1][0][1]=s[1][0][1]=1;
	f[0][1][0]=s[0][1][0]=1;
	rep(x,1,10)
		rep(y,1,10) {
			f[x][y][1] = s[x-1][y][0];
			f[x][y][0] = s[x-1][y][1];
			s[x][y][1] = s[x-1][y][1]+f[x][y][1];
			s[x][y][0] = s[x][y-1][0]+f[x][y][0];
		}
	//ans[n]+=ans[n-1];
	//cout << ans[n]<< endl;
//	ans[1]=0;
	cout<< f[2][3][0];
	return 0;
}
