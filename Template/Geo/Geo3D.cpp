// didn't vertify
typedef double T;
const T eps = 1e-8;
int sgn(T x){return (x>eps)-(x<-eps);}
struct P{
  T x,y,z;P(){} P(T x,T y,T z):x(x),y(y),z(z){}
  P operator - (const P&b) const {return P(x-b.x,y-b.y,z-b.z);}
  P operator + (const P&b) const {return P(x+b.x,y+b.y,z+b.z);}
  P operator * (const T&k) const {return P(x*k,y*k,z*k);}
  P operator / (const T&k) const {return P(x/k,y/k,z/k);}
  T operator * (const P&b) const {return x*b.x+y*b.y+z*b.z;}
  P operator / (const P&b) const {return P(y*b.z-z*b.y,z*b.x-x*b.z,x*b.y-y*b.x);}
  bool operator < (const P&b) const {return tie(x,y,z)<tie(b.x,b.y,b.z);}
  bool operator == (const P&b) const {return sgn(x-b.x)==0&&sgn(y-b.y)==0&&sgn(z-b.z)==0;}
  T len() const {return sqrtl(x*x+y*y+z*z);}
};
T norm(P a){return a*a;}
P outC(P A,P B,P C){
  T d = 2 * norm((A-B)/(B-C));
  if(sgn(d) == 0) {
    if((B-A).len()<(C-A).len()) swap(B,C);
    if((B-A).len()<(C-B).len()) swap(A,C);
    return (A+B)/2;
  }
  T a = (A-B)*(A-C)*norm(B-C);
  T b = (B-C)*(B-A)*norm(C-A);
  T c = (C-A)*(C-B)*norm(A-B);
  return (A*a+B*b+C*c)/d;
}
T mix(P a,P b,P c){return a / b * c;}
T area(P a,P b,P c){return ((b - a) / (c - a)).len();}
namespace Convex{
  typedef tuple<int,int,int> F;
  const int N = 1010;
  int mark[N][N] , n , cnt;
  vector<F> face;// (p[a]-p[b])/(p[c]-p[b]) inward ?
  void build(vector<P> p){
    sort(all(p));p.erase(unique(all(p)),p.end());
    n = sz(p);
    random_shuffle(all(p));
    face.clear();
    auto volume = [&](int a,int b,int c,int d)
    {return mix(p[b]-p[a],p[c]-p[a],p[d]-p[a]);};
    auto insert = [&](int a,int b,int c)
    {face.pb(make_tuple(a,b,c));};
    auto find = [&](){
      rep(i,2,n){
        P dir = (p[0] - p[i]) / (p[1] - p[i]);
        if(dir == P(0 , 0 , 0)) continue;
        swap(p[i] , p[2]);
        rep(j,i+1,n) if(sgn(volume(0,1,2,j))) {
          swap(p[j],p[3]);
          insert(0,1,2);
          insert(0,2,1);
          return 1;
        }
      }
      return 0;
    };
    auto add = [&](int d){
      vector<F> tmp;
      int a, b, c;
      cnt++;
      for(auto f : face){
        tie(a , b , c) = f;
        if (sgn(volume(d, a, b, c)) < 0)
          mark[a][b] = mark[b][a] = mark[b][c] = mark[c][b]
            = mark[c][a] = mark[a][c] = cnt;
        else tmp.pb(f);
      }
      face = tmp;
      for(auto f : tmp){
        tie(a , b , c) = f;
        if (mark[a][b] == cnt) insert(b,a,d);
        if (mark[b][c] == cnt) insert(c,b,d);
        if (mark[c][a] == cnt) insert(a,c,d);
      }
    };
    if(find()){
      rep(i,0,n) memset(mark[i],0,sizeof(int)*n);
      cnt = 0;
      rep(i,3,n) add(i);
    }}}
struct L{ P a,b; L(){} L(P a,P b):a(a),b(b){}};
struct PL{
  P a,b,c;
  PL(){} PL(P a,P b,P c):a(a),b(b),c(c){}
  P pvec() {return (b-a)/(c-a);}
  T area() {return pvec().len();}
};
T dis(P a,P b){return (b-a).len();}
bool PonL(P a,L l) {return sgn(((l.b-l.a)/(a-l.a)).len())==0;}
bool PonS(P a,L l){
  return PonL(a,l) &&
    sgn((l.a.x-a.x)*(l.b.x-a.x)) <= 0 &&
    sgn((l.a.y-a.y)*(l.b.y-a.y)) <= 0 &&
    sgn((l.a.z-a.z)*(l.b.z-a.z)) <= 0;
}
bool PonPL(P a,PL s) {return sgn(s.pvec()*(a-s.a))==0;}
bool PonTri(P a,PL s){
  return sgn(s.area()-PL(a,s.a,s.b).area()-PL(a,s.b,s.c).area()-PL(a,s.c,s.a).area())==0;
}
bool PonPL(vector<P> p){ // distinct points
  int n=sz(p);
  if(n<4) return true;
  int c=-1;rep(i,2,n) if(!PonL(p[0],L(p[1],p[i]))) {c=i;break;}
  if(c==-1) return true;
  PL s(p[0],p[1],p[c]);
  rep(i,2,n) if(!PonPL(p[i],s)) return false;
  return true;
}
bool same_side(P a,P b,L l){ // coplanar, sgn(pvec()) to prove precision
  return sgn(PL(l.a,l.b,a).pvec()*PL(l.a,l.b,b).pvec()) > 0;
}
bool same_side(P a,P b,PL s){
  return sgn((s.pvec()*(a-s.a))*(s.pvec()*(b-s.a))) > 0;
}
bool opposite_side(P a,P b,L l){ // coplanar, sgn(pvec()) to prove precision
  return sgn(PL(l.a,l.b,a).pvec()*PL(l.a,l.b,b).pvec()) < 0;
}
bool opposite_side(P a,P b,PL s){
  return sgn((s.pvec()*(a-s.a))*(s.pvec()*(b-s.a))) < 0;
}
bool isSSr(L u,L v){
  return PonPL(u.a,PL(u.b,v.a,v.b)) &&
    opposite_side(u.a,u.b,v) && opposite_side(v.a,v.b,u);
}
bool isSS(L u,L v){
  if(!PonPL(u.a,PL(u.b,v.a,v.b))) return false;
  if(!PonL(u.a,v) || !PonL(u.b,v)) return isSSr(u,v);
  return PonS(u.a,v) || PonS(u.b,v) || PonS(v.a,u) || PonS(v.b,u);
}
bool isSTri(L l,PL s){ // can't coplanar
  return !same_side(l.a,l.b,s) && !same_side(s.a,s.b,PL(l.a,l.b,s.c)) &&
    !same_side(s.b,s.c,PL(l.a,l.b,s.a)) && !same_side(s.c,s.a,PL(l.a,l.b,s.b));
}
bool isSTrir(L l,PL s){
  return opposite_side(l.a,l.b,s) && opposite_side(s.a,s.b,PL(l.a,l.b,s.c)) &&
    opposite_side(s.b,s.c,PL(l.a,l.b,s.a)) && opposite_side(s.c,s.a,PL(l.a,l.b,s.b));
}
// | parallel , ^ perpendicular , & intersection
bool operator | (L a,L b) {return sgn(((a.b-a.a)/(b.b-b.a)).len())==0;}
bool operator ^ (L a,L b) {return sgn((a.b-a.a)*(b.b-b.a))==0;}
bool operator | (PL a,PL b) {return sgn((a.pvec()/b.pvec()).len())==0;}
bool operator ^ (PL a,PL b) {return sgn(a.pvec()*b.pvec())==0;}
bool operator | (L l,PL s) {return sgn(((l.b-l.a)/s.pvec()).len())==0;}
bool operator ^ (L l,PL s) {return sgn((l.b-l.a)*s.pvec())==0;}
P operator & (L a,L b) { // can't parallel
  P s = a.a - b.a , v = a.b - a.a , w = b.b - b.a;
  db k = (s / w) * (w / v) / ((w / v) * (w / v));
  return a.a + v * k;
}
P operator & (L l,PL s){ // can't parallel
  return l.a+(l.b-l.a)*((s.pvec()*(s.a-l.a))/(s.pvec()*(l.b-l.a)));
}
L operator & (PL s,PL t){ // can't parallel
  P a=L(s.a,(L(s.a,s.b)|t)?s.c:s.b)&t;
  return L(a,a+s.pvec()/t.pvec());
}
P PtoS(P a,L l){
  P b=l.a,c=l.b;
  rep(i,0,50) {
    P d=(b+c)*0.5,e=(d+c)*0.5;
    if(dis(a,d)<=dis(a,e)) b=e;
    else c=d;
  }
  return b;
}
// - distance , + projection
T operator - (P a,L l) {return ((a-l.a)/(l.b-l.a)).len() / dis(l.a,l.b);}
P operator + (P a,L l) {P s=l.a,d=l.b-l.a;return s+d*((a-s)*d/(d*d));}
T operator - (P a,PL s) {return fabs((a-s.a)*s.pvec()/s.pvec().len());}
P operator + (P a,PL s) {P d=s.pvec();return a+d*((s.a-a)*d/(d*d));}
T operator - (L u,L v) {P t=(u.b-u.a)/(v.b-v.a);return fabs((v.a-u.a)*t/t.len());}
P operator + (L a,L b) {return a & b;}
db angle(P a,P b) {return acos(max(-1.,min(1.,a*b/a.len()/b.len())));}
db angle(PL a,PL b) {return angle(a.pvec(),b.pvec());}
db angle(L l,PL s) {return asin(max(-1.,min(1.,(l.b-l.a)*s.pvec()/(l.b-l.a).len()/s.pvec().len())));}
struct SP{
  P o;T r;
  T dis(P a,P b){ return angle(a-o,b-o)*r;}
  P to(T lng,T lat){ return P(cos(lng)*cos(lat)*r,sin(lng)*cos(lat)*r,sin(lat)*r);}
};
vector<P> operator & (L l,SP sp){
  if(sgn((sp.o-l)-sp.r)>0) return vector<P>();
  P s=l.a,d=l.b-l.a;
  T A=d*d,B=(s-sp.o)*d*2,C=(s-sp.o)*(s-sp.o)-sp.r*sp.r;
  T delta=sqrt(max(0.,B*B-4*A*C)),k1=(-B-delta)/(2*A),k2=(-B+delta)/(2*A);
  return {s+d*k1,s+d*k2};
}
