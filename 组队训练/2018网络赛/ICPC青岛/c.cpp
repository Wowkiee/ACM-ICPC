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
const int P = 256;
int add(int a, int b) {if((a += b) >= P) a -= P; return a;}
int sub(int a, int b) {if((a -= b) < 0) a += P; return a;}
int mul(int a, int b) {return 1ll * a * b % P;}
int kpow(int a, int b) {int r=1;for(;b;b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);}return r;}
//---
const int N = 1e4 + 7;
int n, T, x[N], k[N], now, val;
string s[N];
bool vis [N][300];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n;
		rep(i, 1, n+1) {
			cin >> s[i];
			if (s[i] == "add") cin >> x[i];
			else cin >> x[i] >> k[i];
		}
		rep(i, 1, n+1) rep(j, 0, 256) vis[i][j] = 0;
		val = 0; now = 1;
		bool ok = 1;
		while (now <= n) {
			if (vis[now][val]) {ok = 0;break;}
			vis[now][val] = 1;
			if (s[now] == "add") {val = add(x[now++], val);continue;}
			if (s[now] == "beq") {
				if (val == x[now]) now = k[now];else now++;
				continue;
			}			
			if (s[now] == "bne") {
				if (val != x[now]) now = k[now];else now++;
				continue;
			}	
			if (s[now] == "blt") {
				if (val < x[now]) now = k[now];else now++;
				continue;
			}	
			if (s[now] == "bgt") {
				if (val > x[now]) now = k[now];else now++;
				continue;
			}		
		}
		if (ok) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
