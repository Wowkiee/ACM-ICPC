#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double db;
//---
const int MAXN = 1<<18;
const double pi = acos(-1);
int N=1, na, nb, rev[MAXN*2];
struct vir{
	double re,im;
	vir(double r = 0.0, double i = 0.0) {re = r, im = i;}
} W[2][MAXN * 2];

vir operator + (const vir &A, const vir &B) { return vir(A.re + B.re, A.im + B.im);}
vir operator - (const vir &A, const vir &B) { return vir(A.re - B.re, A.im - B.im);}
vir operator * (const vir &A, const vir &B) { return vir(A.re * B.re - A.im * B.im, A.re * B.im + A.im * B.re);}

void FFT(vir *a, int f) {
	vir x, y;
	for (int i = 0; i < N; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int i = 1; i < N; i <<= 1)
		for (int j = 0, t= N / (i << 1); j < N; j += i<<1) 
				for (int k = 0,l=0;k<i;k++,l+=t) x = W[f][l] * a[j+k+i], y = a[j+k], a[j+k] = y + x, a[j+k+i] = y - x;
	if (f) for (int i = 0; i < N; i++) a[i].re /=N;
}

void work(){
	for (int i = 0; i < N; i++) {
		int x = i, y= 0;
		for (int k = 1; k<N; x>>=1, k<<=1) (y<<=1) |=x&1;
		rev[i] = y;
	}
	rep(i, 0, N) W[0][i] = W[1][i] = vir(cos(2*pi*i/N), sin(2*pi*i/N)), W[1][i].im = -W[0][i].im;
}


void doit(vir *a,vir *b) {
	FFT(a, 0), FFT(b, 0);
	rep(i, 0, N) a[i] = a[i] * b[i];
	FFT(a, 1);
}

//FFT
const int NN=250005;
char s1[NN][10],s2[NN][10];
vir data1[MAXN*2+10],data2[MAXN*2+10];
int Ans[NN];
int main() {
	int n,m;scanf("%d%d",&n,&m);
	if(n<m) {
		puts("No");
		return 0;
	}
	N=1;
	while(n*2+10>=N)N<<=1;
	work();
	rep(i,0,n)scanf("%s",s1[i]);
	rep(i,0,m)scanf("%s",s2[i]);
	rep(j,0,8) {
		//--- 1
		rep(i,0,N)data1[i]=data2[i]=vir(0,0);
		rep(i,0,n)data1[i]=vir(s1[i][j]=='1',0);
		per(i,0,m)data2[i]=vir(s2[i][j]=='0',0);
		doit(data1,data2);
		rep(i,m-1,n) {
			int ans=data1[i].re+0.5;
			Ans[i]+=ans;
		}
		//--- 2
		rep(i,0,N)data1[i]=data2[i]=vir(0,0);
		rep(i,0,n)data1[i]=vir(s1[i][j]=='0',0);
		per(i,0,m)data2[i]=vir(s2[i][j]=='1',0);
		doit(data1,data2);
		rep(i,m-1,n) {
			int ans=data1[i].re+0.5;
			Ans[i]+=ans;
		}
	}
	int xx=m-1;
	rep(i,m,n)if(Ans[i]<Ans[xx])xx=i;
	puts("Yes");
	printf("%d %d\n",Ans[xx],xx-m+2);
	return 0;
}
