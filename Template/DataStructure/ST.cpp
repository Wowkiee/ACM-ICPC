const int N=101010;

int n,m;
int Max[N][22];

int main() {
	while(~scanf("%d%d",&n,&m)) {
		///read
		rep(i,1,n+1) scanf("%d",&Max[i][0]);
		///solve
		for(int i=1;(1<<i)<=n;++i) {
			for(int j=1;j+(1<<i)-1<=n;++j) {
				Max[j][i]=max(Max[j][i-1], Max[j+(1<<(i-1))][i-1]);
			}
		}
		while(m--) { 
			int l,r;scanf("%d%d",&l,&r);
			int _ = log2(r-l+1);
			printf("%d\n",max(Max[l][_], Max[r-(1<<_)+1][_]));
		}
	}
	return 0;
}
