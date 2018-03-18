void init() {
	mu[1]=1;
	rep(i,2,N) if(!vis[i]) {
		mu[i]=-1;
		for(int j=i+i;j<N;j+=i) {
			if(!vis[j]) mu[j]=-1, vis[j]=1;
			else mu[j]=-mu[j];
			if(j%(i*i)==0) mu[j]=0;
		}
	}
}
