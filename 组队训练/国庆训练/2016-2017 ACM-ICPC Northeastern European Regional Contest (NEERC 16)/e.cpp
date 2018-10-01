
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(x) (int)x.size()
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 7;
ll ans[N], s[N], t[N], k, now, x, sum1, sum2;
pii qry[N];
int n, q;
string op;
priority_queue<pair<ll, ll> > Q;
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	freopen("expect.in", "r", stdin);
	freopen("expect.out", "w", stdout);
	cin >> n  >> q;
	rep(i, 1, n+1) {
		cin >> op >> t[i] >> k;
		if (op[0] == '-') s[i] = s[i-1] + k;
		else s[i] = s[i-1] - k;
	}
	rep(i, 1, n) {
		if (s[i] > 0) {
			sum1 += s[i] * (t[i+1] - t[i]);
			sum2 += (t[i+1] - t[i]);
			Q.push(mp(-s[i], t[i+1] - t[i]));
		}
	}
	rep(i, 1, q+1) {
		cin >> x;
		qry[i] = {x, i};
	} 
	sort(qry + 1, qry + q + 1);
	rep(i, 1, q + 1) {
		if (qry[i].fi < s[n]) ans[qry[i].se] = -1;
		else {
			while (!Q.empty()) {
				if (qry[i].fi <= -Q.top().fi) {
					x = qry[i].fi;
					sum1 -= sum2 * (x - now);
					now = x;
					break;
				}else {
					sum1 -= sum2 * (-Q.top().fi - now);
					sum2 -= Q.top().se;
					now = -Q.top().fi;
					Q.pop();
				}
			}
			ans[qry[i].se] = sum1;
		}
	}
	rep(i, 1, q + 1) {
		if (ans[i] == -1) cout  << "INFINITY" << endl;
		else cout << ans[i] << endl;
	}
	return 0;
}
