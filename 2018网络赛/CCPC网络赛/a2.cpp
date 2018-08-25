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

const int N = 1e5 + 7;
int f[N];
ll ans1, ans2;
int n, x, T;

/*struct node{
	int val, pos;
	bool operator
}*/

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n;
		priority_queue<pair<pii, int > > q;
		rep(i, 0, n) {
			cin >> x;
			if (!q.empty() && -q.top().fi.fi < x) {
				ans1 += x + q.top().fi.fi;
				f[q.top().se]++;
				//q.top().fi.se++;
				f[i]--;
				if (f[q.top().se] == 1) q.pop();
				else {
					auto tmp = q.top();
					q.pop();
					tmp.fi.se = f[tmp.se];
					q.push(tmp);
				}
			}
			q.push(mp(mp(-x, -f[i]), i));
		}
		rep(i, 0, n) {
				//de(f[i]);
				if(f[i]) ans2++, f[i] = 0;}
		cout << ans1 << " " << ans2 << endl;
		ans1 = ans2 = 0;
	}
	return 0;
}
