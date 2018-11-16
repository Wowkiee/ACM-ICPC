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
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
//----
const int N = 51;
typedef pair<pii, pii> ppp;
char s[N][N];
string step[N][N][N][N];
bool flag[N][N][N][N], flg[N * N];
int pos[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
char po[5] = "RLDU";
int n, m;
int dis[N * N];
vi V[N * N];
bool isok(int x, int y) {
	if(x < 1 || x > n)return false;
	if(y < 1 || y > m)return false;
	if(s[x][y] == '#')return false;
	return true;
}
int getid(int i, int j) {
	i--, j--;
	return i * m + j;
}
void dijkstra(int st, int ed) {
	memset(dis, -1, sizeof dis);
	queue<int> Q; Q.push(st); dis[st] = 0;flg[st] = true;
	while(!Q.empty()) {
		int f = Q.front(); Q.pop();
		rep(i, 0, sz(V[f])) {
			int nxt = V[f][i];
			if(flg[nxt])continue;
			dis[nxt] = dis[f] + 1; flg[nxt] = true;
			Q.push(nxt);
		}
	}
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m;
	rep(i, 1, n + 1)cin >> s[i] + 1;
	queue<ppp> Q;pii st,ed;
	rep(i, 1, n + 1)rep(j, 1, m + 1) {
		if(s[i][j] == 'S')st = mp(i, j), s[i][j] = '.';
		if(s[i][j] == 'F')ed = mp(i, j), s[i][j] = '.';
	}
	rep(i, 1, n + 1)rep(j, 1, m + 1)if(isok(i, j)) {
		Q.push(mp(mp(i, j), mp(i, j)));
		flag[i][j][i][j] = true;
	}
	rep(i, 1, n + 1)rep(j, 1, m + 1)rep(k, 0, 4)if(isok(i, j)) {
		int xx = i + pos[k][0];
		int yy = j + pos[k][1];
		if(!isok(xx,yy))continue;
		Q.push(mp(mp(i, j), mp(xx, yy)));
		flag[i][j][xx][yy] = true;
		step[i][j][xx][yy] += po[k];
	}
	while(!Q.empty()) {
		ppp f = Q.front(); Q.pop();
		if(sz(step[f.fi.fi][f.fi.se][f.se.fi][f.se.se]) >= 99)break;
		rep(i, 0, 4) {
			int x1 = f.fi.fi - pos[i][0];
			int y1 = f.fi.se - pos[i][1];
			int x2 = f.se.fi + pos[i][0];
			int y2 = f.se.se + pos[i][1];
			if(!isok(x1, y1) || !isok(x2, y2))continue;
			if(flag[x1][y1][x2][y2])continue;
			flag[x1][y1][x2][y2] = true;
			step[x1][y1][x2][y2] = po[i] + step[f.fi.fi][f.fi.se][f.se.fi][f.se.se] + po[i];
			Q.push(mp(mp(x1, y1), mp(x2, y2)));
		}
	}
	rep(i, 1, n + 1)rep(j, 1, m + 1)rep(ii, 1, n + 1)rep(jj, 1, m + 1)if(flag[i][j][ii][jj]) {
		int id1 = getid(i, j), id2 = getid(ii, jj);
		V[id1].pb(id2);
	}
	dijkstra(getid(ed.fi, ed.se), getid(st.fi, st.se));
	int ans = dis[getid(st.fi, st.se)];
	cout << ans << endl;
	if(ans != -1) {	
		int now = getid(st.fi, st.se);
		while(ans--) {
			rep(i, 0, sz(V[now])) {
				int nxt = V[now][i];
				if(dis[nxt] == ans) {
					cout << step[now / m + 1][now % m + 1][nxt / m + 1][nxt % m + 1] << endl;
					now = nxt;
					break;
				}
			}
		}
	}
	return 0;
}
