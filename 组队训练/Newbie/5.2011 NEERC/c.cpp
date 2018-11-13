#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll<<(a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int N = 33, M = 2020;

int n, m, k, L, R, t, len, len2;
int pos[N], a[N], b[N], pre[M], f[N][M], sav[N][M], path[N][M];
bool ch[N][M], vis[N];
string str, str2;
string s[N], s2[N];

int main() {
	freopen("caption.in","r",stdin);
	freopen("caption.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> m >> k >> L >> R;
	getline(cin, s[0]);
	rep(i, 0, n) getline(cin, s[i]);
	t = (sz(s[0]) + 1) / (k + 3);
	for(int i = 0; i < sz(s[0]); i += k + 3) vis[s[0][i] - 'A'] = 1, pos[s[0][i] - 'A'] = i + 2;
	getline(cin, str);
	len = sz(str);
	rep(i, 0, len) cin >> a[i];
	int p = 0;
	rep(i, 0, len) {
		p += a[i];
		if(str[i] != ' ') rep(x, 0, n) rep(j, 0, k) {
			ch[x][p + j + 1] = (s[x][pos[str[i] - 'A'] + j] == '*');
		}
		p += k;
	}
	/*
	rep(i, 0, n) {
		rep(j, 1, m + 1) cout << (ch[i][j] ? '*' : '.');
		cout << endl;
	}
	*/
	rep(i, 1, m + 1) {
		pre[i] = pre[i - 1];
		rep(j, 0, n) pre[i] += ch[j][i];
	}
	rep(i, 0, 26) if(vis[i]) {
		rep(j, 1, m - k + 2) {
			rep(x, 0, n) rep(y, 0, k) {
				sav[i][j] += (ch[x][j + y] != (s[x][pos[i] + y] == '*'));
			}
		}
	}
	getline(cin, str2);
	getline(cin, str2);
	len2 = sz(str2);
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	rep(i, 1, len2 + 1) {
		rep(j, 1, m - k + 2) {
			int t = (str2[i - 1] == ' ') ? (pre[j + k - 1] - pre[j - 1]) : sav[str2[i - 1] - 'A'][j];
			if(i == 1) {
				f[i][j] = t + pre[j - 1];
			} else {
				rep(c, L, R + 1) if(j - c - k >= 1) {
					int s = f[i - 1][j - c - k] + pre[j - 1] - pre[j - c - 1] + t;
					if(s < f[i][j]) {
						f[i][j] = s;
						path[i][j] = j - c - k;
					}
				}
			}
		}
	}
	int mi = 1;
	rep(j, 1, m - k + 2) if(f[len2][mi] + pre[m] - pre[mi - 1 + k] > f[len2][j] + pre[m] - pre[j - 1 + k]) mi = j;
	vi ans;
	for(int i = len2; i; --i) {
		ans.pb(mi);
		mi = path[i][mi];
	}
	reverse(all(ans));
	rep(i, 0, sz(ans)) {
		if(i == 0) cout << ans[i] - 1 << " \n"[i == sz(ans) - 1];
		else cout << ans[i] - ans[i - 1] - k << " \n"[i == sz(ans) - 1];
	}
	return 0;
}
