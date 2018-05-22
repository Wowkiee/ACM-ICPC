namespace Gauss{
	static const int N=210;
	int a[510][N];
	int kpow(int a, int b){
		int r=1;
		while(b>0){
			if(b&1)r=r*a%P;
			a=a*a%P;
			b>>=1;
		}
		return r;
	}
	int solve(int n, int m){//n=equ, m=var 同 Gaussxor
		int i=0, x=0;
		for(; i<n&&x<m; i++, x++){
			int r=i;
			while(r<n&&!a[r][x])r++;
			if(r>=n){
				i--;
				continue;
			}
			if(r!=i)
				rep(j, 0, m+1)swap(a[r][j], a[i][j]);
			int inv=kpow(a[i][x], P-2);
			for(int k=m; k>=x; k--)a[i][k]=a[i][k]*inv%P;
			rep(j, 0, n)
				if(i!=j&&a[j][x])
					for(int k=m; k>=x; k--)
						a[j][k]=(a[j][k]-a[i][k]*a[j][x]%P+P)%P;
		}
		rep(k, i, n)if(a[k][m])return -1;
		return m-i;
	}
	void out(int n, int m){
		rep(i, 0, n){
			rep(j, 0, m)cout<<a[i][j]<<' ';
			cout<<endl;
		}
	}
};

