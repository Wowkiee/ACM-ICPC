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

int T, n, a[3][3],b[3][3], x, y;
string s;
void solve(bool o) {
	memcpy(b,a,sizeof(a));
	if (o == 0) {
		b[x][y] = a[x+1][y];
		b[x][y+1] = a[x][y];
		b[x+1][y] = a[x+1][y+1];
		b[x+1][y+1] = a[x][y+1];
	}else {
		b[x][y] = a[x][y+1];
		b[x+1][y] = a[x][y];
		b[x+1][y+1] = a[x+1][y];
		b[x][y+1] = a[x+1][y+1];
	}
	memcpy(a,b,sizeof(a));
}	

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	cin >> T;
	rep(cas, 0, T) {
		cin >> n;
		rep(i, 0, 3){
			cin >> s;
			rep(j, 0, 3) a[i][j] = s[j] -'0';
		}
		rep(i, 0, n) {
			cin >> s;
			if (s[0] == '1') {
				x = 0; y = 0;
			}else if (s[0] == '2') {
				x = 0; y = 1;
			}else if (s[0] == '3') {
				x = 1; y = 0;
			}else {
				x = 1; y = 1;	
			}
			if (s[1] == 'C') {
				solve(0);	
			}else solve(1);
		}
		rep(i, 0, 3) {
			rep(j, 0, 3) {
				cout << a[i][j];
				//if (j == 2) cout << endl;else cout << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
