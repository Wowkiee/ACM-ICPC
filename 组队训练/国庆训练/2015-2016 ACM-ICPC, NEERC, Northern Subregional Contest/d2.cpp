
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(x) (int)x.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll<<(a))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 205;
int T;
ll n, m, ok, w;
ll tmp[N];

ll kpow(ll a, int b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

ll cal(pii x) {
	return kpow(2, x.fi) * kpow(3, x.se);
}

void solve(int a, int b, ll s) {
	if (s == 0) {
		ok = 1;
		cout << m << endl;
		ll w = 0;
		rep(i, 1, m+1) w += tmp[i],cout << tmp[i] << (i == m ? "\n" : " ");
		de(w);
		return;
	}
	ll x = 1, y;
	rep(i, 1, a+1) {
		 if (x * 2 > s) {a = i;break;}
		 x <<= 1;
	}
	per(i, 0, a+1) {
		y = x;
		rep(j, 1, b) {
			y *= 3;
			if (s < y) break;
		}
		rep(j, b, 70) {
			if (s < y) break;
			if (j > 0) y *= 3;
			if (s < y) break;
			tmp[++m] = y;
			solve(i-1, j+1, s - y);
			m--;
			if (ok) return;
		}
		x >>= 1;
	}
} 

int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n;
		ok = m = 0;
		solve(70, 0, n);
	}
	return 0;
}
