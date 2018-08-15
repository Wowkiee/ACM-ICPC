#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---
const int N = 4e5 + 7;
const int INF=0x7fffffff;
int r[N],sa[N],rk[N],het[N];
int wa[N],wb[N],wx[N],wv[N];
bool ise(int *r,int a,int b,int len) {
	return r[a]==r[b]&&r[a+len]==r[b+len];
}
void getSa(int n,int m) {
	int *x=wa,*y=wb;
	rep(i,0,m)wx[i]=0;
	rep(i,0,n)++wx[x[i]=r[i]];
	rep(i,1,m)wx[i]+=wx[i-1];
	for(int i=n-1;i>=0;--i)sa[--wx[x[i]]]=i;
	for(int j=1,p=0;p<n;j<<=1,m=p) {
		p=0;
		rep(i,n-j,n)y[p++]=i;
		rep(i,0,n)sa[i]>=j?y[p++]=sa[i]-j:0;
		rep(i,0,m)wx[i]=0;
		rep(i,0,n)++wx[wv[i]=x[y[i]]];
		rep(i,1,m)wx[i]+=wx[i-1];
		for(int i=n-1;i>=0;--i)sa[--wx[wv[i]]]=y[i];
		p=1,swap(x,y);
		x[sa[0]]=0;
		rep(i,1,n)x[sa[i]]=ise(y,sa[i],sa[i-1],j)?p-1:p++;
	}
}
void getHeight(int n) {
	rep(i,1,n+1)rk[sa[i]]=i;
	for(int i=0,k=0;i<n;het[rk[i++]]=k) {
		k=k>0?k-1:0;
		for(int j=sa[rk[i]-1];r[i+k]==r[j+k];++k);
	}
}
