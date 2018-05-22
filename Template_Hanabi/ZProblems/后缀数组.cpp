
/* 后缀数组 */
// repeat string

int T , n;
int a[N];
int ans;

void go(int d){
	for(int l=0;l+d<n;l+=d){
		int gt = lcp(l,l+d);
		int tmp = gt / d;
		int jp = l - (d - gt%d);
		if(jp >= 0) tmp = max(tmp , lcp(jp,jp+d) / d);
		ans = max(tmp + 1 , ans);
	}
}

int main(){
	scanf("%d",&T);
	rep(re,0,T){
		scanf("%d",&n);
		rep(i,0,n){
			char c[2];
			scanf("%s",c);
			a[i] = c[0] - 'a' + 1;
		}a[n] = 0;
		da(a,n+1,100);cal_h(a,n);rmq(n);
		ans = 1;
		rep(i,1,n+1) go(i);
		printf("%d\n",ans);
	}
	return 0;
}
//	字典序最小，repeat string
void go(int d){
	int tmp = 0;
	for(int l=0;l+d<len;l+=d){
		int gt = lcp(l,l+d);
		tmp = max(tmp , gt / d);
		int jp = l - (d - gt%d);
		if(jp >= 0) tmp = max(tmp , lcp(jp,jp+d) / d);
	}
	if(tmp > ans) _q = 0 , ans = tmp;
	if(tmp >= ans) q[_q++] = d;
}

int re = 0;
void out(){
	for(int i=1;i<=len;++i){
		int id = sa[i];
		for(int j=0;j<_q;++j){
			if(id + q[j] >= len) continue;
			if(lcp(id,id+q[j]) >= ans * q[j]){
				s[id + (ans + 1) * q[j]] = 0;
				printf("Case %d: ",++re);
				puts(s + id);
				return;
			}
		}
	}
}

int main(){
	while(~scanf("%s",s)){
		len = strlen(s);
		if(len == 1 && s[0] == '#') return 0;
		rep(i,0,len) a[i] = s[i] - 'a' + 100;
		a[len] = 0;
		da(a,len+1,200); cal_h(a,len); rmp(len);
		ans = 0; rep(i,1,len+1) go(i);
		out();
	}
	return 0;
}
//	长度不小于K的公共串对
char s[N];
int a[N] , n , len , K;
int who[N];
ll ans;
pii st[N];
int p;
void cal(int p1,int p2){
	p = -1;
	ll tot = 0;
	rep(i,1,n+1){
		if(h[i] < K) p = -1 , tot = 0;
		else{
			int cnt = 0;
			if(who[sa[i-1]] == p1) cnt++ , tot += h[i] - K + 1;
			while(~p && h[i] <= st[p].fi){
				tot -= 1ll * st[p].se * (st[p].fi - h[i]);
				cnt += st[p].se;
				--p;
			}
			st[++p] = mp(h[i],cnt);
			if(who[sa[i]] == p2) ans += tot;
		}
	}
}


int main(){
	while(~scanf("%d",&K)){
		if(K == 0) return 0;
		scanf("%s",s);
		n = len = strlen(s);
		rep(i,0,len) a[i] = s[i] , who[i] = 1;
		a[n] = 1; who[n++] = 0;
		scanf("%s",s);
		rep(i,0,len) a[n+i] = s[i] , who[n+i] = 2;
		a[n += len] = 0; who[n] = 0;
		da(a,n+1,300); cal_h(a,n);
		ans = 0;
		cal(1,2); cal(2,1);
		printf("%I64d\n",ans);
	}
	return 0;
}

