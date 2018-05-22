#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
typedef long long ll;
const int MOD =1e9+7;
const int MAXN=1<<17;
const double PI = acos(-1);

int N,L,MASK,na,nb;
int a[MAXN],b[MAXN];

struct Complex
{
	double re,im;
	Complex(double r=0.0,double i=0.0) {re=r,im=i;}
	void print() {printf("%lf %lf\n",re,im);}
};

Complex operator +(const Complex&A,const Complex&B) {return Complex(A.re+B.re,A.im+B.im);}
Complex operator -(const Complex&A,const Complex&B) {return Complex(A.re-B.re,A.im-B.im);}
Complex operator *(const Complex&A,const Complex&B) {return Complex(A.re*B.re-A.im*B.im,A.re*B.im+A.im*B.re);}

Complex conj(Complex a){
	return Complex(a.re,-a.im);
}

Complex w[MAXN];
void FFTInit() {
	for (int i = 0; i < N; ++i) {
		w[i] = Complex(cos(2 * i * PI / N), sin(2 * i * PI / N));
	}
}
void FFT(Complex p[], int n) {
	for (int i = 1, j = 0; i < n - 1; ++i) {
		for (int s = n; j ^= s >>= 1, ~j & s;);
		if (i < j) {
			swap(p[i], p[j]);
		}
	}
	for (int d = 0; (1 << d) < n; ++d) {
		int m = 1 << d, m2 = m * 2, rm = n >> (d + 1);
		for (int i = 0; i < n; i += m2) {
			for (int j = 0; j < m; ++j) {
				Complex &p1 = p[i + j + m], &p2 = p[i + j];
				Complex t = w[rm * j] * p1;
				p1 = p2 - t;
				p2 = p2 + t;
			}
		}
	}
}
Complex A[MAXN], B[MAXN], C[MAXN], D[MAXN];


void init(){
	L=0;
	scanf("%d",&na);rep(i,0,na) scanf("%d",&a[i]);
	scanf("%d",&nb);rep(i,0,nb) scanf("%d",&b[i]);
	for (N=1; N<na || N<nb; N<<=1) L++;  N<<=1;	
	MASK=(1<<L)-1;
	FFTInit();
	for (int i = 0; i < N; ++i) {
		A[i] = Complex(a[i] >> L, a[i] & MASK);
		B[i] = Complex(b[i] >> L, b[i] & MASK);
	}
}

void mul() {
	FFT(A, N), FFT(B, N);
	for (int i = 0; i < N; ++i) {
		int j = (N - i) % N;
		Complex da = (A[i] - conj(A[j])) * Complex(0, -0.5),
				db = (A[i] + conj(A[j])) * Complex(0.5, 0),
				dc = (B[i] - conj(B[j])) * Complex(0, -0.5),
				dd = (B[i] + conj(B[j])) * Complex(0.5, 0);
		C[j] = da * dd + da * dc * Complex(0, 1);
		D[j] = db * dd + db * dc * Complex(0, 1);
	}
	FFT(C, N), FFT(D, N);
	for (int i = 0; i < N; ++i) {
		ll  da = (ll)(C[i].im / N + 0.5) % MOD,
			db = (ll)(C[i].re / N + 0.5) % MOD,
			dc = (ll)(D[i].im / N + 0.5) % MOD,
			dd = (ll)(D[i].re / N + 0.5) % MOD;
		a[i] = ((dd << (L * 2)) + ((db + dc) << L) + da) % MOD;
	}
}

int main(){
	init();
	mul();
	rep(i,0,N) printf("%d\n",a[i]);
}
