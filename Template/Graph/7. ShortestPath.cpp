// Floyd
// id starts from 1
// 可以处理负权边，但判不了负环
const int N=111;
int n, dis[N][N];
void Floyd() {
	rep(i, 1, n + 1) {
		rep(j, 1, n + 1) dis[i][j] = inf;
		dis[i][i] = 0;
	}
	// todo: load edge
	rep(k, 1, n + 1) rep(i, 1, n + 1) rep(j, 1, n + 1) dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

// Dijkstra
// id starts from 1
// 不能处理负权边
const int N=101010;
int n, dis[N];
void Dijkstra(int st) {
	priority_queue<pii> q;
	rep(i, 1, n + 1) dis[i] = inf;
	dis[st] = 0;
	q.push(mp(0, st));
	while(!q.empty()) {
		pii u = q.top();q.pop();
		if(dis[u.se] != -u.fi) continue;
		for(auto v : g[u.se]) {
			if(dis[v.fi] > dis[u.se] + v.se) {
				dis[v.fi] = dis[u.se] + v.se;
				q.push(mp(-dis[v.fi], v.fi));
			}
		}
	}
}

// SPFA
// 在网格图中会退化，如果边权非负最好使用 Dijkstra
