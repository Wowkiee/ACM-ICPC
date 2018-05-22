#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b-1);i>=(a);i--)
#define sz(x) (int)x.szie()
#define de(x) cout<<#x<<" = "<<x<<endl
#define dd(x) cout<<#x<<" = "<<x<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 50;

int n, m;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
struct Floyd{
	int n;
	int d[N][N];
	
	void init(int n) {
		this->n = n;
		memset(d, 0x3f, sizeof(d));
		rep(i, 1, n + 1) d[i][i] = 0;
		
	}
	
	void add(int from, int to, int dis) {
		d[from][to] = min(d[from][to], dis); 
	}
	
	void f() {
		rep(k, 1, n + 1) rep(i, 1, n + 1) rep(j, 1, n + 1) {
			d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
 		} 
	}
}FF;
int main() {
	
	int T;
	while(T--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, n + 1) scanf("%s", str[i] + 1);
		rep(i, 1, n + 1) {
			rep(j, 1, n + 1) {
				rep(k, 0, 4) {
				   x = i + dx[k];
				   y = j + dy[k];
				   if(isok(x, y)) {
				   	if(str[i][j] == str[x][y]) {
				   		add()
					   }
				   }
				}
			}
		}
		FF.init(n);
	}
	return 0;
}

