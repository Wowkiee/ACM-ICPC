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

int main() {
	
	int n;
	cin>>n;
	ll sum = 0;
	rep(i, 1, n + 1) {
		
		ll t = 1;
		rep(j, 1 , i + 1) {
			t = (t * i) % 7;
		}
		sum = (sum + t)%7;
	//	cout<<i<< " "<<t<<" "<<sum<< endl;
	//	cout<<i<< " "<<t<<endl;
		cout<<t<<",";
		if(i % 42 == 0) cout<<endl;
	}
	return 0;
}

