namespace GaussDB{
	static const int N=210;
	double mat[N][N];//增广矩阵
	double x[N];//解集
	bool free_x[N];//标记是否是不确定的变元
	const double eps = 1e-7;
	int Gauss(int equ, int var){
		int k;
		int max_r, col;
		int free_index, free_num;
		memset(free_x, 1, sizeof(free_x));
		memset(x, 0, sizeof(x));
		for(k=col=0; k<equ&&col<var; ++k, ++col){
			max_r=k;
			rep(i, k+1, equ)
				if(fabs(mat[i][col])-mat[max_r][col]>eps) max_r=i;
			if(max_r!=k)
				rep(j, k, var+1)swap(mat[max_r][j], mat[k][j]);
			if(fabs(mat[k][col]<eps)){--k;continue;}
			rep(i, k+1, equ){
				if(fabs(mat[i][col])<=eps) continue;
				double tmp=mat[i][col]/mat[k][col];
				rep(j, col, var+1)
					mat[i][j]-=mat[k][j]*tmp;
			}

		}
		rep(i, k, equ)
			if(fabs(mat[i][var]>eps)) return 0;//无解
		if(k<var){
			for(int i=k-1; i>=0; --i){
				free_num=0;
				rep(j, 0, var){
					if(fabs(mat[i][j])>eps&&free_x[j]){
						free_num+=1;
						free_index=j;
					}
				}
				if(free_num>1) continue;
				double tmp=mat[i][var];
				rep(j, 0, var){
					if(j!=free_index&&fabs(mat[i][j])>eps)
						tmp-=mat[i][j]*x[j];
				}
				free_x[free_index]=0;
				x[free_index]=tmp/mat[i][free_index];
			}
			return var-k;//自由变元个数
		}
		for(int i=var-1; i>=0; --i){
			double tmp=mat[i][var];
			rep(j, i+1, var){
				if(fabs(mat[i][j])>eps)
					tmp-=x[j]*mat[i][j];
			}
			x[i]=tmp/mat[i][i];
		}
		return 1;
	}
}

