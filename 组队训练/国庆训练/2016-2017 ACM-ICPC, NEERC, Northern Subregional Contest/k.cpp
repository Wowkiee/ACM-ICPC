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
//---
const int N=1e7+7,M=5000;
int cmp(int a,int b,int c,int A,int B,int C) {
	if(a>A)return 1;
	if(a<A)return -1;
	if(b>B)return 1;
	if(b<B)return -1;
	if(c>C)return 1;
	if(c==C)return 0;
	return -1;
}
int main() {
	freopen("king.in","r",stdin);
	freopen("king.out","w",stdout);
	int y,m,d;scanf("%d%d%d",&d,&m,&y);y-=18;
	int ans=-1;
	int nowy,nowm,nowd;
	int n;scanf("%d",&n);
	rep(i,1,n+1) {
		int Y,M,D;scanf("%d%d%d",&D,&M,&Y);
		if(cmp(Y,M,D,y,m,d)!=1) {
			if(ans==-1||cmp(Y,M,D,nowy,nowm,nowd)==1) {
				ans=i;
				nowy=Y;nowm=M,nowd=D;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
