void upd(int p,int c) {
	for(int i=p;i<=n;i+=(i&-i)) pre[i]+=c;
}
int sum(int p) {
	int res=0;
	for(int i=p;i;i-=(i&-i)) res+=pre[i];
	return res;
}
