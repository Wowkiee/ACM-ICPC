#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(c) cout << #c << " = " << c << endl
#define dd(c) cout << #c << " = " << c << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
//----
const int N=200005;
int data[N];
int main() {
	int n,m;scanf("%d%d",&n,&m);
	rep(i,1,n+1)scanf("%d",&data[i]);
	ll ans=0;
	rep(i,1,n+1) {
		if(data[i-1]) {
			if(data[i-1]+data[i]<=m) {
				data[i-1]=data[i]=0;ans++;
			}
			data[i]+=data[i-1];
		}
		ans+=data[i]/m,data[i]%=m;
	}
	if(data[n])ans++;
	cout<<ans<<endl;
	return 0;
}
