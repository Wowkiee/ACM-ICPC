#include <iostream>
#include <vector>
#include <complex>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define sz(x) (int)(x).size()
namespace Geo{
    typedef double T;
    typedef complex<T> P;
    T dot(P a,P b){return (conj(a)*b).real();}
    T cross(P a,P b){return (conj(a)*b).imag();}
    T disq(P a,P b){return norm(a-b);}
    // able with integer above
    T dis(P a,P b){return abs(a-b);}
    T angle(P a,P b){return arg(b-a);}
    T angle(P a,P o,P b){return abs(remainder(arg(a-o)-arg(b-o),2.*M_PI));}
    P rot(P a,T theta){return a*polar(1.,theta);}
    P rot(P a,P o,T theta){return (a-o)*polar(1.,theta)+o;}
    P proj(P p,P v){return v*dot(p,v)/norm(v);}
    P proj(P p,P a,P b){return (b-a)*dot(p-a,b-a)/norm(b-a)+a;}
    P reflect(P p,P a,P b){return conj((p-a)/(b-a))*(b-a)+a;}
    P intersection(P a,P b,P p,P q){T c1=cross(p-a,b-a),c2=cross(q-a,b-a);
        return (c1*q-c2*p)/(c1-c2);}
}
using namespace Geo;
namespace NearestPoints{
    T Min;P tmp[100000];
    void Update(T disq) {Min = min(Min , disq);}
    T solve(int l,int r,P*p){
        if(l >= r) return 1e100;
        if(l + 1 == r){
            if(p[l].imag() > p[r].imag()) swap(p[l],p[r]);
            Update(disq(p[l],p[r]));
            return disq(p[l],p[r]);
        }
        int m=(l+r)>>1;
        T Xm = p[m].real() , lim = min(solve(l,m,p) , solve(m+1,r,p));
        int i=l,j=m+1,ii=m,jj=r,k=l;
        while(i<=ii&&j<=jj){
            while(i<=ii&&(j>jj||p[i].imag() <= p[j].imag())) tmp[k++] = p[i++];
            swap(i,j);swap(ii,jj);
        }
        vector<P> V;
        rep(i,l,r+1){
            p[i] = tmp[i];
            if(fabs(p[i].real() - Xm) <= lim) V.push_back(p[i]);
        }
        rep(i,0,sz(V)) rep(j,i+1,sz(V)){
            if(fabs(V[j].imag() - V[i].imag()) >= lim) break;
            T _dis = disq(V[i] , V[j]);
            Update(_dis);lim = min(lim,_dis);
        }
        return lim;
    }
    void ini(){Min = 1e100;}
}

int main(){
    return 0;
}
