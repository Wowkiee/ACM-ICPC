
/*	@Gym-100430I
	平面点集度数已知，构造生成树，线不相交
*/

const int N = 1001;
int x[N] , y[N] , d[N] , n;
vector<pii> ans;
db ang[N];
bool cmp(const int a,const int b){
	return ang[a] < ang[b];
}
void solve(int,int,db,vi&);
void link(int s,vi& v){
	if(sz(v) == 0) return;
	int sum = 0 , o = 0 , d1 = 0;
	for(;o<sz(v);++o){
		int a = v[o];
		sum += d[a] - 2;
		if(sum >= 0 || o + 1 == sz(v)){
			sum -= d[a] - 2;
			d1 = -sum;
			break;
		}
	}
	vi nv , mv;
	rep(i,0,o) nv.pb(v[i]);
	rep(i,o+1,sz(v)) mv.pb(v[i]);
	o = v[o];
	ans.pb(mp(o,s));
	db hori = atan2(y[o] - y[s] , x[o] - x[s]);
	solve(o,d1,hori,nv);
	solve(o,d[o]-1-d1,hori,mv);
}
void solve(int s,int du,db horizon,vi& v){
	if(sz(v) == 0) return;
	rep(i,0,sz(v)){
		int a = v[i];
		db tmp = atan2(y[a] - y[s] , x[a] - x[s]) - horizon;
		while(tmp <= -pi) tmp += 2*pi;
		while(tmp > pi) tmp -= 2*pi;
		ang[a] = tmp;
	}
	sort(all(v),cmp);
	vi nv;
	int sum = 0 , psum = 0;
	rep(i,0,sz(v)){
		int a = v[i];
		sum += d[a] - 2;
		nv.pb(a);
		if((sum < psum && sum + du >= 1) || i + 1 == sz(v)){
			psum = sum;
			link(s,nv);
			nv.clear();
		}
	}
}

int main(){
	scanf("%d",&n);
	rep(i,0,n) scanf("%d%d%d",x + i , y + i , d + i);
	int start = min_element(x , x + n) - x;
	vi v; rep(i,0,n) if(i != start) v.pb(i);
	solve(start,d[start],0.,v);
	rep(i,0,n-1) printf("%d %d\n",ans[i].fi + 1,ans[i].se + 1);
	return 0;
}
