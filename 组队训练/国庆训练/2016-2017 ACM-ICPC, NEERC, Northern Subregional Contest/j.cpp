#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define dd(x) cout << #x << " = " << x << " "
#define de(x) cout << #x << " = " << x << endl
#define all(a) a.begin(), a.end()
#define pw(x) (1ll << (x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int c, p, w;
double a;
vi ans;
char get(int x) {return char(x + 'a' - 1);}

int main() {
	freopen("java2016.in","r",stdin);
	freopen("java2016.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> c;
	cout << 'a' << " = ? max ?" << endl;
	p = 17;
	rep(i, 1, p) cout << char(i + 'a') << " = "<< char(i + 'a' - 1)  << " max " << char(i + 'a' - 1) << endl;
	p++;
	cout << get(p) << " = " << "(" << get(p-1) << ") * (" << get(p-1) <<")" <<endl;
	w = 1;	
	if (c == 0) {
		cout << "? / ? / ?" << endl;
		return 0;
	}
	while (c > 0) {
		if (c & 1) {
			ans.pb(p);
		}
		p++;
		w = w + w;	
		cout << get(p) << " = " << get(p-1) << " + " << get(p-1) << endl;
		c >>= 1;
	}
	cout << get(ans[0]);
	rep(i, 1, sz(ans)) cout << " + " << get(ans[i]);
	return 0;
}
