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
const int N = 3e5 + 7;
int n;
char s[N];
ll pre[N];
map<ll,int> M;
int getRank(char a) {
	if(a>='a')return a-'a';
	else return 26+a-'A';
}
int main() {
	//freopen("hyperdrome.in", "r", stdin);
	//freopen("hyperdrome.out", "w", stdout);
	//scanf("%d%s", &n, s + 1);
	n = 3e5;rep(i,1,300001)s[i]=rand()%26+'a';
	ll ans = 0;
	M[0]++;
	rep(i, 1, n + 1) {
		pre[i] = pre[i - 1] ^ (1ll << getRank(s[i]));
		rep(j, 0, 52)if(M.find(pre[i] ^ (1ll << j)) != M.end())ans += M[pre[i] ^ (1ll << j)];
		ans += M[pre[i]];
		M[pre[i]]++;
	}
	printf("%lld\n",ans);
	return 0;
}
