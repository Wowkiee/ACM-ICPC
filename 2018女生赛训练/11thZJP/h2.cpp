#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b-1);i>=(a);i--)
#define sz(x) (int)x.size()
#define de(x) cout<<#x<<" = "<<x<<endl
#define dd(x) cout<<#x<<" = "<<x<<" "
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const db eps=1e-7;
const db pi=acos(-1);
int sign(db x) {
	return (x>eps)-(x<-eps);
}
struct P {
	db x, y;
	P() {};
	P(db x, db y) {
		this->x=x;
		this->y=y;
	}
	P operator + (const P &c) const {
		return P(x+c.x, y+c.y);
	}
	P operator - (const P &c) const {
		return P(x-c.x, y-c.y);
	}
	P operator * (const db &c) const {
		return P(x*c, y*c);
	}
	bool operator < (const P &c) const {
		int f=sign(x-c.x);
		return f?f<0:sign(y-c.y)<0;
	}
};
db norm(P a) {
	return a.x*a.x+a.y*a.y;
}
db abs(P a) {
	return sqrt(norm(a));
}
db dot(P a, P b) {
	return a.x*b.x+a.y*b.y;
} 
db ang(P a, P b) {
	db res = atan2(b.y-a.y, b.x-a.x);
	return res;
}
db dis(P a, P b) {
	return sqrt(norm(a-b));
}
P rot90(P p) {
	return P(-p.y, p.x);
}
struct C {
	P o;
	db r;
	C() {};
	C(P o, db r) : o(o), r(r) {}
};
bool isCC(C c1, C c2, P &p1, P &p2) {
	db x=norm(c1.o-c2.o), 
	y=((c1.r * c1.r - c2.r * c2.r) / x + 1) /2, 
	d=c1.r*c1.r/x-y*y;
	if(sign(d)<0) return 0;if(d<0) d=0;
	P q1=(c2.o-c1.o)*y+c1.o, q2=rot90((c2.o-c1.o)*sqrt(d));
	p1=q1-q2;
	p2=q1+q2;
	return 1;
} 
int relCC(C c1, C c2) {
	P p1=c1.o, p2=c2.o;
	db r1=c1.r, r2=c2.r;
	db d=dis(p1, p2);
	if(sign(d)==0&&sign(r1-r2)==0) return 0;
	int x=sign(d-r1-r2), y=sign(d-fabs(r1-r2));
	if(x==0) return 2;
	if(y==0) return 4;
	if(x>0) return 1;
	if(y<0) return 5;
	if(y>0&&x<0) return 3;
	return -1; 
} 

const int N=1010;
int n;
int pre[N];
bool ok[N];
C cr;
C c[N];

void print(P p) {
	dd(p.x);de(p.y);
}

inline db solve(int x) {
	vector<pair<db, int> > p;
	rep(y,1,n+1) if(x!=y) {
		P p1, p2;
		if(relCC(c[x], c[y])==3) {
			isCC(c[x], c[y], p1, p2);
			db st=ang(c[x].o, p1);
			db ed=ang(c[x].o, p2);
			db mid=ang(c[x].o, p1+p2);
			if(st>ed) swap(st, ed);
			if(sign(st-mid)<=0&&sign(mid-ed)<=0) {
				p.pb(mp(st, -1));
				p.pb(mp(ed, 1));
			} else {
				p.pb(mp(-pi, -1));
				p.pb(mp(st, 1));
				p.pb(mp(ed, -1));
				p.pb(mp(pi, 1));
			}
		}
	}
	db ans=0;
	sort(p.begin(), p.end());
	int now=0;
	double pre=-pi;
	rep(i,0,sz(p)) {
		if(!now) ans+=p[i].fi-pre;
		now-=p[i].se;
		pre=p[i].fi;
	}
	ans+=pi-pre;
	return ans*c[x].r;
}

int find(int x) {
	if(x==pre[x]) return x;
	return pre[x]=find(pre[x]);
}
void join(int x,int y) {
	int fx=find(x);
	int fy=find(y);
	pre[fx]=fy;
}

int main() {
	int T;scanf("%d",&T);
	while(T--) {
		///
		scanf("%d",&n);
		///init
		fill_n(ok, n+1, 1);
		rep(i,1,n+2) pre[i]=i;
		///read
		rep(i,1,n+1) {
			db x,y,r;scanf("%lf%lf%lf",&x,&y,&r);
			c[i]=C(P(x, y), r);
		}	
		db x,y,r;scanf("%lf%lf%lf",&x,&y,&r);
		cr=C(P(x, y), r);
		rep(i,1,n+1) c[i].r+=r;
		rep(i,1,n+1) if(relCC(cr, c[i])!=1) join(i, n+1);
		rep(i,1,n+1) rep(j,i+1,n+1) if(relCC(c[j], c[i])!=1) join(i, j);
		///solve
		db ans=0;
		rep(i,1,n+1) if(find(i)==find(n+1)) ans+=solve(i);
		printf("%.6f\n",ans/pi/r*180);
	} 
	return 0;
}
/*
2
1
0 0 1
-2 0 1
3
-1 0 1
1 0 1
1000 1000 1
-1 2 1
*/
