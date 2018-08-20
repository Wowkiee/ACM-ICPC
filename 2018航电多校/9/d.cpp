#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
//---

__int128 s, fz, g;
ll a, b, c, aa, bb, cc, T;

void print(__int128 x) {
	bool sign = (x < 0);
	if(x == 0) {
		cout << "0";
		return ;
	}
	vi v;
	if(x < 0) x = -x;
	while(x) {
		v.pb(x%10);
		x/=10;
	}
	reverse(all(v));
	if(sign) cout << "-";
	rep(i, 0, sz(v)) cout << v[i];
}

__int128 abs(__int128 x) {
	return x > 0 ? x : -x;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T)  {
		cin >> a >> b >> c;
		cin >> aa >> bb >> cc;
		s = a + b + c;
		fz = (__int128)aa * c - aa * b + bb * a - bb * c + cc * b - cc * a;
		g = __gcd(abs(fz),s);
		s /= g;
		fz /= g;
		print(fz);
		if (s != 1) cout << "/",print(s);
		cout << endl;
	}
	return 0;
}
