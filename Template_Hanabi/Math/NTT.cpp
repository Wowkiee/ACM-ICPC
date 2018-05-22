#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define rep(i,a,b) for (int i=(a);i<(b);i++)
#define ll long long
using namespace std;


const int MAXN=1<<17;
const int G=3; 
const int P=1004535809; //P=C*2^k+1
int N,na,nb,a[MAXN*2],b[MAXN*2],W[2][MAXN*2],rev[MAXN*2];

ll Pow(ll a,int b)
{
	ll c=1;
	for (;b; b>>=1,a=a*a%P) if (b&1) c=c*a%P;
	return c;
}

void FFT(int*a,int f)
{
	rep(i,0,N) if (i<rev[i]) swap(a[i],a[rev[i]]);
	for (int i=1; i<N; i<<=1)
		for (int j=0,t=N/(i<<1); j<N; j+=i<<1)
			for (int k=0,l=0,x,y; k<i; k++,l+=t)
				x=(ll)W[f][l]*a[j+k+i]%P,y=a[j+k],a[j+k]=(y+x)%P,a[j+k+i]=(y-x+P)%P;
	if (f) for (int i=0,x=Pow(N,P-2); i<N; i++) a[i]=(ll)a[i]*x%P;
}

void work()
{
	rep(i,0,N)
	{
		int x=i,y=0;
		for (int k=1; k<N; x>>=1,k<<=1) (y<<=1)|=x&1;
		rev[i]=y;
	}
	W[0][0]=W[1][0]=1;
	for (int i=1,x=Pow(G,(P-1)/N),y=Pow(x,P-2); i<N; i++)
		W[0][i]=(ll)x*W[0][i-1]%P,W[1][i]=(ll)y*W[1][i-1]%P;
}

void init()
{
	scanf("%d",&na); for (int i=0; i<na; i++) scanf("%d",&a[i]);
	scanf("%d",&nb); for (int i=0; i<nb; i++) scanf("%d",&b[i]);
	for (N=1; N<na||N<nb; N<<=1); N<<=1;
}

void doit()
{
	work(),FFT(a,0),FFT(b,0);
	rep(i,0,N) a[i]=(ll)a[i]*b[i]%P;
	FFT(a,1);
	rep(i,0,N) printf("%d\n",a[i]);
}

int main(){
	init();
	doit();
}
