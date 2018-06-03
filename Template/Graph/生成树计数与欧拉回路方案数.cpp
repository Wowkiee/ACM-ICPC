// d[][]:
//     i!=j d[i][j]=0
//     i==j d[i][j]=out_deg(i) 
// b[][]:
//     from i to j has b[i][j] directed edges
// a[][] = d[][] - b[][]

// 无向图生成树个数： a[][] 任何一个 n-1 阶主子式的绝对值
// 有向图以 i 为根的生成树个数： a[][] 去掉第 i 行第 i 列的行列式的绝对值

// 如果有模数，注释 mod 的地方可以直接取模
ll det() { // det(a[1..n-1][1..n-1])
	ll ans=1;
	rep(i,1,n) {
		rep(j,i+1,n) {
			while(a[j][i]) {
				ll t=a[i][i]/a[j][i];
				rep(k,i,n) a[i][k]=a[i][k]-a[j][k]*t;// mod
				rep(k,i,n) swap(a[i][k],a[j][k]);
				ans=-ans;// mod
			}
		}
		if(a[i][i]==0) return 0;
		ans=ans*a[i][i];// mod
	}
	if(ans<0) ans=-ans;// mod
	return ans;
}

// 有向图要记得判断每个点的出度入度是否相等
// 无向图需要转换成有向图
// tw(G): 以 w 为根的生成树个数
// ec(G) = tw(G) * pi((deg[v] - 1)!) 
// ans = ec(G) * deg[w]; 因为 best theorem 求的是本质不同的方案数，所以还需要这一步
//     本质相同：1231341 1341231
//     本质不同：1231341 1312341
