#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(a) cout << #a << " = " << a << " "
#define de(a) cout << #a << " = " << a << endl
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;
//----
const db EPS = 1e-8;
const db DINF = 1e15;
const int MAXA = 70000;
const int N = 55;
struct Simplex {
	const static int MAXN = 3000;
	int n, m, B[MAXN], N[MAXN];
	db v, ans[MAXN], b[MAXN], c[MAXN], A[MAXN][MAXN];
	void init(int _n, int _m) {
		n = _n, m = _m, v = 0;
		rep(i, 1, n + 1)N[i] = i;
		rep(i, 1, m + 1)B[i] = i + n;
	}
	inline int sgn(db x) { return (x > EPS) - (x < -EPS);}
	void pivot(int l, int e) {
		db tmp = A[l][e];
		b[l] /= tmp, A[l][e] = 1 / tmp;
		rep(i, 1, n + 1)if(i != e) A[l][i] /= tmp;
		rep(i, 1, m + 1)if(i != l) {
			b[i] -= A[i][e] * b[l];
			rep(j, 1, n + 1)A[i][j] -= (j != e) * A[i][e] * A[l][j];
			A[i][e] = -A[i][e] / tmp;
		}
		rep(i, 1, n + 1)c[i] -= (i != e) * c[e] * A[l][i];
		v += b[l] * c[e]; c[e] *= -A[l][e]; swap(B[l],N[e]);
	}
	db run() {
		while(1) {
			int r, l, e = -1;db delt = -DINF;
			rep(j, 1, n + 1)if(sgn(c[j]) > 0) {
				db tmp = DINF;
				rep(i, 1, m + 1)if(sgn(A[i][j]) > 0 && b[i] / A[i][j] < tmp)
					r = i, tmp = b[i] / A[i][j];
				if(delt < tmp * c[j]) l = r, e = j, delt = tmp * c[j];
			}
			if(e == -1) break; pivot(l, e);
		}
		rep(i, 1, n + 1) rep(j, 1, m + 1)
			if(B[j] == i) { ans[i] = (j <= m ? b[j] : 0); break;}
		return v;
	}
}Sim;
int n, a[N][N];	
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	Sim.init(n << 1, n * n);
	rep(i, 0, n)rep(j, 0, n) {
		cin >> a[i][j];
		Sim.A[i * n + j + 1][i + 1] = 1; 
		Sim.A[i * n + j + 1][j + n + 1] = 1;
		Sim.b[i * n + j + 1] = MAXA - a[i][j];
	}
	rep(i, 0, n << 1)Sim.c[i + 1] = 1;
	cout << MAXA * n * n - n * (int)(Sim.run()) << endl;
	rep(i, 0, n)rep(j, 0, n) {
		cout << MAXA - (int)(Sim.ans[i + 1] + Sim.ans[j + n + 1]) << " \n"[j == n - 1];
	}
	return 0;
}
