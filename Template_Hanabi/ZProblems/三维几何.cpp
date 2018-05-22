
/*	@5388 三维几何
	T l r x y z, translate points;
	S l r x y z k, scale points;
	R r x y z x' y' z' a, rotate points;
	C i, calculate the current coordinates of the point;
	L l r, calculate the current length of the polygonal chain.
*/


const int N = (222222 + 10);
inline int sgn(db x){
	return fabs(x) < eps ? 0 : (x > 0 ? 1 : -1);
}
struct MM{
	db a[4][4];
	MM(db x=1) {rep(i,0,4) rep(j,0,4) a[i][j] = i == j ? x : 0;}
	void in() {*this = MM(); rep(i,0,3) scanf("%lf",&a[0][i]);a[0][3] = 1;}
	void out() {rep(i,0,3) printf("%.5lf%c",a[0][i]," \n"[i==2]);}
	db dis() {db ret(0); rep(i,0,3) ret += a[0][i]*a[0][i]; return sqrt(ret);}
	MM operator -= (const MM&b) {rep(i,0,4) rep(j,0,4) a[i][j] -= b.a[i][j];return *this;}
	MM operator *= (const MM&b) {MM tmp(0);rep(i,0,4) rep(j,0,4) rep(k,0,4) tmp.a[i][j] += a[i][k] * b.a[k][j]; return *this = tmp;}
	bool operator == (const MM&b) {rep(i,0,4) rep(j,0,4) if(sgn(a[i][j] - b.a[i][j])) return false; return true;}
	MM(db x,db y,db z){ // Translation
		*this = MM(1); a[3][0] = x , a[3][1] = y , a[3][2] = z;
	}
	MM(db x ,db y,db z,db k){ // Scaling
		*this = MM(k); a[3][0] = (1-k)*x , a[3][1] = (1-k)*y , a[3][2] = (1-k)*z , a[3][3] = 1;
	}
	MM(db x ,db y,db z,db xx,db yy,db zz,double aa){ // Rotation
		MM t1 = MM(-x,-y,-z) , t2 = MM(x,y,z);
		db d = sqrt(xx*xx+yy*yy+zz*zz); x = xx/d , y = yy/d , z = zz/d;
		db COS = cos(aa) , SIN = sin(aa);
		*this = MM(1);
		a[0][0] = x*x*(1-COS) + COS , a[0][1] = x*y*(1-COS) + z*SIN	 , a[0][2] = x*z*(1-COS) - y*SIN;
		a[1][0] = x*y*(1-COS) - z*SIN,a[1][1] = y*y*(1-COS) + COS   , a[1][2] = y*z*(1-COS) + x*SIN;
		a[2][0] = x*z*(1-COS) + y*SIN,a[2][1] = y*z*(1-COS)	- x*SIN , a[2][2] = z*z*(1-COS) + COS;
		t1 *= *this , t1 *= t2;
		*this = t1;
	}
	void oo(){
		rep(i,0,4) rep(j,0,4) printf("%.5lf%c",a[i][j]," \n"[j==3]);
	}
}I,a[N<<2];
#define pos int x,int l,int r
#define lson x<<1
#define rson x<<1|1
#define left lson,l,m
#define right rson,m+1,r
#define getm int m=(l+r)>>1
double c[N<<2] , ans[N<<2];
void Build(pos){
	a[x] = I; c[x] = 1;
	if(l == r){
		a[x].in();
		return;
	}getm;
	Build(left);Build(right);
}
inline void downA(int x){
	if(!(a[x] == I)) a[lson] *= a[x] ,
		a[rson] *= a[x] , a[x] = I;
}
MM Query(pos,int p){
	if(l == r) return a[x];
	getm;downA(x);
	if(p <= m) return Query(left,p); else return Query(right,p);
}
void Modify(pos,int L,int R,MM b){
	if(L <= l && r <= R){
		a[x] *= b;
		return;
	}getm;downA(x);
	if(L <= m) Modify(left,L,R,b);
	if(R > m) Modify(right,L,R,b);
}
inline void downC(int x){
	if(c[x] != 1) ans[lson] *= c[x] , c[lson] *= c[x] ,
		ans[rson] *= c[x] , c[rson] *= c[x] , c[x] = 1;
}
void Change(pos,int p,double v){
	if(l == r){
		ans[x] = v;
		return;
	}getm;downC(x);
	if(p <= m) Change(left,p,v); else Change(right,p,v);
	ans[x] = ans[lson] + ans[rson];
}
void mult(pos,int L,int R,double k){
	if(L <= l && r <= R){
		c[x] *= k , ans[x] *= k;
		return;
	}getm;downC(x);
	if(L <= m) mult(left,L,R,k);
	if(R > m) mult(right,L,R,k);
	ans[x] = ans[lson] + ans[rson];
}
double sum(pos,int L,int R){
	if(L <= l && r <= R) return ans[x];
	getm;downC(x);
	double ret = 0;
	if(L <= m) ret += sum(left,L,R);
	if(R > m) ret += sum(right,L,R);
	return ret;
}

int n , m;
int main(){
	int re = 0;
	while(~scanf("%d%d",&n,&m)){
		if(n == 0 && m == 0) return 0;
		printf("Case #%d:\n",++re);
		Build(1,1,n);
		rep(i,1,n) Change(1,1,n,i,(Query(1,1,n,i)-=Query(1,1,n,i+1)).dis());
		char s[100];
		double x , y , z , xx , yy , zz , k , theta;
		int l , r;
		rep(i,0,m){
			scanf("%s",s);
			scanf("%d",&l);
			if(s[0] == 'C')
				Query(1,1,n,l).out();
			else{
				scanf("%d",&r);
				if(s[0] == 'L'){
					printf("%.5lf\n",l+1<=r?sum(1,1,n,l,r-1):0);
				}
				else{
					scanf("%lf%lf%lf",&x,&y,&z);
					if(s[0] == 'T') Modify(1,1,n,l,r,MM(x,y,z));
					else if(s[0] == 'S'){
						scanf("%lf",&k);
						Modify(1,1,n,l,r,MM(x,y,z,k));
						if(l < r) mult(1,1,n,l,r-1,k);
					}
					else if(s[0] == 'R'){
						scanf("%lf%lf%lf%lf",&xx,&yy,&zz,&theta);
						Modify(1,1,n,l,r,MM(x,y,z,xx,yy,zz,theta));
					}
					if(l > 1) Change(1,1,n,l-1,(Query(1,1,n,l-1)-=Query(1,1,n,l)).dis());
					if(r < n) Change(1,1,n,r,(Query(1,1,n,r)-=Query(1,1,n,r+1)).dis());
				}
			}
		}
	}
	return 0;
}
