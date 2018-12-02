#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 1e5 + 7;
int l, r, n, id[N], ans[N], n1, n2;
pii sta[N];
string s;

bool check(pii a, pii b) {
	return (a.se - 'A' + 'a' == b.se) || (b.se - 'A' + 'a' == a.se);
}

void add(pii a, pii b){
	if (a.se >= 'A' && a.se <= 'Z') {
		ans[a.fi] = b.fi;
	}else ans[b.fi] = a.fi;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n >> s;
	rep(i, 0, 2*n) {
		if(s[i]>='a' && s[i] <='z') id[i] = ++n1;
		else id[i] = ++n2;
	}
	l = 0; r = -1;
	rep(i, 0, 2*n) {
		if (r < l) {
			sta[++r] = mp(id[i], s[i]);
		}else {
			if (check(sta[r], mp(id[i], s[i]))) add(sta[r], mp(id[i], s[i])), r--;
			else sta[++r] = mp(id[i], s[i]);
		}
	}
	if (r >= l) cout << "Impossible";
	else {
		rep(i, 1, n+1) cout << ans[i] << (i == n ? "\n" : " ");
	}
	return 0;
}
