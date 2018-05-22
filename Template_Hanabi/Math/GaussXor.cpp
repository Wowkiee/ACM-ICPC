//对 2 取模的 01 方程组
namespace Gause{
	static const int N=310;
	//有 equ 个方程， var 个变元。增广矩阵行数为 equ ,列数为 [0..var]
	int equ,var;
	bitset<N> a[N]; //增广矩阵 modif
	int x[N]; //解集
	int free_x[N];//用来存储自由变元（多解枚举自由变元可以使用）
	int free_num;//自由变元的个数
	//返回值为 -1 表示无解，为 0 是唯一解，否则返回自由变元个数
	int Gauss(){
		int max_r,col,k;// k 为增广矩阵的秩
		free_num = 0;
		for(k=0, col=0; k<equ&&col<var; k++, col++){
			max_r = k;
			for(int i=k+1; i<equ; i++){
				if(abs(a[i][col])>abs(a[max_r][col]))
					max_r=i;
			}
			if(a[max_r][col]==0){
				k--;
				free_x[free_num++]=col;//这个是自由变元
				continue;
			}
			if(max_r!=k){
				swap(a[k],a[max_r]);
			}
			for(int i=k+1; i<equ; i++){
				if(a[i][col]!=0)
					a[i]^=a[k];
			}
		}
		for(int i=k; i<equ; i++)
			if(a[i][col]!=0)
				return -1;//无解
		if(k<var) return var-k;//自由变元个数
		//唯一解，回代
		for(int i=var-1; i>=0; i--){
			x[i]=a[i][var];
			for(int j=i+1; j<var; j++)
				x[i]^=(a[i][j]&&x[j]);
		}
		return 0;
	}
}

