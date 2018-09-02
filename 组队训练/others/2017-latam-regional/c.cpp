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
int n, cnt[N], a[N], k, ans1, ans2, ans, d;

int check(int n, int o){
	if (n % k != 0) return -1;
	d = n / k;
	ans1 = ans2 = -1;
	rep(i, 1, k+1) {
		if (cnt[i] > d && o == 1) return -1;
		if (cnt[i] < d && o == -1) return -1;
		if (cnt[i] > d) {
			if (cnt[i] > d + 1 || ans1 != -1) return -1;
			ans1 = i;
		}
		if (cnt[i] < d) {
			if (cnt[i] < d - 1 || ans2 != -1) return -1;
			ans2 = i;
		}
	}
	if (o == -1) cout << "-" << ans1;
	else if (o == 1) cout << "+" << ans2;
	else cout << "-" << ans1 << " " << "+" << ans2;
	return 0;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> k >> n;
	rep(i, 1, n+1) cin >> a[i], cnt[a[i]]++;
	ans = check(n-1, -1);
	if (ans != -1) return 0;
	ans = check(n+1, 1);
	if (ans != -1) return 0;
	ans = check(n, 0);
	if (ans != -1) return 0;
	cout << "*";
	return 0;
}
