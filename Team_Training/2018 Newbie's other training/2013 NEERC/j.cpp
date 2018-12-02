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

const int N = 1e7 + 7;
string s;
vi v, an;
map<string, int > M;
int ans, n, len[N], now[N], pre[N], p, tid, pos, pp; 


int get(int l) {
	string t;
	rep(i, l, sz(s)) {
		pp = i;
		if (s[i] == ' ' || (l == 0 && s[i] == ':')) break;
		t += s[i];
	}
	if (M.count(t) == 0) return M[t] = ++ tid;
	else return M[t];
}

int main() {
	freopen("join.in", "r", stdin);
	freopen("join.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	getline(cin, s);
	rep(i, 1, n+1) {
		getline(cin, s);
		v.clear();
		pp = -1;
		rep(i, 0, sz(s)) if ((i == 0 || s[i-1] == ' ') && s[i] == '@') v.pb(get(i));
		//rep(i, 0, sz(v)) dd(v[i]);
		//cout << endl;
		p = v[0];
		pre[i] = 0; 
		if (len[p] == 0) {
			len[p] = 1;
			now[p] = i;
		}
		rep(j, 1, sz(v)) if (v[j] != p) {
			if (len[p] < len[v[j]] + 1) {
				len[p] = len[v[j]] + 1;
				pre[i] = now[v[j]];
				now[p] = i;
			}
		}
		if (len[p] > ans) {
			ans = len[p];
			pos = i;
		}
	}
	while (pos) {
		an.pb(pos);
		pos = pre[pos];
	}
	cout << ans << endl;
	reverse(all(an));
	rep(i, 0, sz(an)) cout << an[i] << " ";
	return 0;
}
