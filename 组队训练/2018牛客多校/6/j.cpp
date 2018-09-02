#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b-1);i>=a;i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---
const int N=1e7+5;
const int msz=100;
unsigned long long data[N];
ull v[msz+5];
unsigned x,y,z;
unsigned tang() {
	x^=x<<16;
	x^=x>>5;
	x^=x<<1;
	unsigned t=x;
	x=y;y=z;z=t^x^y;
	return z;
}
ull gcd(ull x, ull y) {
	if(y == 0) return x;
	return gcd(y, x%y);
}
int main() {
	int T;scanf("%d",&T);rep(cas,0,T) {
		memset(v,0,sizeof(v));
		int n;
		scanf("%d%u%u%u",&n,&x,&y,&z);
		unsigned B=-2;B=B/n+1;
		rep(i,0,n) {
			data[i]=tang();
		}
		rep(i,0,n) {
			int pp=min(i,msz);
			v[pp]=data[i];
			while(pp&&v[pp]>v[pp-1])swap(v[pp],v[pp-1]),pp--;
		}
		unsigned long long ans=0;
		int xx=min(n,msz);
		rep(i,0,xx)
		{
			int yy=min(n,msz);
			rep(j,i,yy) {
				ans=max(ans,v[i]/gcd(v[i],v[j])*v[j]);
			}
		}
		printf("Case #%d: %llu\n",cas+1,ans);
	}
	return 0;
}
