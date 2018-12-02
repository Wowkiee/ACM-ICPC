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
//------
const int N = 20;
int n, m, c;
int a[N];
char s[N][N];
int main() {
	freopen("addictive.in", "r", stdin);
	freopen("addictive.out", "w", stdout);
	scanf("%d%d%d",&n,&m,&c);
	rep(i, 1, c + 1)cin >> a[i];
	int p = 1;
	rep(i, 0, n) {
		if(i&1)per(j, 0, m) {
			s[i][j] = p + '0';
			a[p]--;
			while(!a[p])p++;
		}
		else rep(j, 0, m) {
			s[i][j] = p + '0';
			a[p]--;
			while(!a[p])p++;
		}
	}
	rep(i, 0, n)printf("%s\n",s[i]);
	return 0;
}
