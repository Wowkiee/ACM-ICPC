#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(a) (int)a.size()
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double db;

const int N = 111;

int p;
string s;
char res[N];

void solve(int l, int r) {
	int i, j;
	rep(t, l, r) {
		if(s[t] == '{') i = t;
		if(s[t] == '}') j = t;
	}
	rep(t, i + 1, j) res[++p] = s[t];
	res[++p] = ' ';
	rep(t, l, r) {
		if(s[t] == '(') i = t;
		if(s[t] == ')') j = t;
	}
	rep(t, i + 1, j) res[++p] = s[t];
	res[++p] = ' ';
	rep(t, l, r) {
		if(s[t] == '[') i = t;
		if(s[t] == ']') j = t;
	}
	rep(t, i + 1, j) res[++p] = s[t];
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	getline(cin, s);
	for(int i = 0, j = 0; i < sz(s); i = j) {
		if(s[i] != '(' && s[i] != '{' && s[i] != '[') {
			while(j < sz(s) && s[j] != '(' && s[j] != '{' && s[j] != '[') ++j;
			rep(t, i, j) res[++p] = s[t];
		} else {
			int cnt = 0;
			while((cnt += (s[j] == ')' || s[j] == '}' || s[j] == ']')) < 3) ++j;
			++j;
			solve(i, j);
		}
	}
	if('a' <= res[1] && res[1] <= 'z') res[1] = res[1] - 'a' + 'A';
	rep(i, 2, p + 1) if('A' <= res[i] && res[i] <= 'Z') res[i] = res[i] - 'A' + 'a';
	rep(i, 1, p + 1) cout << res[i];
	cout << endl;
	return 0;
}
