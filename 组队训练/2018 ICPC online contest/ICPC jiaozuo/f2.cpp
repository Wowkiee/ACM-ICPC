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
typedef int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---
const int N=100005;
int l[N],r[N],data[N];
vector<int> V;
//----

const int inf = 1e9 + 7;

template <class U, class V> 
struct ZKW{
	static const int N = 1010, M = 40040;
	int h[N], ing[N], v[N], to[M], ne[M], e, s, t, n;
	U cap[M]; V dis[N], cost[M];
	void ini(int _n = N) {fill(h, h + (n = _n), -1); e = 0;}
	void liu(int u, int v, U c, V w) {to[e] = v; ne[e] = h[u];cap[e] = c; cost[e] = w; h[u] = e++;}
	void link(int u, int v, U c, V w) {liu(u, v, c, w);liu(v, u, 0, -w);}
	void spfa() {
		queue<int> Q;
		fill(dis, dis+n, inf);
		ing[t] = 1, dis[t] =0;
		Q.push(t);
		while (!Q.empty()) {
			int c = Q.front();Q.pop();ing[c] = 0;
			for(int k = h[c]; ~k; k = ne[k]) {
				int v = to[k];
				if(cap[k^1] <= 0) continue;
				if (dis[c] + cost[k ^ 1] < dis[v]) {
					dis[v] = dis[c] + cost[k ^ 1];
					if (!ing[v]) Q.push(v), ing[v] = 1;
				}
			}
		}
	}
	U flow; V mincost;
	bool modlable() {
		V Min = inf;
		rep(c, 0, n) if (v[c]) 
			for (int k = h[c]; ~k; k = ne[k]) {
				int t = to[k];
				if (!v[t] && cap[k] > 0) 
						Min = min(Min, dis[t] + cost[k] - dis[c]);
			}
		//if (Min >= 0) return 0;
		if (Min == inf) return 0;
		rep(i, 0, n) if (v[i]) dis[i] += Min;
		return 1;
	}
	U dfs(int c, U mx) {
		if (c == t) return flow += mx, mincost += mx * dis[s], mx;
		v[c] = 1; U ret = 0;
		for (int k = h[c]; ~k; k = ne[k]) {
			int t = to[k];
			if (!v[t] && cap[k] > 0 && dis[c] - cost[k] == dis[t]) {
				U tmp = dfs(t, min(cap[k], mx - ret));
				cap[k] -= tmp, cap[k ^ 1] += tmp;
				ret += tmp;
				if (ret == mx) return ret;
			}
		}
		return ret;
	}
	pair<U, V> run(int _s, int _t) {
		s = _s, t = _t;
		spfa();
		flow = mincost = 0;
		do do memset(v, 0, sizeof(v[0]) * n);
			while (dfs(s, inf));
		while(modlable());
		return mp(flow, mincost);
	}
};

ZKW<int, int> G;

int main() {
	int T;scanf("%d",&T);
	while(T--) {
		int n,k,m;scanf("%d%d%d",&n,&k,&m);
		V.clear();
		rep(i,0,m)scanf("%d%d%d",&l[i],&r[i],&data[i]),V.pb(l[i]);
		V.pb(0),V.pb(n+1);
		sort(all(V));V.erase(unique(all(V)),V.end());
		n=sz(V);
		G.ini(n);
		rep(i,1,n)G.link(i-1,i,k,0);
		rep(i,0,m) {
			l[i]=lower_bound(all(V),l[i])-V.begin();
			r[i]=upper_bound(all(V),r[i])-V.begin();
			G.link(l[i],r[i],1,-data[i]);
		}
		cout<<-G.run(0,n-1).se<<endl;
	}
	return 0;
}
