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

const int N = 8e5 + 7;
int n, n2, T, M, a[N], x, ok, p;
string s;
struct Trie{
	static const int N = :: N;
	int son[N][2], _ , w[N];
	int ne() {fill_n(son[_], 2, -1); w[_] = -1; return _++;}
	void ini(){_ = 0; ne();}
	void insert(const string &s) {
		int u = 0;
		for (auto ch : s) {
			int & v = son[u][ch - '0'];
			if (!~v) v = ne();
			u = v;
		}
		w[u] = x;
	}
	int ask(int &p) {
		int u = 0;
		while (w[u] == - 1) {
			int & v = son[u][a[p]];
			u = v;
			p++;
		}
		return w[u];
	}
} tree;

int get(char x) {
	if (x >= '0' && x <='9') return x - '0';
	if (x >= 'A' && x<= 'Z') return x - 'A' + 10;
	return x - 'a' + 10;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T) {
		cin >> M >> n;
		tree.ini();
		rep(i, 1, n+1) {
			cin >> x >> s;
			tree.insert(s);
		}
		cin >> s;
		//dd(s);
		n = 0;
		rep(i, 0, sz(s)) {
			int tmp = get(s[i]);
			per(j, 0, 4) if (pw(j) & tmp) a[++n] = 1;else a[++n] = 0;
		}
		n2 = 0;
		for (int i = 1; i <= n; i += 9) {
			if (i + 8 > n) break;
			ok = 0;
			rep(j, i, i + 9) ok ^= a[j];
			if (ok) rep(j, i, i + 8) a[++n2] = a[j]; 
		}
		/*dd(n2);
		rep(i, 1, n2+1) cout << a[i];
		cout << endl;*/
		n = n2;p = 1;
		rep(i, 0, M) {
			cout << char(tree.ask(p));
		}
		cout << endl;
	}
	return 0;
}
