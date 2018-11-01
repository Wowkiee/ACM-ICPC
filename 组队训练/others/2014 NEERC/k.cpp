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
#define pw(a) (1ll << (a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
//----
const int N=1005;
int l[N],r[N];
int main() {
	freopen("knockout.in", "r", stdin);
	freopen("knockout.out", "w", stdout);
	int n,m;scanf("%d%d",&n,&m);
	rep(i,0,n)scanf("%d%d",&l[i],&r[i]);
	while(m--) {
		int ans=0;
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		rep(i,0,n) {
			int pos=c%(2*(r[i]-l[i])),now;
			if(pos<=r[i]-l[i])now=l[i]+pos;
			else {
				pos-=r[i]-l[i];
				now=r[i]-pos;
			}
			ans+=(a<=now&&now<=b);
		}
		cout<<ans<<endl;
	}
	return 0;
}
