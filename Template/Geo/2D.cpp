/*
 *ŷ������ ƽ��ͼ���� V+F-E=2
 *ֱ�ߵ�һ��ʽ�� Ax+By+C=0
 *�㵽ֱ�ߵľ��룺 |Ax0+By0+C|/sqrt(A*A+B*B)
*/
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define sz(a) (int)a.size()
#define de(x) cout << #x << " = " << x << endl;
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define x(a) a.x
#define y(a) a.y
typedef double db;
const db eps = 1e-8;
const db pi = acos(-1);

//���� -1 ��  0 ����  1
int sign(db x) {
    return (x > eps) - (x < -eps);
}

struct P {
    db x,y;
    P() {}
    P(db x, db y) {
        this->x = x;
        this->y = y;
    }
    P operator + (const P &c) const {
        return P(x + c.x, y + c.y);
    }
    P operator - (const P &c) const {
        return P(x - c.x, y - c.y);
    }
    P operator * (const db &c) const {
        return P(x * c, y * c);
    }
    P operator / (const db &c) const {
        return P(x / c, y / c);
    }
    bool operator < (const P &c) const {
        int f = sign(x - c.x);
        return f ? f < 0 : sign(y - c.y) < 0;
    }
    bool operator == (const P &c) const {
        return !sign(x - c.x) && !sign(y - c.y);
    }
    bool operator != (const P &c) const {
        return !(*this == c);
    }
    bool operator > (const P &c) const {
        return !(*this == c) && !(*this < c);
    }
};

P read() {
    db x,y;scanf("%lf%lf", &x, &y);
    return P(x, y);
}
void print(P p) {
	printf("%f %f\n",x(p),y(p));
}
db abs(P a) {
    return sqrt(x(a) * x(a) + y(a) * y(a));
}
db norm(P a) {
    return x(a) * x(a) + y(a) * y(a);
}
db dot(P a, P b) {
    return x(a) * x(b) + y(a) * y(b);
}
db cross(P a, P b) {
    return x(a) * y(b) - x(b) * y(a);
}
// ��������ƽ��
db disq(P a, P b) {
    return norm(a - b);
}
// �������
db dis(P a, P b) {
    return sqrt(norm(a - b));
}
// ���� ab �� x ��ļнǣ����ȣ�ȡֵ��Χ (-pi, pi]
db ang(P a, P b) {
    return atan2(y(b)-y(a),x(b)-x(a));
}
// ���� oa�� ob�ļнǣ����ȣ�ȡֵ��Χ [0, pi]
db ang(P a, P o, P b) {
    return acos(dot(a - o, b - o) / abs(a - o) / abs(b - o));
}
// ������ʱ����ת rad�����ȣ�
P rot(P a, db rad) {
    return P(x(a) * cos(rad) - y(a) * sin(rad), x(a) * sin(rad) + y(a) * cos(rad));
}
P rot(P a, P o, db rad) {
    return rot(a - o, rad) + o;
}
// ��ʱ����ת 90��
P rot90(P p) {
    return P(-y(p), x(p));
}
// ���� p������ v�����ϵ�ͶӰ���㣩
P proj(P p, P v) {
    return v * dot(p, v) / norm(v);
}
// ���� ap������ ab�����ϵ�ͶӰ���㣩
P proj(P p, P a, P b) {
    return proj(p - a, b - a) + a;
}
// p���ڹ��� ab�ĶԳƵ�
P reflect(P p, P a, P b) {
    P o = proj(p, a, b);
    return o * 2 - p;
}
// ֱ�� pv�� qw�Ľ���
P insLL(P p, P v, P q, P w) {
    P u = p - q;
    v = v - p;
    w = w - q;
    db t = cross(w, u) / cross(v, w);
    return p + v * t;
}
// �жϵ��Ƿ����߶��ϣ��������˵㣩
bool onS0(P p, P a, P b) {
    return sign(cross(p - a, b - a)) == 0 && sign(dot(p - a, p - b)) < 0;
}
// �жϵ��Ƿ����߶��ϣ������˵㣩
bool onS1(P p, P a, P b) {
    return sign(cross(p - a, b - a)) == 0 && sign(dot(p - a, p - b)) <= 0;
}
// �ж���ֱ���Ƿ��ཻ
bool isLL(P a1, P a2, P b1, P b2) {
	return sign(cross(a2 - a1, b2 - b1)) != 0;
}
// �ж��߶��Ƿ�淶�ཻ�����㲻����һ���˵��ϣ�
bool isSS0(P a1, P a2, P b1, P b2) {
    db c1 = cross(a2 - a1, b1 - a1), c2 = cross(a2 - a1, b2 - a1),
       c3 = cross(b2 - b1, a1 - b1), c4 = cross(b2 - b1, a2 - b1);
    return sign(c1) * sign(c2) < 0 && sign(c3) * sign(c4) < 0;
}
// �ж��߶��Ƿ񲻹淶�ཻ
bool isSS1(P a1, P a2, P b1, P b2) {
    db c1 = cross(a2 - a1, b1 - a1), c2 = cross(a2 - a1, b2 - a1),
       c3 = cross(b2 - b1, a1 - b1), c4 = cross(b2 - b1, a2 - b1);
	return sign(max(x(a1), x(a2)) - min(x(b1), x(b2))) >= 0 &&
		   sign(max(x(b1), x(b2)) - min(x(a1), x(a2))) >= 0 &&
		   sign(max(y(a1), y(a2)) - min(y(b1), y(b2))) >= 0 &&
		   sign(max(y(b1), y(b2)) - min(y(a1), y(a2))) >= 0 &&
		   sign(c1) * sign(c2) <= 0 && sign(c3) * sign(c4) <= 0;
}
// �ж�ֱ���߶��Ƿ��ཻ���˵�Ҳ�㣩
bool isLS(P a1, P a2, P b1, P b2) {
    db c1 = cross(a2 - a1, b1 - a1), c2 = cross(a2 - a1, b2 - a1);
    return sign(c1) * sign(c2) <= 0;
}
// �㵽ֱ�߾���
db distoL(P p, P a, P b) {
    return fabs(cross(b - a, p - a)) / abs(b - a);
}
// �㵽�߶ξ���
db distoS(P p, P a, P b) {
    if(sign(dot(b - a, p - a)) < 0) return abs(p - a);
    if(sign(dot(a - b, p - b)) < 0) return abs(p - b);
    return distoL(p, a, b);
}
// ֱ������ʽתһ��ʽ
// ֱ�ߵ�һ��ʽ�� Ax+By+C=0
void getLABC(P a, P b, db &A, db &B, db &C) {
    A = y(a) - y(b);
	B = x(b) - x(a);
	C = x(a) * y(b) - y(a) * x(b);
}
// ��������
db areaP(P *p, int n) {
	db ans = 0;p[n] = p[0];
	rep(i, 0, n) ans += cross(p[i], p[i+1]);
	return fabs(ans) / 2;
}
// �жϵ�Ͷ���ι�ϵ ���� -1 �� 0 �� 1 
int Pinploy(P o, P *p, int n) {
	int res = 0;
	rep(i, 0, n) {
		P u = p[i], v = p[(i + 1) % n];
		if(onS1(o, u, v)) return -1;
		int k = sign(cross(v - u, o - u));
		int d1 = sign(y(u) - y(o));
		int d2 = sign(y(v) - y(o));
		if(k > 0 && d1 <= 0 && d2 > 0) ++res;
		if(k < 0 && d2 <= 0 && d1 > 0) --res;
	}
	return res != 0;
}
// ��͹�����Ѹ������Χ���ڲ��ģ������С��͹�����
// ���Ӷȣ� O(n) �������� O(nlogn)
// ����ĵ�Ҫ��ȥ��
// �����ϣ����͹���ı���������㣬������ <= �ĳ� <
int convexhull(P *p, int n, P *ch) {
	sort(p, p + n);
	int m = 0;
	rep(i, 0, n) {
		while(m > 1 && sign(cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2])) <= 0) --m;
		ch[m++] = p[i];
	}
	int k = m;
	for(int i = n - 2; i >= 0; --i) {
		while(m > k && sign(cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2])) <= 0) --m;
		ch[m++] = p[i];
	}
	if(n > 1) --m;
	return m;
}

struct C {
	P o;
	db r;
	C() {}
	C(P o, db r) : o(o), r(r) {}
	// ͨ��Բ�Ľǣ����ȣ���Բ������
	P point(db rad) {
		return P(o.x + cos(rad) * r, o.y + sin(rad) * r);
	}
};
// �жϡ�����Բ����
bool isLC(C c, P a, P b, P &p1, P &p2) {
	db x = dot(a - c.o, b - a), y = norm(b - a),
	   d = x * x - y * (norm(a - c.o) - c.r * c.r);
	if(sign(d) < 0) return 0; if(d < 0) d = 0;
	P q1 = a - (b - a) * (x / y),
	  q2 = (b - a) * (sqrt(d) / y);
	p1 = q1 - q2;
	p2 = q1 + q2;
	return 1;
}
// �ж���Բ��ϵ
// ��� 0 ���� 1 ���� 2 �ཻ 3 ���� 4 �ں� 5
int relCC(C c1, C c2) {
	P p1 = c1.o, p2 = c2.o;
	db r1 = c1.r, r2 = c2.r;
	db d = dis(p1, p2);
	if(sign(d) == 0 && sign(r1 - r2) == 0) return 0;
	int x = sign(d - r1 - r2), y = sign(d - fabs(r1 - r2));
	if(x == 0) return 2;
	if(y == 0) return 4;
	if(x > 0) return 1;
	if(y < 0) return 5;
	if(y > 0 && x < 0) return 3;
	return -1;
}
// ����ֵ��ʾ�Ƿ��н���
// ��ԲԲ����
bool isCC(C c1, C c2, P &p1, P &p2) {
	db x = norm(c1.o - c2.o),
	   y = ((c1.r * c1.r - c2.r * c2.r) / x + 1) / 2,
	   d = c1.r * c1.r / x - y * y;
	if(sign(d) < 0) return 0; if(d < 0) d = 0;
	P q1 = (c2.o - c1.o) * y + c1.o,
	  q2 = rot90((c2.o - c1.o) * sqrt(d));
	p1 = q1 - q2;
	p2 = q1 + q2;
	return 1;
}
// ���Բ�е�
vector<P> tanCP(P p, C c, P &p1, P &p2) {
	db x = norm(p - c.o), d = x - c.r * c.r;
	vector<P> ans;
	if(sign(d) < 0) return ans; if(d < 0) d = 0;
	P q1 = (p - c.o) * (c.r * c.r / x),
	  q2 = rot90((p - c.o) * (-c.r * sqrt(d) / x));
	p1 = c.o + q1 - q2;
	p2 = c.o + q1 + q2;
	ans.pb(p1);ans.pb(p2);
	return ans;
}
// ��ԲԲ����
vector<pair<P, P> > tanCC(C c1, C c2) {
	vector<pair<P, P> > ans;
	if(!sign(c1.r - c2.r)) {
		P dir = c2.o - c1.o;
		dir = rot90(dir * (c1.r / abs(dir)));
		ans.pb(mp(c1.o + dir, c2.o + dir));
		ans.pb(mp(c1.o - dir, c2.o - dir));
	} else {
		P p = (c1.o * (-c2.r) + c2.o * c1.r) / (c1.r - c2.r);
		P t1,t2;
		vector<P> ps = tanCP(p, c1, t1, t2);
		vector<P> qs = tanCP(p, c2, t1, t2);
		for (int i = 0; i < sz(ps) && i < sz(qs); ++i) {
			if(!i || !(ps[i] == ps[i-1] && qs[i] == qs[i-1]))
				ans.pb(mp(ps[i],qs[i]));
		}
	}
	P p = (c1.o * c2.r + c2.o * c1.r) / (c1.r + c2.r);
	P t1,t2;
	vector<P> ps = tanCP(p, c1, t1, t2);
	vector<P> qs = tanCP(p, c2, t1, t2);
	for (int i = 0; i < sz(ps) && i < sz(qs); ++i) {
		if(!i || !(ps[i] == ps[i-1] && qs[i] == qs[i-1]))
			ans.pb(mp(ps[i],qs[i]));
	}
	return ans;
}
// Բ�����
db areaCC(C c1, C c2) {
	db d = abs(c1.o - c2.o);
	if(sign(c1.r + c2.r - d) <= 0) return 0;
	if(sign(d - fabs(c1.r - c2.r)) <= 0) {
		db r = min(c1.r, c2.r);
		return r*r*pi;
	}
	db x = (d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d);
	db t1 = acos(x / c1.r);
	db t2 = acos((d - x) / c2.r);
	return c1.r * c1.r * t1 + c2.r * c2.r * t2 - d * c1.r * sin(t1);
}
// Բ�����������
// Բ���뾶�� r Բ�ģ�ԭ��
// �����Σ�Բ�ġ� p1�� p2
db areaCT(db r, P p1, P p2) {
	P q1, q2, o = P(0, 0);
	C c = C(o, r);
	int f = isLC(c, p1, p2, q1, q2);
	if(!f) return r * r * ang(p1, o, p2) / 2;
	bool b1 = sign(abs(p1) - r) > 0;
	bool b2 = sign(abs(p2) - r) > 0;
	if(b1 && b2) {
		if(sign(dot(p1 - q1, p2 - q1)) <= 0 && sign(dot(p1 - q2, p2 - q2)) <= 0) {
			return (r * r * (ang(p1, o, p2) - ang(q1, o, q2))) + fabs(cross(q1, q2)) / 2;
		} else {
			return r * r * ang(p1, o, p2) / 2;
		}
	} else if(b1) {
		return (r * r * ang(p1, o, q1) ) + fabs(cross(q1, p2)) / 2;
	} else if(b2) {
		return (r * r * ang(q2, o, p2) ) + fabs(cross(p1, q2)) / 2;
	} else {
		return fabs(cross(p1, p2)) / 2;
	}
}
// ����������
P inC(P A, P B, P C) {
	db a = abs(B - C);
	db b = abs(A - C);
	db c = abs(A - B);
	return (A * a + B * b + C * c) / (a + b + c);
}
// ����������
P outC(P A, P B, P C) {
	P b = B - A, c = C - A;
	db db = norm(b), dc = norm(c), d = 2 * cross(b, c);
	return A - P(y(b) * dc - y(c) * db, x(c) * db - x(b) * dc) / d;
}
// �����δ���
P othroC(P A, P B, P C) {
	P ba = B - A, ca = C - A, bc = B - C;
	db Y = y(ba) * y(ca) * y(bc);
	db a = cross(ca, ba);
	db xx = (Y + x(ca) * y(ba) * x(B) - x(ba) * y(ca) * x(C)) / a;
	db yy = -x(ba) * (xx - x(C)) / y(ba) + y(ca);
	return P(xx, yy);
}
// ��СԲ����  O(n)
void Mincir(P *p, int n){
	random_shuffle(p, p+n);
	P cir = p[0]; db r= 0;
	for(int i = 1; i < n; i++){
		if(sign(dis(cir, p[i]) - r) <= 0) continue;
		cir = p[i], r = 0;
		for(int j = 0; j < i; j++){
			if(sign(dis(cir, p[j]) - r) <= 0) continue;
			cir = P ((x(p[i]) + x(p[j])) / 2, (y(p[i]) + y(p[j])) / 2);
			r = dis(cir, p[j]);
			for(int k = 0; k < j; k++){
				if(sign(dis(cir, p[k]) - r) <= 0) continue;
				cir = outC(p[i], p[j], p[k]);
				r = dis(cir, p[k]);
			}
		}
	}
	printf("%.2f %.2f %.2f\n", x(cir), y(cir), r);
}
// ��ƽ�潻 δ���� 
const int N=450005;
struct Seg{
	P s, e;
	double r;
	void getr(){r = atan2(y(e)-y(s), x(e)-x(s));}
	bool operator < (const Seg& c)const {
		int d = sign(r - c.r);
		if (!d) return sign(cross(c.s - s, c.e -s)) > 0;
		return d < 0;
	}
}seg[N], Q[N];
int sz;
P insLL(Seg a, Seg b){return insLL(a.s,a.e,b.s,b.e);}
void add_seg(db xa, db ya, db xb, db yb){
	seg[sz].s=P(xa,ya);seg[sz].e=P(xb,yb);
	seg[sz].getr();sz++; 
}
int hpi(P *p){
	sort(seg, seg+sz);
	int tmp=1;
	for(int i=1; i<sz; i++)
		if(sign(seg[i].r-seg[tmp-1].r))
			seg[tmp++]=seg[i];
	sz=tmp; Q[0]=seg[0];Q[1]=seg[1];
	int h=0,r=1;
	for(int i=2; i<sz; i++){
		while(h<r&&sign(cross(seg[i].e-seg[i].s,insLL(Q[r],Q[r-1])-seg[i].s))<=0) r--;
		while(h<r&&sign(cross(seg[i].e-seg[i].s,insLL(Q[h],Q[h+1])-seg[i].s))<=0) h++;
		Q[++r]=seg[i];
	}
	while(h<r&&sign(cross(Q[h].e-Q[h].s,insLL(Q[r],Q[r-1])-Q[h].s))<=0)r--;
	while(h<r&&sign(cross(Q[r].e-Q[r].s,insLL(Q[h],Q[h+1])-Q[r].s))<=0)h++;
	if(h+1>=r) return 0;
	int m=0;
	for(int i=h;i<r;i++)p[m++]=insLL(Q[i], Q[i+1]);
	if(r>h+1)p[m++]=insLL(Q[h], Q[r]);
	return m;
}
// Բ����� k
struct Event{
	P p;
	db ang;
	int delta;
	Event() {}
	Event (P p = P(0, 0), db ang = 0, int delta = 0):p(p), ang(ang), delta(delta){}
	bool operator <(const Event& c) const {return ang < c.ang;} 
};
db sqr(db x) {return x*x;}
void addEvent(C a, C b, vector<Event> &evt, int&cnt){
	db d2=norm(a.o - b.o),
	dRatio=((a.r - b.r) * (a.r + b.r)/d2+1)/2, 
	pRatio=sqrt(-(d2-sqr(a.r-b.r))*(d2-sqr(a.r+b.r))/(d2*d2*4));
	P d=b.o-a.o, p=rot(d, pi/2),
	  q0=a.o+d*dRatio+p*pRatio,
	  q1=a.o+d*dRatio-p*pRatio;
	db ang0 = ang(a.o, q0), ang1=ang(a.o, q1);
	evt.pb(Event(q1, ang1, 1));evt.pb(Event(q0, ang0, -1));
	cnt += ang1>ang0; 
}
bool issame(C a, C b){return !sign(abs(a.o - b.o))&&!sign(a.r-b.r);}
bool overlap(C a, C b){return sign(a.r-b.r-abs(a.o-b.o))>=0;}
bool intersect(C a, C b){return sign(abs(a.o-b.o) - a.r - b.r) < 0;}
void solve(C *c, int n, db *ans){
	memset(ans, 0, sizeof(db) * (n+2));
	for(int i=0; i<n; i++){
		int cnt=1;
		vector<Event> evt;
		for(int j=0; j<i; j++) if(issame(c[i], c[j])) ++cnt;
		for(int j=0; j<n; j++)
			if(j != i && !issame(c[i], c[j]) && overlap(c[j], c[i]))
				cnt++;
		for(int j=0; j<n; j++)
			if(j!=i&&!overlap(c[j], c[i])&& !overlap(c[i], c[j])&&intersect(c[i], c[j]))
			addEvent(c[i], c[j], evt, cnt);
		if(!sz(evt))ans[cnt]+=pi*c[i].r*c[i].r;
		else{
			sort(evt.begin(), evt.end());
			evt.pb(evt.front());
			for(int j=0; j+1<sz(evt); j++){
				cnt+=evt[j].delta;
				ans[cnt]+=cross(evt[j].p, evt[j+1].p)/2;
				db ang=evt[j+1].ang-evt[j].ang;
				if(ang<0)ang+=pi*2;
				ans[cnt]+=ang*c[i].r*c[i].r/2-sin(ang)*c[i].r*c[i].r/2;
			}
		}
	}
}
int n;
const int MAXN=101010;
P p[MAXN], p2[MAXN];
int main() {
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		rep(i, 0, n){
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}
		rep(i, 0, n-1){
			add_seg(p[i].x, p[i].y, p[i+1].x, p[i+1].y);
		}
		add_seg(p[n-1].x, p[n-1].y, p[0].x, p[0].y);
		int n2=hpi(p2); 
		printf("%.2f\n", areaP(p2, n2)); 
	}
    return 0;
}
