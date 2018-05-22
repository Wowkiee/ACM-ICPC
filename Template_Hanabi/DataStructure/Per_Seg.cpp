#include<bits/stdc++.h>
using namespace std;

const int N=100005;
int cntn,n,q;
int a[N],b[N],root[N],cnt[N*20],L[N*20],R[N*20];//*20

void UP(int nid) {
	cnt[nid]=cnt[L[nid]]+cnt[R[nid]];
}

int build(int l=1,int r=n) {
	int nid=cntn++;
	if(l==r) return nid;
	int m=l+r>>1;
	L[nid]=build(l,m);
	R[nid]=build(m+1,r);
	return nid;
}

int upd(int nth,int p,int l=1,int r=n) {
	if(p<l||r<p) return nth;
	int nid=cntn++;
	if(l==r) {
		++cnt[nid];
		return nid;
	}
	int m=l+r>>1;
    L[nid]=upd(L[nth],p,l,m);
	R[nid]=upd(R[nth],p,m+1,r);
	UP(nid);
	return nid;
}

int qry(int idl,int idr,int k,int l=1,int r=n) {
	if(l==r) return l;
	int m=l+r>>1;
	int cntl=cnt[L[idr]]-cnt[L[idl]];
	if(cntl>=k) return qry(L[idl],L[idr],k,l,m);
	return qry(R[idl],R[idr],k-cntl,m+1,r);
}

int main() {
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i) {
		scanf("%d",a+i);
		b[i]=a[i];
	}
	sort(b+1,b+1+n);

	root[0]=build();
	for(int i=1;i<=n;++i) {
		int p=lower_bound(b+1,b+1+n,a[i])-b;
		root[i]=upd(root[i-1],p);
	}

	while(q--) {
		int l,r,k;scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",b[qry(root[l-1],root[r],k)]);
	}
	return 0;
}
