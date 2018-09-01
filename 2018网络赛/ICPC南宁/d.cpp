#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

// ---
const db eps = 1e-8;
int sign(db x) {
	return (x > eps) - (x < -eps);
}
const int N=1005;
struct P {
	db x,y;
	P(){}
	P(db x,db y) {
		this->x=x;
		this->y=y;
	}
	P operator +(const P &c) const {
		return P(x+c.x, y+c.y);
	}
	P operator -(const P &c) const {
		return P(x-c.x,y-c.y);
	}
	P operator * (const db &c) const {
		return P(x * c, y * c);
	}
	P operator / (const db &c) const {
		return P(x / c, y / c);
	}
	bool operator == (const P &c) const {
		return !sign(x - c.x) && !sign(y - c.y);
	}
	bool operator != (const P &c) const {
		return !(*this == c);
	}
};
typedef P TPoint;
//55
struct TSegment {
	TPoint s, e;
};
//68
struct TPolygon {
	TPoint p[N];
	int n;
};
db cross(P a,P b) {
	return a.x*b.y-b.x*a.y;
}
//54
db cross(P a, P b, P c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
db cal(P a,P b,P p) {
	return fabs(cross(p-a,p-b));
}
db solve(vector<P> V) {
	int n=sz(V);
	P data[N<<1];
	rep(i,0,sz(V))data[i]=data[i+n]=V[i];
	db ans=0;
	rep(i,0,n)rep(j,i+1,n) {
		int l=i,r=j;
		while(l<r-1) {
			int mid=(l+r)/2,midd=mid+r>>1;
			if(cal(data[i],data[j],data[mid])<cal(data[i],data[j],data[midd]))l=mid;
			else r=midd;
		}
		ans=max(ans,max(cal(data[i],data[j],data[l]),cal(data[i],data[j],data[r])));
		l=j,r=i+n;
		while(l<r-1) {
			int mid=(l+r)/2,midd=mid+r>>1;
			if(cal(data[i],data[j],data[mid])<cal(data[i],data[j],data[midd]))l=mid;
			else r=midd;
		}
		ans=max(ans,max(cal(data[i],data[j],data[l]),cal(data[i],data[j],data[r])));
	}
	return ans;
}
// ---
//58
TSegment prep_mid_seg(TPoint a, TPoint b) {
	TSegment tmp;
	tmp.s.x = (a.x + b.x) * 0.5;
	tmp.s.y = (a.y + b.y) * 0.5;
	tmp.e.x = tmp.s.x - (a.y - b.y);
	tmp.e.y = tmp.s.y + (a.x - b.x);
	return tmp;
}
//61
void get_dis_parall(db offset, TSegment & a, TSegment & b, TSegment & c) {
	TSegment prep = prep_mid_seg(a.s, a.e);
	TPoint vec_p = prep.e - prep.s, tempp;
	db temp = sqrt(1.0 / (vec_p.x * vec_p.x + vec_p.y * vec_p.y)) * offset;
	tempp.x = temp * vec_p.x;
	tempp.y = temp * vec_p.y;
	b.s = a.s + tempp;
	b.e = a.e + tempp;
	c.s = a.s - tempp;
	c.e = a.e - tempp;
}
//59
TPoint seg_inter_pnt(TPoint & a, TPoint & b, TPoint & c, TPoint & d) {
	db s1 = cross(a, b, c), s2 = cross(a, b, d);
	TPoint tmp;
	tmp.x = (c.x * s2 - d.x * s1) / (s2 - s1);
	tmp.y = (c.y * s2 - d.y * s1) / (s2 - s1);
	return tmp;
}
//70
void cut_poly_by_side(TSegment seg, TPolygon & poly, int side = 1) {
	TPolygon new_poly; new_poly.n = 0;
	TPoint interp, dirt = seg.e - seg.s;
	int i, next, now = sign(cross(dirt, poly.p[0] - seg.e));
	for(i = 0; i < poly.n; ++i, now = next) {
		if(now == 0 || now == side) new_poly.p[new_poly.n++] = poly.p[i];
		next = sign(cross(dirt, poly.p[i+1] - seg.e));
		if(now * next < 0) {
			new_poly.p[new_poly.n++] = seg_inter_pnt(seg.s, seg.e, poly.p[i], poly.p[i+1]);
		}
	}
	poly.n = 0;
	if(new_poly.n == 0) return ;
	poly.p[poly.n++] = new_poly.p[0];
	for(i = 1; i < new_poly.n; ++i) {
		if(new_poly.p[i] != new_poly.p[i-1]) poly.p[poly.n++] = new_poly.p[i];
	}
	if(poly.p[poly.n-1] == poly.p[0]) poly.n--;
	poly.p[poly.n] = poly.p[0];
}

int n, r;
TPolygon tp;
P p[N];

void solve() {
	cin >> n >> r;
	rep(i, 0, n) cin >> p[i].x >> p[i].y;
	tp.n = n;
	rep(i, 0, n) tp.p[i] = p[i];
	tp.p[n] = p[0];
	rep(i, 0, n) {
		TSegment ts, t1, t2;
		ts.s = p[i];
		ts.e = p[(i+1) % n];
		get_dis_parall(r, ts, t1, t2);
		cut_poly_by_side(t1, tp, -1);
		cut_poly_by_side(t2, tp, -1);
	}
	vector<P> v;
	rep(i, 0, tp.n) v.pb(tp.p[i]);
	cout << setiosflags(ios::fixed);
	cout << setprecision(4);
	cout << solve(v) << endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
	return 0;
}
