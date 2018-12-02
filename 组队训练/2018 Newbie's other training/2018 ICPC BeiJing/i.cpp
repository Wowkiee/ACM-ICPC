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
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
//----
const int N = 100005;
char s[N];
int main() {
	int T; scanf("%d", &T); while(T--) {
		scanf("%s",s);
		int n = strlen(s);
		if(n == 1)printf("%c\n",s[0] - 1);
		else {
			if(s[0] >= '2') {
				s[0] -= 1;
				rep(i, 0, n)printf("%c",s[i]);
				per(i, 0, n - 1)printf("%c",s[i]);
			} else if(s[1] == '0') {
				s[1] = '9';
				rep(i, 1, n)printf("%c",s[i]);
				per(i, 1, n - 1)printf("%c",s[i]);
			} else {
				rep(i, 1, n)printf("%c",s[i]);
				per(i, 1, n)printf("%c",s[i]);
			}
			puts("");
		}
	}
	return 0;
}
