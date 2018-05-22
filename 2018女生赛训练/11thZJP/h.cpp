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

const db eps=1e-8;
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
	db res = atan2(b.y-a.y, b.x-a.x)/pi*180;
	if(res<-180) res=-180;
	if(res>180) res=180;
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

const int N=1010;
int n;
pair<pii, int> a[N];
C cr;
C c[N];

inline ll dis(int i,int j) {
	int dx=a[i].fi.fi-a[j].fi.fi;
	int dy=a[i].fi.se-a[j].fi.se;
	return 1ll*dx*dx+1ll*dy*dy;
}
inline ll sqr(int x) {
	return 1ll*x*x;
}

inline db solve(int x) {
	vector<pair<db, int> > p;
	rep(y,1,n+1) if(x!=y) {
		P p1, p2;
		if(dis(x, y)==sqr(a[x].se+a[y].se)) {
			isCC(c[x], c[y], p1, p2);
			db st=ang(c[x].o, p1);
			db ed=ang(c[x].o, p2);
			db mid=ang(c[x].o, p1+p2);
			if(st>ed) swap(st, ed);
			if(sign(st-mid)<=0&&sign(mid-ed)<=0) {
				p.pb(mp(st, -1));
				p.pb(mp(ed, 1));
			} else {
				p.pb(mp(-180, -1));
				p.pb(mp(st, 1));
				p.pb(mp(ed, -1));
				p.pb(mp(180, 1));
			}
		}
	}
	db ans=0;
	sort(p.begin(), p.end());
	int now=0;
	double pre=-180;
	rep(i,0,sz(p)) {
		if(!now) ans+=p[i].fi-pre;
		now-=p[i].se;
		pre=p[i].fi;
	}
	ans+=180-pre;
	return ans;
}

int main() {
	int T;scanf("%d",&T);
	while(T--) {
		///
		scanf("%d",&n);
		///read
		rep(i,1,n+1) {
			int x,y,r;scanf("%d%d%d",&x,&y,&r);
			c[i]=C(P(x, y), r);
			a[i]=mp(mp(x, y), r);
		}	
		int x,y,r;scanf("%d%d%d",&x,&y,&r);
		cr=C(P(x, y), r);
		rep(i,1,n+1) c[i].r+=r, a[i].se+=r;
		///solve
		db ans=0;
		rep(i,1,n+1) ans+=solve(i);
		printf("%.6f\n",ans);
	} 
	return 0;
}

