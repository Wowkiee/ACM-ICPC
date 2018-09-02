#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pw(x) (1ll << (x))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl

//-----

int main() {
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	int a,b,c,d;
	while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF)
	{
		a--;c--;
		ll _2018=b/2018-a/2018;
		ll _1009=b/1009-a/1009-_2018;
		ll _2=b/2-a/2-_2018;
		ll _1=b-a-_2018-_1009-_2;
		//de(_2018);de(_1009);de(_2);de(_1);
		ll ans=_2018*(d-c)+_1009*(d/2-c/2)+_2*(d/1009-c/1009)+_1*(d/2018-c/2018);
		printf("%lld\n",ans);
	}
	return 0;
}
