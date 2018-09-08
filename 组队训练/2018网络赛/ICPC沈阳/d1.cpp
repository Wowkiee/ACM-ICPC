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

int n, m;
struct edge{
	int v1, v2, v;
}e[M];
struct node {
	int v;
	ll len;
};
queue<node> Q;

vector<ll> heap[N];
int F[N];

bool cmp(const edge &a, const edge &b) {
	return a.v1 < b.v1;
}
void Insert(int num, ll x) {
	heap[num].pb(x);
	std::push_heap(all(heap[num]));
}

int findkmin(int s, int t, int k, int n, int m, int T) {
	int i;
	node x, tmp;
	sort(e, e + m, cmp);
	memset(F, -1, sizeof(F));
	rep(i, 0, N) heap[i].clear();
	F[e[0].v1] = 0;
	for(i = 1; i < m; ++i) if(e[i].v1 != e[i-1].v1) F[e[i].v1] = i;
	tmp.v = s, tmp.len = 0;
	Q.push(tmp);
	ll cnt=0;
	while(!Q.empty()) {
		++cnt;
		x = Q.front(); Q.pop();
		for(i = F[x.v]; i != -1 && i < m && e[i].v1 == x.v; ++i) {
			tmp.v = e[i].v2;
			tmp.len = x.len + e[i].v;
			if(tmp.len > T) continue;
			if(heap[tmp.v].size() < k) {
				Insert(tmp.v, tmp.len);
				Q.push(tmp);
			} else if(tmp.len < heap[tmp.v][0]) {
				std::pop_heap(heap[tmp.v].begin(), heap[tmp.v].end());
				*(heap[tmp.v].rbegin()) = tmp.len;
				std::push_heap(heap[tmp.v].begin(), heap[tmp.v].end());
				Q.push(tmp);
			}
		}
	}
	de(cnt);
	std::sort_heap(heap[t].begin(), heap[t].end());
	if(heap[t].size() < k) return -1;
	return heap[t][k - 1];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	while(cin >> n >> m) {
		int st, ed, k, t;
		cin >> st >> ed >> k >> t;
		rep(i, 0, m) cin >> e[i].v1 >> e[i].v2 >> e[i].v, --e[i].v1, --e[i].v2;
		ll res = findkmin(st-1, ed-1, k, n, m, t);
		if(res == -1 || res > t) cout << "Whitesnake!" << endl;
		else cout << "yareyaredawa" << endl;
	}
	return 0;
}
