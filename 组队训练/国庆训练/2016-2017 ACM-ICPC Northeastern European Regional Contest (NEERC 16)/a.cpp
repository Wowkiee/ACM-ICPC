#include<bits/stdc++.h>
using namespace std;
#define fi firse
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define sz(x) (int)x.size()
#define de(x) cout << #x << " = " << x << endl
#define dd(x) cout << #x << " = " << x << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N=100005;
char s[N];
vector<string> V;
bool isok(string a) {
	if(sz(a)==1)return false;
	if('A'<=a[0]&&a[0]<='Z');
	else return false;
	rep(i,1,sz(a)) {
		if('a'<=a[i]&&a[i]<='z');
		else return false;
	}
	return true;
}
void output(bool sp) {
	if(sz(V)==0)return;
	else if(sz(V)==1)cout<<V[0];
	else {
		rep(i,0,sz(V))cout<<V[i][0];
		cout<<" (";
		rep(i,0,sz(V)) {
			cout<<V[i];
			if(i!=sz(V)-1)cout<<" ";
		}
		cout<<")";
	}
	if(sp)cout<<" ";
	V.clear();
}
int main() {
	freopen("abbreviation.in", "r", stdin);
	freopen("abbreviation.out", "w", stdout);
	while(gets(s)) {
		int n=strlen(s);
		s[n]='\n';s[++n]=0;
		string ss;
	//	printf("%s",s);
		for(int i=0;s[i];i++) {
//			de(s[i]);
			if(isalpha(s[i]))ss+=s[i];
			else {
				if(sz(ss)==0) {
					output(true);
					cout<<s[i];
				}
				else {
					if(isok(ss)) {
						V.pb(ss);
						if(s[i]!=' ') {
							output(false);
							cout<<s[i];
						}
					}
					else {
						output(true);
						cout<<ss;
						cout<<s[i];
					}
				}
				ss.clear();
			}
		}
	}
	return 0;
}
