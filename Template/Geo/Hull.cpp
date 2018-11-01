typedef complex<ll> P;
typedef map<ll,P> hull;
#define X real()
#define Y imag()
ll cross(const P&a,const P&b){return (conj(a)*b).Y;}
struct Hull{
  hull h1,h2;
  bool in(hull&h,ll x,ll y){
    if(!sz(h)) return false;
    if(x < h.begin()->se.X || x > h.rbegin()->se.X) return false;
    auto l = h.lower_bound(x);
    if(x == l->se.X) return y <= l->se.Y;
    auto r = l--;
    return cross(r->se - l->se , P(x,y) - l->se) <= 0;
  }
  void ins(hull&h,ll x,ll y){
    if(in(h , x , y)) return;
    P p(x,y);h[x] = p;
    auto LL = h.find(x) , RR = LL , L = LL , R = L;
    if(L != h.begin()) for(--LL;(L = LL) != h.begin();){
      --(LL = L);
      if(cross(p - LL->se , L->se - LL->se) <= 0) h.erase(L);
      else break;
    }
    if(*R != *h.rbegin()) for(++RR;*(R = RR) != *h.rbegin();){
      ++(RR = R);
      if(cross(p - RR->se , R->se - RR->se) >= 0) h.erase(R);
      else break;
    }
  }
  void ins(ll x,ll y){ ins(h1,x,y);ins(h2,x,-y); }
  bool in(ll x,ll y){ return in(h1,x,y) && in(h2,x,-y); }
};
