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
#define endl "\n"
#define pw(a) (1ll << (a))
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;

const int N = 202020;

int n = 200;
int p[N], q[N], cnt[N];

void shuffle() {
	rep(i, 1, n + 1) q[i * 2 - 1] = p[i];
	rep(i, 1, n + 1) q[i * 2] = p[i + n];
	rep(i, 1, n << 1 | 1) p[i] = q[i];
}

bool check() {
	rep(i, 1, n << 1 | 1) {
		if(p[i] != i) return 0;
		//if (p[i] == 2) de(i);
	}
	return 1;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	rep(i, 1, n << 1 | 1) p[i] = i;
	for(int i = 1; ; ++i) {
		shuffle();
		rep(j, 1, n <<1 | 1) if (p[j] == j) cnt[j]++; //cout << p[j] << " ";
		//if i(p[6] == 6) cnt++;
		//cout << endl;
		if(check()) {
			de(i);
			//rep(j, 1, n <<1 | 1) de(cnt[j]); //cout << p[j] << " ";
			break;
		}
	}
	return 0;
}
