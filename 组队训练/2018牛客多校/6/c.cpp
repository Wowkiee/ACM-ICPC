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

const int N=1005;
int n,m,f[N][N],ans;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin>>n>>m;
	f[0][0]=1;
	rep(i,1,n+1) 
		rep(j,1,min(i,m)+1) {
			f[i][j]+=f[i-1][j];
			f[i][j]+=f[i-1][j-1]*(m-(j-1));
		}
	rep(i,1,n+1) ans+=f[n][i];
	cout<<ans;
	return 0;
}
