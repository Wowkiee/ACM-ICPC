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
const int N=100005;
char s[N];
bool isok(char a) {
	return a=='a'||a=='e'||a=='i'||a=='o'||a=='u';
}
int main() {
	scanf("%s",s+1);
	int n=strlen(s+1),cc=0;
	rep(i,1,n+1)cc+=isok(s[i]);
	if(!isok(s[1])) {
		printf("%d\n",!cc);
		return 0;
	}
	int l=1,r=n,zt=0;
	while(cc!=1) {
		if(!zt) {
			while(!isok(s[r]))r--;
			l++;
		}
		else {
			while(!isok(s[l]))l++;
			r--;
		}
		zt^=1;cc--;
	}
	printf("%d\n",r-l+1);
	return 0;
}
