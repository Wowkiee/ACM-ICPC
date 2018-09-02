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

const int N = 101010;

int n;
int a[N], ans[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		///
		cin >> n;
		///init
		fill_n(ans+1, n, 0);
		///read
		rep(i, 1, n+1) cin >> a[i];
		///solve
		priority_queue<pii> iso; // v, i
		priority_queue<pii> pai; // b, i
		rep(i, 1, n+1) {
			if(!iso.empty() && -iso.top().fi < a[i]) {
				auto u = iso.top();iso.pop();
				ans[u.se] = -1;
				ans[i] = 1;
				pai.push(mp(-a[i], i));
			} else {
				if(!pai.empty() && -pai.top().fi < a[i]) {
					auto u = pai.top();pai.pop();
					ans[u.se] = 0;
					iso.push(u);
					ans[i] = 1;
					pai.push(mp(-a[i], i));
				} else {
					iso.push(mp(-a[i], i));
				}
			}
		}
		ll r1 = 0;
		rep(i, 1, n+1) r1 += a[i] * ans[i];
		multiset<int> s;
		int r2 = 0;
		rep(i, 1, n+1) {
			if(ans[i] == -1) s.insert(a[i]), ++r2;
			if(ans[i] == 1) {
				if(s.find(a[i]) != s.end()) {
					s.erase(s.find(a[i]));
					--r2;
				} else {
					++r2;
				}
			}
		}
		cout << r1 << " " << r2 << endl;
	}
	return 0;
}
