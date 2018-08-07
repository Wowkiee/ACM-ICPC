#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b-1);i>=a;i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef unsigned uint;
//---
const int N=5e6+7;
uint x,y,z;
uint RNG61() {
	x^=x<<11;
	x^=x>>4;
	x^=x<<5;
	x^=x>>14;
	uint w=x^(y^z);
	x=y;
	y=z;
	z=w;
	return z;
}
struct Upd {
	uint l,r,v;
	bool operator < (Upd &a) {
		return v<a.v;
	}
	bool operator <= (Upd &a) {
		return v<=a.v;
	}
}data[N], tmp[N];
ll val[100005];
set<int> S;
set<int>::iterator it;
void update(int l,int r,int Val) {
	for(it=S.lower_bound(l);it!=S.end()&&*it<=r;) {
		val[*it]=Val;S.erase(it++);
	}
}
int main() {
	/*
	int tt[] = {0, 9,8,7,6,1,4,3,2,5};
	nth_element(tt, tt+7, tt+10);
	rep(i, 0, 10) dd(i), de(tt[i]);
	return 0;
	*/
	int T;scanf("%d",&T);while(T--) {
		S.clear();
		int n,m;scanf("%d%d%u%u%u",&n,&m,&x,&y,&z);
		rep(i,1,n+1)S.insert(i);
		rep(i,1,m+1) {
			data[i].l=RNG61()%n+1,data[i].r=RNG61()%n+1,data[i].v=RNG61()%(1<<30);
			if(data[i].l>data[i].r)swap(data[i].l,data[i].r);
		}
		//nth_element(tt,tt+2,tt+9);
		int t = min(n*3, m);
		nth_element(data+1,data+m+1-t,data+m+1);
		Upd a=*(data+m+1-t);
		int cnt = 0;
		rep(i,1,m+1)if(a<=data[i]) tmp[++cnt] = data[i];
		sort(tmp+1, tmp+1+cnt);
		for(int i = cnt; i; --i) update(tmp[i].l, tmp[i].r, tmp[i].v);
//		de(cnt);
		ll ans=0;
		rep(i,1,n+1)ans^=i*val[i];
		cout<<ans<<endl;
	}
	return 0;
}
