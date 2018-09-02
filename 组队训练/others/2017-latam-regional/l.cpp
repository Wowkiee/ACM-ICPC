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

const int N = 1e5 + 6;
int n, l[N], r[N], sx[N], sy[N], len, d, d1, d2, ax[N], ay[N], bx[N], by[N], ans[N], q, yl, yr, pos;

int w, x[N], y[N];

int get(int i) {
	int ans = 0;
	ans = sx[max(ax[i], bx[i]) - 1] - sx[min(ax[i], bx[i]) - 1];	
	ans += sy[max(ay[i], by[i]) - 1] - sy[min(ay[i], by[i]) - 1];
	return ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> n;
	rep(i, 1, n) cin >> x[i], sx[i] = sx[i-1] + x[i];
	rep(i, 1, n) cin >> y[i], sy[i] = sy[i-1] + y[i];
	cin >> q;
	rep(i, 1, q+1) {
		cin >> ax[i] >> ay[i] >> bx[i] >> by[i];
	}
	rep(i, 1, n) if (y[i] == 1) l[i] = i;else l[i] = l[i-1];
	per(i, 1, n) if (y[i] == 1) r[i] = i;else r[i] = r[i+1];
	rep(i, 1, q+1) {
		d1 = abs(ax[i] - bx[i]);
		d2 = abs(ay[i] - by[i]);
		//dd(d1);de(d2);
		if (d1 == d2) {
			ans[i] = get(i);
		}else if (d1 > d2) {
			ans[i] = get(i);
			yl = max(min(ay[i] - 1, by[i] - 1), 1);
			yr = min(max(ay[i], by[i]), n - 1);
			yl --;
			//pos = r[yl];
			len = n+1;
			if (r[yl] >= yl && r[yl] <= yr) len = 0;
			else {
				if (r[yl] > 0) len = r[yl] - yr;
				//len = min(r[yl] - yr, yl - l[yl]);
				if (l[yl] > 0) len = min(yl - l[yl], len);
			}
			//de(len);
			d = d1 - d2;
			if (d % 2 == 1) d--;
			w = min(2 * len, d);
			ans[i] += w * 5 + (d - w);
		}
	}
	rep(i, 1, n+1) swap(x[i], y[i]), swap(sx[i], sy[i]);
	rep(i, 1, n) if (y[i] == 1) l[i] = i;else l[i] = l[i-1];
	per(i, 1, n) if (y[i] == 1) r[i] = i;else r[i] = r[i+1];
	rep(i, 1, q+1) {
		swap(ax[i], ay[i]);
		swap(bx[i], by[i]);
		d1 = abs(ax[i] - bx[i]);
		d2 = abs(ay[i] - by[i]);
		if (d1 > d2) {
			ans[i] = get(i);
			yl = max(min(ay[i] - 1, by[i] - 1), 1);
			yr = min(max(ay[i], by[i]), n - 1);
			yl --;
			//pos = r[yl];		
			len = n+1;
			if (r[yl] >= yl && r[yl] <= yr) len = 0;
			else {
				if (r[yl] > 0) len = r[yl] - yr;
				//len = min(r[yl] - yr, yl - l[yl]);
				if (l[yl] > 0) len = min(yl - l[yl], len);
			}
			//de(len);
			d = d1 - d2;
			if (d % 2 == 1) d--;
			w = min(2 * len, d);
			ans[i] += w * 5 + (d - w);
		}
	}
	rep(i, 1, q+1) cout << ans[i] << endl; 
	return 0;
}
