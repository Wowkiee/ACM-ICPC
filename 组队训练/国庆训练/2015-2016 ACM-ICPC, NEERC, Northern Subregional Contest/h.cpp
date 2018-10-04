#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(x) (int)x.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll<<(a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
string os[2]={"ed","fE"};
int dig(int a) {
	if(a==0)return 1;
	int ans=0;
	while(a)a>>=1,ans++;
	return ans;
}
int main() {
	freopen("hash.in","r",stdin);
	freopen("hash.out","w",stdout);
	int n;while(scanf("%d",&n)!=EOF) {	
		int d=dig(n-1);
		rep(i,0,n) {
			per(j,0,d)cout<<os[(i>>j)&1];
			cout<<endl;
		}
	}
	return 0;
}
