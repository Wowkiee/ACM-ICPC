namespace 2DST{
	void build(){
		for(int i=0; i<11; i++)P[i]=1<<i;
		for(int i=2; i<1025; i++)LOG[i]=LOG[i>>1]+1;
		for(dep1=0; (1<<dep1)<n; dep1++);
		for(dep2=0; (1<<dep2)<m; dep2++);
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				st[0][0][i][j]=a[i][j];//modi
		for(int i=1; i<=n; i++)
			for(int j=1; j<=dep2; j++)
				for(int k=P[j]; k<=m; k++)
					st[0][j][i][k]=max(st[0][j-1][i][k], st[0][j-1][i][k-P[j-1]]);
		for(int i=1; i<=dep1; i++)
			for(int j=P[i]; j<=n; j++)
				for(int k=0; k<=dep2; k++)//attention to range of k
					for(int l=P[k]; l<=m; l++)
						st[i][k][j][l]=max(st[i-1][k][j-P[i-1]][l], st[i-1][k][j][l]);
	}
	int qry(int x1, int y1, int x2, int y2){
		int len1=x2-x1+1, len2=y2-y1+1, l1, l2, res1, res2;
		l1=LOG[len1];l2=LOG[len2];
		res1=max(st[l1][l2][x1+P[l1]-1][y1+P[l2]-1], st[l1][l2][x2][y2]);
		res2=max(st[l1][l2][x1+P[l1]-1][y2], st[l1][l2][x2][y1+P[l2]-1]);
		return max(res1, res2);
	}
}
