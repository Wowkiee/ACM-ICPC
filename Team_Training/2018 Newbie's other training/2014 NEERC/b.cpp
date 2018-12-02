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
const int N=1e5 + 7;
db ans[N];
struct eql {
	int g,a,b,id;
	eql(int _g=0,int _a=0,int _b=0,int _id=0) {
		g=_g,a=_a,b=_b,id=_id;
	}
	bool operator <(eql o) {
		return 1ll*a*o.b>1ll*b*o.a;
	}
}data[N];
int main() {
	freopen("burrito.in", "r", stdin);
	freopen("burrito.out", "w", stdout);
	int n,A,B;scanf("%d%d%d",&n,&A,&B);
	rep(i,0,n) {
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		data[i]=eql(a,b,c,i);
	}
	sort(data,data+n);
	db AA=0,BB=B;
	rep(i,0,n) {
		if(1ll*data[i].g*data[i].b>B) {
			db l=1.0*B/data[i].b;
			ans[data[i].id]=l;
			AA+=l*data[i].a;
			B=0;
		}
		else {
			ans[data[i].id]=data[i].g;
			B-=1ll*data[i].g*data[i].b;
			AA+=1ll*data[i].g*data[i].a;
		}
	}
	if(AA>=A) {
		printf("%.12lf %.12lf\n",AA,BB-B);
		rep(i,0,n)printf("%.12lf%c",ans[i],i==n-1?'\n':' ');
	}
	else puts("-1 -1");
	return 0;
}
