#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define db double
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---
const db pi=acos(-1);
const db eps=1e-8;
int main() {
	int T;scanf("%d",&T);while(T--) {
		db v,R,d;scanf("%lf%lf%lf",&v,&R,&d);
		if(d-(2*R+pi*R)<=eps) {
			printf("%.10lf\n",d/v);
		}
		else {
			db l=pi*R/v,r=pi*R/v+(d-2*R-pi*R)/v;
			de(l);de(r);
			while(r-l>1e-8) {
				db mid=(l+r)/2.0;
				db nowd=d-v*mid-R;
				de(nowd);de(R);
				db cir=pi/2+cos(nowd/R);
				db ans=sqrt(nowd*nowd-R*R);
				de(ans);
				ans+=cir*R;
				de(ans);
				if(ans>mid)l=mid;
				else r=mid;
			}
			printf("%.10lf\n",l);
		}
	}
	return 0;
}
