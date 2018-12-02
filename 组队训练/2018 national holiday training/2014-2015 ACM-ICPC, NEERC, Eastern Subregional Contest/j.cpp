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
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---
set<pii> s1,s2;
stack<pii> S;
int main() {
	int n;scanf("%d",&n);
	int sum1=0,sum2=0;
	rep(i,1,n+1) {
		int a;scanf("%d",&a);
		sum1+=a;s1.insert(mp(a,i));
	}
	rep(i,1,n+1) {
		int a;scanf("%d",&a);
		sum2+=a;s2.insert(mp(a,i));
	}
	rep(i,0,n) {
		if(sum1<=sum2) {
			pii a=*s1.begin();
			pii b=*s2.rbegin();
			S.push(mp(a.se,b.se));
			sum1-=a.fi,sum2-=b.fi;
			s1.erase(a),s2.erase(b);
		}
		else {
			pii a=*s1.rbegin();
			pii b=*s2.begin();
			S.push(mp(a.se,b.se));
			sum1-=a.fi,sum2-=b.fi;
			s1.erase(a),s2.erase(b);
		}
	}
	while(!S.empty()) {
		pii now=S.top();
		printf("%d %d\n",now.fi,now.se);
		S.pop();
	}
	return 0;
}
