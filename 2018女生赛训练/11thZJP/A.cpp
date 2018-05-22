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
	int T;
	scanf("%d",&T);
	while(T--) {
		int s1 = 0, s2 = 0;
		int n, m;
		scanf("%d%d", &n, &m);
		while(n--) {
			int t;
			scanf("%d", &t);
			s1+=t;
			
			
		}
		while(m--) {
			int t;
			scanf("%d", &t);
			s2+=t;
		}
		
		if(s1>s2) puts("Calem"); 
		else if(s1<s2) puts("Serena");
		else puts("Draw");
	} 
	
	
	return 0;
}

