
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
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

int main() {
	srand(time(0));
	freopen("xx.in","w",stdout);
	rep(cas,0,2) {
		int n=rand()%1000+1,m=rand()%10000+1;
		cout<<n<<" "<<m<<endl;
		int S=rand()%n+1,E=S,K=rand()%10000+1,T=rand()%100000000+1;
		while(E!=S)E=rand()%n+1;
		cout<<S<<" "<<E<<" "<<K<<" "<<T<<endl;
		while(m--) {
			int a=rand()%n+1,b=rand()%n+1,c=rand()%1000+1;
			cout<<a<<" "<<b<<" "<<c<<endl;
		}
	}
	return 0;
}
