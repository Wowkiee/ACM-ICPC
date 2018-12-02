#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(a) cout << #a << " = " << a << " "
#define de(a) cout << #a << " = " << a << endl
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double db;

const int N = 205;
int mid, ans, l[N], r[N], p, v, nowr, nowl, pos;
ll cnt, cc, now;
string s;
int getd(int a, int b) {
	if (a < 0) return -1;
	return a / b;
}

int getu(int a, int b){
	if (a < 0) return 0;
	if (a % b == 0) return a / b;
	return a / b + 1;
}

void print(int l1, int r1, int i) {
	cout << "check " << l1 << " " << r1 << endl;
	fflush(stdout);
	cin >> s;
	if (s[0] == 'Y') l[i] = 0, r[i] = r1;
	else l[i] = r1 + 1, r[i] = 1e9;
}
ll solve(int cas) {	
	ll cnt = 0;
	rep(x, l[0], r[0]+1) {
		nowr = v; nowl = 0;
		rep(i, 1, cas+1) {
			nowr = min(nowr, getd(r[i] - x, i));
			nowl = max(nowl, getu(l[i] - x, i));
			if (nowr < nowl) break;
		}
		if (nowr >= nowl) {
			cnt += nowr - nowl + 1;
			ans = x + nowr * cas;
		}
	}
	return cnt;
}
int main() {
	//	freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//std::ios::sync_with_stdio(0);
	//std::cin.tie(0);
	cin >> p >> v;
	rep(cas, 0, 100) {
		if (cas == 0) {
			print(0, p/2, cas);
			r[0] = min(r[0], p);
		}else {
			l[cas] = 0; r[cas] = 1e9;
			cnt = solve(cas);
			if (cnt == 1) {
				cout << "answer " << ans;
				fflush(stdout);
				return 0;
			}
			int l1 = 0, r1 = 1e9;
			now = 2 * cnt; pos = 0;
			while (l1 <= r1) {
				mid = l1 + r1 >> 1;
				r[cas] = mid;
				cc = solve(cas);
				if (abs(cc * 2 - cnt) < now) {
					now = abs(cc * 2 - cnt);
					pos = mid;
				}
				if (cc * 2 > cnt) r1 = mid - 1;
				else l1 = mid + 1;
			}
			r[cas] = pos;
			print(l[cas], r[cas], cas);
		}	
	}
	assert(0);
	return 0;
}
