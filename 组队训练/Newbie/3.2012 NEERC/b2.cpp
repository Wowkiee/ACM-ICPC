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

const int TIM = 850;

char o[][22] = {"decline", "accept", "stop"};
map<int,int> M,M2;
map<int,int>::iterator it;
int n, c, cnt, tim;
vi v;

int read() {
	int x;
	scanf("%d", &x);
	return x;
}

void print(int i) {
	++cnt;
	//assert(cnt <= 1000);
	printf("%s\n", o[i]);
	fflush(stdout);
}

int main() {
	n = read(), c = read();
	int a = read();
	print(1);
	while(a) {
		int b = read();
		tim++;
		M[abs(b - a)]++;
		if(a > b) print(1), a = b;
		else print(0);
	}
	rep(i, 0, TIM) {
		int a = read();
		print(0);
		tim++;
		M[a]++;
	}
	for(it = M.begin(); it != M.end(); it++) {
		int tim = 1.0 * it->se / (tim * 1. / n) + 0.5;
		tim = max(tim, 1);
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
		int a = read();
		print(1);
		while(1) {
			int b = read();
			if(b) print(0);
			else {
				print(2);
				return 0;
			}
		}
	}
	while(now < Max) {
		int a = read();
		if(a > now && M2[a - now]) {
			if(a != Max) {
				print(1);
				M2[a - now]--;
				now = a;
			}
			else {
				print(2);
				return 0;
			}
		}
		else {
			print(0);
		}
	}
	return 0;
}
