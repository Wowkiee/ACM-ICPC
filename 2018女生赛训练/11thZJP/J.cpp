#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b-1);i>=(a);i--)
#define sz(x) (int)x.szie()
#define de(x) cout<<#x<<" = "<<x<<endl
#define dd(x) cout<<#x<<" = "<<x<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll mod = 7;
ll biao[] = {1,4,6,4,3,1,0,1,1,4,2,1,6,0,1,2,5,1,5,1,0,1,4,1,4,4,6,0,1,1,3,2,6,1,0,1,2,2,1,2,6,0};
ll add(ll x, ll y) {
	return (x + y) % mod;
}
char str[][11] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int main() {
	int T, now = 6;
	ll s = 0;
		rep(i, 0, 42) s = add(s, biao[i]);
	scanf("%d",&T);
	while(T--) {
		ll n;scanf("%lld",&n);
		ll k = n / 42;
		ll sum = 0;
		sum = add(sum, s * k);
		int pos = n - k * (ll)42;
		rep(i, 0, pos) {
			sum = add(sum, biao[i]);
		}
		ll ans = add(now, sum);
		printf("%s\n",str[ans]);
			
	}
	return 0;
}

