const int N=101010;
int cntn, rt[N], cnt[N*22], ls[N*22], rs[N*22];
void upd(int pre,int &now,int p,int l,int r) {
	now=++cntn;
	cnt[now]=cnt[pre]+1;
	ls[now]=ls[pre];
	rs[now]=rs[pre];
	if(l==r) return ;
	int mid=l+r>>1;
	if(p<=mid) upd(ls[pre], ls[now], p, l, mid);
	else upd(rs[pre], rs[now], p, mid+1, r);
}
int qry(int L,int R,int l,int r,int k) {
	if(l==r) return l;
	int mid=l+r>>1;
	int cl = cnt[ls[R]]-cnt[ls[L]];
	if(k<=cl) return qry(ls[L], ls[R], l, mid, k);
	return qry(rs[L], rs[R], mid+1, r, k-cl);
}
