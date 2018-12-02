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
typedef pair<int, int> pii;
typedef vector<int> vi;
const int P = 1e9 + 7;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---

const int N = 1010, M = 10101;

int n, m, st, ed, k, T;
int cnt[N];
vector<pii> g[N];

bool spfa() {
	queue<pii> q;
	q.push(mp(st, 0));
	while(!q.empty() && cnt[ed] < k) {
		auto u = q.front(); q.pop();
		for(auto v : g[u.fi]) {
			int dis = u.se + v.se;
			if(dis > T) continue;
			if(v.fi == ed && cnt[ed] >= k - 1) {
				++cnt[ed];
				break;
			}
			++cnt[v.fi];
			if(cnt[v.fi] >= 2 * k) continue;
			q.push(mp(v.fi, dis));
		}
	}
	return cnt[ed] >= k;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	while(cin >> n >> m >> st >> ed >> k >> T) {
		rep(i, 1, n+1) g[i].clear(),cnt[i]=0;
		rep(i, 0, m) {
			int u, v, w;
			cin >> u >> v >> w;
			g[u].pb(mp(v, w));
		}
		if(spfa()) cout << "yareyaredawa" << endl;
		else cout << "Whitesnake!" << endl;
	}
	return 0;
}
