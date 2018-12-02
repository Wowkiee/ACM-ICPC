#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(a) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
//----
map<int,int> M,M2;
map<int,int>::iterator it;
int n, c;
vi v;
int main() {
	// freopen(".in", "r", stdin);
	// freopen(".out", "w", stdout);
	cin >> n >> c;
	rep(i, 0, 800) {
		int a; cin >> a;
		cout << "decline" << endl;
		fflush(stdout);
		M[a]++;
	}
	for(it = M.begin(); it != M.end(); it++) {
		int tim = 1.0 * it->se / (800.0 / n) + 0.5;
		while(tim--)v.pb(it->fi);
	}
	assert(sz(v) == n);
	int pos = 0, Max = 0;
	rep(i, 1, 1 << n) {
		int sum = 0;
		rep(j, 0, n)if((i >> j) & 1)sum += v[j];
		if(sum <= c && sum > Max) pos = i, Max = sum;
	}
	rep(j, 0, n) if((pos >> j) & 1)M2[v[j]]++;
	int now = 0;
	if(Max == 0) {
		int a; cin >> a;
		cout << "accept" << endl;
		fflush(stdout);
		while(1) {
			int b; cin >> b;
			if(b)	cout << "decline" << endl;		
			else {
				cout<< "stop" << endl;
				return 0;
			}
			fflush(stdout);
		}
	}
	while(now < Max) {
		int a; cin >> a;
		if(a > now && M2[a - now]) {
			if(a != Max) {
				cout<< "accept" << endl;
				fflush(stdout);
				M2[a - now]--;
				now = a;
			}
			else {
				cout << "stop" << endl;
				fflush(stdout);
				return 0;
			}
		}
		else {
			cout << "decline" << endl;
			fflush(stdout);
		}
	}
	cout << "stop" << endl;
	fflush(stdout);
	return 0;
}
