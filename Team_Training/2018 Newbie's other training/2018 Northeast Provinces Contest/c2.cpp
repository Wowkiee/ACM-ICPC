#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define endl "\n"
#define pw(a) (1ll << (a))
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;

const int N = 2e5 + 7;
int dis, n, a[N], b[N], pos[N], vis[N], op[N], fa[N], len, x, d[N], ans,  m, w, tim, id[N], l[N];
vi c[N];
ll vv;

int cnt[200][N];

int ne(int x) {
	if (x <= n) return x * 2 - 1;
	else return (x - n) * 2;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	//for(n = 100000; n >= 100000; n --){
	//n = 100000;
	srand(time(0));
	rep(i, 1, n * 2 + 1) cin >> a[i];
	rep(i, 1, n * 2 + 1) cin >> b[i];
	//rep(i, 1, n * 2 + 1) a[i] = i;
	//rep(i, 1, n * 2 + 1) b[ne(i)] = i, vis[i] = 0;
	//rep(i, 1, m+1) c[i].clear();
	//m = 0;tim = 0;
	
//	random_shuffle(a+1, a + 2 * n + 1);
//	random_shuffle(b+1, b + 2 * n + 1);
	//rep(i, 1, n*2 + 1) cout << a[i] << " ";
	rep(i, 1, n * 2 + 1) pos[b[i]] = i;
	rep(i, 1, n * 2 + 1) op[i] = pos[a[i]];
	rep(i, 1, n * 2 + 1) if (vis[i] == 0){
		x = i;vis[x] = 1;c[++m].pb(x); fa[x] = m; d[x] = 0, w = 0;
		while (1) {
			x = ne(x);w++;
			//dd(i);de(x);
			if(x == i) break;
			c[m].pb(x);d[x] = w; fa[x] = m;
			vis[x] = 1;
		}
	}
	set<int> s;
	rep(i, 1, m+1) s.insert(sz(c[i]));
	for (auto t : s) id[t] = tim++, l[tim-1] = t;
	rep(i, 1, n * 2 + 1) {
		if (fa[i] == fa[op[i]]) {
			len = sz(c[fa[i]]);
			//de(len);
			if (d[i] <= d[op[i]]) dis = d[op[i]] - d[i];
			else dis = len - d[i] + d[op[i]];
			cnt[id[len]][dis]++;
			//assert(dis < len); 
			//while (dis <= n * 2) cnt[dis]++, dis += len;
		}
	}
	//ll val = 0;
	//rep(i, 1, m+1) val += n * 2 / sz(c[i]);
	ans = pw(30);
	//vv = max((ll)sz(s), vv);
	rep(i, 0, n * 2 + 1) {
		int tmp = 0;

		rep(j, 0, tim) tmp += cnt[j][i % l[j]];
		ans = min(ans, i + n * 2 - tmp);
	
	}
	//dd(n);dd(m);de(vv);
	cout << ans << endl;
//	}
	return 0;
}
