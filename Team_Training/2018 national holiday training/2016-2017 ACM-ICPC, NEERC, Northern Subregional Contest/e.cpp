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

const int P = 1e9 + 7;
int add(int x, int y) {return (x + y) % P;}
int sub(int x, int y) {return (x - y + P) % P;}
int mul(int x, int y) {return 1ll * x * y % P;}

const int N = 1e5 + 7;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int pos, n,m, S1, S2,x, y, sum1, sum2, cnt, w, CNT, k, sum3, S3;
string s;
pii b[N], tmp;
vector<pii> a;
map<pii, int> M;
set<pii> S;
int get(char x) {
	if (x == 'u') return 0;
	if (x == 'd') return 1;
	if (x == 'l') return 2;
	if (x == 'r') return 3;
	return -1;
}

pii pp[N];

pii operator - (pii a, pii b) {return {a.fi - b.fi, a.se - b.se};}

int cal(pii x) {
	return ((x.fi * pw(30) + x.se) % P + P) % P;
}

bool check() {
	ll tmp1 , tmp2, tmp3;
	pii tmp = *S.begin();
	tmp.fi--;tmp.se--;
	w = cal(tmp);
	tmp1 = sub(sum1, mul(w, cnt));
	tmp2 = sub(sum2, mul(2 * sum1, w));
	tmp2 = add(tmp2, mul(mul(w, w), cnt));
	tmp3 = add(sum3, 3ll * sum1 % P * w % P * w % P);
	tmp3 = sub(tmp3, 3ll * sum2 % P * w % P);
	tmp3 = sub(tmp3, 1ll * w * w % P * w % P);
	de(tmp3);de(S3);
	return tmp1 == S1 && tmp2 == S2 && tmp3 == S3;
}

int main() {
//	freopen("easy.in","r",stdin);
	//freopen("easy.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	getline(cin, s);
	getline(cin, s);
	rep(i, 1, n+1) if (get(s[i-1]) >= 0) a.pb({get(s[i-1]), i});
	k = sz(a);
	cin >> n >> m;
	tmp = {pw(30), pw(30)};
	rep(i, 1, n+1) {
		cin >> s;
		rep(j, 1 ,m+1) if (s[j-1] == 'X') {
			CNT++;
			tmp = min(tmp, {i, j});
			w = cal(mp(i+1, j+1) - tmp);
			S1 = add(S1, w);
			S2 = add(S2, mul(w, w));
			S3 = add(S3, 1ll * w * w % P * w % P);
		}
	}
	pos = 0;
	x = 1; y = 1;
	tmp = {1, 1};
	S.insert(tmp);
	M[tmp] = 1;
	cnt = 1;
	w = cal(tmp);
	sum1 = w;
	sum2 = mul(w, w);
	sum3 = 1ll * w * w % P * w % P;
	pii st = tmp;
	rep(i, 0, k) {
		while (cnt < CNT && pos < k) {
			x += dx[a[pos].fi]; y += dy[a[pos].fi];
			tmp = {x, y};
			b[i] = tmp;
			pp[pos] = tmp;
			M[tmp]++;
			if (M[tmp] == 1) {
				S.insert(tmp);
				cnt++;
				w = cal(tmp);
				sum1 = add(sum1, w);
				sum2 = add(sum2, mul(w, w));
				sum3 = add(sum3, 1ll * w * w % P * w % P);
			}
			pos++;
		}
		if (cnt == CNT && check()) {
			cout << "YES" << endl;
			cout << a[i].se << " " << a[pos-1].se << endl;
			return 0;
		}

		M[st]--;
		if (M[st] == 0) {
			cnt--;
			S.erase(st);
			w = cal(st);
			sum1 = sub(sum1, w);
			sum2 = sub(sum2, mul(w, w));
			sum3 = sub(sum3, 1ll * w * w % P * w % P);
		}
		st = pp[i];
	}
	cout << "NO";
	return 0;
}
