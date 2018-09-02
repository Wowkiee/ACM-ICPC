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
ll P = 1e9 + 7;
ll add(ll a, ll b) {if((a += b) >= P) a -= P; return a;}
ll sub(ll a, ll b) {if((a -= b) < 0) a += P; return a;}
ll mul(ll a, ll b) {return 1ll * a * b % P;}
//---

const int N = 1000001;

int A, B;
ll n;

struct S {
	int a, b;
	S() {}
	S(int x, int y) {
		a = x, b = y;
	}
	S operator * (const S &c) const {
		int x = add(mul(a, c.a), mul(mul(b, c.b), B));
		int y = add(mul(b, c.a), mul(a, c.b));
		return S(x, y);
	}
	S operator - (const S &c) const {
		int x = sub(a, c.a);
		int y = sub(b, c.b);
		return S(x, y);
	}
};

S kpow(S a, ll b) {
	S r = S(1, 0);
	while(b) {
		if(b & 1) r = r * a;
		a = a * a;
		b >>= 1;
	}
	return r;
}

ll h[N];

void init() {
	rep(i, 1, 1001) {
		for(int j = i * i; j < N; j += i * i) {
			h[j] = max(h[j], (ll)i);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	cin >> T;
	init();
	while(T--) {
		cin >> A >> B >> n >> P;
		P = P * 2;
		S L = S(A, 1), R = S(A, P - 1);
		S ans = kpow(L, n) - kpow(R, n);
		ans.b /= 2;
		P /= 2;
		cout << 1 << " ";
		cout << mul(ans.b, h[B]) << " ";
		cout << B / h[B] / h[B] << endl;
	}
	return 0;
}
