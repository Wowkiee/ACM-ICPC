#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int N = 200000 + 10;

int cnt[N];

int main() {
	
	int ma = 0, ans =  0;
	int n;
	scanf("%d", &n);
	memset(cnt,0,sizeof(cnt));
	
	while(n--) {
		int t;
		scanf("%d", &t);
		if(t>ma) ma = t;
		cnt[t]++;
	}
	
	rep(i,0, ma + 1) {
		ans += cnt[i] /2;
	}
	printf("%d", ans/2);
	
	return 0;
}

